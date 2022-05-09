#include "LIST.h"
#include <stdio.h>
#include <stdlib.h>
#include "LIST.c"

int main() {

list head = malloc(sizeof(list));
list second = malloc(sizeof(list));
list third = malloc(sizeof(list));
list fourth = malloc(sizeof(list));
list fifth = malloc(sizeof(list));
list sixth = malloc(sizeof(list));

head->el = aasel('a');
head->next = second;

second->el = lasel(third);
second->next = fifth;

third->el = aasel('b');
third->next = fourth;

fourth->el = aasel('c');
fourth->next = NULL;

fifth->el = aasel('d');
fifth->next = sixth;

sixth->el = aasel('e');
sixth->next = NULL;




}
