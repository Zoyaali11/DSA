// Linear Search in C++

#include <iostream>
using namespace std;

// Function to perform linear search
int search(int array[], int n, int x) {

  // Going through the array sequentially
  for (int i = 0; i < n; i++) {
    if (array[i] == x)
      return i; // If the element is found, return its index
  }

  return -1; // Element not found, return -1
}

int main() {
  int array[] = {2, 4, 0, 1, 9};
  int x = 1; // Element to search for
  int n = sizeof(array) / sizeof(array[0]); // Calculate the size of the array
  int result = search(array, n, x); // Call the search function
  (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result; // Print the result
}
// Linear Search Algorithm:

// Function LinearSearch(array, key):
    // For each item in the array:
        // If the item is equal to the key:
            // Return its index
    // If the key is not found in the array:
        // Return -1 (Element not found)
