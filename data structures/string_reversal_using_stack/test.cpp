#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
/*class Stack
{
private:
    char A[101];
    int top;
public:
    void Push(int x);
    void Pop();
    int Top();
    bool IsEmpty();
};*/

void Reverse(char *C,int n);

int main()
{
    char C[51];
    cout << "Enter a string: " ;
    gets(C);
    Reverse(C,strlen(C));
    cout << "Output = "<< C << endl;
    return 0;
}

void Reverse(char *C,int n)     //O(n)
{
    stack<char> S;
    for(int i=0;i<n;i++)  //O(n)
    {
        S.push(C[i]);
    }
    for(int i=0;i<n;i++)  //O(n)
    {
        C[i]=S.top();
        S.pop();
    }

}


