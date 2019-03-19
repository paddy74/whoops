#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>


namespace whoops
{

// Class peg
class peg
{

// Begin public
public:

    // Holds position of peg
    int pos;
    // Holds number of peg
    std::string num;

    // Constructor
    peg();

    // Adds rh to pos
    // if rh is 0 changes pos to 0
    void move(int rh);
    // Compares the pos of two pegs
    bool operator ==(const peg& rh);

};


// Class player
class player
{

// Begin public
public:

    // Each player has 4 pegs
    peg p1, p2, p3, p4;

    // Finds the first peg at start
    int startFinder();
    // Returns number of pegs at position 0
    int startCount();
    // Checks if a given peg is at start
    bool startTest(int whichPeg);

    // Returns true if specified peg is home
    bool homeTest(int whichPeg);

    // Increments specified peg position by rh
    void jump(int whichPeg, int rh);

    // Sets specified peg position to 0
    void setPos(int whichPeg, int rh);
    // Returns pos of specified peg
    int getPos(int whichPeg);

    // Holds the result of rollDice()
    int rollDice();
    // Allow board to see the rollDice result
    int dieValue;

    // Performs the user's turn
    void turnHuman();

    // Randomly selects a peg choice for computer
    int choiceFinder();
    // Performs a computer turn
    void turnComputer();
};

}
