let func_ = (in_stream) => {
  let sum = ref(0);
  let calc = n => int_of_float(Float.floor(n /. 3.0) -. 2.0);

  in_stream |> Stream.iter(x => sum := sum.contents + calc(float_of_string(x)));

  string_of_int(sum.contents)

};

let positive = x => if(x > 0.0) x else 0.0;

let func = (in_stream) => {
  let sum = ref(0);
  let rec calc = (n, acc) => {
    let res = positive(Float.floor(n /. 3.0) -. 2.0);
    if(res > 0.) {
      calc(res, acc +. res)
    } else {
      int_of_float(acc +. res)
    }
  }

  in_stream |> Stream.iter(x => sum := sum.contents + calc(float_of_string(x), 0.));

  string_of_int(sum.contents)

};