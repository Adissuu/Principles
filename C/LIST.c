#include "LIST.h"
#include <stdio.h>
#include <stdlib.h>

// Definitions of the list
typedef enum
{
	ATOM,
	LIST
} eltype;		   // eltype is ATOM or LIST
typedef char atom; // char
struct _listnode;
typedef struct
{
	eltype type; // eltype is ATOM or LIST
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

const element NIL = {.type = LIST, .l = NULL};
//---------------------------------------------
// Functions

// Takes atom and returns element with atom set to it
element aasel(atom a)
{
	element r = {.type = ATOM, .a = a};
	return r;
}

// Takes list and returns element who is set to list
element lasel(list l)
{
	element r = {.type = LIST, .l = &l};
	return r;
}

// returns head of a list
element car(element e)
{
	if (e.l == LIST)
	{
		return e.l->el;
	}
	else
	{
		return NIL;
	}
}
// Returns tail of the list
list cdr(element e)
{
	if (e.type != LIST)
	{
		return NIL.l;
	}
	return e.l->next;
}

list cddr(element e)
{
	return cdr(cdr(e)->el);
}

list cons(element e, list l)
{
	list r = malloc(sizeof(list));
	r->el = e;
	r->next = l;
	return r;
}
// adds l2 to l1 and return l1
list append(list l1, list l2)
{
	list r = l1;
	while (r->next != NULL)
	{
		r = r->next;
	}
	r->next = l2;

	return l1;
}
// Deletes the list and its inner list
void lfreer(list l)
{
	list r = l;
	list next;

	while (r != NULL)
	{
		next = r->next;
		free(r);
		r = next;
	}

	l = NULL;
}

void print(element e)
{
	if (e.type == ATOM)
	{
		printf("%c", e.a);
	}
	else if (e.type == LIST && e.l == NULL)
	{
		printf("NIL");
	}
	else
	{
		list r = e.l;
		printf("(");
		while (r != NULL)
		{
			print(r->el);
			r = r->next;
		}
		printf(")");
	}
}
