let input = ref("")
let output = ref(None)
let day = ref(0)


let main () = {
    let cmds = [
            ( "-o", Arg.String(str => output:= Some(str)), "output data"),
            ( "-d", Arg.Int(int => day:= int), "day problem")
        ];
    Arg.parse(cmds, (str => input:= str), "Help:");

    let func = switch(day.contents) {
        | 1 => Lib.Day1.func
        | 2 => Lib.Day2.func 
        | 3 => Lib.Day3.func
        | 4 => Lib.Day4.func
        | _ => Lib.Day1.func
    }

    let file_in_channel = Pervasives.open_in(input.contents);

    let file_stream = {
        Stream.from(_i => {
            switch(Pervasives.input_line(file_in_channel)) {
            | line => Some(line)
            | exception(End_of_file) => None
            };
        });

    };

    let out_stream = switch(output.contents) {
        | Some(name) => Pervasives.open_out(name)
        | None => Pervasives.stdout
    };

    let solution = func(file_stream);
    Pervasives.output_string(out_stream, solution)    
    Pervasives.close_out(out_stream);
};

let () = main()

 
 