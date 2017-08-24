/*
 * DeleteMiddleElement.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: chivora
 */

#include <stdio.h>
#include <stdlib.h>

/* structure of a linked list node */
struct node
{
    int data;
    struct node *next;
};

/* Utility function to insert a node at the begining */
struct node * push(struct node **head_ref, int new_data)
{
    struct node *new_node =
        (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

/*
 * Assumes there are at least 3 elements in linked list
 * and middle element given is not first or last element
 */
void deleteMiddleElement(struct node* middle_element){
	   struct node *temp = middle_element->next;
	   middle_element->data    = temp->data;
	   middle_element->next    = temp->next;
	   free(temp);
}

/* Utility function to print a linked list */
void printList(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}



/* Driver program to test above functions */
int main()
{
    struct node *head = NULL;
    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    struct node* middle_element = push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);

    printList(head);

    deleteMiddleElement(middle_element);

    printList(head);

	return 0;

}


