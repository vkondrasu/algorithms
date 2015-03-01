#include <iostream>

using namespace std;

struct TreeNode<T>
{
  TreeNode* left, right;
  T value;
};

TreeNode<T>* insert(TreeNode<T>** root, T value)
{
  if(root == NULL)
  {
    *root = (TreeNode<T>*) malloc(sizeof(TreeNode));
    *root->left = NULL;
    *root->right = NULL;
    *root->value = value;
    return *root;
  }

  if(*root->value < value)
    return insert(&(*root->left), value);
  else
    return insert(&(*root->right), value);
  
}
int main()
{
  
  return 0;
}
