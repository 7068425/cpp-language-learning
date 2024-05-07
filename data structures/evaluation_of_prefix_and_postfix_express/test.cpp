/* Evaluation Of postfix Expression in C++ 
  Input Postfix expression must be in a desired format. 
  Operands must be integers and there should be space in between two operands.
  Only '+'  ,  '-'  , '*' and '/'  operators are expected. */

#include<iostream>
#include<stack>
#include<string>

using namespace std;
int EvaluatePostfix(string expression);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);
bool IsNumericDigit(char C);

int main()
{
    string expression;
    cout << "Enter Postfix Expression \n";
    getline(cin,expression);
    int result = EvaluatePostfix(expression);
    cout << "Output = "<<result<<"\n";
    return 0;
}
int EvaluatePostfix(string expression)
{
    stack<int> S;
    for(int i = 0;i< expression.length();i++) 
    {
        if(expression[i] == ' ' || expression[i] == ',') 
            continue;
        else if(IsOperator(expression[i])) 
        {
            int operand2 = S.top(); 
            S.pop();
            int operand1 = S.top(); 
            S.pop(); 
            int result = PerformOperation(expression[i], operand1, operand2);
            S.push(result);
        }
        else if(IsNumericDigit(expression[i]))
        {
            int operand = 0;
            while(i<expression.length() && IsNumericDigit(expression[i])) 
            {
                operand = (operand*10) + (expression[i] - '0');
                i++;
            }
            i--;            
/*Finally, you will come out of while loop with i set to a 
non-numeric character or end of string.decrement i because 
it will be incremented in increment section of loop once again. 
We do not want to skip the non-numeric character by 
incrementing i twice.  */
        }
    }
    return S.top();
}

bool IsNumericDigit(char C)
{
    if(C >= '0' && C <= '9') 
        return true;
    else
        return false;
}

bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    else
        return false;
}

int PerformOperation(char operation, int operand1, int operand2)
{
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;
    else cout<<"Unexpected Error \n";
    return -1;
} 