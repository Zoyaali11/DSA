// CPP program to construct a linked list
// from given 2D matrix
// #include <bits/stdc++.h>
// using namespace std;
// // struct node of linked list
// struct Node {
// 	int data;
// 	Node *right, *down;
// };
// // returns head pointer of linked list
// // constructed from 2D matrix
// Node* construct(int arr[][4], int i, int j, int m, int n,
// 				vector<vector<Node*> >& visited)
// {
// 	// return if i or j is out of bounds
// 	if (i > m - 1 || j > n - 1)
// 		return NULL;
// 	// Check if node is previously created then,
// 	// don't need to create new/
// 	if (visited[i][j]) {
// 		return visited[i][j];
// 	}
// 	// create a new node for current i and j
// 	// and recursively allocate its down and
// 	// right pointers
// 	Node* temp = new Node();
// 	visited[i][j] = temp;
// 	temp->data = arr[i][j];
// 	temp->right = construct(arr, i, j + 1, m, n, visited);
// 	temp->down = construct(arr, i + 1, j, m, n, visited);
// 	return temp;
// }
// // utility function for displaying
// // linked list data
// void display(Node* head)
// {
// 	// pointer to move right
// 	Node* Rp;
// 	// pointer to move down
// 	Node* Dp = head;
// 	// loop till node->down is not NULL
// 	while (Dp) {
// 		Rp = Dp;
// 		// loop till node->right is not NULL
// 		while (Rp) {
// 			cout << Rp->data << " ";
// 			Rp = Rp->right;
// 		}
// 		cout << "\n";
// 		Dp = Dp->down;
// 	}
// }
// // driver program
// int main()
// {
// 	// 2D matrix
// 	int arr[][4] = { { 1, 2, 3, 0 },
// 					{ 4, 5, 6, 1 },
// 					{ 7, 8, 9, 2 },
// 					{ 7, 8, 9, 2 } };
// 	int m = 4, n = 4;
// 	vector<vector<Node*> > visited(m, vector<Node*>(n));
// 	Node* head = construct(arr, 0, 0, m, n, visited);
// 	display(head);
// 	return 0;
// }


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

class NodeOperation{
public:
	
	// Function to add a new node
	void pushNode(class Node** head_ref,int data_val){
		
		// Allocate node
		class Node *new_node = new Node();
		
		// Put in the data
		new_node->data = data_val;
		
		// Link the old list of the new node
		new_node->next = *head_ref;
		
		// move the head to point to the new node
		*head_ref = new_node;
	}
};

int main() {
class Node *head = NULL;
	class NodeOperation *temp = new NodeOperation();
	for(int i=5; i>0; i--){
		temp->pushNode(&head, i);
	}
	vector<int>v;
	while(head!=NULL){
	v.push_back(head->data);
	head=head->next;
	}
	cout<<"Middle Value Of Linked List is :";
	cout<<v[v.size()/2]<<endl;
	return 0;
}


// Delete linkedlist from middle
// for (int i = 2; i < position; i++) {
// 	if(temp->next != NULL) { temp = temp->next; }
// }
// temp->next = temp->next->next;
// // This code is contributed by Yash Agarwal(yashagarwal2852002)
// //last node delete
// node* temp = head;
// while (temp->next->next != NULL) {
// temp = temp->next;
// }
// temp->next = nullptr;
