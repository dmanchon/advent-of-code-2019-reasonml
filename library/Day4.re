exception WrongInput;

let parse = s => String.split_on_char('-', s);

let range = (x1, x2) => List.init(x2-x1, x => x + x1)

let _adjacent = x => {
    let x1 = List.concat([x, [-1]]);
    let x2 = List.concat([[-1], x]);
    List.exists(((x,y))=> x == y, List.combine(x1, x2))
}

let adjacent = x => {
    let rec helper = (x, prev, counts) => {
        
        let (count, others) = switch(counts) {
        | [] => (1, [])
        | [hd, ...tl] => (hd, tl)
        };
        
        switch x {
            | [] => counts
            | [hd, ...tl] => if (hd == prev) {helper(tl, prev, [count+1, ...others])} else {helper(tl, hd, [1, count, ...others])}
        }
    }
    List.exists(x=> x==2, helper(x, -1, []))
}

let increasing = x => {
    let x1 = List.concat([x, [Int32.to_int(Int32.max_int)]]);
    let x2 = List.concat([[-1], x]);
    List.for_all(((x,y))=> x >= y, List.combine(x1, x2))
}

let candidate = x => {
    let sx = string_of_int(x) |> String.to_seq |> List.of_seq |> List.map(x=>int_of_char(x));
    if (adjacent(sx) && increasing(sx)) {
        true
    } else {
        false
    }
}

let func = in_stream => {
  let (l1, l2) = switch(parse(Stream.next(in_stream))) {
      | [e1, e2] => (int_of_string(e1), int_of_string(e2))
      | _ => raise(WrongInput)
  };

  string_of_int(List.length(List.filter(candidate, range(l1, l2))))
  
};