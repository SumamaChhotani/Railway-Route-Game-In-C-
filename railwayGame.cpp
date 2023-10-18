/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <string>
#include "goal.h"
#include "railwayGame.h"
#include "adts/graph.h"
#include "adjacencyListUndirectedGraph.h"
#include "player.h"


using namespace std;

RailwayGame::RailwayGame(Graph<string, int, int>* mapGraph){
this->mapGraph = mapGraph;

int turn = 1;
}

vector<Goal> RailwayGame::randomizeGoals(){
return {};


}
// create 3 random goals for each player using  vector<Goal*> goalP1 & vector<Goal*> goalP2;
 // Goal goalP1 = new Goal();
 


int RailwayGame::getPlayerTurn(){
  return turn; //will return either 1 & 2 to determine whose turn it is
}

void RailwayGame::updateTurn(){
  if(turn = 1){
  turn = 2;
  }
  else if(turn = 2){
  turn = 1;
  }
  // call this function to switch player turn for getPlayerTurn
}

//switches player turn by updating int

bool RailwayGame::isGameOver(Player p1, Player p2){
  if(mapGraph.getEdges() == (p1.getEdges() +p2,getEdges())){
    return true;
  }
  else{
    return false;
  }
 
}

bool RailwayGame::goalCaptured(){
return false; // returns true if a specific goal is captured
}

bool RailwayGame::gameIsRunning(){
return true; // returns true if the game is running.  WIll be used to start and end the game
}

 void RailwayGame::updatePlayer(int playerNum){
  if(playerNum == 1){
    p1.
    //need to update rail #, score #, and player map 
  }
  if(playerNum == 2){
    p2.
  }

  
  //
 }

int RailwayGame::getScore(int playerNum){
    if(playerNum == 1){
   return p1.score;
  }
  if(playerNum == 2){
   return p2.score;
  }
}

int RailwayGame::getTracks(int playerNum){
    if(playerNum == 1){
   return p1.trackNum;
  }
  if(playerNum == 2){
   return p2.trackNum;
  }
}

int RailwayGame::getGoals(int playerNum){
     if(playerNum == 1){
   return p1.listOfGoals;
  }
  if(playerNum == 2){
   return p2.listOfGoals;
  }
}

int RailwayGame::Edge(int playerNum){
//implement gaining an edge
}
int RailwayGame::Pass(int playerNum){
//implement gaining a pass
}



// TODO: implement your RailwayGame class constructor and methods here
