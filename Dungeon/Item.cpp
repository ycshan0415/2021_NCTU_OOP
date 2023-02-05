#include "Item.h"

Item::Item():Object(){

}

Item::Item(string name, int health, int attack, int defense):Object(name, "Item"){
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    e=0;
}

bool Item::triggerEvent(Object* object){
    int answer;
    Player* player = dynamic_cast<Player*>(object);
    cout << "You find a chest!!\n"<< "Do you want to open it?" << endl;
    cout << "1. Yes\n2. No" << endl;
    cin >> answer;
    if (answer == 1){
        if (this->getName() == "God's_bless"){
            cout << "God had blessed you!! Your status increases by 10 respectively!!" << endl;
            player->addItem(*this);
            player->increaseStates(10, 10, 10);
            player->setCurrentRoom(player->getPreviousRoom());
            cout << "You now go back to the previous room..." << endl;
            cout << "You are now in room " << player->getCurrentRoom()->getIndex() << endl;
            return true;
        }
        else if (this->getName() == "Devil's_curse"){
            cout << "Devil had cursed you!! Your status decreases by 5 respectively!!" << endl;
            player->addItem(*this);
            player->increaseStates(-5, -5, -5);
            player->setCurrentRoom(player->getPreviousRoom());
            cout << "You now go back to the previous room..." << endl;
            cout << "You are now in room " << player->getCurrentRoom()->getIndex() << endl;
            return true; 
        }
    }
    else if (answer == 2){
        player->setCurrentRoom(player->getPreviousRoom());
        cout << "You now go back to the previous room" << endl;
        cout << "You are now in room " << player->getCurrentRoom()->getIndex() << endl;
        return false;
    }
    return false;
}

int Item::getHealth(){
    return this->health;
}

int Item::getAttack(){
    return this->attack;
}
int Item::getDefense(){
    return this->defense;
}

void Item::setHealth(int health){
    this->health = health;
}

void Item::setAttack(int attack){
    this->attack = attack;
}

void Item::setDefense(int defense){
    this->defense = defense;
}