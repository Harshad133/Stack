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
int pop(struct Stack *stack)
{
    char v;
    if(isEmpty(stack))
        return(-1);
    v=stack->arry[stack->top];
    stack->top--;
    return(v);
}
int prederence(char p, char k)
{
    int i,t1,t2;
    char O[5]="-+*/%";
    for(i=0; O[i]; i++)
    {
        if(p==O[i])
            t1=i;
        if(k==O[i])
            t2=i;
    }
    if(t2>=t1)
        return(1);
    return(0);
}
void inToPost(char *q)
{
    struct Stack *stack;

    char p[50];
    int i,k=0;
    stack=createStack(50);
    push(stack,'(');
    strcat(q,")");
    //printf("\n q = %s",q);
    for(i=0; stack->top!=-1; i++)
    {
        if(q[i]>='A'&&q[i]<='Z')
        {
            p[k]=q[i];
            k++;
        }
        else if(q[i]=='(')
            push(stack,'(');
        else if(q[i]==')')
        {
            while(stack->arry[stack->top]!='(')
            {
                p[k]=pop(stack);
                k++;
            }
            stack->top--;
        }
        else
        {
            if(stack->arry[stack->top]!='(')
            {
                if(prederence(q[i],stack->arry[stack->top]))
                {
                    p[k]=pop(stack);
                    k++;
                }
            }
            push(stack,q[i]);
        }
    }
    p[k]='\0';
    printf("\n Postfix is :::::------>>\n%s",p);
}

int main()
{
    char Q[50];
    int i;
    printf("enter Infix = ");
    /*for(i=0;i<=)*/
    gets(Q);
    //strcat(Q,")");
    inToPost(Q);
    /*for(i=0; i<=12; i++)
        printf("%d",p[i]);*/
    return 0;
}