#pragma once

#include <iomanip>

#include "peg.h"


namespace whoops
{

/**
 * @brief Contains the game board and conducts gameplay operations
 *
 */
class GameBoard
{

public:

    // Creates an object representing the user
    player user;
    std::string userName;
    // Creates an object for each computer player
    player green, red, blue;

    // Ends the game when true
    bool Endgame;

    // Creates pegs to represent the pegs of the user object
    peg userPieces[4];
    // Creates pegs to represent the pegs of the computer objects
    peg greenPieces[4];
    peg redPieces[4];
    peg bluePieces[4];

    /* Constructors */

    // Empty constructor. Assigns values 1-40 to locations array
    GameBoard();

    // Outputs the pegs at position k of the locations array
    std::string locationOutput(int x);
    // Updates the board with the peg positions of each player
    void updateBoardPegPositions();

    // Checks if a peg is on another player's peg
    void userKillCheck();
    void greenKillCheck();
    void redKillCheck();
    void blueKillCheck();

    // Holds number of pegs a player has at home
    int userHome;
    int greenHome;
    int redHome;
    int blueHome;

    // Checks if all of a player's pegs are at home
    bool userWinCheck();
    bool greenWinCheck();
    bool redWinCheck();
    bool blueWinCheck();

    // Ends the game in favor of the specified winner
    void gameOver(int winner);

    // Holds the rolled dice
    int dieValue;
    //Displays the board
    void displayNewBoard();
    //Rotates through player turns
    void play();
};

}
