#include <string>

#include "player.h"

using namespace std;

void Player::updateScore(){
 this->score = 0;
}

void Player::updatePlayerGraph(vector<string> movementCity){
this->score = 0;
}

int Player::getCities(){
    return cities;
}

int Player::getTrackNum();{
    return trackNum;
}