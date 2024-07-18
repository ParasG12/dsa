#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} node_t;

node_t *head = NULL;
node_t *create_node(int data);
void add_at_first_position(int data);
void display_list(void);
void add_node_at_last_postion(int data);
int count_nodes(void);
void add_at_specific_pos(int data , int pos); 
void delete_node_at_first_pos(void);
void delete_node_at_last_pos(void);  
void freelist( void ); 
int main()
{
	// add_at_first_position(10);
	// add_at_first_position(20);
	//  add_at_first_position(30);
	//30->20->10

	add_node_at_last_postion(50);
	add_node_at_last_postion(60);
	add_node_at_last_postion(70);
	// 50->60->70
	int pos;
	display_list();
	int data;
	// while (1)
	// {
	// 	//step-1: accept position from user
	// 	printf("enter the position: ");
	// 	scanf("%d", &pos);

	// 	//step-2: validate position
	// 	if (pos > 0 && pos <= count_nodes() + 1) //if pos is valid then loop gets break
	// 		break;

	// 	printf("invalid position !!!\n");
	// }
	// printf("Enter the data");
	// scanf("%d", &data);
	// add_at_specific_pos(data,pos);
	//delete_node_at_first_pos( );  
	delete_node_at_last_pos(); 
	display_list();

	return 0;
}

void delete_node_at_last_pos(void)
{
	//check list is not empty 
	if(head!=NULL)
	{
		  if(head->next == NULL) // if list contains only 1 node 
		  {
			    free(head); // to avoid mem leakage
				head = NULL;//to avoid dangling pointer   	
		  }
		  else // if list is not empty 
		  {
			  //start traversal from first node 
			  node_t *trav = head; 
			  //traverse till second last node 
			  while(trav->next->next!=NULL)
			  {
				  trav = trav->next; 
			  }
			  free(trav->next); 
			  trav->next = NULL; 
		  }
	} 
	else 
	  printf("list is empty"); 
}


node_t *create_node(int data)
{
	// int *ptr = (int*)malloc(sizeof(int));

	node_t *temp = (node_t *)malloc(sizeof(node_t));
	//malloc function allocates memory from heap section
	//on success it returns the starting address of dynamically
	//allocated block
	// on failure it returns null

	if (temp == NULL)
	{
		printf("malloc failed");
		exit(1);
	}
	//init the members of node
	temp->data = data;
	temp->next = NULL;

	return temp;
}

void display_list(void)
{
	//if linked list is not empty
	if (head != NULL)
	{
		//start traversal from first node
		node_t *trav = head;
		//traverse till last node
		while (trav != NULL)
		{
			printf("%d->", trav->data);
			trav = trav->next;
		}
		printf("null\n");
	}
	else
		printf("linked list is empty");
}

void delete_at_specific_pos(int pos)
{
	if(pos == 1)
	  delete_node_at_first_pos( ); 
	else if(pos == count_nodes( ))
	  delete_node_at_last_pos( ); 
	else 
	{
		//start the traversal from first node 
		node_t *trav = head; 
		while(i < pos - 1 )
		{
			i++; 
			trav = trav->next; 
		}
		/*
				Homework 
		*/
	} 
}

void delete_node_at_first_pos(void)
{
	if(head!=NULL)
	{	
		 //if list contains only one node  
		 if(head->next == NULL)
		 {
			 	free(head);  // to avoid memory leakage 
				head = NULL; // to avoid dangling pointer  
		 }
		 else 
		 {
			 node_t *temp = head; 
			 head = head->next;
			 free(temp); 
			 temp = NULL;   
		 }
	}
	else 
	 printf("linked list is empty"); 
}

void add_at_first_position(int data)
{
	//create node
	node_t *newnode = create_node(data);
	if (head == NULL) // if linked list is empty
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
}
void add_node_at_last_postion(int data)
{
	//1.Create node
	node_t *newnode = create_node(data);

	if (head == NULL) //if list is empty
	{
		head = newnode;
	}
	else // if list is not empty
	{
		node_t *trav = head;
		while (trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = newnode;
	}
}

void add_at_specific_pos(int data , int pos)
{
	if(pos==1)
	  add_at_first_position(data); 
	else if(pos == count_nodes( ) + 1 ) // if pos is last 
	  add_node_at_last_postion(data); 
	else 
	{
		//create the node 
		node_t *newnode =create_node(data);  
		//start the traversal from first node 
		node_t *trav = head; 
		int i = 1; 
		while( i < pos - 1 )
		{
			i++; 
			trav = trav->next; 
		} 	
		newnode->next = trav->next; 
		trav->next = newnode; 
	}
}



int count_nodes(void)
{
	int cnt = 0;

	//if list is not empty
	if (head != NULL)
	{
		//start traversal from the first node
		node_t *trav = head;
		//traverse the list till last node and increment the counter
		while (trav != NULL)
		{
			cnt++;
			trav = trav->next;
		}

		//return final count i.e. no. of nodes in a list
	}

	return cnt;
}

void freelist( void )
{
	
	while(head!=NULL)
	{
	      delete_node_at_last_pos( ); 
		  //delete_node_at_first_pos( ); 		
	} 
	printf("Memory freed successfully"); 
}