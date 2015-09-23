//Author: Dominick Modica
//Implement Linked List for Systems Programming
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void search_list(struct Node *root,int value);
void print_list(struct Node *root);
void add_node(struct Node *appending_node, int number_value);
struct Node * get_last_node(struct Node *root);

//search_list receives a root point for a list and a value to search for
void search_list(struct Node *root,int value){
    struct Node * starting_point = root; 
    //travel across list until NULL is encounter, if value is encountered inform user else tell them sorry no dice :/
    while (starting_point != NULL)
        {
        if (starting_point->data == value)
        {
            printf("The value %d was found in the list \n", value);
            return;     
        }
        starting_point=starting_point->next;
        }
    
    printf("The value %d was NOT found in the list \n", value);

}
void print_list(struct Node *root)
{
    //I like to copy the root pointer just so I can't mess it up
    struct Node * starting_point = root;
    
    printf("Printing Your list: \n");
    //start at starting point and traverse the list untill a NULL is encountered
    while (starting_point != NULL)
    {
        printf("%d \n",starting_point->data);
        starting_point=starting_point->next;
    }
    
}

//construct the new node within add_node function and set appending node's next to this newly created node
void add_node(struct Node *appending_node, int number_value)
{
    struct Node * new_node;
    new_node = (struct Node *) malloc( sizeof(struct Node) ); 
    appending_node->next=new_node;
    new_node->next=NULL;
    new_node->data=number_value;
    printf("The value %d has been added to the linked list \n",new_node->data);

    
}

/*a helper get_last_node function didn't even really utilize it since I kept track of tail with the current pointer within main()*/
struct Node * get_last_node(struct Node *root)
{
    //copy the root pointer just in case
    struct Node * copy_root = root;
    //find the node who's ->next is NULL
    while (copy_root->next != NULL){
        copy_root=copy_root->next;
    }
    //return this node
    return copy_root;

}

int main(int argc, char * argv)
{   
    //seed rng
    srand(time(NULL));
    //basically head and tail pointer initialization
    struct Node *root;
    struct Node *current;
  

    //i guess this is the C version of the new() constructor in other languages....annoying and clunky
    root = (struct Node *) malloc( sizeof(struct Node) ); 
    //out of laziness I want the list to start with 10
    root->data= 10;
    current=root;
    
    int index=0;
    int r;
    while (index<10)
    {
    r = rand()%10 ;
    index++;
    //send the last current node and the data into add node
    add_node(current,r);
    current=current->next;
    }
    
    print_list(root);
    //search this list for index 10, used index++ since index is 9 at the end of the previous while loop
    search_list(root, index++);
    //search using a random int, didn't think this syntax would work but it does...sort of cool
    search_list(root, rand()%10);
    free(current);
    free(root);
}
