#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x <= y) ? x : y; }

int fibMonaccianSearch(int arr[], int x, int n)
{
    int fibMMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1;

    
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    
    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        
        else
            return i;
    }

    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int Fibonacci()
{
    int n;
    cout << " Enter the number of elements in array :\n";
    cin>>n;
    int arr[n];
    cout << " Enter the elements in the array :\n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    int x;
    cout << " Enter the number to be searched :\n";
    cin>>x;
    int ind = fibMonaccianSearch(arr, x, n);
if(ind>=0)
    cout << "The number is Present in the array \n";
else
    cout << x << "The number is not present in the array \n";
    return 0;
}

int main()
{
    
int choice;

    do{

    cout << "\n Menu \n 1.Fibonacci search \n 2.Exit \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Fibonacci();
        break;
    case 2:
        cout << "\n Thank you for using the program  \n";
        exit(0);
        break;        

    default:
        cout << "\n Invalid Choice \n";
        break;
    }
    }while(choice != 4);

    return 0;
}
