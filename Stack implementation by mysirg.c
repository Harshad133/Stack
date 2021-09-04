#include<stdio.h>
#include<conio.h>
struct Stack
{
    int top;
    int capacity;
    int *arry;
};

struct Stack* createStack(int cap)
{
    struct Stack *p;
    p=(struct Stack*) malloc(sizeof(struct Stack));
    p->top=-1;
    p->capacity=cap;
    p->arry=(int *) malloc(sizeof(int)*p->capacity);
    return(p);
}
int isFull(struct Stack *stack)
{
    if(stack->top==stack->capacity-1)
        return(1);
    else
        return(0);
}
int isEmpty(struct Stack *stack)
{
    if(stack->top==-1)
        return(1);
    else
        return(0);
}
void push(struct Stack *stack,int v)
{
    if(isFull(stack))
        printf("\n Stack Overflow");
    else
    {
        stack->top++;
        stack->arry[stack->top]=v;
    }
}
int pop(struct Stack *stack)
{
    int v;
    if(isEmpty(stack))
        return(-1);
    v=stack->arry[stack->top];
    stack->top--;
    return(v);
}
int main()
{
    struct Stack *stack;
    int n,v,ch,r;
    printf("enter capacity of Stack = ");
    scanf("%d",&n);
    stack=createStack(n);
    printf("\n Enter 1 = push");
    printf("\n Enter 2 = pop");
    printf("\n Enter 3 = exit");

    while(1)
    {
        // clrscr();


        printf("\n\n Enter chois = ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nenter item = ");
            scanf("%d",&v);
            push(stack,v);
            break;
        case 2:
            r=pop(stack);
            if(r==-1)
                printf("\nStack is Underflow ::::----->> ");
            else
                printf("\n value = %d",r);
            break;
        case 3:
            exit(0);

        default:
            printf("\n choice is not available");
            break;
        }
    }
}