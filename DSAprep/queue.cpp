#include <iostream>

const int MAX_SIZE = 100; // Maximum queue size

int front = -1; // Initialize front and rear to -1 to represent an empty queue
int rear = -1;
int data[MAX_SIZE];

void enqueue(int value) {
    if (rear >= MAX_SIZE - 1) {
        std::cout << "Queue overflow! Cannot enqueue " << value << std::endl;
        return;
    }

    data[++rear] = value;
    if (front == -1) {
        front = 0;
    }
}

int dequeue() {
    if (front == -1) {
        std::cout << "Queue underflow! Cannot dequeue from an empty queue." << std::endl;
        return -1; // Return a default value in this case
    }

    int dequeuedValue = data[front];
    if (front == rear) {
        front = rear = -1; // Reset front and rear when the last element is dequeued
    } else {
        front++;
    }

    return dequeuedValue;
}

bool isEmpty() {
    return front == -1;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    std::cout << "Dequeued element: " << dequeue() << std::endl;
    std::cout << "Dequeued element: " << dequeue() << std::endl;

    std::cout << "Is the queue empty? " << (isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
