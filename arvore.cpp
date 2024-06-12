#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    // Construtor do nó
    Node(int key) {
        this->key = key;
        this->left = this->right = nullptr;
    }
};



Node* insert(Node* node, int key) {
    // se a arvore tiver vazia inserir o no 
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}


Node* search(Node* raiz, int key) {
    if (raiz == nullptr || raiz->key == key) {
        return raiz;
    }
    if (key < raiz->key) {
        return search(raiz->left,key);
    }
    return search(raiz->right,key);

}




Node* findmin(Node* raiz) {
    while (raiz->left != nullptr) {

        raiz = raiz->left;
    }

    return raiz;
    
}

Node* removeHelper(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (value < node->key) {
            node->left = removeHelper(node->left, value);
        } else if (value > node->key) {
            node->right = removeHelper(node->right, value);
        } else {
            // Nó com apenas um filho ou nenhum
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Nó com dois filhos: pegar o sucessor in-order (menor na subárvore direita)
            Node* temp = findmin(node->right);
            node->key = temp->key;
            node->right = removeHelper(node->right, temp->key);
        }
        
        return node;
    }



int main() {
    Node* raiz = nullptr;
    raiz = insert(raiz, 50);
    raiz = insert(raiz, 30);
    raiz = insert(raiz, 20);
    raiz = insert(raiz, 40);
    raiz = insert(raiz, 10);
    raiz = insert(raiz, 60);
    raiz = insert(raiz, 80);


Node* x = findmin(raiz);

   
Node *y = search(raiz, 20);
if (y != nullptr) {
    cout << y->key << endl;
} else {
    cout << "Nenhum no encontrado" << endl;
}
    




}


