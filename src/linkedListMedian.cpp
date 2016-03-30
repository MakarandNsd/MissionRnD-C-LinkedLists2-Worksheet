/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	if (head==NULL)
		return -1;
	int len = 0;
	struct node *tmp = head;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	tmp = head;
	if (len % 2 == 0)
	{
		len /= 2;
		while (len-1)
		{
			tmp = tmp->next;
			len--;
		}
		return ((tmp->num) + ((tmp->next)->num)) / 2;
	}
	else
	{
		len /= 2;
		while (len)
		{
			tmp = tmp->next;
			len--;
		}
		return tmp->num;
	}
}
