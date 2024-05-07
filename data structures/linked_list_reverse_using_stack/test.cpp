#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

Node *head;
void Reverse();
void Insert(int data);
void Print ();

int main ()
{
     head = NULL;
     Insert(2);
     Insert(4);
     Insert(6);
     Insert(8);
     Print();
     Reverse();
     Print();
     return 0 ;
}

void Insert(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if(head ==NULL)
    {
        head = temp;
    }
    else
    {
        Node*temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;    
    }
}

void Print(void)
{
    Node * temp = head;  //head是全局变量，不要在函数中直接使用，可能会改变head的指向。
    while (temp != NULL)
    {
        cout << setw(2) << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

void Reverse()
{
    if(head == NULL)
    {
        return;
    }
    stack<Node*>S;
    Node*temp = head;
    while(temp!=NULL)
    {
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    
} 
