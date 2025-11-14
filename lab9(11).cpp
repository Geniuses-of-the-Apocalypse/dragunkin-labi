#include <iostream>
#include <string>
using namespace std;

template<typename T>
class BinaryTree {
    struct Node {
        T vrem;
        Node* left;
        Node* right;
        
        Node(T val) : vrem(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

  
    bool poisk(T vrem) {
        Node* srav = root;
        
        while (srav) {
            if (vrem == srav->vrem) {
                return true;
            }
            if (vrem < srav->vrem) {
                srav = srav->left;
            } else {
                srav = srav->right;
            }
        }
        return false;
    }

    
    void insert(T vrem) {
        if (poisk(vrem)) {
            return;
        }
        if (!root) {
            root = new Node(vrem);
            return;
        }
        Node* srav = root;
        while (true) {
            if (vrem < srav->vrem) {
                if (!srav->left) {
                    srav->left = new Node(vrem);
                    return;
                }
                srav = srav->left;
            } else {
                if (!srav->right) {
                    srav->right = new Node(vrem);
                    return;
                }
                srav = srav->right;
            }
        }
    }
    
  
    void remove(T vrem) {
        root = removeR(root, vrem);
    }
    
    
    string toString() {
        string result = "";
        toStringR(root, result);
        return result;
    }
    
    
    void writeToStream(ostream& os) {
        writeToStreamR(root, os);
    }
     void print() {
        cout << "Дерево:" << endl;
        cout << "====================" << endl;
        printR(root, 0, 40);
        cout << "====================" << endl;
    }
    
    void readFromStream(istream& is) {
        clear();
        T value;
        while (is >> value) {
            insert(value);
        }
    }
    
    
    void clear() {
        clearR(root);
        root = nullptr;
    }
    
    
    bool empty() {
        return root == nullptr;
    }

private:

    void clearR(Node* node) {
        if (node) {
            clearR(node->left);
            clearR(node->right);
            delete node;
        }
    }
    
   
    Node* removeR(Node* node, T vrem) {
        if (!node) return nullptr;
        
        if (vrem < node->vrem) {
            node->left = removeR(node->left, vrem);
        } else if (vrem > node->vrem) {
            node->right = removeR(node->right, vrem);
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->vrem = temp->vrem;
                node->right = removeR(node->right, temp->vrem);
            }
        }
        return node;
    }
    
    
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
    
    
    void toStringR(Node* node, string& result) {
        if (node) {
            toStringR(node->left, result);
            if (!result.empty()) {
                result += " ";
            }
            result += to_string(node->vrem);
            toStringR(node->right, result);
        }
    }
    
    
    void writeToStreamR(Node* node, ostream& os) {
        if (node) {
            os << node->vrem << " ";
            writeToStreamR(node->left, os);
            writeToStreamR(node->right, os);
        }
    }

     void printR(Node* node, int level, int spaces) {
        if (node) {
         
            printR(node->right, level + 1, spaces + 8);
            
         
            for (int i = 0; i < spaces; i++) {
                cout << " ";
            }
            cout << node->vrem << endl;
            
          
            printR(node->left, level + 1, spaces + 8);
        }
    }
};
int main() {
    BinaryTree<int> tree;
    
 
    cout << "Добавляем элементы: 5, 3, 7, 2, 4" << endl;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    
    tree.print();
    cout << "Есть ли 3 в дереве: " << tree.poisk(3) << endl;
    cout << "Есть ли 6 в дереве: " << tree.poisk(6) << endl;
    
    
    cout << "Содержимое дерева: " << tree.toString() << endl;
    
    
    cout << "Удаляем элемент 3" << endl;
    tree.remove(3);
    tree.print();
    cout << "Содержимое после удаления: " << tree.toString() << endl;
   
    cout << "Дерево пустое: " << tree.empty() << endl;
    
    
    tree.clear();
    cout << "После очистки дерево пустое: " << tree.empty() << endl;
    
    return 0;
}
// Если не запускается нужно поставить c/c++ compile run
