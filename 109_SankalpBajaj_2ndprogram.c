//Author- Sankalp Bajaj
//Purpose- Push & Pop operations in stack implemented using an array

#include<stdio.h>

int stack[50],top,x,i;
int Push(int,int);
int Pop();
int Display();
int main()
{
	int ch,n;
    top=-1;
    printf("\n Enter the size of STACK:");
    scanf("%d",&n);
    printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                	Push(n,x);
                	break;
            case 2:
               		Pop();
                	break;
            case 3:
                	Display();
                	break;
            case 4:
                	printf("\n  Exit Point ");
                	break;
            default:
                	printf ("\n  Please Enter a Valid Choice(1/2/3/4)");
                
        }
    }
    while(ch!=4);
    return 0;
}
int Push(n,x)
{
    if(top>=n-1)
    {
        printf("\n Stack is overflowing");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
int Pop()
{
    if(top<=-1)
    {
        printf("\n  Stack is underflowing");
    }
    else
    {
        printf("\n  The Popped element is %d",stack[top]);
        top--;
    }
}
int Display()
{
    if(top>=0)
    {
        printf("\n The elements in stack are: ");
        for(i=top; i>=0; i--)
            printf("%d ",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The stack is empty");
    }
   
}