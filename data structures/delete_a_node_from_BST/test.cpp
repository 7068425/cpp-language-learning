#include<iostream>
#include<queue>

using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
};


Node* FindMin(Node* root);
Node* Delete(Node *root,int data);
Node* GetNewNode(int data);
Node* Insert(Node*root,int data);
void LevelOrder(Node *root);

int main()
{
    Node *root= NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    LevelOrder(root);
    cout << endl;
    root = Delete(root,10);
    LevelOrder(root);
    return 0;
}

Node* Delete(Node *root,int data)
{
    if(root == NULL)   return root;
    else if(data < root->data)  root->left = Delete(root->left,data);
    else if(data > root->data)  root->right = Delete(root->right,data);
    else
    {
        if(root->left == NULL && root->right == NULL)  //No child
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)  //One child
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else  //two child
        {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}


Node* FindMin(Node* root)
{
    if (root == NULL)
    {
        cout << "Error: Tree is empty\n";
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
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

void LevelOrder(Node *root)    //层次遍历
{
    if (root==NULL)  return;
    queue <Node*> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node* current = Q.front();
        cout << current->data<<" ";
        if (current->left != NULL)
        {
            Q.push(current->left);
        }
        if (current->right!= NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }      
}

