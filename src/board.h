/********************************************
 * CS 250: Problem Solving & Programming II
 *
 *       Author: Patrick T Cox
 * Date Created: 22 November 2015
 * Date Updated: 24 November 2015
 *      Project: Final Project
 *         File: board.h
 *
 * Description: Runs a simulation of the board
 * game "Sorry!" with 3 ai and 1 human
 *  
 *******************************************/

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

//==========================================================================================
//==========================================================================================

//Libraries
#include <iomanip>
#include "peg.h"

//==========================================================================================
//==========================================================================================
//ADT member functions
//class board
 
/*------------------------------------------
 * board
 *
 * Contains the game board and gameplay operations
 */
class board
{

//Begin public
public:

    //Creates an object representing the user
    player user;
    std::string userName;
    //Creates an object for each computer player
    player green, red, blue;

    //Ends the game when true
    bool Endgame;

    //Creates pegs to represent the pegs of the user object
    peg userPieces[4];
    //Creates pegs to represent the pegs of the computer objects
    peg greenPieces[4];
    peg redPieces[4];
    peg bluePieces[4];

    //Constructor
    //Assigns values 1-40 to locations array
    board();

    //Outputs the pegs at position k of the locations array
    std::string locationOutput(int x);
    //Updates the board with the peg positions of each player
    void updateBoardPegPositions();

    //Checks if a peg is on another player's peg
    void userKillCheck();
    void greenKillCheck();
    void redKillCheck();
    void blueKillCheck();

    //Holds number of pegs a player has at home
    int userHome;
    int greenHome;
    int redHome;
    int blueHome;

    //Checks if all of a player's pegs are at home
    bool userWinCheck();
    bool greenWinCheck();
    bool redWinCheck();
    bool blueWinCheck();

    //Ends the game in favor of the specified winner
    void gameOver(int winner);

    //Holds the rolled dice
    int dieValue;
    //Displays the board
    void displayNewBoard();
    //Rotates through player turns
    void play();

};//End of ADT board

//==========================================================================================
//==========================================================================================

#endif // BOARD_H_INCLUDED
