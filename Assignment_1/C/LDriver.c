#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    ATOM,
    LIST
} eltype;
typedef char atom;
struct _listnode;
typedef struct
{
    eltype type;
    union
    {
        atom a;
        struct _listnode *l;
    };
} element;
typedef struct _listnode
{
    element el;
    struct _listnode *next;
} * list;
// DECLARATION OF FUNCTION
element aasel(atom a);
element lasel(list l);
element car(element e);
list cdr(element e);
list cddr(element e);
list cons(element e, list l);
list append(list l1, list l2);
void lfreer(list l);
void print(element e);

//CONSTANT NIL
const element NIL = {.type = LIST, .l = NULL};


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



element aasel(atom a)
{
    element d;
    d.type = ATOM;
    d.a = a;
    return d;
}
element lasel(list l)
{
    element d;
    d.type = LIST;
    d.l = l;
    return d;
}
element car(element e)
{
    element d;
    if (e.type != LIST)
    {
        return NIL;
    }
    d = e.l->el;
    return d;
}
list cdr(element e)
{
    list d;
    if (e.type != LIST || (e.l->el.l) == NULL)
    {
        return NULL;
    }
    else
        return e.l->next;
}
list cddr(element e)
{
    list d;
    element ed;
    if (e.type != LIST)
    {
        return NULL;
    }
    if (e.l->next == NULL)
    {
        return NULL;
    }
    ed = e.l->el;
    if (ed.type != LIST)
    {
        return NULL;
    }
    if (ed.l->next == NULL)
    {
        return NULL;
    }
    d = ed.l;
    return d;
}
list cons(element e, list l)
{
    list new_list = malloc(sizeof(struct _listnode));
    new_list->el = e;
    new_list->next = l;
    return new_list;
}
void lfreer(list l)
{
    free(l);
}
list append(list l1, list l2)
{
    list new = malloc(sizeof(list));
    list list1 = l1;
    list list_new = new;
    while (list1 != NULL)
    {
        list_new->el = list1->el;
        list1 = list1->next;
        list_new->next = malloc(sizeof(list));
        list_new = list_new->next;
    }
    list1 = l2;
    while (list1 != NULL)
    {
        list_new->el = list1->el;
        list1 = list1->next;
        list_new->next = malloc(sizeof(list));
        list_new = list_new->next;
    }
    return new;
}
void print(element e)
{
    if (e.l == NULL && e.type == LIST)
    {
        printf("NIL");
    }
    else if (e.type == ATOM)
    {
        printf(" %c ", e.a);
    }
    else
    {
        printf("%c ", '(');
        for (list r = e.l; r != NULL; r = r->next)
        {
            if (r->el.type == LIST)
            {
                print(r->el);
            }
            else
                printf("%c ", r->el.a);
        }
        printf("%c ", ')');
    }
}