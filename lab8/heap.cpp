#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;// say the root of the tree is the largest
    int left = 2 * root + 1; // left child
    int right = 2 * root + 2; // right child
 
    // when left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // when right child is larger 
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // If largest is not root
    if (largest != root) {
        int temp = arr[root]; //swap the root and the largest child
        arr[root] = arr[largest];
        arr[largest] = temp;
 
        // heapify the subtree that was modified
        heapify(arr, n, largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // building the heap tree from the array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) { //Getting the sorted values from the heap tree
        int temp = arr[0];// moving the root to the leaves
        arr[0] = arr[i];
        arr[i] = temp; 
 
        heapify(arr, i, 0);//heapify the reduced sub tree
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {4, 17, 3, 12, 9, 6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}