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

/*-------------Infix To Postfix-------------*/

char* inToPost(char *q)
{
    struct Stack *stack;

    char *p;
    p=(char*) malloc(sizeof(char)*50);
    // z=p;
    int i,k=0;
    stack=createStack(50);
    push(stack,'(');
    strcat(q,")");
    //printf("\n q = %s",q);
    for(i=0; stack->top!=-1; i++)
    {
        if(q[i]>='0'&&q[i]<='9')
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
    //  z=p;
    return(p);
}

/*----------------------------------------*/

/*-----postfix Evaluation-------*/
char plus(char a, char b)
{
    return(a+b);
}
char sub(char a,char b)
{
    return(a-b);
}
char multiple(char a,char b)
{
    return(a*b);
}
char devide(char a,char b)
{
    return(a/b);
}
char modulo(char a,char b)
{
    return(a%b);
}


int postfixEvalute(char *p)
{
    struct Stack *stack;
    int i;
    int x,y,c,v;
    strcat(p,")");
    stack=createStack(strlen(p));

    for(i=0; p[i]!=')'; i++)
    {
        if(p[i]>='0'&&p[i]<='9')
            push(stack,p[i]);
        else
        {
            x=pop(stack);
            y=pop(stack);
            if(p[i]=='+')
                c=plus(y-48,x-48);
            if(p[i]=='-')
                c=sub(y-48,x-48);
            if(p[i]=='*')
                c=multiple(y-48,x-48);
            if(p[i]=='/')
                c=devide(y-48,x-48);
            if(p[i]=='%')
                c=modulo(y-48,x-48);
            push(stack,c+48);
        }
    }
    v=pop(stack);
    return(v-48);
}

/*--------------------------------*/

int main()
{
    char Q[50];
    int i;
    int VALUE;
    char *p;
    printf("enter Infix = ");
    /*for(i=0;i<=)*/
    gets(Q);
    //strcat(Q,")");
    p=inToPost(Q);
    /*for(i=0; i<=12; i++)
        printf("%d",p[i]);*/
    printf("\n Postfix is :::::------>>\n%s",p);
    VALUE=postfixEvalute(p);
    printf("\n\n Result of Postfix Evaluation = %d", VALUE);
    return 0;
}