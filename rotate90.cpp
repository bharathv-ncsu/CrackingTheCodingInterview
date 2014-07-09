/*Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/
#include <iostream>

using namespace std;

int main()
{
    int n,temp,i,j;
    n=4;
    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};;
        
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            temp=arr[j][i];
            arr[j][i]=arr[i][j];
            arr[i][j]=temp;
        }
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";        
        }
        cout<<"\n";
    }
    /*for(i=0;i<n;i++)
    {
        *arr[i]=new int[10];
    }*/
   
   return 0;
}



