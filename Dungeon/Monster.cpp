#include "Monster.h"

Monster::Monster():GameCharacter(){

}

Monster::Monster(string name, int health, int attack, int defense):GameCharacter(name, "Monster", health, attack, defense){
    setName(name);
    setCurrentHealth(health);
    setAttack(attack);
    setDefense(defense);
}

bool Monster::triggerEvent(Object* objects){
    Player* player = dynamic_cast<Player*>(objects);
    if (this->checkIsDead()){
        return false;
    }
    else{
        int answer;
        cout << "Here comes the monster " << this->getName() << "!!!" << endl;
        cout << getCurrentHealth() << " / " << getAttack() << " / " << getDefense() << endl;
        cout << "What do you want to do?" << endl;
        cout << "1. Attack\n" << "2. Retreat\n" << "3. Check my status" << endl;
        cin >> answer;

        if (answer == 1){
            while (getCurrentHealth() > 0 && player->getCurrentHealth() > 0){ 
                takeDamage(player->getAttack());
                if (getCurrentHealth() <= 0){
                    cout << "Congratulations!!! You beat " << getName() << endl;
                }
                else{
                    player->takeDamage(getAttack());
                    if (player->getCurrentHealth() < 0){
                        cout << "You are beaten by " << getName() << endl;
                    }
                }                     
            }
        }
        else if (answer == 2){
            player->changeRoom(player->getPreviousRoom()); 
            cout << "You are now in room " << player->getCurrentRoom()->getIndex() << endl;
            return false;        
        }
        else if (answer == 3){
            player->triggerEvent(player);
            return false;      
        }
        return false;
    }
}
