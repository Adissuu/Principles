%Quesrtion 1.
%Declare the start and final points
%Starts:

start(a).
start(b).

%Finals:

final(a).
final(d).
final(f).

%Transactions
tran(a,0,b).
tran(a,1,c).
tran(b,0,a).
tran(b,1,d).
tran(c,0,f).
tran(c,1,e).
tran(d,0,f).
tran(d,1,e).
tran(e,0,e).
tran(e,1,e).
tran(f,0,f).
tran(f,1,e).

%Finding the last points.
find_last(Q,[],Q).
find_last(Q,[H|T],Q2):-tran(Q,H,Q1),find_last(Q1,T,Q2).

%Checking acceptance
is_accepted(L):- start(Q),find_last(Q,L,Q1),final(Q1),!.

%Question 2.

%Queries:

%?- is_accepted([0]).

%- true.

%?- is_accepted([1]).

%- true.

%?- is_accepted([0,1]).

%- true.

%?- is_accepted([1,0]).

%- true.

%Therefore, all the four sequences are accepted.