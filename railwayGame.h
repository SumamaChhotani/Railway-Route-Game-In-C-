/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
   */ 
#pragma once
#include "adts/graph.h"
#include "player.h"
#include "adjacencyListUndirectedGraph.h"

class RailwayGame {
  public:
    // TODO: write your RailwayGame constructor and method declarations here
    RailwayGame(Graph<string, int, int>* mapGraph);
    vector<Goal> randomizeGoals();
    int getPlayerTurn();
    bool isGameOver();
    bool goalCaptured();
    bool gameIsRunning();
    void updateTurn();

  private:
    // TODO: write your RailwayGame fields here
     Player* p1;
     Player* p2;
     Graph<string, int, int>* mapGraph;
     int turn; //Flip-flops between 1 & 2 determining whose turn it is
     

    // You can safely ignore the following code.  This eliminates some default
    // class routines, preventing you from using them accidentally.
    // Specifically, we are disabling the use of the copy constructor and the
    // copy assignment operator.  You can read more here:
    //   http://www.cplusplus.com/articles/y8hv0pDG/
    RailwayGame(const RailwayGame& game) = delete;
    RailwayGame& operator=(const RailwayGame& game) = delete;
};
