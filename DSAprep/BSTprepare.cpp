#include <iostream>
#include <string>

// Define the structure for a binary tree node
struct TreeNode {
    std::string data;
    TreeNode* left;
    TreeNode* right;
};

// Function to check if two trees have the same data at corresponding nodes
bool areEqual(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) {
        return true; // Both trees are empty, so they are equal
    }
    if (t1 == nullptr || t2 == nullptr) {
        return false; // One tree is empty while the other is not, so they are not equal
    }
    return (t1->data == t2->data) && areEqual(t1->left, t2->left) && areEqual(t1->right, t2->right);
}

// Function to check if two trees have the same structure
bool haveSameStructure(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) {
        return true; // Both trees are empty, so they have the same structure
    }
    if (t1 == nullptr || t2 == nullptr) {
        return false; // One tree is empty while the other is not, so they have different structures
    }
    return haveSameStructure(t1->left, t2->left) && haveSameStructure(t1->right, t2->right);
}

// Function to check if two trees are mirror images of each other
bool areMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) {
        return true; // Both trees are empty, so they are mirror images
    }
    if (t1 == nullptr || t2 == nullptr) {
        return false; // One tree is empty while the other is not, so they are not mirror images
    }
    return (t1->data == t2->data) && areMirror(t1->left, t2->right) && areMirror(t1->right, t2->left);
}

int main() {
    // Create and populate two binary trees
    TreeNode tree1;
    tree1.data = "A";
    tree1.left = new TreeNode;
    tree1.left->data = "B";
    tree1.left->left = nullptr;
    tree1.left->right = nullptr;
    tree1.right = new TreeNode;
    tree1.right->data = "C";
    tree1.right->left = nullptr;
    tree1.right->right = nullptr;

    TreeNode tree2;
    tree2.data = "A";
    tree2.left = new TreeNode;
    tree2.left->data = "C";
    tree2.left->left = nullptr;
    tree2.left->right = nullptr;
    tree2.right = new TreeNode;
    tree2.right->data = "B";
    tree2.right->left = nullptr;
    tree2.right->right = nullptr;

    // Task 1: Check if the trees are equal
    bool equalTrees = areEqual(&tree1, &tree2);
    if (equalTrees) {
        std::cout << "The trees are equal." << std::endl;
    } else {
        std::cout << "The trees are not equal." << std::endl;
    }

    // Task 2: Check if the trees have the same structure
    bool sameStructure = haveSameStructure(&tree1, &tree2);
    if (sameStructure) {
        std::cout << "The trees have the same structure." << std::endl;
    } else {
        std::cout << "The trees do not have the same structure." << std::endl;
    }

    // Task 3: Check if the trees are mirror images of each other
    bool mirrorImages = areMirror(&tree1, &tree2);
    if (mirrorImages) {
        std::cout << "The trees are mirror images of each other." << std::endl;
    } else {
        std::cout << "The trees are not mirror images of each other." << std::endl;
    }

    // Clean up memory (delete dynamically allocated nodes)
    delete tree1.left;
    delete tree1.right;
    delete tree2.left;
    delete tree2.right;

    return 0;
}


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to represent a cell/node in the graph
struct Cell {
    int x, y;
};

// Function to check if a cell is within the maze boundaries
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// Function to add an edge to the adjacency list
void addEdge(vector<vector<Cell>>& graph, int x1, int y1, int x2, int y2, int m) {
    // Add an edge between two cells (x1, y1) and (x2, y2) in the adjacency list
    graph[x1 * m + y1].push_back({x2, y2});
    graph[x2 * m + y2].push_back({x1, y1});
}

// Function to perform BFS to find the path
void findPath(int n, int m, vector<vector<Cell>>& graph) {
    bool visited[10000] = {false}; // Assuming n * m <= 10000
    Cell parent[10000] = { { -1, -1 } }; // Parent cell for each cell
    queue<int> q;
    int start = 0;
    int end = n * m - 1;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int x = cur / m;
        int y = cur % m;

        if (cur == end) {
            cout << "Path found:" << endl;
            int cell = end;
            while (cell != start) {
                int x = cell / m;
                int y = cell % m;
                cout << x << "," << y << endl;
                cell = parent[cell].x * m + parent[cell].y;
            }
            cout << "0,0" << endl;
            return;
        }

        for (const Cell& neighbor : graph[cur]) {
            int newX = neighbor.x;
            int newY = neighbor.y;
            int neighborCell = newX * m + newY;
            if (!visited[neighborCell]) {
                q.push(neighborCell);
                visited[neighborCell] = true;
                parent[neighborCell] = { x, y };
            }
        }
    }

    cout << "No path found." << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    int maze[100][100];

    cout << "Enter the maze (0 or 1) - 0 for open, 1 for blocked:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    // Start and end points are always open
    maze[0][0] = 0;
    maze[n - 1][m - 1] = 0;

    cout << "Maze:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<Cell>> graph(n * m); // Adjacency list for the graph
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (maze[x][y] == 0) {
                if (x > 0 && maze[x - 1][y] == 0) {
                    addEdge(graph, x, y, x - 1, y, m);
                }
                if (x < n - 1 && maze[x + 1][y] == 0) {
                    addEdge(graph, x, y, x + 1, y, m);
                }
                if (y > 0 && maze[x][y - 1] == 0) {
                    addEdge(graph, x, y, x, y - 1, m);
                }
                if (y < m - 1 && maze[x][y + 1] == 0) {
                    addEdge(graph, x, y, x, y + 1, m);
                }
            }
        }
    }

    findPath(n, m, graph);

    return 0;
}


#include <iostream>

using namespace std;

// Define a structure to represent a task with a name and priority.
struct Task {
    string name;
    int priority;
};

// Define the maximum size of the priority queue.
const int MAX_SIZE = 100;

// Initialize an array to store the priority queue.
Task priorityQueue[MAX_SIZE];

// Initialize variables to keep track of the front and rear of the queue.
int front = -1, rear = -1;

// Function to check if the queue is empty.
bool isEmpty() {
    return front == -1;
}

// Function to check if the queue is full.
bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to enqueue a task with a given name and priority.
void enqueue(string taskName, int taskPriority) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }

    // Create a new task.
    Task newTask;
    newTask.name = taskName;
    newTask.priority = taskPriority;

    if (isEmpty()) {
        // If the queue is empty, insert the task at the front.
        front = rear = 0;
        priorityQueue[rear] = newTask;
    } else {
        // Find the correct position to insert the task based on priority.
        int insertPosition = rear;
        while (insertPosition >= front && newTask.priority > priorityQueue[insertPosition].priority) {
            priorityQueue[(insertPosition + 1) % MAX_SIZE] = priorityQueue[insertPosition];
            insertPosition = (insertPosition - 1 + MAX_SIZE) % MAX_SIZE;
        }

        // Insert the new task at the appropriate position.
        priorityQueue[(insertPosition + 1) % MAX_SIZE] = newTask;
        rear = (rear + 1) % MAX_SIZE;
    }

    cout << "Enqueued: " << taskName << " with priority " << taskPriority << endl;
}

// Function to dequeue the task with the highest priority.
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    // Dequeue the task from the front.
    cout << "Dequeued: " << priorityQueue[front].name << " with priority " << priorityQueue[front].priority << endl;

    if (front == rear) {
        // If there was only one task in the queue, reset front and rear.
        front = rear = -1;
    } else {
        // Move front to the next task with the highest priority.
        front = (front + 1) % MAX_SIZE;
    }
}

int main() {
    while (true) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            string taskName;
            int taskPriority;
            cout << "Enter task name: ";
            cin >> taskName;
            cout << "Enter task priority: ";
            cin >> taskPriority;
            enqueue(taskName, taskPriority);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }

    return 0;
}

#include <iostream>

using namespace std;

// Define the structure for a node in the linked list.
struct Node {
    int data;
    Node* next;
};

// Function to insert a node with given data after every occurrence of a specific item in the linked list.
Node* insertAfter(Node* head, int findItem, int insertItem) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == findItem) {
            // Create a new node with insertItem.
            Node* newNode = new Node;
            newNode->data = insertItem;
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;  // Move current to the next node.
        } else {
            current = current->next;
        }
    }

    return head;
}

// Function to merge two sorted linked lists.
Node* mergeSortedLists(Node* list1, Node* list2) {
    Node* mergedList = nullptr;
    Node* tail = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            if (mergedList == nullptr) {
                mergedList = new Node{list1->data, nullptr};
                tail = mergedList;
            } else {
                tail->next = new Node{list1->data, nullptr};
                tail = tail->next;
            }
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            if (mergedList == nullptr) {
                mergedList = new Node{list2->data, nullptr};
                tail = mergedList;
            } else {
                tail->next = new Node{list2->data, nullptr};
                tail = tail->next;
            }
            list2 = list2->next;
        } else {
            if (mergedList == nullptr) {
                mergedList = new Node{list1->data, nullptr};
                tail = mergedList;
            } else {
                tail->next = new Node{list1->data, nullptr};
                tail = tail->next;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    // Add any remaining nodes from list1.
    while (list1 != nullptr) {
        tail->next = new Node{list1->data, nullptr};
        tail = tail->next;
        list1 = list1->next;
    }

    // Add any remaining nodes from list2.
    while (list2 != nullptr) {
        tail->next = new Node{list2->data, nullptr};
        tail = tail->next;
        list2 = list2->next;
    }

    return mergedList;
}

// Function to perform the difference operation on two linked lists.
Node* difference(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            if (result == nullptr) {
                result = new Node{list1->data, nullptr};
                tail = result;
            } else {
                tail->next = new Node{list1->data, nullptr};
                tail = tail->next;
            }
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            list2 = list2->next;
        } else {
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    while (list1 != nullptr) {
        if (result == nullptr) {
            result = new Node{list1->data, nullptr};
            tail = result;
        } else {
            tail->next = new Node{list1->data, nullptr};
            tail = tail->next;
        }
        list1 = list1->next;
    }

    return result;
}

// Function to perform the union operation on two linked lists.
Node* setUnion(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (list1 != nullptr || list2 != nullptr) {
        if (list1 == nullptr) {
            tail->next = new Node{list2->data, nullptr};
            tail = tail->next;
            list2 = list2->next;
        } else if (list2 == nullptr) {
            tail->next = new Node{list1->data, nullptr};
            tail = tail->next;
            list1 = list1->next;
        } else if (list1->data < list2->data) {
            tail->next = new Node{list1->data, nullptr};
            tail = tail->next;
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            tail->next = new Node{list2->data, nullptr};
            tail = tail->next;
            list2 = list2->next;
        } else {
            tail->next = new Node{list1->data, nullptr};
            tail = tail->next;
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    return result;
}

// Function to perform the intersection operation on two linked lists.
Node* setIntersection(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            list2 = list2->next;
        } else {
            if (result == nullptr) {
                result = new Node{list1->data, nullptr};
                tail = result;
            } else {
                tail->next = new Node{list1->data, nullptr};
                tail = tail->next;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    return result;
}

// Function to print the linked list.
void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create two linked lists for testing.
    Node* list1 = new Node{ 1, new Node{ 3, new Node{ 4, new Node{ 7, new Node{ 12, nullptr } } } } };
    Node* list2 = new Node{ 1, new Node{ 5, new Node{ 7, new Node{ 9, nullptr } } } };

    // Insert data into list1 and list2.

    // Test insertAfter function.
    list1 = insertAfter(list1, 2, 10);
    list1 = insertAfter(list1, 4, 10);
    list1 = insertAfter(list1, 2, 10);
    list1 = insertAfter(list1, 8, 10);
    list1 = insertAfter(list1, 2, 10);

    // Print list1 after insertAfter operations.
    cout << "List1 after insertAfter operations: ";
    printList(list1);

    // Test mergeSortedLists function.
    Node* mergedList = mergeSortedLists(list1, list2);

    // Print the merged list.
    cout << "Merged sorted lists: ";
    printList(mergedList);

    // Test difference function.
    Node* diffList = difference(list1, list2);

    // Print the difference of two lists.
    cout << "Difference of lists: ";
    printList(diffList);

    // Test setUnion function.
    Node* unionList = setUnion(list1, list2);

    // Print the union of two lists.
    cout << "Union of lists: ";
    printList(unionList);

    // Test setIntersection function.
    Node* intersectionList = setIntersection(list1, list2);

    // Print the intersection of two lists.
    cout << "Intersection of lists: ";
    printList(intersectionList);

    return 0;
}



#include <iostream>
#include <queue>
using namespace std;

// Define the structure for a binary tree node.
struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new binary tree node.
TreeNode* createNode(string val) {
    TreeNode* newNode = new TreeNode;
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to find the mirror image of a binary tree.
TreeNode* findMirrorImage(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Swap the left and right subtrees.
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively find the mirror image of left and right subtrees.
    findMirrorImage(root->left);
    findMirrorImage(root->right);

    return root;
}

// Function to find the predecessors and successors of a level of a given element x.
void findPredecessorsAndSuccessors(TreeNode* root, string x, int level) {
    if (root == nullptr) {
        return;
    }

    if (root->data == x) {
        // Found the element x, now find predecessors and successors at the same level.
        queue<TreeNode*> q;
        q.push(root);
        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currentLevel == level) {
                cout << "Predecessors and successors at level " << level << ": ";
                while (!q.empty()) {
                    cout << q.front()->data << " ";
                    q.pop();
                }
                cout << endl;
                return;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            currentLevel++;
        }
    } else {
        // Traverse the tree to find the element x.
        findPredecessorsAndSuccessors(root->left, x, level + 1);
        findPredecessorsAndSuccessors(root->right, x, level + 1);
    }
}

// Function to find the level of a given element x in the tree.
int findLevel(TreeNode* root, string x, int level) {
    if (root == nullptr) {
        return -1; // Element not found.
    }

    if (root->data == x) {
        return level;
    }

    int leftLevel = findLevel(root->left, x, level + 1);
    int rightLevel = findLevel(root->right, x, level + 1);

    if (leftLevel != -1) {
        return leftLevel;
    } else {
        return rightLevel;
    }
}

// Function to find the height of the node containing element x in the tree.
int findHeight(TreeNode* root, string x) {
    if (root == nullptr) {
        return -1; // Element not found.
    }

    if (root->data == x) {
        return 0;
    }

    int leftHeight = findHeight(root->left, x);
    if (leftHeight != -1) {
        return leftHeight + 1;
    }

    int rightHeight = findHeight(root->right, x);
    if (rightHeight != -1) {
        return rightHeight + 1;
    }

    return -1; // Element not found in the current subtree.
}

int main() {
    // Build the binary tree.
    TreeNode* root = createNode("A");
    root->left = createNode("B");
    root->right = createNode("C");
    root->left->left = createNode("D");
    root->left->right = createNode("E");
    root->right->left = createNode("F");
    root->right->right = createNode("G");

    // Find the mirror image of the tree.
    TreeNode* mirrorImage = findMirrorImage(root);

    // Find the predecessors and successors of level 2 of element "E".
    findPredecessorsAndSuccessors(root, "E", 2);

    // Find the level of element "F".
    int levelF = findLevel(root, "F", 0);
    if (levelF != -1) {
        cout << "Level of element F is: " << levelF << endl;
    } else {
        cout << "Element not found." << endl;
    }

    // Find the height of the node containing element "B".
    int heightB = findHeight(root, "B");
    if (heightB != -1) {
        cout << "Height of node containing element B is: " << heightB << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

// Define the structure for a node in the linked list.
struct Node {
    int data;
    Node* next;
};

// Function to create a new node with the given digit.
Node* createNode(int digit) {
    Node* newNode = new Node;
    newNode->data = digit;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a digit at the front of the linked list.
Node* insertFront(Node* head, int digit) {
    Node* newNode = createNode(digit);
    newNode->next = head;
    return newNode;
}

// Function to add two big integers stored as linked lists.
Node* addBigIntegers(Node* num1, Node* num2) {
    Node* result = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (num1 != nullptr || num2 != nullptr || carry != 0) {
        int sum = carry;

        if (num1 != nullptr) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != nullptr) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        if (result == nullptr) {
            result = createNode(digit);
            current = result;
        } else {
            current->next = createNode(digit);
            current = current->next;
        }
    }

    return result;
}

// Function to subtract two big integers stored as linked lists.
Node* subtractBigIntegers(Node* num1, Node* num2) {
    Node* result = nullptr;
    Node* current = nullptr;
    int borrow = 0;

    while (num1 != nullptr || num2 != nullptr) {
        int diff = borrow;
        if (num1 != nullptr) {
            diff += num1->data;
            num1 = num1->next;
        }
        if (num2 != nullptr) {
            diff -= num2->data;
            num2 = num2->next;
        }

        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        if (result == nullptr) {
            result = createNode(diff);
            current = result;
        } else {
            current->next = createNode(diff);
            current = current->next;
        }
    }

    // Remove leading zeros from the result.
    while (result != nullptr && result->data == 0) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return result;
}

// Function to multiply two big integers stored as linked lists.
Node* multiplyBigIntegers(Node* num1, Node* num2) {
    Node* result = createNode(0);

    Node* currentNum2 = num2;
    int position = 0;

    while (currentNum2 != nullptr) {
        Node* current = createNode(0);
        Node* currentResult = current;

        int carry = 0;
        int multiplier = currentNum2->data;

        for (int i = 0; i < position; i++) {
            currentResult->next = createNode(0);
            currentResult = currentResult->next;
        }

        Node* currentNum1 = num1;

        while (currentNum1 != nullptr || carry != 0) {
            int product = carry;
            if (currentNum1 != nullptr) {
                product += currentNum1->data * multiplier;
                currentNum1 = currentNum1->next;
            }

            carry = product / 10;
            currentResult->data = product % 10;

            if (currentNum1 != nullptr || carry != 0) {
                currentResult->next = createNode(0);
                currentResult = currentResult->next;
            }
        }

        result = addBigIntegers(result, current);

        currentNum2 = currentNum2->next;
        position++;
    }

    return result;
}

// Function to print the big integer stored as a linked list.
void printBigInteger(Node* head) {
    if (head == nullptr) {
        cout << "0";
    } else {
        while (head != nullptr) {
            cout << head->data;
            head = head->next;
        }
    }
    cout << endl;
}

int main() {
    // Create two big integers stored as linked lists.
    Node* num1 = createNode(9);
    num1 = insertFront(num1, 7);
    num1 = insertFront(num1, 4);

    Node* num2 = createNode(3);
    num2 = insertFront(num2, 5);
    num2 = insertFront(num2, 1);

    // Perform addition and print the result.
    Node* sum = addBigIntegers(num1, num2);
    cout << "Addition result: ";
    printBigInteger(sum);

    // Perform subtraction and print the result.
    Node* difference = subtractBigIntegers(num1, num2);
    cout << "Subtraction result: ";
    printBigInteger(difference);

    // Perform multiplication and print the result.
    Node* product = multiplyBigIntegers(num1, num2);
    cout << "Multiplication result: ";
    printBigInteger(product);

    return 0;
}
