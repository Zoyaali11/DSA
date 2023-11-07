#include <iostream>
#include <stack>

struct Node {
    char data;
    Node* left;
    Node* right;
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* buildExpressionTree(const std::string& expression) {
    std::stack<Node*> stack;

    for (char c : expression) {
        if (!isOperator(c)) {
            stack.push(createNode(c));
        } else {
            Node* rightOperand = stack.top();
            stack.pop();

            Node* leftOperand = stack.top();
            stack.pop();

            Node* operatorNode = createNode(c);
            operatorNode->left = leftOperand;
            operatorNode->right = rightOperand;

            stack.push(operatorNode);
        }
    }

    return stack.top();
}

void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    std::string infixExpression = "a+b*c-d/e";
    Node* expressionTree = buildExpressionTree(infixExpression);

    std::cout << "Postorder traversal of the expression tree: ";
    postorderTraversal(expressionTree);

    return 0;
}
