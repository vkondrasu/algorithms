#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>

using namespace std;

template <typename T>
struct ListNode
{
	T key;
	ListNode *next;
};

template <typename T>
class LinkedList
{
    int count;
	public:
		ListNode<T> *head, *tail;
		LinkedList<T>():count(0)
		{
			head=tail=NULL;		
		}

		~LinkedList<T>()
		{
		}

		ListNode<T>* newNode(T value)
		{
			ListNode<T> *node = new ListNode<T>;
			node->next = NULL;
			node->key = value;

			return node;
		}

		ListNode<T>* insertNode(T value);
		ListNode<T>* searchNode(T value);
		ListNode<T>* reverseList();
		void traverseList();
		void traverseListReverse();
		bool deleteNode(T value);
		int getCount(){ return count; }
		void insertEndElementsBetween();
};


#endif
