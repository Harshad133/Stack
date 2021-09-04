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
void isBinary(int n)
{
    int i;
    struct Stack *stack;
    stack=createStack(100);

    for(i=1; n!=0; i++) {
        push(stack,n%2);
        n=n/2;
    }

    while(stack->top!=-1)
        printf("%d",pop(stack));
}
int main()
{
    int n;
    printf("n = ");
    scanf("%d",&n);

    isBinary(n);
}