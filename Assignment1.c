#include <stdio.h>
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}
void insertionsort(int *a, int n)
{
    int j = 0, temp, key;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quicksort(int *A, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quicksort(A, low, partitionIndex - 1);
        quicksort(A, partitionIndex + 1, high);
    }
}
int binarysearch(int *a, int n, int e)
{
    int low = 0, high, mid;
    high = n - 1;
    mid = low +(high-low)/ 2;
    while (low <= high)
    {
        if (a[mid] == e)
        {
            printf("Element %d Founded at %d index of array", e, mid);
            return 0;
        }
        else if (e > a[mid])
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }
    printf("Element %d Not Founded ", e);
    return 0;
}
int main()
{
    int s;
    do
    {
   
    
       
        printf("\nEnter 1 for doing insertion sort\n");
        printf("\nEnter 2 for doing Quick sort\n");
        printf("\nEnter 3 for doing Binary Search\n");
        printf("\nEnter 4 to exit\n");
        scanf("%d", &s);

        switch (s)
    
        {
        case 1:
        {
            int n;
            printf("\nEnter the number of element :\n");
            scanf("%d", &n);
            int arr[n];
            printf("\nEnter the numbers :\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\nArray before sorting :\n");
            printarray(arr, n);
            insertionsort(arr, n);
            printf("\n\n");
            printf("\nArray After sorting :\n");
            printarray(arr, n);
        break;
        }
        case 2:
        {
            int n;
            printf("\nEnter the number of element :\n");
            scanf("%d", &n);
            int arr[n];
            printf("\nEnter the numbers :\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\nArray before sorting :\n");
            printarray(arr, n);
            quicksort(arr, 0, n);
            printf("\n\n");
            printf("\nArray After sorting :\n");
            printarray(arr, n);
        break;
        }
        case 3:
        {
            int n, e;
            printf("\nEnter the number of element :\n");
            scanf("%d", &n);
            int arr[n];
            printf("\nEnter the numbers :\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\n");
            printf("Your Array is :\n");
            printarray(arr, n);
            printf("\n\n");
            printf("Enter Element would you like to find using binary search :\n");
            scanf("%d", &e);
            binarysearch(arr, n, e);
        break;
        }
        case 4:
        {
            
            printf("We have exited the program");
        break;
        }
        
        }
    } while (s!=4);
    return 0;
}