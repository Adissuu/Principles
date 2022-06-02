method(0,2) :- !.
method(1,1) :- !.
method(N,R) :-
    N > 1,
    N_pre os n-1,
    N_PrePrevious is n-2,
    method(N_pre, LHS),
    method(N_PrePrevious, RHS),
    R is LHS + RHS.

% Memorization of Lucas numbers
:- table lucas/2.

% Generate List
Lucasseq(M,R) :-
  numlist(0,M, List),
  Maplist(method, List, Result).


 
