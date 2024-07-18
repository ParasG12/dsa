#include<stdio.h>
int comparisons = 0; 
#define SIZE 10 
void display_array_elements(int arr[]); 
int binary_search(int arr[ ], int key); 
int linear_search(int arr[],int key); 
int main()
{
    int key; 
    //int arr[SIZE]={30,70,90,10,50,80,100,20,40,60}; 
    int arr[SIZE]={10,20,30,40,50,60,70,80,90,100}; 
    display_array_elements(arr);   
    printf("Enter the key :: "); 
    scanf("%d",&key); //60 
    //if(linear_search(arr,key)) 
    if(binary_search(arr,key))  
    {
         printf("%d is found in an array , no of comparisons are %d : \n",key,comparisons);    
    }  
    else 
    {
        printf("%d is not found in an array , no of comparisons are %d : \n",key,comparisons); 
    }
    return 0;
}
int binary_search(int arr[ ], int key)
{
        int left = 0; 
        int right = SIZE - 1;  
        comparisons = 0; 
        while(left <= right)
        {
              int mid = (left + right) / 2; 
              comparisons++; 
              if(key == arr[mid])
                return 1; // ele found  
              else if( key < arr[mid])
                right = mid - 1;  
              else
                left = mid + 1;     
        }
        return 0; // ele no found   
}
int linear_search(int arr[],int key)
{
        int index = 0; 
        comparisons = 0; 
        for(index = 0 ; index < SIZE ; index++)
        {   
            comparisons++;  
            if(key == arr[index])
                 return 1;  //element found 
        }
        return 0; // element not found 

}
void display_array_elements(int arr[])
{
    int index; 
    for(index = 0 ; index < SIZE ; index++)
            printf("%4d",arr[index]); 
    printf("\n");         
}    
