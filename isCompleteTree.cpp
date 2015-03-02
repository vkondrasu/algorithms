/*
  Method to insert an element into a tree and to check if the tree is complete.
  TO-DO: Methods and the TreeNode structure are written as templates, improve it to work with all kind of 'types'.
*/
#include <iostream>

using namespace std;

template <typename T>
struct TreeNode
{
  TreeNode *left, *right;
  T value;
};

template <typename T>
TreeNode<T>* insert(TreeNode<T> **root, T value)
{
  if(*root == NULL)
  {
    *root = new TreeNode<T>;
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->value = value;
    return *root;
  }

  if((*root)->value < value)
    return insert(&((*root)->left), value);

    return insert(&((*root)->right), value);
  
}

template <typename T>
bool isCompleteTree(TreeNode<T>* root)
{
  //An empty tree is a complete binary tree.
  if(root == NULL)
    return true;
  //All leaf node's are complete binary trees.
  if(root->left == NULL && root->right == NULL)
    return true;
  //If the tree has both childs and they are complete binary trees then the tree is complete
  if(root->left && root->right) 
    return (isCompleteTree(root->left) && isCompleteTree(root->right));
  //Rest all are not complete 
  return false;

}


int main()
{
  TreeNode<int> *root = NULL;
  insert(&root, 10);
  insert(&root, 20);
  /*insert(&root, 05);
  insert(&root, 7);
  insert(&root, 3);
  insert(&root, 8);*/
  
  cout<<isCompleteTree(root)<<endl;
  
  return 0;
}
