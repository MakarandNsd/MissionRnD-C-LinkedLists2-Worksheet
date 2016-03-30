/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	if (head1 == NULL && head2 != NULL)
		return head2;
	else if (head1 != NULL && head2 == NULL)
		return head1;
	else if (head1 == NULL && head2 == NULL)
		return NULL;
	struct node *tmp1=NULL,*result;
	while (head1 != NULL && head2 != NULL)
	{
		if (((head1->num) >= (head2->num)))
		{
			if (tmp1 == NULL)
			{
				tmp1 = head2;
				head2 = head2->next;
				tmp1->next = NULL;
				result = tmp1;
			}
			else
			{
				tmp1->next = head2;
				head2=head2->next;
				tmp1 = tmp1->next;
				tmp1->next = NULL;
			}
		}
		else
		{
			if (tmp1 == NULL)
			{
				tmp1 = head1;
				head1 = head1->next;
				tmp1->next = NULL;
				result = tmp1;
			}
			else
			{
				tmp1->next = head1;
				head1 = head1->next;
				tmp1 = tmp1->next;
				tmp1->next = NULL;
			}
		}
		
	}
	if (head2 == NULL)
		tmp1->next = head1;
	else if (head1 == NULL)
		tmp1->next = head2;
	return result;
}
