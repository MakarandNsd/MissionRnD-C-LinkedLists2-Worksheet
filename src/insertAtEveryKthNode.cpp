/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) 
{
	if (head==NULL || K<0)
	return NULL;
	int len=0;
	struct node *tmp = head;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	if (K > len||K==0)
		return head;
	tmp = head;
	while (len)
	{
		if (len%K == 0)
		{
			struct node *newstr = (struct node *)malloc(sizeof(struct node ));
			
			newstr->num = K;
			newstr->next = (tmp->next);
			tmp->next = newstr;
			tmp = tmp->next;
		}
		len--;
		tmp = tmp->next;

	}
	return head;
}
