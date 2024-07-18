#include<stdio.h> 
#include<stdlib.h> 

typedef struct node  //self referential structure 
{
    int data; // 4 byte 
    struct node *next;// 4 byte  // self referential pointer 
}node_t;

node_t *head = NULL; 
node_t *create_node( int data ); 
void display_list( void ); 
void add_at_first_position( int data); 
void add_node_at_last_position ( int data); 
int main( )
{
    //   add_at_first_position(10); 
    //   add_at_first_position(20); 
    //   add_at_first_position(30);

        add_node_at_last_position(40);
        add_node_at_last_position(50); 
        add_node_at_last_position(60); 
      
      //40->50->60

      display_list( ); 
      return 0;   
}

node_t *create_node( int data )
{
    //int *ptr = (int*)malloc(sizeof(int)); 

    node_t *temp =(node_t*)malloc(sizeof(node_t));
// malloc function allocates memory from heap section 
//on success it returns memory from heap section of allocated block 
//on failure it returns null  

    if(temp == NULL )
    {
        printf("malloc failed.."); 
        exit(1); 
    }
    // init the members of node 
    temp->data = data;   
    temp->next = NULL; 

    return temp; 

}

void add_at_first_position( int data)
{
     //create node 
    node_t *newnode = create_node(data); 
    if(head == NULL) // linked list empty 
    {
        head = newnode; 
    }
    else 
    {
        newnode->next = head; 
        head = newnode; 
    }
}

void display_list( void )
{
    //if linked list is not empty 
    if( head!=NULL)
    {
        //start traversal from first node 
        node_t *trav = head;
        //traverse till last node 
        while(trav != NULL)
        {   
             printf("%d->",trav->data);    
             trav = trav->next;    
        }
        printf("null \n");   
    }
    else 
      printf("Linked list is empty"); 
}

void add_node_at_last_position ( int data)
{
    //1.Create a node 
        node_t* newnode = create_node(data); 
        if(head == NULL) // if list is empty 
        {
            head = newnode;      
        }
        else  // if list is not empty 
        {
             node_t *trav = head; 
             while(trav->next!=NULL)
             {
                 trav = trav->next; 
             }  
             trav->next = newnode;  
        }
}