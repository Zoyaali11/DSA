#include <iostream>
struct node {
   int data;
   struct node *leftChild, *rightChild;
};
struct node *root = NULL;
struct node *newNode(int item){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = item;
   temp->leftChild = temp->rightChild = NULL;
   return temp;
}
void insert(int data){
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;
   
   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;
      while(1) {
         parent = current;

         //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;

            //insert to the left
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->rightChild;
            
            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}
struct node* search(int data){
   struct node *current = root;
   printf("\n\nVisiting elements: ");
   while(current->data != data) {
      if(current != NULL) {
         printf("%d ",current->data);
         
         //go to left tree
         if(current->data > data) {
            current = current->leftChild;
         }//else go to right tree
         else {
            current = current->rightChild;
         }
         
         //not found
         if(current == NULL) {
            return NULL;
         }
      }
   }
   return current;
}

// Inorder Traversal
void inorder(struct node *root){
   if (root != NULL) {
      inorder(root->leftChild);
      printf("%d -> ", root->data);
      inorder(root->rightChild);
   }
}

// Preorder Traversal
void preorder(struct node *root){
   if (root != NULL) {
      printf("%d -> ", root->data);
      preorder(root->leftChild);
      preorder(root->rightChild);
   }
}

// Postorder Traversal
void postorder(struct node *root){
   if (root != NULL) {
      printf("%d -> ", root->data);
      postorder(root->leftChild);
      postorder(root->rightChild);
   }
}
int main(){
   insert(55);
   insert(20);
   insert(90);
   insert(50);
   insert(35);
   insert(15);
   insert(65);
   printf("Insertion done\n");
   printf("\nPreorder Traversal: ");
   preorder(root);
   printf("\nInorder Traversal: ");
   inorder(root);
   printf("\nPostorder Traversal: ");
   postorder(root);
   struct node* k;
   k = search(35);
   if(k != NULL)
      printf("\nElement %d found", k->data);
   else
      printf("\nElement not found");
   return 0;
}
// 1. START
// 2. Traverse the left subtree, recursively
// 3. Then, traverse the root node
// 4. Traverse the right subtree, recursively.
// 5. END

// 1. START
// 2. Traverse the root node first.
// 3. Then traverse the left subtree, recursively
// 4. Later, traverse the right subtree, recursively.
//5. END

// 1. START
// 2. Traverse the left subtree, recursively
// 3. Traverse the right subtree, recursively.
// 4. Then, traverse the root node
// 5. END
