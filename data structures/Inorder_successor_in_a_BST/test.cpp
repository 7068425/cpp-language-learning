/* C++ program to find Inorder successor in a BST */

#include<iostream>
using namespace std;
struct Node 
{
    int data;
    Node *left;
    Node *right;
};

Node* Find(Node*root, int data);
Node* FindMin(Node* root); 
Node* Getsuccessor(Node* root,int data); 
void Inorder(Node *root); 
Node* Insert(Node *root,char data); 

int main() 
{
    Node* root = NULL;
    root = Insert(root,5); root = Insert(root,10);
    root = Insert(root,3); root = Insert(root,4);
    root = Insert(root,1); root = Insert(root,11);
    cout<<"Inorder Traversal: ";
    Inorder(root);
    cout << endl;
    Node* successor = Getsuccessor(root,1);
    if(successor == NULL) cout<<"No successor Found"<<endl;
    else
        cout<<"Successor is "<<successor->data<<endl;
}

Node* Find(Node*root, int data) 
{
    if(root == NULL) return NULL;
    else if(root->data == data) return root;
    else if(root->data < data) return Find(root->right,data);
    else return Find(root->left,data);
}

Node* FindMin(Node* root) 
{
    if(root == NULL) return NULL;
    while(root->left != NULL)
    root = root->left;
    return root;
}

Node* Getsuccessor(Node* root,int data) 
{
    Node* current = Find(root,data);
    if(current == NULL) return NULL;
    if(current->right != NULL) 
    { 
        return FindMin(current->right);
    }
    else 
    {
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current) 
        {
            if(current->data < ancestor->data) 
            {
                successor = ancestor; 
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

void Inorder(Node *root) 
{
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right); 
}

Node* Insert(Node *root,char data) 
{
    if(root == NULL) 
    {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->data)
        root->left = Insert(root->left,data);
    else
        root->right = Insert(root->right,data);
    return root;
}
