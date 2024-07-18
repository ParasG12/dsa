#include<stdio.h> 
#include<stdlib.h> 

#define SIZE 5

typedef struct 
{
    int arr[SIZE]; 
    int front; 
    int rear; 
}queue_t;
void init_queue(queue_t *pq); 
int is_queue_full(queue_t *pq);
void enqueue(queue_t *pq,int ele );  
void display_queue(queue_t *pq); 
int getfront(queue_t *pq); 
void dequeue(queue_t *pq); 
int is_queue_empty(queue_t *pq); 
int menu( )
{
    int choice; 
    printf("\n=================\n");
    printf("Linear queue...\n"); 
    printf("0. Exit\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("Enter the choice"); 
    scanf("%d",&choice); 
    return choice; 
}

enum menu_options 
{ EXIT , ENQUEUE , DEQUEUE, DISPLAY}; 

int main()
{
    int ele; 
    queue_t q; 
    init_queue(&q);  
    while(1)
    {
        int choice = menu( ); 
        switch(choice)
        {
            case EXIT: 
            exit(0);

            case ENQUEUE: 
            //step-1: check queue is not full
            if(!is_queue_full(&q))//if queue is not full 
            {
                printf("Enter the ele :: ");
                scanf("%d",&ele); 
                enqueue(&q,ele);  
                printf("%d is inserted in queue ... \n",ele); 
                 
            }
            else 
                printf("Queue is full!!!...\n");  
            break; 

            case DEQUEUE: 
            //step-1: check queue is not empty    
              if(!is_queue_empty(&q)) // if queue is not empty 
              {
                    ele = getfront(&q); 
                    dequeue(&q); 
                    printf("Deleted ele is : %d \n",ele);
                    display_queue(&q);  
              }
              else 
                printf("Queue is empty....\n");   
            break; 

            case DISPLAY: 
            display_queue(&q); 
            break; 

        }//end of switch 
    }//end of while 
    return 0;
}
void init_queue(queue_t *pq)
{
       pq->front = -1; 
       pq->rear = -1;  
}
int getfront(queue_t *pq)
{
    // return the value from front position 
     return (pq->arr[pq->front]) ; 
}
/*
        return arr[1]; 
        return arr[front]; 
        return pq->arr[pq->front]; 
*/

int is_queue_full(queue_t *pq)
{
        return (pq->rear == SIZE - 1);   
}

void enqueue(queue_t *pq,int ele )
{
    //step-2: increment the value of rear by 1
      pq->rear++; 
   //step-3: insert an element into the queue from rear end   
      pq->arr[pq->rear] = ele;   
   //step-4: if( front == -1 ) then front = 0
      if(pq->front == -1)
         pq->front = 0; 
   
 
}
/*
        arr[3] = ele; 
        arr[rear] = ele;
        pq->arr[pq->rear] = ele;   
*/
int is_queue_empty(queue_t *pq)
{
        return ( pq->rear == -1 || pq->front > pq->rear);
}
void display_queue(queue_t *pq)
{
       if(!is_queue_empty(pq))//if queue is not empty 
       {
            int index; 
            printf("que ele are : "); 
            for(index = pq->front ; index <= pq->rear ; index++ )
            {
                  printf("%4d ",pq->arr[index]);   
            }
       } 
       else 
         printf("Queue is empty...!!\n"); 
}

void dequeue(queue_t *pq)
{
    //step-2: increment the value of front by 1
      pq->front++;       
}