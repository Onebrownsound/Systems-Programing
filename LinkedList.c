#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void print_list(struct Node *root)
{
    //I like to copy the root pointer just so I can't mess it up
    struct Node * starting_point = root;
    while (starting_point != NULL)
    {
        printf("%d",starting_point->data);
        starting_point=starting_point->next;
    }
    
}
void add_node(struct Node *appending_node, int number_value)
{
    struct Node * new_node;
    new_node = (struct Node *) malloc( sizeof(struct Node) ); 
    appending_node->next=new_node;
    new_node->next=NULL;
    new_node->data=number_value;
}

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
    //root pointer
    struct Node *root;
    struct Node *current;
  

    
    root = (struct Node *) malloc( sizeof(struct Node) ); 
    //out of laziness I want the list to start with 10
    root->data= 10;
    current=root;
    
    int index=0;
    int r;
    while (index<10)
    {
    r = rand();
    index++;
    //send the last current node and the data into add node
    add_node(current,r);
        
    }
    
    print_list(root);
    
}
