let func_ = (in_stream) => {
  let sum = ref(0);
  let calc = n => int_of_float(Float.floor(n /. 3.0) -. 2.0);

  in_stream |> Stream.iter(x => sum := sum.contents + calc(float_of_string(x)));

  string_of_int(sum.contents)

};

let positive = x => if(x > 0.0) x else 0.0;



let read_file = (stream) => {
  let rec helper = (stream, l) => {
    switch(Stream.next(stream)) {
            | line => helper(stream, [float_of_string(line), ...l])
            | exception Stream.Failure => List.rev(l)
    }
  }
  helper(stream, [])
};


let func = (in_stream) => {
  let rec calc = (n, acc) => {
    let res = positive(Float.floor(n /. 3.0) -. 2.0);
    if(res > 0.) {
      calc(res, acc +. res)
    } else {
      int_of_float(acc +. res)
    }
  }

  let ns = List.map((x => calc(x, 0.)), read_file(in_stream));
  let sum = List.fold_left((x, y) => x + y, 0, ns);

  string_of_int(sum)

};