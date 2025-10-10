#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue
{
    int r,f;
    int data[SIZE];
};
typedef struct queue QUEUE;
void enqueue(QUEUE *q, int item)
{
    if(q->r==SIZE-1)
        printf("\n queue full ");
    else
    {
        q->r = q->r+1;
        q->data[q->r] = item;
        if (q->f == -1)
            q->f=0;
    }
}
void dequeue(QUEUE *q)
{
    if(q->f==-1)
        printf("\n oueue is empty");
    else
    {
        printf("\n elemnt deleted %d",q->data[q->f]);
    if(q->f==q->r)
    {
        q->f=-1;
        q->r=-1;
    }
    else
        q->f=q->f+1;
    }
}
void display(QUEUE q)
{
    int i;
    if(q.f==-1)
        printf("\n queue empty");
    else
    {

        printf("\n queue content are\n");
        for(i=q.f;i<=q.r;i++)
            printf("%d\t",q.data[i]);
    }
}
int main()
{
    int item,ch;
    QUEUE q;
    q.f=-1;
    q.r=-1;
    for(;;)
    {
        printf("\n 1.INSERT \n 2.DELETE \n 3.DISPLAY \n 4.EXIT");
        printf("\n Read choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n read elements to be inserted:");
            scanf("%d",&item);
            enqueue(&q,item);
            break;
            case 2:dequeue(&q);
            break;
            case 3:display(q);
            break;
            default:exit(0);
        }
    }
    return 0;
}
