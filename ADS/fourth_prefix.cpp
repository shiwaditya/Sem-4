 <iostream>
#include <stack>

struct Node {
    char data;
    Node* left;
    Node* right;
};

class ExpressionTree {
private:
    Node* root;

public:
    ExpressionTree(std::string prefix) {
        std::stack<Node*> s;
        for (int i = prefix.length() - 1; i >= 0; i--) {
            if (isalnum(prefix[i])) {
                Node* newNode = new Node;
                newNode->data = prefix[i];
                newNode->left = NULL;
                newNode->right = NULL;
                s.push(newNode);
            } else {
                Node* newNode = new Node;
                newNode->data = prefix[i];
                newNode->right = s.top();
                s.pop();
                newNode->left = s.top();
                s.pop();
                s.push(newNode);
            }
        }
        root = s.top();
    }

    void postOrderTraversal() {
        std::stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();
            s2.push(current);
            if (current->left) {
                s1.push(current->left);
            }
            if (current->right) {
                s1.push(current->right);
            }
        }
        while (!s2.empty()) {
            Node* current = s2.top();
            s2.pop();
            std::cout << current->data << " ";
        }
    }

    void deleteTree(Node* node) {
        if (node == NULL) {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    ~ExpressionTree() {
        deleteTree(root);
    }
};

int main() {
    std::string prefix = "+--a*bc/def";
    ExpressionTree et(prefix);
    std::cout << "Post-Order Traversal: ";
    et.postOrderTraversal();
    return 0;
}