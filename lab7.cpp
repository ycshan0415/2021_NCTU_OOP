#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    Node *root;
    int len;
    LinkedList() : root(nullptr), len(0) {}
    void push(int);
    void insert(int, int);
    int find(int);
    void remove(int);
    void print();
};

void LinkedList::push(int x){
    Node *newNode = new Node(x);

    if (root == nullptr){
        root = newNode;
        len++;
        return;
    }
    Node *cur = root;
    while (cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = newNode;
    len++;
}

void LinkedList::insert(int pos, int x){
    Node *cur = root;
    if (pos > len){
        cout << "insert fail" << endl;
        return;
    } 
    else{
        Node *newNode = new Node(x);
        
        if (pos == 0 && cur == nullptr){
            root = new Node(x);
            len++;
            return;
        }
        if (pos == 0){
            newNode->next = cur;
            root = newNode;
            len++;
        }
        else{
            for (int i = 0; i < pos -1; i++){
                cur = cur->next;
            }
        }
        Node *next = cur->next;
        cur->next = newNode;
        newNode->next = next;
        len++;
    }
}

int LinkedList::find(int x){
    int count = 0;
	Node *cur = root;
    while(cur != NULL){
        if (cur->val == x){
            return count;
            count++;
            cur = cur->next;
        }
        cur = cur->next;
    }
    delete cur;
    return -1;
}

void LinkedList::remove(int pos){
    Node *cur = root;
    Node *pre = 0;
	if(pos > len - 1){
        cout << "remove fail" << endl;
        return;
    }
    if (pos == 0){
        root = root->next;
        delete cur;
        len--;
        return;
    }
    else if (pos == 1){
        cur->next = cur->next->next;
        len--;
        return;
    }
    for (int i = 0; i < pos; i++){
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    len--;
}

void LinkedList::print(){
    if(root == nullptr)
        return;

    Node *cur = root;
    while(cur->next != nullptr){
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << cur->val << endl;
}

int main(){
    LinkedList mylist;
    
    int n, a, b;
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'p'){
            cin >> a;
            mylist.push(a);
        }else if(c == 'i'){
            cin >> a >> b;
            mylist.insert(a, b);
        }else if(c == 'r'){
            cin >> a;
            mylist.remove(a);
        }else if(c == 'f'){
            cin >> a;
            cout << mylist.find(a) << endl;
        }else if(c == '?'){
            mylist.print();
        }
    }
    return 0;
}