/* Programmer: Per Stoor
 * Date: 2022-10-22
 * Last changed: 2022-10-22
 * Type of program: More single linked list practice.
 */

#include <stdio.h> 
#include <stdlib.h> 

#define STRING_LENGTH 50

typedef struct node{

    int data;
    struct node *address;

} node;

int amount_of_nodes_function();
node *generate_nodes_function(node *function_head_node, int function_amount_of_nodes);
void traverse_list_function(node *function_head_node);

int main(int argc, char *argv[]){ 

    int amount_of_nodes;
    node *head_node;
    node *next_node;

        head_node = NULL;
        next_node = NULL;
        head_node = (node *)malloc(sizeof(head_node));
            if(head_node == NULL){
                perror("Error allocating memory for head node.\n");
                exit(EXIT_FAILURE);
            }

        amount_of_nodes = amount_of_nodes_function();
        next_node = generate_nodes_function(head_node, amount_of_nodes);
        traverse_list_function(head_node);

        /*
         * head_node has it's memory allocated in main and is subsequently
         * freed in main at the end.
         */
        free(head_node);
        /*
         * next_node has it's memory allocated in 'generate_nodes_function' 
         * and is subsequently freed in main at the end since freeing it in
         * the function makes the last data entry point fail.
         */
        free(next_node);

return 0;
} 

int amount_of_nodes_function(){

    int function_integer_buffer;
    char function_string_buffer[STRING_LENGTH];

        printf("Enter amount of nodes:");
        fgets(function_string_buffer, STRING_LENGTH, stdin);
        sscanf(function_string_buffer, "%d", &function_integer_buffer);

return function_integer_buffer;
}

node *generate_nodes_function(node *function_head_node, int function_amount_of_nodes){

    int function_loop_counter1;
    char function_string_buffer[STRING_LENGTH];
    node *function_next_node;
    node *temp_node;

        function_loop_counter1 = function_amount_of_nodes;

        printf("---------------------------------\n");
        printf("Enter head node data: ");
        fgets(function_string_buffer, STRING_LENGTH, stdin);
        sscanf(function_string_buffer, "%d", &function_head_node->data);
        function_head_node->address = NULL;

            temp_node = function_head_node;
            for(function_loop_counter1 = 2; function_loop_counter1 <= function_amount_of_nodes; function_loop_counter1++){
                function_next_node = (node *)malloc(sizeof(function_next_node));
                    if(function_next_node == NULL){
                        perror("Error allocating memory for new node.\n");
                        exit(EXIT_FAILURE);
                    }
                
                printf("Enter node %d data: ", function_loop_counter1);
                fgets(function_string_buffer, STRING_LENGTH, stdin);
                sscanf(function_string_buffer, "%d", &function_next_node->data);
                function_next_node->address = NULL;

                temp_node->address = function_next_node;
                temp_node = temp_node->address;

            }
return function_next_node;
}

void traverse_list_function(node *function_head_node){

    node *traversing_node;

        if(function_head_node == NULL){
            printf("The list is empty.\n");
            return;
        }

        printf("---------------------------------\n");
        traversing_node = function_head_node;
        while(traversing_node != NULL){
            printf("Data:   %d\n", traversing_node->data);
            traversing_node = traversing_node->address;
        }
}
