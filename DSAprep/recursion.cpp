#include <iostream>
using namespace std;

int factorial(int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    // Recursive case
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    
        int result = factorial(n);
        cout << "Factorial of " << n << " = " << result << endl;
        return 0;
    }

    

