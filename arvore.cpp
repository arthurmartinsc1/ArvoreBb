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

   cout<<x->key;





}


