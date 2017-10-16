#include <bits/stdc++.h>
using namespace std;

bool isNumber(char data)
{
    string numbers= "1234567890";
    for(char n:numbers)
    {
        if(data==n) return true;
    }
    return false;
}
bool isOperator(char data)
{
    string operators= "+-*/";
    for(char n:operators)
    {
        if(data==n) return true;
    }
    return false;
}
void printStack(stack<double> d)
{
    while(!d.empty())
    {
        cout<<d.top()<<",";
        d.pop();
    }
    cout<<"\n";
}



int main(){
    stack<double> numbers;
    string expr;
    double a,b,res;
    getline(cin, expr, '\n');

    for(int i=0; i<expr.size(); i++)
    {
        if(isNumber(expr[i]))
        {
            numbers.push(int(expr[i]-'0'));
        }
        else if (isOperator(expr[i]))
        {
            b=numbers.top();
            if(!numbers.empty())numbers.pop();
            a=numbers.top();
            if(!numbers.empty())numbers.pop();
            switch(expr[i])
            {
            case '+':
                res=a+b;
                numbers.push(res);
                break;
            case '-':
                res=a-b;
                numbers.push(res);
                break;
            case '*':
                res=a*b;
                numbers.push(res);
                break;
            case '/':
                res=a/b;
                numbers.push(res);
                break;
            }
        }
           printStack(numbers);
    }

}
