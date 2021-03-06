student(liam_daigle,40207583).
student(gabriel_dalesio,40208868).
student(gabriel_dubois,40200000).
student(ali_fertanat,40200001).

course(data_structures_and_algorithms,comp352).
course(principles_of_programming,comp348).
course(technical_writing,encs282).
course(web_programming,soen287).

enrolled(liam_daigle,comp352).
enrolled(liam_daigle,comp348).
enrolled(liam_daigle,encs282).

enrolled(gabriel_dalesio,comp352).
enrolled(gabriel_dalesio,comp348).
enrolled(gabriel_dalesio,encs282).

enrolled(gabriel_dubois,comp352).
enrolled(gabriel_dubois,comp348).
enrolled(gabriel_dubois,encs282).

enrolled(ali_fertanat,comp352).
enrolled(ali_fertanat,comp348).
enrolled(ali_fertanat,encs282).

size([],0).
size([_|Tail],X):-
    size(Tail,Y),
    X is Y + 1.

findcourses(X):-
    course(_,X).

uniquecourses(X):-
    enrolled(liam_daigle,X),
    enrolled(gabriel_dalesio,X),
    enrolled(gabriel_dubois,X),
    enrolled(ali_fertanat,X).

unique_course_list(L):-
    findall(X,uniquecourses(X),L).

course_list(L):-
    findall(X,findcourses(X),L).


