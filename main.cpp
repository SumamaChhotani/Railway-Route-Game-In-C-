/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/
// #pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "goal.h"
#include "ioUtils.h"
#include "railwayGUI.h"
#include "player.h"
#include "railwayGame.h"


using namespace std;

int main(int argc, char** argv) {
    // Check command line arguments and give up if necessary.
    if (argc != 2) {
        cerr << "Expected one argument:" << endl;
        cerr << "  Base filename of map data" << endl;
        cerr << "  e.g., test_data/Europe " << endl;
        return 1;
    }

    // Initialize randomizer.  This should happen before any random numbers are
    // selected.
    srand(time(nullptr));

    // Get command-line arguments.
    string baseName(argv[1]);
    string graphDataFilename = baseName + "_graphData.txt";
    string vertexPositionFilename = baseName + "_vertexPositions.txt";
    string backgroundImageFilename = baseName + "_background.png";

    // Retrieve vertex positions (so we know where each vertex goes on the map).
    Dictionary<string, pair<int, int>>* vertexPositions;
    try {
        vertexPositions = readVertexPositions(vertexPositionFilename);
    } catch (exception e) {
        cout << "Could not read vertex positions file "
             << vertexPositionFilename << ": " << e.what() << endl;
        return 1;
    }

    // Load the initial graph.
    Graph<string, int, int>* graph;
    try {
        graph = readRailwayGraph(graphDataFilename);
    } catch (exception e) {
        cout << "Could not read graph data file " << graphDataFilename << ": "
             << e.what() << endl;
        delete vertexPositions;
        return 1;
    }

    // Player p2;cally allocated, so the GUI
    // will disappear the moment your program leaves the main function.
    // The GUI object should only be used by main, and not by any other function
    // or object.
    RailwayGUI gui(backgroundImageFilename, vertexPositions);
 
    // Tell the GUI about the graph we have.
    gui.updateRailwayMap(graph);

    // TODO: Write code that runs the game.  You'll want to write most of your
    // game logic into the RailwayGame class and then use an object of that type
    // here to control the game and relay what it says to the GUI.  This
    // assignment is more open-ended than the previous assignments.

    {

        //create random goals before game really starts
     
            RailwayGame gameMain(graph);
            Player p1;
            Player p2;
            int score_of_player;     
            p1.listOfGoals = gameMain.randomizeGoals(); //creates random goals for p1
            p2.listOfGoals = gameMain.randomizeGoals(); ///creates random goals for p2
//-------------------------------------------------------
               //While loop when games is not over 

        while(gameMain.isGameOver() == false){ 

            gui.updateMessage("Turn: Player 1");
            gui.updatePlayerStatus(1, gameMain.getScore(1), gameMain.getTracks(1), gameMain.getGoals(1));
            gui.updatePlayerStatus(2, gameMain.getScore(2), gameMain.getTracks(2), gameMain.getGoals(2));


            if(gameMain.getPlayerTurn() == 1){ //player 1 working
               
               vector<string> movementCity = gui.getNextMove(); // pass, close game, select edge -----update GUI in main
               if(movementCity[0].isequal("pass")){
        
                gameMain.updateTurn(); //changes getPlayerTurn value
                gameMain.Pass(p1);
                gui.updateMessage();
                gui.updateRailwaymap();

                        //NEED TO WRITE method in game class to change things    gameMain.updatePlayerStatus(p1,  score, moreTracks, std::vector<Goal*> goals); //need cities
                                        // gameMain.updateRailwayMap(Graph<std::string, int, int>* graph);
               }
               else if(movementCity[0].isequal("edge")){
                gameMain.updateTurn(); //changes getPlayerTurn value
                 gameMain.Edge(p1);
                 gui.updateMessage();
                 gui.updateRailwaymap();


              //NEED TO WRITE      gameMain.updatePlayerStatus(p1,  score, int tracks, std::vector<Goal*> goals);
               
                //add mnore tracks find the length of players personal map/graph and add amunt of  tracks
                // gui.updateRailwayMap(Graph<std::string, int, int>* graph);
               } 
                else if(movementCity[0].equals("close"/*might need function that tracks when clicking x button*/)){
                    gameMain.quit();
                }



            /*
            A vector containing just the string "pass", if the player has
            passed.
            2. A vector containing just the string "close", if the player has
            closed the window (meaning that the program should now stop and no
            further moves will be made).
            3.  A vector containing the string "edge" followed by the names of the
            two vertices between which that edge has been placed, if the player
            has selected an edge.
        */ 

               else{
               p1.updatePlayerGraph(movementCity);
               p1.updateScore();
                    if(gameMain.isGameOver()){
                        gui.updateMessage("game over gg");
                    }  
                  gameMain.updateTurn();
            }
          
            }



//------------------------------



            if(gameMain.getPlayerTurn() == 2){ //player 2 working
               vector<string> movementCity = gui.getNextMove(); // pass, close game, select edge -----update GUI in main
               if(movementCity[0].isequal("pass")){
        
                gameMain.updateTurn(); //changes getPlayerTurn value
                gameMain.Pass(p2);
                gui.updateMessage();
                gui.updateRailwaymap();

                        //NEED TO WRITE method in game class to change things    gameMain.updatePlayerStatus(p1,  score, moreTracks, std::vector<Goal*> goals); //need cities
                                        // gameMain.updateRailwayMap(Graph<std::string, int, int>* graph);
               }
               else if(movementCity[0].isequal("edge")){
                gameMain.updateTurn(); //changes getPlayerTurn value
                 gameMain.Edge(p2);
                 gui.updateMessage();
                 gui.updateRailwaymap();


              //NEED TO WRITE      gameMain.updatePlayerStatus(p1,  score, int tracks, std::vector<Goal*> goals);
               
                //add mnore tracks find the length of players personal map/graph and add amunt of  tracks
                // gui.updateRailwayMap(Graph<std::string, int, int>* graph);
               } 
                else if(movementCity[0].equals("close"/*might need function that tracks when clicking x button*/)){
                    gameMain.quit();
                }


               else{
               p1.updatePlayerGraph(movementCity);
               p1.updateScore();
                    if(gameMain.isGameOver()){
                        gui.updateMessage("game over gg");
                    }  
                  gameMain.updateTurn();
            }
          
            } 
            }

        }

    



    // TODO: Delete the following code.  It's just here at the start of the
    // assignment to make sure that you can see what the GUI looks like.  If we
    // didn't do something here (like wait for the user to press enter on the
    // console), then the main function would stop and the GUI would instantly
    // vanish.
  //  string deleteThisVariable;
   // getline(cin, deleteThisVariable);

    // Finally, clean up and exit successfully.
    delete graph;
    delete vertexPositions;
    return 0;
}
