#include<stdio.h>
int main() 
{
    int n, i, target, j, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a1[n + 1]; 
    for(k=0; k<n; k++) 
    {  printf("Enter the element at position [%d]: ", k);
       scanf("%d", &a1[k]); }
    printf("\nEnter the number you want to add: ");
    scanf("%d", &target);
    printf("Enter the index to insert at: ");
    scanf("%d", &i);
    for(k=n; k>i; k--) 
    {  a1[k] = a1[k-1]; }
    a1[i] = target;
    
    printf("\nFinal Array: ");
    for(k=0; k<n; k++) 
    { printf("%d ", a1[k]); }
    return 0;
}