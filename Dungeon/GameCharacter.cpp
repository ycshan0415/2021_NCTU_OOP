#include "GameCharacter.h"

GameCharacter::GameCharacter():Object(){

}

GameCharacter::GameCharacter(string name, string tag, int currentHealth, int attack, int defense):Object(name, tag){
    this->name = name;
    this->currentHealth = currentHealth;
    this->attack = attack;
    this->defense = defense;
}

bool GameCharacter::checkIsDead(){
    if (currentHealth <= 0){
        return true;
    }
    else
        return false;
}

int GameCharacter::takeDamage(int damage){
    currentHealth = currentHealth - (damage - this->getDefense());
    return currentHealth;
}

void GameCharacter::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
}

void GameCharacter::setCurrentHealth(int currentHealth){
    this->currentHealth = currentHealth;
}

void GameCharacter::setAttack(int attack){
    this->attack = attack;
}

void GameCharacter::setDefense(int defense){
    this->defense = defense;
}

int GameCharacter::getMaxHealth(){
    return this->maxHealth;
}

int GameCharacter::getCurrentHealth(){
    return this->currentHealth;
}

int GameCharacter::getAttack(){
    if (this->attack <= 0){
        return 0;
    }
    else
        return this->attack;
}

int GameCharacter::getDefense(){
    if (this->defense <= 0){
        return 0;
    }
    else
        return this->defense;
}
