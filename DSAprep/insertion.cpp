// Insertion sort in C++

#include <iostream>
using namespace std;

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(int array[], int size) {
  // Loop through the array starting from the second element
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare the 'key' with each element on the left of it until an element smaller
    // than it is found. This loop shifts elements to the right until the correct
    // position for 'key' is found.
    // For descending order, change key < array[j] to key > array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Driver code
int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);

  // Call the insertionSort function to sort the array
  insertionSort(data, size);

  // Print the sorted array in ascending order
  cout << "Sorted array in ascending order:\n";
  printArray(data, size);
}
//insertionSort(array)
 // mark first element as sorted
 // for each unsorted element X
   // 'extract' the element X
    //for j <- lastSortedIndex down to 0
      //if current element j > X
       // move sorted element to the right by 1
   // break loop and insert X here
//end insertionSort
//Algorithm of insertion sort 