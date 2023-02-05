#include <vector>
#include <iostream>
using namespace std;

class Object{
public:
    virtual void response() = 0;
    
    virtual ~Object() = default;
};

class IceMonster : public Object{
    public:
        bool used;
        IceMonster(){
            used = 0;
        }
    
        void response(){
            if (used == 0)
                cout << "fire attack";
            used = 1;
        }
};

class FireMonster : public Object{
    public:
        bool used;
        FireMonster(){
            used = 0;
        }
    
        void response(){
            if (used == 0)
                cout << "ice attack";
            used = 1;
        }
};

class Treasure : public Object{
    public:
        bool used;
        Treasure(){
            used = 0;
        }
    
        void response(){
            if (used == 0)
                cout << "ya";
            used = 1;
        }  
};


class Room{
public:
    Room *up_room;
    Room *down_room;
    Room *left_room;
    Room *right_room;
    int index;
    Object *o;
    Room(){
        up_room = down_room = left_room = right_room = NULL;
        index = 0;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    Room room[10];
    
    char object_in_room;
    int room_number, steps, up, down, left, right;
    int i;
    
    cin >> room_number >> steps;
    
    for (i = 0; i < room_number; i++){
        cin >> object_in_room;
        cin >> up >> down >> left >> right;
        
        room[i].index = i;

        if(up != -1)
            room[i].up_room = &room[up];
        if(down != -1)
            room[i].down_room = &room[down];
        if(left != -1)
            room[i].left_room = &room[left];
        if(right != -1)
            room[i].right_room = &room[right];

        if(object_in_room == 'e')
            room[i].o = NULL;
        else if(object_in_room == 'i')
            room[i].o =  new IceMonster();
        else if(object_in_room == 'f')
            room[i].o = new FireMonster();
        else if(object_in_room == 't')
            room[i].o = new Treasure();
        }

    Room *cur = &room[0];
    char direction;

    cout << 0 << endl;

    for(i = 0; i < steps; i++){
        Room *next;    
        cin >> direction;

        if (direction == 'u')
            next = cur->up_room;
        else if (direction == 'd')
            next = cur->down_room;
        else if (direction == 'l')
            next = cur->left_room;
        else if (direction == 'r')
            next = cur->right_room;

        if (next == NULL)
            cout << -1;
        else{
            cur = next;
            cout << cur->index;
            if (cur->o != NULL){
                cout << ' ';
                cur->o->response();
            }
        }
        cout << endl;
    }
    return 0;
}