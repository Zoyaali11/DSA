// Quick sort in C++

#include <iostream>
using namespace std;

// Function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to print the array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Function to rearrange the array and find the partition point
int partition(int array[], int low, int high) {

  // Select the rightmost element as the pivot
  int pivot = array[high];

  // Pointer for greater element
  int i = (low - 1);

  // Traverse each element of the array, compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // If an element smaller than the pivot is found
      // Swap it with the greater element pointed by i
      i++;

      // Swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // Swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);

  // Return the partition point
  return (i + 1);
}

// QuickSort function
void quickSort(int array[], int low, int high) {
  if (low < high) {

    // Find the pivot element such that
    // elements smaller than the pivot are on the left of the pivot
    // elements greater than the pivot are on the right of the pivot
    int pi = partition(array, low, high);

    // Recursive call on the left of the pivot
    quickSort(array, low, pi - 1);

    // Recursive call on the right of the pivot
    quickSort(array, pi + 1, high);
  }
}

// Driver code
int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);

  cout << "Unsorted Array: \n";
  printArray(data, n);

  // Perform quicksort on data
  quickSort(data, 0, n - 1);

  cout << "Sorted array in ascending order: \n";
  printArray(data, n);
}

//quickSort(array, leftmostIndex, rightmostIndex):
  //if leftmostIndex < rightmostIndex:
    //pivotIndex <- partition(array, leftmostIndex, rightmostIndex)
    //quickSort(array, leftmostIndex, pivotIndex - 1)
    //quickSort(array, pivotIndex, rightmostIndex)

//partition(array, leftmostIndex, rightmostIndex):
  //set pivotElement as the element at rightmostIndex
  //storeIndex <- leftmostIndex - 1
  //for i <- leftmostIndex + 1 to rightmostIndex:
    //if element[i] < pivotElement:
      //swap element[i] and element[storeIndex]
     // storeIndex++
  //swap pivotElement and element[storeIndex + 1]
  //return storeIndex + 1
