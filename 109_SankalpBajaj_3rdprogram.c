//Author-SankalpBajaj
//Date- 20-06-2021
//purpose-To check whether given expression is correctly parenthesized or not


#include <stdio.h>
#include <string.h>
void push(char);
void pop();


int i,top=-1;
char e[20],stack[20];


int main(){
	printf("Enter the Expression:\n");
	scanf("%s",&e);
	for(i=0;e[i]!='\0';i++){
	    if(e[i]=='('){
	        push(e[i]);
	    }
	    else if(e[i]==')'){
	        pop();
	    }
	}
	if(top==-1){
	    printf("Expression is correctly parenthesized\n");
	} 
	else{
	printf("Expression is incorrectly parenthesized\n");
	}  
}  
void push(char e){
	top=top+1;
	stack[top]=e;
}
void pop(){
	top=top-1;
}
