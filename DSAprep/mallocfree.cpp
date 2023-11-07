#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

  // allocate 5 int memory blocks
  int* ptr = (int*) malloc(5 * sizeof(int));

  // check if memory has been allocated successfully
  if (!ptr) {
    cout << "Memory Allocation Failed";
    exit(1);
  }

  cout << "Initializing values..." << endl << endl;

  for (int i = 0; i < 5; i++) {
    ptr[i] = i * 2 + 1;
  }
  cout << "Initialized values" << endl;

  // print the values in allocated memories
  for (int i = 0; i < 5; i++) {

    // ptr[i] and *(ptr+i) can be used interchangeably
    cout << *(ptr + i) << endl;
  }

  // deallocate memory
  free(ptr);

  return 0;
}
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

  // allocate memory of size 0
  int *ptr = (int*) malloc(0);

  if (ptr==NULL) {
    cout << "Null pointer";
  }
  else {
    cout << "Address = " << ptr;
  }

  // deallocate memory
  free(ptr);

  return 0;
}





#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int *ptr;
	ptr = (int*) malloc(5*sizeof(int));
	cout << "Enter 5 integers" << endl;

	for (int i=0; i<5; i++)
	{
	// *(ptr+i) can be replaced by ptr[i]
		cin >> *(ptr+i);
	}
	cout << endl << "User entered value"<< endl;

	for (int i=0; i<5; i++)
	{
		cout << *(ptr+i) << " ";
	}
	free(ptr);

	/* prints a garbage value after ptr is free */
	cout << "Garbage Value" << endl;

	for (int i=0; i<5; i++)
	{
		cout << *(ptr+i) << " ";
	}
	return 0;
}
