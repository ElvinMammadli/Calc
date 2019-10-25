#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
 typedef struct {
    int top;
    int st[SIZE];
}STACK;

typedef struct {
    int top;
    char  st_c[SIZE];
}STACK_C;
//stack tanimlama
int son(STACK *sayi ,STACK_C *isaret);


int cevir(STACK *sayi ,STACK_C *isaret ,char *dizi);

void initialize (STACK *stack){
    stack->top=0;
}

int isEmpty (STACK *stack){
    if(stack->top==0)
       return 1;
    else return 0;
}


char look_c(STACK_C *stack){
if(isEmpty(stack)){
        printf("");
    }
    else {
        return stack->st_c[stack->top-1];
    }
}


int isFull (STACK *stack){
    if(stack->top==SIZE){
        return 1;
    }
    else return 0;
}

int pop (STACK *stack ){
    if(isEmpty(stack)){
        printf("");
        return -1;
    }
    else {
        stack->top--;
        return stack->st[stack->top];
    }
}

void push (STACK *stack , int value ){
    if (isFull(stack))
        printf("Stack is full");
    else {
        stack ->st[stack->top]=value;
        stack->top++;
    }
}


char pop_c (STACK *stack ){
    if(isEmpty(stack)){
        printf("");
        return -1;
    }
    else {
        stack->top--;
        return stack->st[stack->top];
    }
}

void push_c (STACK *stack , char value ){
    if (isFull(stack))
        printf("Stack is full");
    else {
        stack ->st[stack->top]=value;
        stack->top++;
    }
}

int main()
{
    char dizi[100];
    char v;
    int i =0,j=0;
    int value;
    STACK sayi;
    STACK_C isaret;
    initialize(&sayi);
    initialize(&isaret);
    printf("aritmetik ifadeyi giriniz");
    scanf("%s",dizi);
    cevir(&sayi,&isaret,dizi);
    while(sayi.top!=0  ){
    value=pop(&sayi);


    printf("%d \n",value);

    i++;}
    while(isaret.top!=0 ){

    v=pop_c(&isaret);
     printf("%c \n",v);


    j++;}
    return 0;
}



int cevir(STACK *sayi ,STACK_C *isaret ,char *dizi){
    int i=0,f=0;
    int j=0,k=0;
while (dizi[i]!=NULL){

    if(dizi[i]>'/'&&dizi[i]<':'){
        f=dizi[i]-'0';
        k=k*10+f;
        j++;
    }
    else {push(sayi,k);
    k=0;
    }
    char h;
   if (dizi[i]=='+'){
         h=pop(isaret);
        if(h=='/'){
              int g=0;
              int b=0;
              g=pop(sayi);
              b=pop(sayi);
              push(sayi,b/g);


        }
    if(h=='*'){
            int g=0;
            int b=0;
            g=pop(sayi);
            b=pop(sayi);
            push(sayi,g*b);

        } if(h=='+'){
             int g=0;
             int b=0;
             g=pop(sayi);
             b=pop(sayi);
             push(sayi,b+g);
          }


        push_c(isaret,dizi[i]);
    }
    else if (dizi[i]=='-'){
        char h=pop(isaret);
         if (h=='*'){
             int g=0;
             int b=0;
             g=pop(sayi);
             b=pop(sayi);
             push(sayi,g*b);
         }



         if(h=='/'){
             int g=0;
             int b=0;
             g=pop(sayi);
             b=pop(sayi);
             push(sayi,b/g);
         }

           if(h=='-'){
             int g=0;
             int b=0;
             g=pop(sayi);
             b=pop(sayi);
             push(sayi,b-g);
         }

         push_c(isaret,dizi[i]);
         k=0;
    }
    else if (dizi[i]=='*'){
        char r=pop_c(isaret);
            if(r=='/'){
             int g=0;
             int b=0;
             g=pop(sayi);
             b=pop(sayi);
             push(sayi,b/g*-1);
        }
             push_c(isaret,dizi[i]);
               int g=0;
             int b=0;
             g=pop(sayi);
             b=pop(sayi);
             push(sayi,b*g);
             }


       else if (dizi[i]=='/'){
        char r=pop_c(isaret);
       if(r=='/'){
             int g=0;
             int b=0;
             g=pop(sayi);
             b=pop(sayi);
             push(sayi,b/g);
       }
        if (r=='*'){
            int g=0;
             int b=0;
             g=pop(sayi);
             b=pop(sayi);
             push(sayi,g*b*-1);
        }
               push_c(isaret,dizi[i]);

       }
        else if (dizi[i]=='('){
        push_c(isaret,dizi[i]);
        }
       else if (dizi[i]==')'){
        push_c(isaret,dizi[i]);
        while(pop_c(isaret)!='('){
        son(sayi,isaret);
        }
       }
        else if(h=='('){
                    push_c(isaret,h);
                }


i++;
 }
    push(sayi,k);
while(isaret->top!=0){

    son(sayi,isaret);
}


return 1;
}


int son(STACK *sayi ,STACK_C *isaret){
   char f ;
   f= pop_c(isaret);
        if(f=='+'){
        int g=0;
        int b=0;
        g=pop(sayi);
        b=pop(sayi);
        push(sayi,b+g);

         }
        if(f=='*'){
            int g=0;
            int b=0;
            g=pop(sayi);
            b=pop(sayi);
            push(sayi,g*b);
        }
        if(f=='-'){
            int g=0;
            int b=0;
            g=pop(sayi);
            b=pop(sayi);
            push(sayi,b-g);
        }
         if(f=='/'){
            int g=0;
            int b=0;
            g=pop(sayi);
            b=pop(sayi);
            push(sayi,b/g);
        }

    }



