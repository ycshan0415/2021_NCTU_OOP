#include "NPC.h"

NPC::NPC():GameCharacter(){

}

NPC::NPC(string name, string script, vector<Item> commodity):GameCharacter(name, "NPC", 100, 100, 100){
    setName(name);
    this->script = script;
    this->commodity = commodity;
}

void NPC::listCommodity(){
    for (int i = 0; i < commodity.size(); i++){
        cout << i + 1 << ". " << commodity[i].getName() << endl;
    }
}

bool NPC::triggerEvent(Object* objects){
    Player* player = dynamic_cast<Player*>(objects);
    int answer;
    cout << "Here comes " << this->getName() << "!!!" << endl;
    cout << "I'm the basketball team leader!!!" << endl;
    cout << "Are you good at basketball?\n" << "1. Yes\n2. No" << endl;
    cin >> answer;
    if (answer == 1){
        cout << "No way!! I am the best!!" << endl;
        cout << "Your health decrease by 10, attack and defense decreases by 5" << endl;
        player->increaseStates(-10, -5, -5);
        player->setCurrentRoom(player->getPreviousRoom());
        cout << "You now go back to the previous room..." << endl;
        cout << "You are now in room " << player->getCurrentRoom()->getIndex() << endl;
    }
    else if (answer == 2){
        cout << "Let's okay, join my team and you can get better" << endl;
        cout << "Because you undergo Danzel's training, your health decrease by 20, your health increase by 10" << endl;
        player->increaseStates(-20, -10, 0);
        player->setCurrentRoom(player->getPreviousRoom());
        cout << "You now go back to the previous room..." << endl;
        cout << "You are now in room " << player->getCurrentRoom()->getIndex() << endl;
    }
    return false;
}

void NPC::setScript(string script){
    this->script = script;
}

void NPC::setCommodity(vector<Item> commodity){
    this->commodity = commodity;
}

string NPC::getScript(){
    return this->script;
}

vector<Item> NPC::getCommodity(){
    return commodity;
}