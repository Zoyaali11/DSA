#include<stdio.h>
using namespace std;
struct DataItem {
   int data;
   int key;
};
// Define a hashing method to compute the hash code of the key of the data item.
#include <iostream>
#include <unordered_map>
using namespace std;
#define SIZE 10 // Define the size of the hash table
struct DataItem {
    int key;
};
unordered_map<int, DataItem*> hashMap; // Define the hash table as an unordered_map

int hashCode(int key) {
    // Return a hash value based on the key
    return key % SIZE;
}

DataItem* search(int key) {
    // get the hash
    int hashIndex = hashCode(key);

    // move in the map until an empty slot is found or the key is found
    while (hashMap[hashIndex] != nullptr) {
        // If the key is found, return the corresponding DataItem pointer
        if (hashMap[hashIndex]->key == key)
            return hashMap[hashIndex];

        // go to the next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    // If the key is not found, return nullptr
    return nullptr;
}

int main() {

    // Initializing the hash table with some sample DataItems
    DataItem item2 = {25}; // Assuming the key is 25
    DataItem item3 = {64}; // Assuming the key is 64
    DataItem item4 = {22}; // Assuming the key is 22

    // Calculate the hash index for each item and place them in the hash table
    
    int hashIndex2 = hashCode(item2.key);
    hashMap[hashIndex2] = &item2;
    
    int hashIndex3 = hashCode(item3.key);
    hashMap[hashIndex3] = &item3;

    int hashIndex4 = hashCode(item4.key);
    hashMap[hashIndex4] = &item4;

    // Call the search function to test it
    int keyToSearch = 64; // The key to search for in the hash table
    DataItem* result = search(keyToSearch);

    if (result != nullptr) {
        cout << "Key " << keyToSearch << " found, Value: " << result->key << endl;
    } else {
        cout << "Key " << keyToSearch << " not found." << endl;
    }

    return 0;
}





















// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #define SIZE 20
// struct DataItem {
//    int data;   
//    int key;
// };
// struct DataItem* hashArray[SIZE]; 
// struct DataItem* dummyItem;
// struct DataItem* item;

// int hashCode(int key) {
//    return key % SIZE;
// }
// struct DataItem *search(int key) {
//    //get the hash 
//    int hashIndex = hashCode(key);  
	
//    //move in array until an empty 
//    while(hashArray[hashIndex] != NULL) {
	
//       if(hashArray[hashIndex]->key == key)
//          return hashArray[hashIndex]; 
			
//       //go to next cell
//       ++hashIndex;
		
//       //wrap around the table
//       hashIndex %= SIZE;
//    }        
//    return NULL;        
// }
// void insert(int key,int data) {
//    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
//    item->data = data;  
//    item->key = key;

//    //get the hash 
//    int hashIndex = hashCode(key);

//    //move in array until an empty or deleted cell
//    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
//       //go to next cell
//       ++hashIndex;	
//       //wrap around the table
//       hashIndex %= SIZE;
//    }
//    hashArray[hashIndex] = item;
// }
// struct DataItem* delete(struct DataItem* item) {
//    int key = item->key;
//    //get the hash 
//    int hashIndex = hashCode(key);
//    //move in array until an empty
//    while(hashArray[hashIndex] != NULL) {
	
//       if(hashArray[hashIndex]->key == key) {
//          struct DataItem* temp = hashArray[hashIndex]; 		
//          //assign a dummy item at deleted position
//          hashArray[hashIndex] = dummyItem; 
//          return temp;
//       }	
//       //go to next cell
//       ++hashIndex;
		
//       //wrap around the table
//       hashIndex %= SIZE;
//    }      	
//    return NULL;        
// }
// void display() {
//    int i = 0;
	
//    for(i = 0; i<SIZE; i++) {
//       if(hashArray[i] != NULL)
//          printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
//       else
//          printf(" ~~ ");
//    }
	
//    printf("\n");
// }
// int main() {
//    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
//    dummyItem->data = -1;  
//    dummyItem->key = -1; 
//    insert(1, 20);
//    insert(2, 70);
//    insert(42, 80);
//    insert(4, 25);
//    insert(12, 44);
//    insert(14, 32);
//    insert(17, 11);
//    insert(13, 78);
//    insert(37, 97);
//    display();
//    item = search(37);
//    if(item != NULL) {
//       printf("Element found: %d\n", item->data);
//    } else {
//       printf("Element not found\n");
//    }
//    delete(item);
//    item = search(37);

//    if(item != NULL) {
//       printf("Element found: %d\n", item->data);
//    } else {
//       printf("Element not found\n");
//    }
// }