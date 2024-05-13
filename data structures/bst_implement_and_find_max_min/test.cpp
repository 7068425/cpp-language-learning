#include<iostream>
using namespace std;
struct BstNode
{
    int data;
    BstNode*left;
    BstNode*right;
};

BstNode* Insert(BstNode*root,int data);
BstNode* GetNewNode(int data);
//bool Search(BstNode*root,int data);
//int FindMin1(BstNode* root);
//int FindMin2(BstNode* root);
int FindHeight(BstNode *root);  
int main()
{
    BstNode *root= NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    //int number;
    //cout << "Enter number be searched\n";
    //cin >> number;
    //if(Search(root,number)== true)   cout << "Found\n";
    //else cout << "Not Found\n";
    //int max = FindMin2(root);
    //cout << max ;
    int Height = FindHeight(root);
    cout << Height;
}

BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode* Insert(BstNode*root,int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data<=root->data)
    {
        root->left =Insert(root->left,data);  //只要Insert（）中的第一个参数不为0，返回的参数和输入的第一个参数一样
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
    
}
/*bool Search(BstNode*root,int data)
{
    if(root == NULL) return false;
    else if(root->data==data)  return true;
    else if(data <= root->data)   return Search(root->left,data);
    else return Search(root->right,data);
}*/
/*int FindMin(BstNode* root)
{
    if (root == NULL)
    {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}*/
/*int FindMin2(BstNode* root)
{
    if (root == NULL)
    {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    else if(root->left == NULL)
    {
        return root->data;
    }
    return FindMin2(root->left);
}*/
int FindHeight(BstNode *root)
{
    if(root == NULL)
        return -1;
    else
    return max(FindHeight(root->left),FindHeight(root->right))+1;
}