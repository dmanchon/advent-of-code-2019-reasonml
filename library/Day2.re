exception Err(string, string);

let rec step = (tape, pc) => {
    switch(tape[pc]) {
        | 1 => {
            let in1 = tape[tape[pc + 1]];
            let in2 = tape[tape[pc + 2]];
            let out = tape[pc + 3];
            tape[out] = in1 + in2;
            step(tape, pc + 4)
        }
        | 2 => {
            let in1 = tape[tape[pc + 1]];
            let in2 = tape[tape[pc + 2]];
            let out = tape[pc + 3];
            tape[out] = in1 * in2;
            step(tape, pc + 4)
        }
       | 99 => tape
       | x => raise(Err("Invalid operand", string_of_int(x)))
    };

}

let func = (in_stream) => {
    let raw_input = Stream.next(in_stream);
    let f = x => x |> int_of_string;
    let tape = String.split_on_char(',', raw_input) |> List.map(f) |> Array.of_list;
    tape[1] = 12;
    tape[2] = 2;
    let tape = step(tape, 0); 
    string_of_int(tape[0])
};