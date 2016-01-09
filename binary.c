/*BINARY SEARCH + BUBBLE SORT
 *
 *2015
 *coder: Andrea
 */
 
#include<stdio.h>
#include <stdlib.h>

//FUNCION'S PROTOCOL
int binary(int s,int values[],int beg,int end);

int main(int argc, char*argv[])
{
    int values[100];
    int i,j,min,n,tmp;
    
    while(argc != 3)            //Rejects wrong inputs
    {
        printf("Error! ./binary [length][num_search]\n");
        return 1;
    }
    
    int l = atoi(argv[1]);
    int s = atoi(argv[2]);
    
    int beg = 0;
    int end = l;
 
    //ASK FOR NUMBERS     
    printf("Numbers:\n");                   
    
    for(i = 0; i < l; i++)
    {
        scanf("%i", &values[i]);
    }

    //BUBBLE SORT    
    for(j = 0; j < l; j++)
    {
        min = j;
        for(n = j + 1; n < l; n++)
        {
            if(values[n] < values[min])
            {
                tmp = values[min];
                values[min] = values[n];
                values[n] = tmp;
            }
        } 
    }
    
    for(i = 0; i < l; i++)
    {
        printf("%d ",values[i]);
    }
    printf("\n");
    
    //BINARY SEARCH
    int result = binary(s,values,beg,end);      
    
    printf("Found: %i position\n", result + 1);
    
}


// BINARY SEARCH FUNCTION
int binary(int s,int values[],int beg,int end)
{
    int val, mid;
    if(beg > end)
    {
        printf("No value in the list!\n");
        return -1;
    }
    
    else
    {
        mid = beg + ((end - beg) / 2);
        val = values[mid];
    }
    
    if(s < val)
    {
        return binary(s,values,beg,mid - 1);
    }
    
    else if(s > val)
        {
            return binary(s,values,mid + 1,end);
        }
        
        else
            return mid;
}
