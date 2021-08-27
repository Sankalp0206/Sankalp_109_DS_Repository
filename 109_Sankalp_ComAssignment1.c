//Author- Sankalp Bajaj
//Roll No- 109
//Assignment 1


#include<stdio.h>
#include<stdlib.h>

struct info
{
char name[30];
int price;
struct info *next;
};
struct info *temp,*disp,*head;

void addrecord();
void display();

int main()
{
  int ch;
  while (1)
    {
      printf("\n Walnut Tracker\n");
      printf("\n 1. To add records");
      printf("\n 2. To view the records");
      printf("\n 3. To exit");
      printf("\n Enter your choice: ");
      scanf("%d",&ch);
      
      fflush(stdin);
      switch(ch)
            {
              case 1:
                  addrecord();
                      break;

              case 2:
                  display();
                      break;

              case 3:
                  exit(0);
                      break;

              default:
                  printf("Invalid choice! :/");

            }

    }
return 0;
}

void addrecord()
{
  struct info *add;
  add=(struct info*)malloc(sizeof(struct info));
  
  printf("\n Enter the name of dealer: ");
  gets(add->name);
  fflush(stdin);
  printf("\n Enter the price of walnut: ");
  scanf("%d",&add->price);
  fflush(stdin);

    if(head==NULL|| head->price>=add->price)
      {
        add->next=head;
        head=add;
      }
    else
      {
        temp=head;
          
          while(temp->next!=NULL && temp->next->price < add->price)
            {
              temp=temp->next;
            }

        add->next=temp->next;
        temp->next=add;

      }
  return;
 }

void display()
{
  if(head==NULL)
    {
      printf("\n No records to view\n");
      return;
    }

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      printf("\nName of dealer: %s",disp->name);
      printf("\nPrice of walnut: %d \n",disp->price);
    }
return;
}