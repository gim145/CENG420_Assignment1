// Siga.h
#ifndef Siga_H
#define Siga_H

class Siga
{
private:
    int pos[9];             // board position
    int player;             // current player
    int totalTurns;         // how many turns so far?
    int numberPlayers;      // 1 to 20
    bool playerType[20];    // player #, 0 = comp, 1 = human
public:
    Siga();
    void printTurn();
    bool playerHuman();
    void humanMove();
    void computerMove();
    void drawBoard();
    bool Winner();
    void nextTurn();

};

#endif // Siga_H 