#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define INF 100000

int isNumber(char data)
{
    char numbers[10]= "1234567890";
    for(int i=0; i<10;i++)
    {
        if(numbers[i]==data) return 1;
    }
    return 0;
}

int isOperator(char data)
{
    char operators[6]= "+-*/%^";
    for(int i=0; i<6;i++)
    {
        if(operators[i]==data) return 1;
    }
    return 0;
}

/*void printArray(float a[],int n)
{
    for(int i=n-1; i>=0;i--)
    {
        printf("%.1f , ",a[i]);
    }
    printf("\n");
}*/


int main(){
    char expr[80]={'@'};
    float numbers[30]={INF},a,b,res;
    int head=0;
    gets(expr);
    int n=strlen(expr);
    for(int i=0;i<n;i++)
    {
        if(isNumber(expr[i]))
        {
            char aux[5];
            int x=0;
            while( isNumber(expr[i]) )
            {
                aux[x++]=expr[i++];
            }
            char str[6] = "\0";
            for(int j=0;j<x;j++) str[j]=aux[j];
            numbers[head++]=atof(str);
        }

        else if (isOperator(expr[i]))
        {
            b=numbers[head-1];
            if(head>=0)
            {
                numbers[head--]=INF;
            } else { printf("No valida"); return 1;}
            a=numbers[head-1];
            if(head>=0)
            {
                numbers[head--]=INF;
            } else { printf("No valida"); return 1;}
            switch(expr[i])
            {
            case '+':
                res=a+b;
                numbers[head++]=res;
                break;
            case '-':
                res=a-b;
                numbers[head++]=res;
                break;
            case '*':
                res=a*b;
                numbers[head++]=res;
                break;
            case '/':
                res=a/b;
                numbers[head++]=res;
                break;
            case '%':
                res=fmod(a,b);
                numbers[head++]=res;
                break;
            case '^':
                res=pow(a,b);
                numbers[head++]=res;
                break;
            }

        }
        /*printArray(numbers,head);*/
    }
    if(head==1){
    printf("El resultado es: %.2f",numbers[head-1] );}
    else printf("expresion no valida");
    return 0;

}
