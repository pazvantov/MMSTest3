#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define COUNT 10
typedef struct
{
    double x;
    double y;
}point_t;

typedef struct
{
    point_t A;
    point_t B;
}rectangle_t;

typedef struct node {
    rectangle_t data;
    struct node* next;
} node_t;

double randReal(double min, double max);
void push(node_t** list, rectangle_t data);
double getArea(rectangle_t rect);
double areaRects(node_t* list);
rectangle_t genRect();
void filterRects(node_t** list, double min, double max);
void print_list(node_t* list);

int main()
{
    srand(time(NULL));
    double areaRects(node_t* list);
    node_t* head = NULL;
    for(int i=0;i<COUNT;i++)
    {
        push(&head,genRect());
    }
    print_list(head);
    filterRects(&head,10.0,17.0);
    print_list(head);

    return 0;
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

rectangle_t genRect()
{
    rectangle_t data;
    data.A.x = randReal(-10.0,10.0);
    data.A.y = randReal(-10.0,10.0);
    data.B.x = randReal(-10.0,10.0);
    data.B.y = randReal(-10.0,10.0);
    return data;
}

void push(node_t** list, rectangle_t data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

double areaRects(node_t* list)
{
    if(list == NULL)
        return 0;
    return getArea(list->data) + areaRects(list->next);
}

double getArea(rectangle_t rect)
{
    return fabs(rect.B.x - rect.A.x) * fabs(rect.B.y - rect.A.y);
}

void filterRects(node_t** list, double min, double max)
{
    node_t* prev = NULL;
    node_t* current = (*list);
    while(current != NULL)
    {
        
        if(getArea(current->data) > min && getArea(current->data) < max)
        {
            if(prev == NULL)
            {
                node_t* temp = current;
                current = current->next;
                free(temp);
                continue;
            }
            else
            {
                node_t* temp = current;
                prev->next = current->next;
                prev = current;
                current = current->next;
                free(temp);
                continue;
            }
        }
        prev = current;
        current = current->next;
    }
}

void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("Ax=%4.2lf Ay=%4.2lf ", current->data.A.x,current->data.A.y);
        printf("Bx=%4.2lf By=%4.2lf ", current->data.B.x,current->data.B.y);
        printf("area=%6.2lf\n",getArea(current->data));
        current = current->next;
    }
    putchar('\n');
}