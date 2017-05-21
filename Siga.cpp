// Siga.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Siga.hpp"



Siga::Siga()
{
 //   srand (time(0));

    player = 1;           // who starts first?
    totalTurns = 0;

    // new player setup
    numberPlayers = 2;
    playerType[1] = 1;  // playerType[player] is human (1)
    playerType[2] = 0;  // playerType[player] is computer (0)
    
        pos[0] = 1;
        pos[2] = 1;
        pos[2] = 1;
        pos[3] = 0;
        pos[4] = 0;
        pos[5] = 0;
        pos[6] = 2;
        pos[7] = 2;
        pos[8] = 2;
}

void Siga::drawBoard()
{

    std::cout   << std::endl
                << pos[0] << " │ " << pos[1] << " │ " << pos[2]
                << "\n──┼───┼──\n"
                << pos[3] << " │ " << pos[4] << " │ " << pos[5]
                << "\n──┼───┼──\n"
                << pos[6] << " │ " << pos[7] << " │ " << pos[8]
                << std::endl;

}

void Siga::printTurn()
{
    std::cout << "\nPlayer " << player << "'s turn.\n";
}

void Siga::nextTurn()
{
    totalTurns++;

    if (++player > numberPlayers){
        player = 1;
}
}

bool Siga::playerHuman()
{
    return playerType[player];
}

void Siga::humanMove()
{

    std::cout << "\nEnter your piece to move: ";
    int move;

        std::cin >> move;
        move--;     // so user can enter 1-9 instead of 0-8

    std::cout << "\nEnter your destination: ";
    int des;

        std::cin >> des;
        des--;     // so user can enter 1-9 instead of 0-8

if(pos[des]!=0 || pos[move]!=1){
    std::cerr << "Error Invalid Entry";
    humanMove();
    return;
}

    pos[des] = 1;
    pos[move] = 0;
    return;
}

void Siga::computerMove()
{

//Currently this code contains only a dummy computer opponent
//Required to be improved to be implemented with uniformed search techniques
    int move = 0;
    int des =0;

    for(int i=0; i<=8; i++){
        if(pos[i] == 2){
            move = i;
        }
}
   for(int i=0; i<=8; i++){
        if(pos[i] ==0){
            des = i;
        }
}

    pos[des] = 2;
    pos[move] = 0;
}

bool Siga::Winner()
{
    //Winners Bools
    bool hum_Win = false;
    bool comp_Win = false;

    //Check Horizontal
   for(int i =0; i<=6; i=i+3){
       if(pos[i]==1 && pos[i+1]==1 && pos[i+2]==1) hum_Win = true;
       if(pos[i]==2 && pos[i+1]==2 && pos[i+2]==2) comp_Win = true;
   }

   // Check Vertical
   for(int i =0; i<=2; i++){
       if(pos[i]==1 && pos[i+3]==1 && pos[i+6]==1) hum_Win = true;
       if(pos[i]==2 && pos[i+3]==2 && pos[i+6]==2) comp_Win = true;
   }

   //Check Left Diagonal
   if(pos[0] ==1 && pos[4]==1 && pos[8]==1) hum_Win = true;
   if(pos[0] ==2 && pos[4]==2 && pos[8]==2) comp_Win = true;

   //Check Right Diagonal
   if(pos[2] ==1 && pos[4]==1 && pos[6]==1) hum_Win = true;
   if(pos[2] ==2 && pos[4]==2 && pos[6]==2) comp_Win = true;


if(hum_Win && totalTurns >2){
            std::cout << "\n Human player won \n";
            return 1;    // return winner true
}
if(comp_Win && totalTurns >2){
            std::cout << "\n Computer player won \n";
            return 1;    // return winner true
}
    return 0;   // winner false
}


