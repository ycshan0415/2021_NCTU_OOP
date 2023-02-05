#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(){}
        Node(int v){
            this->data = v;
            this->left = NULL;
            this->right = NULL;
        }
};

void insert(Node* &root, int data){
    if (root == NULL){
        root = new Node(data);
    }
    else if (root->data > data){
        insert(root->left, data);
    }
    else if (root->data < data){
        insert(root->right, data);
    }
}

void display(Node* root){
    if (root != NULL){
        display(root->left);
        display(root->right);
        cout << root->data << endl;     
    }
}


int main() {
    Node *root = NULL;
    int n;
    while(cin >> n){
        insert(root, n);
    }
    display(root);
    cout << root->data;
    return 0;
}