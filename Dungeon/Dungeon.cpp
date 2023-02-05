#include "Dungeon.h"

Dungeon::Dungeon(){

}

void Dungeon::createPlayer(){
    string name;
    int choose;
    cout << "Please enter your name:" << endl;
    cin >> name;
    cout << "Please choose your character:" << endl;
    cout << "1. Knight (110 / 10 / 20)" << endl << "2. Archer (90 / 40 / 10)" << endl << "3. Wizard (100 / 25 / 15)" << endl;
    cin >> choose;

    switch (choose){
        case 1:
            player = Player(name, 110, 15, 20);
            player.setMaxHealth(200);
            cout << "Demacia!!!" << endl;
            break;
        case 2:
            player = Player(name, 95, 40, 10);
            player.setMaxHealth(200);
            cout << "Hasaki!!!" << endl;
            break;
        case 3:
            player = Player(name, 100, 30, 15);
            player.setMaxHealth(200);
            cout << "Tibbers!!!" << endl;
            break;
    }
    player.setCurrentRoom(&rooms[0]);
}

void Dungeon::createMap(){
    int total = 9;
    for (int i = 0; i < total; i++){
        Room temp;
        temp.setIndex(i);
        rooms.push_back(temp);
        rooms[i].setUpRoom(NULL);
        rooms[i].setDownRoom(NULL);
        rooms[i].setRightRoom(NULL);
        rooms[i].setIsExit(false);
    }
    
    rooms[0].setDownRoom(&rooms[1]);
    rooms[0].setUpRoom(&rooms[2]);
    rooms[1].setUpRoom(&rooms[0]);
    rooms[2].setDownRoom(&rooms[0]);
    rooms[2].setLeftRoom(&rooms[3]);
    rooms[2].setRightRoom(&rooms[4]);
    rooms[3].setRightRoom(&rooms[2]);
    rooms[4].setLeftRoom(&rooms[2]);
    rooms[4].setRightRoom(&rooms[5]);
    rooms[4].setUpRoom(&rooms[6]);
    rooms[5].setLeftRoom(&rooms[4]);
    rooms[6].setDownRoom(&rooms[4]);
    rooms[6].setUpRoom(&rooms[7]);
    rooms[7].setUpRoom(&rooms[8]);
    rooms[7].setDownRoom(&rooms[6]);    
    rooms[8].setIsExit(true);

    vector <Object*> r1;
    vector <Object*> r2;
    vector <Object*> r3;
    vector <Object*> r5;
    vector <Object*> r7;

    Monster* mob = new Monster("Danzel_is_not_Fun", 40, 25, 5);
    r2.push_back(mob);
    rooms[2].setObjects(r2);

    Monster* boss = new Monster("Danzel_fun", 120, 50, 10);
    r7.push_back(boss);
    rooms[7].setObjects(r7);

    Item* bless = new Item("God's_bless", 10, 10, 10);
    r5.push_back(bless);
    rooms[5].setObjects(r5);

    Item* curse = new Item("Devil's_curse", -5, -5, -5);
    r1.push_back(curse);
    rooms[1].setObjects(r1);
    
    vector<Item> I3;
    NPC *hsu = new NPC("Danzel_Hsu", "0", I3);
    r3.push_back(hsu);
    rooms[3].setObjects(r3);
}

void Dungeon::handleMovement(){
    char choose;
    Room *cur = player.getCurrentRoom();

    cout << "Where do you want to go?" << endl;
    if (player.getCurrentRoom()->getUpRoom() != NULL){
        cout << "u. go up" << endl;
    }
    if (player.getCurrentRoom()->getDownRoom() != NULL){
        cout << "d. go down" << endl;
    }
    if (player.getCurrentRoom()->getLeftRoom() != NULL){
        cout << "l. go left" << endl;
    }
    if (player.getCurrentRoom()->getRightRoom() != NULL){
        cout << "r. go right" << endl;
    }
    cin >> choose;
    if (choose == 'u'){
        player.changeRoom(cur->getUpRoom());
        player.setPreviousRoom(cur);     
    }
    else if (choose == 'd'){
        player.changeRoom(cur->getDownRoom());
        player.setPreviousRoom(cur);
    }
    else if (choose == 'l'){
        player.changeRoom(cur->getLeftRoom());
        player.setPreviousRoom(cur);
    }
    else if (choose == 'r'){
        player.changeRoom(cur->getRightRoom());
        player.setPreviousRoom(cur);
    }

    cout << "You are now in room " << player.getCurrentRoom()->getIndex() << endl;
}

void Dungeon::handleEvent(Object* objects){
    Item* item = dynamic_cast<Item*>(objects);
    Monster* monster = dynamic_cast<Monster*>(objects);
    NPC* npc = dynamic_cast<NPC*>(objects);

    if (item){
        item->triggerEvent(&player);
    }
    if (monster){
        if (monster->getCurrentHealth() <= 0){
            cout << "The room is cleared!" << endl;
            return handleMovement();
        }
        else
            monster->triggerEvent(&player);
    }
    if (npc){
        npc->triggerEvent(&player);
    }
}

void Dungeon::startGame(){
    int choose;
    cout << "Welcome to my dungeon!!!" << endl;
    cout << "Do you want to..." << endl;
    cout << "1. Start a new game\n" << "2. Load a previous save\n";
    cin >> choose;

    if (choose == 1){
        createMap();
        createPlayer();
        player.setCurrentRoom(&rooms[0]);
    }
    else if (choose == 2){
        createMap();
        Record record;
        record.loadFromFile(&player, rooms);
        cout << "Welcome back!" << endl;
        player.triggerEvent(&player);
        player.setCurrentRoom(&rooms[player.cr]);
        player.setPreviousRoom(&rooms[player.pr]);
    }
}

void Dungeon::chooseAction(vector<Object*> objects){
    vector<Object*> checkObject = player.getCurrentRoom()->getObjects();
    int choose;
    
    if (checkObject.size() > 0){
        handleEvent(checkObject[0]);
        cout << endl;
    }
    else{
        cout << "1. Check my status\n" << "2. Move\n" << "3. Show the map\n" << "4. Save and log out" << endl;
        cin >> choose;
        switch (choose){
            case 1:
                player.triggerEvent(&player);
                break;
            case 2:
                handleMovement();
                break;
            case 3:
                cout << "                             _______                " << endl;
                cout << "                            |       |               " << endl;      
                cout << "                            |   7   |               " << endl;
                cout << "                            |_______|               " << endl;
                cout << "                                |                   " << endl;
                cout << "                             ___|___                " << endl;
                cout << "                            |       |               " << endl;
                cout << "                            |   6   |               " << endl;
                cout << "                            |_______|               " << endl;
                cout << "                                |                   " << endl;
                cout << " _______       _______       ___|___       _______  " << endl;
                cout << "|       |     |       |     |       |     |       | " << endl;
                cout << "|   3   |-----|   2   |-----|   4   |-----|   5   | " << endl;
                cout << "|_______|     |_______|     |_______|     |_______| " << endl;
                cout << "                  |                                 " << endl;
                cout << "               ___|___                              " << endl;
                cout << "              |       |                             " << endl;
                cout << "              |   0   |                             " << endl;
                cout << "              |_______|                             " << endl;
                cout << "               ___|___                              " << endl;
                cout << "              |       |                             " << endl;
                cout << "              |   1   |                             " << endl;
                cout << "              |_______|                             " << endl;
                cout << endl;
                break;
            case 4:
                Record record;
                record.saveToFile(&player, rooms);
                exit(1);
        }
    }  
}

bool Dungeon::checkGameLogic(){
    if (player.getCurrentRoom()->getIsExit() == 1){
        cout << "Victory!!!";
        return 0;
    }
    else if(player.getCurrentHealth()<=0){
        cout << "Game Over!!!";
        return 0;
    }
    else{
        return 1;
    }
}

void Dungeon::runDungeon(){
    startGame();
    while (checkGameLogic()){
        chooseAction(player.getCurrentRoom()->getObjects());
    }
}