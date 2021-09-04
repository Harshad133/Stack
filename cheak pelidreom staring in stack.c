#include<stdio.h>
#include<conio.h>

struct Stack
{
    int top;
    int capacity;
    char *arry;
};

struct Stack* createStack(int cap)
{
    struct Stack *p;
    p=(struct Stack*) malloc(sizeof(struct Stack));
    p->top=-1;
    p->capacity=cap;
    p->arry=(char *) malloc(sizeof(char)*p->capacity);
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
void push(struct Stack *stack,char v)
{
    if(isFull(stack))
        printf("\n Stack Overflow");
    else
    {
        stack->top++;
        stack->arry[stack->top]=v;
    }
}
char pop(struct Stack *stack)
{
    char v;
    if(isEmpty(stack))
        return(-1);
    v=stack->arry[stack->top];
    stack->top--;
    return(v);
}

int main()
{
    struct Stack *stack;
    char p[10],q[10];
    int i;
    stack=createStack(10);
    printf("p = ");
    gets(p);
    push(stack,'\0');

    for(i=0; p[i]; i++)
        push(stack,p[i]);


    for(i=0; stack->top!=-1; i++)
        q[i]=pop(stack);

    if(strcmp(p,q)==0)
        printf("YES");
    else
        printf("NO");

    printf("\nq = %s",q);
}