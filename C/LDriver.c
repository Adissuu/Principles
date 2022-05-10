#include "LIST.h"
#include "LIST.c"
#include <stdio.h>
#include <stdlib.h>

int main(){


    element a = aasel('a');
    element b = aasel('b');
    element c = aasel('c');
    element d = aasel('d');
    element e = aasel('e');


    list one = cons(b, cons(c, NULL));
    list two = cons(lasel(one),cons(d, cons(e, NULL)));
    list total = cons(a,two);

    print(lasel(total));

    printf("\n");
    print(car(lasel(total)));
    printf("\n");
    print(lasel(cdr(lasel(total))));
    printf("\n");
    print((car(car(lasel(total)))));
    lfreer(total);
    return 0;
}