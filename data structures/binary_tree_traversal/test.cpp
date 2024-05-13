#include<iostream>
#include<queue>

using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
};

Node* Insert(Node*root,int data);
Node* GetNewNode(int data);
void Preorder(Node*root);
//void LevelOrder(Node *root);
//void Inorder(Node*root);
void Postorder(Node *root);

int main()
{
    Node *root= NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    //LevelOrder(root);
    //Preorder(root);
    //Inorder(root);
    Postorder(root);
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

/*void LevelOrder(Node *root)    //层次遍历
{
    if (root==NULL)  return;
    queue<Node*> Q;
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
}*/

/*void Preorder(Node*root)   //前序遍历
{
    if(root == NULL)  return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}*/


/*void Inorder(Node*root)  //中序遍历
{
    if(root == NULL)   return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}*/

void Postorder(Node *root)   //后序遍历
{
    if(root == NULL)  return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data <<" ";
}



