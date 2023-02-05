#include "Record.h"
Record::Record(){

}

void Record::saveToFile(Player* player, vector<Room>& rooms){
    ofstream fplayer("recordplayer.txt");
    ofstream frooms("recordrooms.txt");
    savePlayer(player, fplayer);
    saveRooms(rooms, frooms);
}

void Record::loadFromFile(Player* player, vector<Room>& rooms){
    ifstream fplayer("recordplayer.txt");
    ifstream frooms("recordrooms.txt");

    loadPlayer(player, fplayer);
    loadRooms(rooms, frooms);
}
    

void Record::savePlayer(Player* player, ofstream& fplayer){
    int i;
    fplayer << player->getName() << endl;
    fplayer << player->getCurrentHealth() << endl;
    fplayer << player->getAttack() << endl;
    fplayer << player->getDefense() << endl;
    fplayer << player->getCurrentRoom()->getIndex() << endl;
    fplayer << player->getPreviousRoom()->getIndex() << endl;
    fplayer << player->getInventory().size() << endl;
    for ( i = 0; i < player->getInventory().size(); i++){
        fplayer << player->getInventory()[i].getName() << endl;
    }

}

void Record::saveRooms(vector<Room>& rooms, ofstream& frooms){
    Monster *mob = dynamic_cast<Monster*>(rooms[2].getObjects()[0]);
    Monster *boss = dynamic_cast<Monster*>(rooms[7].getObjects()[0]);
    frooms << mob->getCurrentHealth() << endl;
    frooms << boss->getCurrentHealth() << endl;
}

void Record::loadPlayer(Player* player, ifstream& fplayer){
    vector<Room> rooms;
    string name;
    int currenthealth, attack, defense, c, p, index, items;
    fplayer >> name;
    fplayer >> currenthealth;
    fplayer >> attack;
    fplayer >> defense;
    fplayer >> c;
    fplayer >> p;
    fplayer >> items;
    player->setName(name);
    player->setCurrentHealth(currenthealth);
    player->setAttack(attack);
    player->setDefense(defense);
    player->cr = c;
    player->pr = p;
    Item item("myItem", 0, 0, 0);
    for (int i = 0; i < items; i++){
        Item item("myItem", 0, 0, 0);
        string name;
        fplayer >> name;
        item.setName(name);
        player->addItem(item);
    }
}

void Record::loadRooms(vector<Room>& rooms, ifstream& frooms){
    int mob_health, boss_health, index;
    frooms >> mob_health;
    frooms >> boss_health;
    Monster *mob = dynamic_cast<Monster*>(rooms[2].getObjects()[0]);
    Monster *boss = dynamic_cast<Monster*>(rooms[7].getObjects()[0]);
    mob->setCurrentHealth(mob_health);
    boss->setCurrentHealth(boss_health);
}
