#include<iostream>

using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
};

Node* Insert(Node*root,int data);
Node* GetNewNode(int data);
bool IsSubtreeLesser(Node* root,int value);
bool IsSubtreeGreater(Node* root,int value);
bool IsBinarySearchTree(Node* root);    //O(n2)
bool IsBstUtil(Node* root,int minValue,int maxValue);
bool IsBST(Node*root);  //O(n)

int main()
{
    Node *root= NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    //cout << IsBinarySearchTree(root);
    cout << IsBST(root);
    return 0;
}

Node* GetNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node*root,int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data<=root->data)
    {
        root->left =Insert(root->left,data); 
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

bool IsBinarySearchTree(Node* root)
{
    if(root == NULL)   return true;
    if (IsSubtreeLesser(root->left,root->data)&& IsSubtreeGreater(root->right,root->data)
        && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
    {
        return true;
    }
    else
        return false; 
}

bool IsSubtreeLesser(Node* root,int value)
{
    if(root == NULL)  return true;
    if(root->data <= value  && IsSubtreeLesser(root->left,value) && IsSubtreeLesser(root->right,value))
        return true;
    else
        return false;
}

bool IsSubtreeGreater(Node* root,int value)
{
    if(root == NULL)  return true;
    if(root->data > value  && IsSubtreeGreater(root->left,value) && IsSubtreeGreater(root->right,value))
        return true;
    else
        return false;
}
bool IsBstUtil(Node* root,int minValue,int maxValue)
{
    if(root == NULL) return true;
    if(root->data > minValue && root->data < maxValue 
       && IsBstUtil(root->left,minValue,root->data)
       && IsBstUtil(root->right,root->data,maxValue))
       return true;
    else
        return false;
}
bool IsBST(Node*root)
{
    return IsBstUtil(root,INT_MIN,INT_MAX);
}