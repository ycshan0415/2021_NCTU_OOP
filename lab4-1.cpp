#include <iostream>
using namespace std;

class Room{
public:
    Room *left_room = NULL;
    Room *right_room = NULL;
    int index;
    Room(int n){
        index = n;
    }
  //add constructor or functions if you need
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int total, number, count;
    char move;
    cin >> total;
    Room *first, *cur;
    
    for(int i = 0; i < total; ++i){
        cin >> number;
        if (first == NULL){
            cur = new Room(number);
            first = cur;
        }
        else {
        cur -> right_room = new Room(number);
        cur -> right_room -> left_room = cur;
        cur = cur -> right_room;
        }
    }
    
    cur = first;
    cin >> count;
    cout << cur -> index << " ";
    
    for(int i = 0; i < count; ++i){
        cin >> move;

        if (move == 'l'){
            if (cur -> left_room == NULL)
                cout << "-1 ";
            else {
                cur = cur -> left_room;
                cout << cur -> index << " ";
            }
        }
        
        if (move == 'r'){
            if (cur -> right_room == NULL)
                cout << "-1" << " ";
            else{
                cur = cur -> right_room;
                cout << cur -> index << " ";
            }
        }  
    }
    
    return 0;
}
