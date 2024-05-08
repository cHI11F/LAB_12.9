#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    char order; // Додаткове поле для визначення порядку обходу
    Node* left;
    Node* right;

    Node(int value, char o) : data(value), order(o), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void insertUtil(Node*& node, int value, char order) {
        if (node == nullptr) {
            node = new Node(value, order);
            return;
        }

        if (value < node->data) {
            insertUtil(node->left, value, order);
        }
        else {
            insertUtil(node->right, value, order);
        }
    }

    void printUtil(Node* node, int indent, char currentOrder) {
        if (node == nullptr) return;

        printUtil(node->right, indent + 4, currentOrder);
        if (node->order == currentOrder) {
            cout << string(indent, ' ') << "=>" << node->data << endl;
        }
        else {
            cout << string(indent, ' ') << node->data << endl;
        }
        printUtil(node->left, indent + 4, currentOrder);
    }

    Node* findMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteUtil(Node* node, int value) {
        if (node == nullptr) return nullptr;

        if (value < node->data) {
            node->left = deleteUtil(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteUtil(node->right, value);
        }
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* temp = findMinNode(node->right);
                node->data = temp->data;
                node->right = deleteUtil(node->right, temp->data);
            }
        }
        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value, char order) {
        insertUtil(root, value, order);
    }

    void print(char currentOrder) {
        printUtil(root, 0, currentOrder);
    }

    void deleteNode(int value) {
        root = deleteUtil(root, value);
    }

    Node* getRoot() {
        return root;
    }

    int findMinValuePostfix() {
        Node* current = root;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (prev == current->right || prev == current->left) {
                break;
            }
            if (current->left != nullptr) {
                current = current->left;
            }
            else if (current->right != nullptr) {
                current = current->right;
            }
            else {
                break;
            }
        }
        return current->data;
    }
};

int main() {
    BinaryTree bst;

    // Вставка елементів у бінарне дерево пошуку з визначенням порядку обходу
    bst.insert(50, 'A');
    bst.insert(30, 'B');
    bst.insert(20, 'C');
    bst.insert(40, 'D');
    bst.insert(70, 'E');
    bst.insert(60, 'F');
    bst.insert(80, 'G');

    // Вивід бінарного дерева з виділенням поточного елемента (наприклад, 'D')
    bst.print('D');

    // Видалення елемента зі значенням 30
    bst.deleteNode(30);

    // Знаходження останнього елемента бінарного дерева з мінімальним значенням за "постфіксним" обходом
    cout << "Останній елемент бінарного дерева з мінімальним значенням: " << bst.findMinValuePostfix() << endl;

    return 0;
}
