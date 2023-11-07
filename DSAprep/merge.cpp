// Merge sort in C++

#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  // Copy elements from A to L and M
  // L ← A[p..q]
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];

  // M ← A[q+1..r]
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain the current index of sub-arrays and the main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M
  while (i < n1 && j < n2) {

    // If the element in L is less than or equal to the element in M
    if (L[i] <= M[j]) {
      // Put the element from L into A
      arr[k] = L[i];
      i++;
    } else {
      // Put the element from M into A
      arr[k] = M[j];
      j++;
    }
    // Move to the next position in A
    k++;
  }

  // When we run out of elements in either L or M
  while (i < n1) {
    // Put the remaining elements from L into A
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    // Put the remaining elements from M into A
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them, and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Calculate the middle index
    int m = l + (r - l) / 2;

    // Recursively sort the left subarray
    mergeSort(arr, l, m);

    // Recursively sort the right subarray
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver program
int main() {
  // Input array
  int arr[] = {6, 5, 12, 10, 9, 1};

  // Calculate the size of the array
  int size = sizeof(arr) / sizeof(arr[0]);

  // Sort the array using mergeSort
  mergeSort(arr, 0, size - 1);

  // Print the sorted array
  cout << "Sorted array: \n";
  printArray(arr, size);

  // Return success
  return 0;
}

//MergeSort(A, p, r):
  //  if p > r 
    //    return
    //q = (p+r)/2
   // mergeSort(A, p, q)
    //mergeSort(A, q+1, r)
    //merge(A, p, q, r)
//sssssSTo sort an entire array, we need to call MergeSort(A, 0, length(A)-1)
//Mega sort algorithm 

