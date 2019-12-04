exception Err(string, string);

let rec step = (tape, pc) =>
  switch (tape[pc]) {
  | 1 =>
    let in1 = tape[tape[pc + 1]];
    let in2 = tape[tape[pc + 2]];
    let out = tape[pc + 3];
    tape[out] = in1 + in2;
    step(tape, pc + 4);
  | 2 =>
    let in1 = tape[tape[pc + 1]];
    let in2 = tape[tape[pc + 2]];
    let out = tape[pc + 3];
    tape[out] = in1 * in2;
    step(tape, pc + 4);
  | 99 => tape
  | x => raise(Err("Invalid operand", string_of_int(x)))
  };

let helper = (tape, x1, x2) => {
  tape[1] = x1;
  tape[2] = x2;
  let tape = step(tape, 0);
  string_of_int(tape[0]);
};

let func1 = in_stream => {
  let raw_input = Stream.next(in_stream);
  let f = x => x |> int_of_string;
  let tape =
    String.split_on_char(',', raw_input) |> List.map(f) |> Array.of_list;
  helper(tape, 12, 2);
};

let rec test = (tape, comb, original) => {
  let (x, y, rst) =
    switch (comb) {
    | [] => raise(Not_found)
    | [(x, y), ...rst] => (x, y, rst)
    };
  switch (helper(tape, x, y)) {
  | "19690720" => string_of_int(100 * x + y)
  | exception (Err(_, _)) => test(Array.of_list(original), rst, original)
  | _ => test(Array.of_list(original), rst, original)
  };
};

let func = in_stream => {
  let raw_input = Stream.next(in_stream);
  let f = x => x |> int_of_string;
  let tape =
    String.split_on_char(',', raw_input) |> List.map(f) |> Array.of_list;

  let r = List.init(100, x => x);
  let combinations =
    List.flatten(List.map(x => List.map(y => (x, y), r), r));
  let original = Array.to_list(tape);

  test(tape, combinations, original);
};
