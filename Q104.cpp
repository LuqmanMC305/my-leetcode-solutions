#include <iostream>

using namespace std;

class BinaryTree
{
     private:
       struct Node
       {
          int value;
          Node* left;
          Node* right;
       };

    public:
      Node* root;
      BinaryTree() : root(nullptr) {}
      void insertValue(int newValue);
      Node* insertNode(Node* root, int newValue);
      void inOrderTraversal(Node* root);
      int maxDepth(Node* root);
      ~BinaryTree()
      {
         deleteNode(root);
      }
      void deleteNode(Node* root)
      {
         if(root)
         {
            deleteNode(root->left);
            deleteNode(root->right);
            delete root;
         }
      }
};

void BinaryTree::insertValue(int newValue)
{
    root = insertNode(root, newValue);
}

BinaryTree::Node* BinaryTree::insertNode(Node* root, int newValue)
{
   if(!root)
   {
      Node* newNode = new Node;
      newNode->value = newValue;
      newNode->left = nullptr;
      newNode->right = nullptr;

      return newNode;
   }
   else if (newValue > root->value)
   {
      root->right = insertNode(root->right, newValue);
   }
   else
   {
     root->left = insertNode(root->left, newValue);
   }

   return root;
}

void BinaryTree::inOrderTraversal(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    else
    {
      inOrderTraversal(root->left);
      cout << root->value << " ";
      inOrderTraversal(root->right);
    }
 
}

int BinaryTree::maxDepth(Node* root)
{
    if(!root)
    {
        return 0;
    }

    int depthLeft = maxDepth(root->left);
    int depthRight = maxDepth(root->right);
    return max(depthLeft, depthRight) + 1;

}

int main()
{
    BinaryTree tree;

    tree.insertValue(8);
    tree.insertValue(3);
    tree.insertValue(1);
    tree.insertValue(10);
    tree.insertValue(14);
    tree.insertValue(13);

    tree.inOrderTraversal(tree.root);


    cout << "\nMax Depth is: " << tree.maxDepth(tree.root);
    return 0;
}