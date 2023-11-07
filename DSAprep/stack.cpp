#include <iostream>

const int MAX_SIZE = 100; // Maximum stack size

class Stack {
private:
    int top;
    int data[MAX_SIZE];

public:
    Stack() {
        top = -1; // Initialize the top to -1 to represent an empty stack
    }

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            std::cout << "Stack overflow! Cannot push " << value << std::endl;
            return;
        }

        data[++top] = value;
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack underflow! Cannot pop from an empty stack." << std::endl;
            return -1; // Return a default value in this case
        }

        return data[top--];
    }

    int peek() {
        if (top < 0) {
            std::cout << "The stack is empty." << std::endl;
            return -1; // Return a default value in this case
        }

        return data[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;

    std::cout << "Popped element: " << stack.pop() << std::endl;

    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
