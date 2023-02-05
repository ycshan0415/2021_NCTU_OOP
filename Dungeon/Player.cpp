#include "Player.h"

Player::Player():GameCharacter(){

}

Player::Player(string name, int health, int attack, int defense):GameCharacter(name, "Player", health, attack, defense){
    setMaxHealth(health);
    setCurrentHealth(health);
    setAttack(attack);
    setDefense(defense);
}

void Player::addItem(Item item){
    inventory.push_back(item);
}

void Player::increaseStates(int health, int attack, int defense){
    setCurrentHealth(getCurrentHealth() + health);
    setAttack(getAttack() + attack);
    setDefense(getDefense() + defense);
}

void Player::changeRoom(Room* newRoom){
    this->previousRoom = currentRoom;
    this->currentRoom = newRoom;
}

bool Player::triggerEvent(Object* objects){
    Player* player = dynamic_cast<Player*>(objects);
    cout << "Name: " << getName() << endl;
    cout << "health: " << getCurrentHealth() << endl;
    cout << "attack: " << getAttack() << endl;
    cout << "defense: " << getDefense() << endl;
    cout << "your equipment:\n";
    for (int i = 0; i < inventory.size(); i++){
        cout << inventory[i].getName() << endl;
    }
    return 0;
}

void Player::setCurrentRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}

void Player::setPreviousRoom(Room* previousRoom){
    this->previousRoom = previousRoom;
}

void Player::setInventory(vector<Item> inventory){
    this->inventory = inventory;
}

Room* Player::getCurrentRoom(){
    return this->currentRoom;
}

Room* Player::getPreviousRoom(){
    return this->previousRoom;
}

vector<Item> Player::getInventory(){
    return this->inventory;
}