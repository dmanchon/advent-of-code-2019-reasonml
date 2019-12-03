let func = (in_stream) => {
  let sum = ref(0);
  let calc = n => int_of_float(Float.floor(n /. 3.0) -. 2.0);

  in_stream |> Stream.iter(x => sum := sum.contents + calc(float_of_string(x)));

  string_of_int(sum.contents)

};