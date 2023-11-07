//C++ code for Max Heap construction  Algorithm
#include <iostream>
// Structure to represent a heap
struct Heap {
    int* array;     // Array to store heap elements
    int capacity;   // Maximum capacity of the heap
    int size;       // Current size of the heap
};
// Function to create a new heap
Heap* createHeap(int capacity)
{
    Heap* heap = new Heap;
    heap->array = new int[capacity];
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}
// Function to swap two elements in the heap
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
// Function to heapify a subtree rooted at index i
void heapify(Heap* heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Check if the left child is larger than the root
    if (left <heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    // Check if the right child is larger than the largest so far
    if (right <heap->size && heap->array[right] > heap->array[largest])
        largest = right;
    // If the largest is not the root, swap the root with the largest
    if (largest != i) {
        swap(heap->array[i], heap->array[largest]);
        heapify(heap, largest);
    }
}
// Function to insert a new element into the heap
void insert(Heap* heap, int value)
{
    if (heap->size == heap->capacity) {
        std::cout << "Heap is full. Cannot insert more elements." << std::endl;
        return;
    }
    // Insert the new element at the end
    int i = heap->size++;
    heap->array[i] = value;
    // Fix the heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(heap->array[i], heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
// Function to extract the maximum element from the heap
int extractMax(Heap* heap)
{
    if (heap->size == 0) {
        std::cout << "Heap is empty. Cannot extract maximum element." << std::endl;
        return -1;
    }
    // Store the root element
    int max = heap->array[0];
    // Replace the root with the last element
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    // Heapify the root
    heapify(heap, 0);
    return max;
}
// Function to print the elements of the heap
void printHeap(Heap* heap)
{
    std::cout << "Heap elements: ";
    for (int i = 0; i < heap->size; i++) {
        std::cout << heap->array[i] << " ";
    }
    std::cout << std::endl;
}
// Example usage of the heap
int main()
{
    Heap* heap = createHeap(10);
    insert(heap, 35);
    insert(heap, 33);
    insert(heap, 42);
    insert(heap, 10);
    insert(heap, 14);
    insert(heap, 19);
    insert(heap, 27);
    insert(heap, 44);
    insert(heap, 26);
    insert(heap, 31);

    printHeap(heap);

    int max = extractMax(heap);
    std::cout << "Maximum element: " << max << std::endl;

    return 0;
}






















// //C++ code for Max Heap Deletion Algorithm
// #include <iostream>
// // Structure to represent a heap
// struct Heap {
//     int* array;     // Array to store heap elements
//     int capacity;   // Maximum capacity of the heap
//     int size;       // Current size of the heap
// };
// // Create a new heap
// Heap* createHeap(int capacity)
// {
//     Heap* heap = new Heap;
//     heap->array = new int[capacity];
//     heap->capacity = capacity;
//     heap->size = 0;
//     return heap;
// }
// // Swap two elements in the heap
// void swap(int& a, int& b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }
// // Heapify a subtree rooted at index i
// void heapify(Heap* heap, int i)
// {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;
//     // Check if the left child is larger than the root
//     if (left < heap->size && heap->array[left] > heap->array[largest])
//         largest = left;
//     // Check if the right child is larger than the largest so far
//     if (right < heap->size && heap->array[right] > heap->array[largest])
//         largest = right;
//     // If the largest is not the root, swap the root with the largest
//     if (largest != i) {
//         swap(heap->array[i], heap->array[largest]);
//         heapify(heap, largest);
//     }
// }
// // Function to insert a new element into the heap
// void insert(Heap* heap, int value)
// {
//     if (heap->size == heap->capacity) {
//         std::cout << "Heap is full. Cannot insert more elements." << std::endl;
//         return;
//     }
//     // Insert the new element at the end
//     int i = heap->size++;
//     heap->array[i] = value;

//     // Fix the heap property if it is violated
//     while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
//         swap(heap->array[i], heap->array[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }
// }
// // Function to delete the maximum element from the heap
// int deleteMax(Heap* heap)
// {
//     if (heap->size == 0) {
//         std::cout << "Heap is empty. Cannot extract maximum element." << std::endl;
//         return -1;
//     }
//     // Store the root element
//     int max = heap->array[0];
//     // Replace the root with the last element
//     heap->array[0] = heap->array[heap->size - 1];
//     heap->size--;
//     // Heapify the root
//     heapify(heap, 0);

//     return max;
// }
// // Function to print the elements of the heap
// void printHeap(Heap* heap)
// {
//     std::cout << "Heap elements: ";
//     for (int i = 0; i < heap->size; i++) {
//         std::cout << heap->array[i] << " ";
//     }
//     std::cout << std::endl;
// }
// // Function to deallocate memory occupied by the heap
// void destroyHeap(Heap* heap)
// {
//     delete[] heap->array;
//     delete heap;
// }
// // Example usage of the heap
// int main()
// {
//     Heap* heap = createHeap(10);
//     insert(heap, 35);
//     insert(heap, 33);
//     insert(heap, 42);
//     insert(heap, 10);
//     insert(heap, 14);
//     insert(heap, 19);
//     insert(heap, 27);
//     insert(heap, 44);
//     insert(heap, 26);
//     insert(heap, 31);
//     printHeap(heap);
//     int max = deleteMax(heap);
//     std::cout << "Maximum element: " << max << std::endl;
//     printHeap(heap);
//     destroyHeap(heap);
//     return 0;
// }