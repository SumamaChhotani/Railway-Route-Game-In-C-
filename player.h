#pragma once

#include "goal.h"
#include <vector>
#include <string>
#include "adts/graph.h"

using namespace std;

class Player {
  public:
    // Player();
    void updateScore();
    void updatePlayerGraph(vector<string> movementCity);
    vector<Goal>listOfGoals;
    int getCities();
    int getTrackNum();

  private:
    int score;
    int cities;
    Graph<string, int, int>* playerGraph; // add every vertex in game map, only add in an edge if player claims it.
    int trackNum;
    //type of verticies(string), type of label for edges(owned 0-unowned, 1 is plauyer 1 owns, 2 if player 2 owns (int), weights for edges (interpreted as tracks) (int)
};
