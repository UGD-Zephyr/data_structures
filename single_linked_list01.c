/* Programmer: Per Stoor
 * Date: 2022-10-21
 * Last changed: 2022-10-21
 * Type of program: Practicing single linked list.
 *
 * Notes: Notice the use of typedef, this code is a
 * blueprint on how to use typedef with linked lists.
 * in the struct declaration 'struct node *link' is
 * needed, you can't skip this struct keyword.
 */

#include <stdio.h> 
#include <stdlib.h> 

typedef struct node{

    int data;
    struct node *link;

} node;

int main(int argc, char *argv[]){ 

    node *head;
    node *current;
        
        head = NULL;
        head = (node *)malloc(sizeof(head));

        head->data = 45;
        head->link = NULL;

        current = (node *)malloc(sizeof(current));
        current->data = 98;
        current->link = NULL;
        head->link = current;

        current = (node *)malloc(sizeof(current));
        current->data = 3;
        current->link = NULL;
        head->link->link = current;

        printf("Traversing the single linked list:\n");
        printf("%d\n", head->data);
        printf("%d\n", head->link->data);
        printf("%d\n", head->link->link->data);

        free(head);
        free(current);

return 0;
} 
