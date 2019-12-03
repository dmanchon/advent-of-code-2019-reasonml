let foo = () => print_endline("Hello");

let url = "https://adventofcode.com/2019/day/1/input";


let req = () => {
    open Curly;
    let request = Request.make(~url=url, ~meth=`GET, ());
    switch(run(request)) {
    | Ok(x) => print_endline(x.Curly.Response.body)
    | _ => ()
    };
}

