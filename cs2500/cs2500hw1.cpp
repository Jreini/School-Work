// Programmer: Justin Reini

#include <iostream>
#include <cstring>
#include <cstdlib>  
#include <ctime>
#include <algorithm>
#include <chrono>
#include<vector>
using namespace std;
using namespace std::chrono;   
//Merge Code
void merge(int *,int, int , int );
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;  //divide the array into half and sort
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);  //merge the arrays
    }
}
// Merge sort 
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[1000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}




//Heapsort
void heapify(int arr[], int n, int root)
{
   int largest = root; // root is largest 
   int l = 2*root + 1; // left child
   int r = 2*root + 2; // right child
  
   if (l < n && arr[l] > arr[largest])  // If left child is larger than root
   largest = l;
  
   if (r < n && arr[r] > arr[largest])  // If right child is larger than largest so far
   largest = r;
  

   if (largest != root)
      {
      
      swap(arr[root], arr[largest]); //swap root and largest

      heapify(arr, n, largest);  //heapify
      }
}
  

void heapSort(int arr[], int n) //sorting algorithm
{
   for (int i = n / 2 - 1; i >= 0; i--)
   heapify(arr, n, i); // build heap
  
   for (int i=n-1; i>=0; i--)
   {
      swap(arr[0], arr[i]);  //Move current to end
  
      heapify(arr, i, 0); //heapify on the reduced heap
   }
}
  
//Print contents of arrays
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
{ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
int main()
{
    //Variable initializations
    int nums;
    cout<<"How many numbers would you like to run?"<<endl;
    cin>>nums;
    int arr1[nums];
    srand((unsigned)time(0));


    for(int i=0; i<nums; i++)  //Create an array with random numbers
    {
        int random = rand() % 1000;
        arr1[i]=random;
    }


    int arr2[nums];
    for(int j=0; j<nums; j++)  //Duplcate the array so one can run heapsort and the other can run mergesort
    {
        arr2[j]=arr1[j];
    }

  
    cout<<"Heapsort:"<<endl<<endl;
    cout<<"Input array"<<endl;
    displayArray(arr1,nums);

    //Code to count time
    auto start = high_resolution_clock::now();
    heapSort(arr1, nums);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Sorted array"<<endl;
    displayArray(arr1, nums);
    cout<<endl;
    cout<<"Time taken by function: "<< duration.count() << " microseconds" <<endl;
    cout<<endl;


    cout<< "Merge sort:"<<endl<<endl;
    cout<<"Input array"<<endl;
    displayArray(arr2,nums);



    //Code to count time
    auto start2 = high_resolution_clock::now();
    merge_sort(arr2, 0, nums-1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout <<"Sorted array"<<endl;
    displayArray(arr2, nums);
    cout<<endl;
    cout<<"Time taken by function: "<< duration2.count() << " microseconds" <<endl;
    cout<<endl;
    return 0;
}