element aasel(atom a)
{
    element r;
    r.type = ATOM;
    r.a = a;
    return r;
}
element lasel(list l)
{
    element r;
    r.type = LIST;
    r.l = l;
    return r;
}
element car(element e)
{
    element r;
    if (e.type != LIST)
    {
        return NIL;
    }
    r = e.l->el;
    return r;
}
list cdr(element e)
{
    list r;
    if (e.type != LIST || (e.l->el.l) == NULL)
    {
        return NULL;
    }
    else
        return e.l->next;
}
list cddr(element e)
{
    list r;
    element er;
    if (e.type != LIST)
    {
        return NULL;
    }
    if (e.l->next == NULL)
    {
        return NULL;
    }
    er = e.l->el;
    if (er.type != LIST)
    {
        return NULL;
    }
    if (er.l->next == NULL)
    {
        return NULL;
    }
    r = er.l;
    return r;
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
    list new = malloc(sizeof(struct _listnode));
    list list1 = l1;
    list list2 = new;
    while (list1 != NULL)
    {
        list2->el = list1->el;
        list1 = list1->next;
        list2->next = malloc(sizeof(list));
        list2 = list2->next;
    }
    list1 = l2;
    while (list1 != NULL)
    {
        list2->el = list1->el;
        list1 = list1->next;
        list2->next = malloc(sizeof(list));
        list2 = list2->next;
    }
    return new;
}
void print(element e)
{
  if(e.type==ATOM){
        printf("%c", e.a);
    }else if(e.type==LIST && e.l==NULL){
        printf("NIL");
    } else {
        list temp = e.l; 
            printf(" ( ");
            while(temp != NULL){
                print(temp->el);
                temp=temp->next; 
            }
            printf(" ) "); 
    }  
}