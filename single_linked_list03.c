/* Programmer: Per Stoor
 * Date: 2022-11-01
 * Last changed: 2022-11-01
 * Type of program: Inserting new node at the
 * beginning of the list.
 *
 * Notes: I have issues with free in the new_beginning_node function...
 */

#include <stdio.h> 
#include <stdlib.h> 

#define STRING_LENGTH 30

typedef struct node{

    int data;
    struct node *address;

} node;

int amount_of_nodes_function();
node *create_head_node();
node *new_beginning_node(node *function_head_node, node *function_insert_node);
void generate_nodes_function(node *function_head_node, int function_amount_of_nodes);
void traverse_list_function(node *function_head_node);
void free_nodes(node *function_head_node);

int main(int argc, char *argv[]){ 

    int amount_of_nodes;
    char string_buffer[STRING_LENGTH];
    char new_node_choice;
    node *head_node;
    node *insert_node;

        amount_of_nodes = amount_of_nodes_function();
        head_node = create_head_node();
        generate_nodes_function(head_node, amount_of_nodes);

        printf("Would you like to add data to the beginning? y/n: ");
        fgets(string_buffer, STRING_LENGTH, stdin);
        sscanf(string_buffer, "%c", &new_node_choice);

            if(new_node_choice == 'y'){
                insert_node = (node *)malloc(sizeof(insert_node));
                    if(insert_node == NULL){
                        perror("Error allocating memory for insert_node.\n");
                        exit(EXIT_FAILURE);
                    }                
                
                head_node = new_beginning_node(head_node, insert_node);
                traverse_list_function(head_node);
            }
            else if(new_node_choice == 'n'){
    
                traverse_list_function(head_node);
            }
            else{
                printf("You did not select 'y' or 'n'!\n");
            }

        free_nodes(head_node);

return 0;
} 

int amount_of_nodes_function(){

    int function_data_buffer;
    char function_string_buffer1[STRING_LENGTH];

        printf("Enter amount of nodes: ");
        fgets(function_string_buffer1, STRING_LENGTH, stdin);
        sscanf(function_string_buffer1, "%d", &function_data_buffer);

return function_data_buffer;
}

node *create_head_node(){

    char function_string_buffer2[STRING_LENGTH];
    node *function_head_node;

        function_head_node = (node *)malloc(sizeof(function_head_node));
            if(function_head_node == NULL){
                perror("Error allocating memory for head_node.\n");
                exit(EXIT_FAILURE);
            }

        printf("Enter head node data: ");
        fgets(function_string_buffer2, STRING_LENGTH, stdin);
        sscanf(function_string_buffer2, "%d", &function_head_node->data);
        function_head_node->address = NULL;

return function_head_node;
}

void generate_nodes_function(node *function_head_node, int function_amount_of_nodes){

    int function_loop_counter1;
    char function_string_buffer3[STRING_LENGTH];
    node *function_next_node;
    node *function_temp_node;

        function_loop_counter1 = function_amount_of_nodes; 
        function_temp_node = function_head_node;

            for(function_loop_counter1 = 2;
                function_loop_counter1 <= function_amount_of_nodes;
                function_loop_counter1++){

                    function_next_node = (node *)malloc(sizeof(function_next_node));
                        if(function_next_node == NULL){
                            perror("Error allocating memory for next_node.\n");
                            exit(EXIT_FAILURE);
                        }

                    printf("Enter node %d data: ", function_loop_counter1);
                    fgets(function_string_buffer3, STRING_LENGTH, stdin);
                    sscanf(function_string_buffer3, "%d", &function_next_node->data);
                    function_next_node->address = NULL;
                    
                    function_temp_node->address = function_next_node;
                    function_temp_node = function_temp_node->address;

            }

//return function_next_node;
}

node *new_beginning_node(node *function_head_node, node *function_insert_node){

    char function_string_buffer4[STRING_LENGTH];

        printf("Enter new head node data: ");
        fgets(function_string_buffer4, STRING_LENGTH, stdin);
        sscanf(function_string_buffer4, "%d", &function_insert_node->data);
        function_insert_node->address = NULL;

        function_insert_node->address = function_head_node;
        function_head_node = function_insert_node;

return function_head_node;
}

void traverse_list_function(node *function_head_node){

    node *traverse_list_node;

        if(function_head_node == NULL){
            printf("List is EMPTY!\n");
            return ;
        }

    traverse_list_node = function_head_node;
    while(traverse_list_node != NULL){
        printf("Data: %d\n", traverse_list_node->data);
        traverse_list_node = traverse_list_node->address;
    }
}
void free_nodes(node *function_head_node){

    node *function_temporary_node;

        while(function_head_node != NULL){
            function_temporary_node = function_head_node;
            function_head_node = function_head_node->address;
            free(function_temporary_node);
        }
}
