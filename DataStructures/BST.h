#ifndef BST_H
#define BST_H
#endif

#include <iostream>

template <typename T>
struct TreeNode
{
	T key;
	TreeNode<T> *left, *right;
};

template <typename T>
class BST
{
	private:
		int count;
		TreeNode<T>* root;
		TreeNode<T>* InsertNode(TreeNode<T>* current, T value);
		bool Search(TreeNode<T>* current, T value);

		TreeNode<T>* newNode(T value)
		{
			TreeNode<T>* temp = new TreeNode<T>;
			temp->key = value;
			temp->left = temp->right = NULL;

			return temp;
		}

		
	public:
		BST<T>():count(0), root(NULL)
		{
		}

		~BST<T>()
		{

		}

		TreeNode<T>* Insert(T value);

		int getCount(){ return count; }

		bool Contains(T value);
};
