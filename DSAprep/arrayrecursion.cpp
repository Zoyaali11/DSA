// C++ Program to print array using 
// recursion 
#include <iostream> 
using namespace std; 

// recursive function to print array 
void pArray(int* arr, int n) 
{ 
	// base condition 
	if (n == 0) { 
		return; 
	} 
	// recursive call 
	pArray(arr, n - 1); 
	cout << arr[n - 1] << ' '; 
} 

int main() 
{ 
	// declaring array 
	int arr[5] = { 1, 2, 3, 4, 5 }; 
	// calling function 
	pArray(arr, 5); 
	return 0; 
}
