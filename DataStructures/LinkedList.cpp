#include "LinkedList.h"

#include <iostream>

using namespace std;

/*
	Algorithm insertNode(T value)
		pre: 'value' is the key to be added to the end of the existing linked list
    post: the node containing the key equal to 'value' will be the new tail of the list
		There are two cases:
		1. Adding a node to the empty list
		n = node(value)
		if head = NULL
      head <- n
			tail <- n
		else
			tail.next <- n
      tail <- n 
		end if
	end insertNode
*/
template <typename T>
ListNode<T>* LinkedList<T>::insertNode(T value)
{
	ListNode<T>* node = newNode(value);
	if(head == NULL)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}

	return node;
}



//driver function

int main()
{
	LinkedList<int> list;
	cout<<list.insertNode(10)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	cout<<list.insertNode(20)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	cout<<list.insertNode(30)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	cout<<list.insertNode(40)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	cout<<list.insertNode(50)<<endl;
	cout<<list.head<<" "<<list.tail<<endl;
	
	return 0;
}
