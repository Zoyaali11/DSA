// Binary Search in C++ using recursion

#include <iostream>
using namespace std;

// Recursive function to perform binary search
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2; // Calculate the middle index

    // If the element is found at mid, then return its index
    if (array[mid] == x)
      return mid;

    // If the element is in the left half, search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // If the element is in the right half, search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1; // Element not found, return -1
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 4; // Element to search for
  int n = sizeof(array) / sizeof(array[0]); // Calculate the size of the array
  int result = binarySearch(array, x, 0, n - 1); // Call the binarySearch function
  if (result == -1)
    printf("Not found"); // Element not found
  else
    printf("Element is found at index %d", result); // Element found, print its index
} //Recursion method




// Recursive Binary Search Algorithm:

// Function binarySearch(arr, x, low, high):
//     if low > high
//         return False (Element not found)
//     else
//         mid = (low + high) / 2
//         if x == arr[mid]
//             return mid (Element found at index mid)
//         else if x > arr[mid]
//             return binarySearch(arr, x, mid + 1, high) (Search in the right half)
//         else
//             return binarySearch(arr, x, low, mid - 1) (Search in the left half)
