

sublist(_,0,0,[]):-!.

sublist([H|T],0,Length,New):-
    Length1 is Length - 1,
    sublist(T,0,Length1,New1),
    !,
    append([H],New1,New).

sublist([_|T],Index,Length,New):-
    Index1 is Index - 1,
    sublist(T,Index1,Length,New).
