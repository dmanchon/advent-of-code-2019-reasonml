
Lib.Day3.(assert(parse("R8,U5,L5,D3") == [R(8), U(5), L(5), D(3)]));
Lib.Day3.(assert(coords_of_path([R(8), U(5), L(5), D(3)]) == [(0, 0), (8, 0), (8, 5), (3, 5), (3, 2)]));

Lib.Day3.(crossings([R(8), U(5), L(5), D(3)], parse("U7,R6,D4,L4")));