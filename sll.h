#ifndef SINGLY_LINKED_LIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node *next;
}node;
typedef struct list{
    node *pHead;
    node *pTail;
}list;


node *createNode(int x){
    node *p = malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}
list *createList(){
    list *l = malloc(sizeof(list));
    l->pHead = l->pTail = NULL;
    return l;
}


list *addTail(list *l, int x){
    if(l->pHead == NULL){
        node *p = createNode(x);
        l->pHead = l->pTail = p;
    }
    else{
        node *p = createNode(x);
        l->pTail->next = p;
        l->pTail = p;
    }
    return l;
}
list *addHead(list *l, int x){
    node *p = createNode(x);
    if(l->pHead == NULL){
        l->pHead = l->pTail = p;
    }
    else{
        p->next = l->pHead;
        l->pHead = p;
    }
    return l;
}
list *addAt(list *l, int locate, int x){
    node *p = createNode(x);
    int count = 0,count_tmp = 0;
    for(node *k = l->pHead; k!=NULL; k = k->next){
        count++;
    }
    if(l->pHead == NULL){
        l->pHead = l->pTail = p;
    }
    else if(locate == 0){
        l = addHead(l,x);
    }
    else if(locate >= count){
        l = addTail(l,x);
    }
    else{
        node *k;
        for(k = l->pHead; k!= NULL; k = k->next){
            if(count_tmp == locate-1) break;
            else count_tmp++;
        }
        node *tmp = k->next;
        k->next = p;
        p->next = tmp;
    }
    return l;

}
list *convert(list *l, int a, int b){
    for(node *k = l->pHead; k!=NULL; k = k->next){
        if(k->data == a){
            k->data = b;
        }
    }
    return l;
}


list *removeHead(list *l){
    if(l->pHead == NULL) return NULL;
    else{
        node *tmp = l->pHead;
        l->pHead = tmp->next;
        free(tmp);
        return l;
    }
}
list *removeTail(list *l){
    if(l->pHead == NULL) return NULL;
    else{
        node *k;
        for(k = l->pHead; (k->next)->next!= NULL; k = k->next);
        node *tmp = k->next;
        l->pTail = k;
        k->next = NULL;
        free(tmp);
        return l;
    }
}
list *removeAt(list *l,int locate,int n){
    if(locate == 0) l = removeHead(l);
    else if(locate == n-1) l = removeTail(l);
    else{
        node *k;
        int count = 0;
        for(k = l->pHead; k!= NULL; k = k->next){
            if(count == locate-1) break;
            else count++;
        }
        node *tmp = k->next;
        k->next = tmp->next;
        free(tmp);  
        return l;

    }
}


node *locate(list *l, int value){
    for(node *k = l->pHead; k!=NULL; k = k->next){
        if(k->data == value) return k;
    }
    return NULL;
}
int value(list *l, int index){
    int tmp = 0;
    for(node *k = l->pHead; k!= NULL; k = k->next){
        if(tmp == index) return k->data;
        else tmp ++;
    }
    return -1;
}
void printList(list *l){
    for(node *k = l->pHead; k!= NULL; k = k->next){
        printf("%d ",k->data);
    }
}
#endif