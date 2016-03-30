/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) 
{
	if (head==NULL)
	return NULL;
	int len = 0;
	struct node *tmp = head;
	while (tmp!= NULL)
	{
		len++;
		tmp = tmp->next;
	}
	struct node *end=head;
	int i;
	for (i = 1; i<=len/2; i++)
	{
		int j = len-i;
		tmp = head;
		while (j != 0)
		{
			tmp = tmp->next;
			j--;
		}
		int t;
		t = tmp->num;
		tmp->num = end->num;
		end->num = t;
		end = end->next;
	}
	return head;
}
