// Insertion sort in C++

// Selection sort in C++

#include <iostream>
using namespace std;

// function to swap the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  // Outer loop: Iterate through the array except the last element
  for (int step = 0; step < size - 1; step++) {
    // Initialize the minimum index as the current step
    int min_idx = step;

    // Inner loop: Find the index of the minimum element in the remaining unsorted portion
    for (int i = step + 1; i < size; i++) {
      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // Swap the minimum element found in the inner loop with the element at the current step
    swap(&array[min_idx], &array[step]);
  }
}

// Driver code
int main() {
  int data[] = {20, 12, 10, 15, 2};
  
  // Calculate the size of the 'data' array by dividing the total size of the array by the size of a single element
  int size = sizeof(data) / sizeof(data[0]);

  // Call the selectionSort function to sort the array
  selectionSort(data, size);

  // Print the sorted array in ascending order
  cout << "Sorted array in Ascending Order:\n";
  printArray(data, size);
}



//selectionSort(array, size):
 // repeat (size - 1) times:
  //  set the first unsorted element as the minimum
    //for each of the unsorted elements:
     // if element < currentMinimum:
       // set element as new minimum
    //swap minimum with the first unsorted position
  //end repeat
//end selectionSort
