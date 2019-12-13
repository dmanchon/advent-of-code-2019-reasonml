exception Undefined(string);

type range = (int, int);

type cross =
  | Ver(int, range)
  | Hor(int, range);

type move =
  | U(int)
  | D(int)
  | R(int)
  | L(int);

let coords_of_path = path => {
  let rec helper = (moves, coords) => {
    let (x, y) = List.hd(coords);
    switch (moves) {
    | [] => List.rev(coords)
    | [p, ...rst] =>
      switch (p) {
      | U(v) => helper(rst, [(x, y + v), ...coords])
      | D(v) => helper(rst, [(x, y - v), ...coords])
      | L(v) => helper(rst, [(x - v, y), ...coords])
      | R(v) => helper(rst, [(x + v, y), ...coords])
      }
    };
  };
  helper(path, [(0, 0)]);
};

let lines_of_path = path => {
  let rec helper = (moves, coords, acc) => {
    let (x, y) = List.hd(coords);
    switch (moves) {
    | [] => List.rev(acc)
    | [p, ...rst] =>
      switch (p) {
      | U(v) => helper(rst, [(x, y + v), ...coords], [Ver(x, (y, y + v)), ...acc])
      | D(v) => helper(rst, [(x, y - v), ...coords], [Ver(x, (y, y - v)), ...acc])
      | L(v) => helper(rst, [(x - v, y), ...coords], [Hor(y, (x, x - v)), ...acc])
      | R(v) => helper(rst, [(x + v, y), ...coords],[Hor(y, (x, x + v)), ...acc])
      }
    };
  };
  helper(path, [(0, 0)], []);
};

let in_range = (x, x1, x2) =>
  if (x > min(x1, x2) && x < max(x1, x2)) {
    Some(x);
  } else {
    None;
  };

let cross = (p1, p2) => {
  let coordinates =
    switch (p1, p2) {
    | (Ver(x, (y1, y2)), Hor(y, (x1, x2))) =>
      Some((x, x1, x2, y, y1, y2))
    | (Hor(y, (x1, x2)), Ver(x, (y1, y2))) =>
      Some((x, x1, x2, y, y1, y2))
    | _ => None
    };

  switch (coordinates) {
  | Some((x, x1, x2, y, y1, y2)) =>
    switch ((in_range(x, x1, x2), in_range(y, y1, y2))) {
    | (Some(m), Some(n)) => abs(m) + abs(n)
    | _ => 0
    };
  | None => 0
  };
};

let crossings = (p1, p2) =>
  List.sort(
    (x, y) => x - y,
    List.filter(
      x => x > 0,
      List.flatten(
        List.map(
          x => List.map(y => cross(x, y), lines_of_path(p2)),
          lines_of_path(p1),
        ),
      ),
    ),
  );

let parse = line => {
  let value = s => int_of_string(String.sub(s, 1, String.length(s) - 1));
  List.map(
    m =>
      switch (m.[0]) {
      | 'U' => U(value(m))
      | 'D' => D(value(m))
      | 'R' => R(value(m))
      | 'L' => L(value(m))
      | _ => raise(Undefined(m))
      },
    String.split_on_char(',', line),
  );
};

let func = in_stream => {
  let p1 = parse(Stream.next(in_stream));
  let p2 = parse(Stream.next(in_stream));
  let c = crossings(p1, p2);
  string_of_int(List.nth(c, 0));
};