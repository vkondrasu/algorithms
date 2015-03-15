/*
	Input: list1 - 5->6->3 represents 365
				 list2 - 8->4->2 represents 248

	Output: list 3->1->6 represents 613
*/


#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* newNode(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;
	
	return temp;
}

//Add a node to the start of the list
void push(struct Node** head_ref, int value)
{
	struct Node* temp = newNode(value);
	temp->next = *head_ref;
	*head_ref = temp;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
	struct Node *res = NULL, *temp = NULL, *prev = NULL;
	int carry = 0, sum = 0;

	while(first != NULL || second!= NULL)
	{
		sum = carry + (first?first->data:0) + (second?second->data:0);
		carry = (sum>=10?1:0);
		sum = sum%10;

		temp = newNode(sum);

		if(res == NULL)
			res = temp;
		else
			prev->next = temp;

		prev = temp;

		if(first) first = first->next;
		if(second) second = second->next;
	}

	if(carry >0)
		prev->next = newNode(carry);

	return res;
}

void printList(struct Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}

	cout<<endl;

}

int main(int argc, char* argv[])
{
	struct Node* list1 = NULL;
	struct Node* list2 = NULL;
	struct Node* result = NULL;

	push(&list1, 5);
	push(&list1, 6);
	push(&list1, 3);
	printList(list1);
	push(&list2, 8);
	push(&list2, 4);
//	push(&list2, 2);
	printList(list2);
	result = addTwoLists(list1, list2);

	printList(result);
	
	return 0;
}
