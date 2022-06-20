#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void push(Node** list, int data);
void print(Node *cll);

int main()
{
    Node* cll;
    cll->next = cll;
    int n;
    int read;
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%d",&read);
        push(&cll,read);
        n--;
    }
    return 0;
}

void push(Node** list, int data){
    Node* n = malloc(sizeof(Node));       
    n->data = data;
    n->next = *list;
    *list = n;
}

void print(Node *cll)
{
    int first = cll->data;
    do
    {
        printf("%d ",cll->data);
        cll = cll->next;
    } while (cll->data != first);
}