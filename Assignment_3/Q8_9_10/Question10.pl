every_other([],[]):-!.

every_other([A],List1):-
    !,
    append([A],[],List1).

every_other([A,_|T],List1):-

    every_other(T,List2),
    append([A],List2,List1).
