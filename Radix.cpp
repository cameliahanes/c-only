#include <iostream>

using namespace std;

int getMax(int arr[], int n){
    int mx = arr[0];
    for ( int i = 1; i < n; ++i ){
        if ( arr[i] > mx ) mx = arr[i];
    }
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[n]; //the output array
    int i, countt[10] = {0};
    //store count of occurences in countt[]
    for ( i = 0; i < n; ++i ){
        countt[(arr[i]/exp) % 10] ++;
    }
    //change countt[i] so that countt[i]
    // now contains actual position of this
    //digit in output[]
    for ( i = 1; i < 10; ++i ){
        countt[i] += countt[i-1];
    }
    //build the output array
    for ( i = n-1; i >= 0; --i ){
        output[countt[(arr[i]/exp)%10]-1] = arr[i];
        countt[(arr[i]/exp)%10] --;
    }
    //cpy the output array into arr[]
    //so that arr[] now contains sorted
    //numbers according to current digit
    for ( i = 0; i < n; ++i ){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    //find the maximum number to know the
    //number of digits
    int m = getMax(arr, n);
    //counting sort ofor every digit
    //instead of passing digit number, exp is passed
    for ( int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver program to test above functions
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);
    print(arr, n);
    return 0;
}
