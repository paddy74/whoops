#include "board.h"


namespace whoops
{

/* Constructors */

/**
 * @brief Construct a new Game Board:: Game Board object
 *
 */
GameBoard::GameBoard()
{

    this->Endgame = false;

    this->dieValue = 0;

    // Sets starting home counts to 0
    userHome = 0;
    greenHome = 0;
    redHome = 0;
    blueHome = 0;

}


/* Public methods */

std::string GameBoard::locationOutput(int x)
{
    // Will hold the output
    std::string str;

    // Determines whether to continue with computer pieces
    bool con = false;

    // userPieces
    if (userPieces[0].pos == x)
    {
        str += "P1";
        con = true;
    }
    if (userPieces[1].pos == x)
    {
        str += "P2";
        con = true;
    }
    if (userPieces[2].pos == x)
    {
        str += "P3";
        con = true;
    }
    if (userPieces[3].pos == x)
    {
        str += "P4";
        con = true;
    }
    // Exits this functions
    if (con == true) {return str;}

    // greenPieces
    if (greenPieces[0].pos == x)
    {
        str = "G1";
    }
    else if (greenPieces[1].pos == x)
    {
        str = "G2";
    }
    else if (greenPieces[2].pos == x)
    {
        str = "G3";
    }
    else if (greenPieces[3].pos == x)
    {
        str = "G4";
    }
    // redPieces
    else if (redPieces[0].pos == x)
    {
        str = "R1";
    }
    else if (redPieces[1].pos == x)
    {
        str = "R2";
    }
    else if (redPieces[2].pos == x)
    {
        str = "R3";
    }
    else if (redPieces[3].pos == x)
    {
        str = "R4";
    }

    // bluePieces
    else if (bluePieces[0].pos == x)
    {
        str = "B1";
    }
    else if (bluePieces[1].pos == x)
    {
        str = "B2";
    }
    else if (bluePieces[2].pos == x)
    {
        str = "B3";
    }
    else if (bluePieces[3].pos == x)
    {
        str = "B4";
    }

    // Empty location
    else
    {
        str = "*";
    }

    return str;
}

void GameBoard::updateBoardPegPositions()
{

    // Update userPieces
    this->userPieces[0].pos = this->user.getPos(1);
    this->userPieces[1].pos = this->user.getPos(2);
    this->userPieces[2].pos = this->user.getPos(3);
    this->userPieces[3].pos = this->user.getPos(4);

    // Holds temp values to adjust computer locations
    int tempArray[4];

    // Update greenPieces
    // Adjust by 10 and 30
    for (int i = 0; i <= 3; i++)
    {
        tempArray[i] = this->green.getPos(i+1);
        // If tempArray is off the board
        if (tempArray[i] == 0)
        {
            greenHome++;
        }
        // If tempArray is home
        else if (tempArray[i] > 40)
        {
            ;// Do nothing
        }
        // If tempArray is at 1-30
        else if ((tempArray[i] > 0) && (tempArray[i] < 31))
        {
            tempArray[i] += 10;
        }
        // If tempArray is a 31-40
        else if ((tempArray[i] < 41) && (tempArray[i] > 30))
        {
            tempArray[i] -= 30;
        }
        // Update greenPieces
        this->greenPieces[i].pos = tempArray[i];
    }

    // Update redPieces
    // Adjust by 20 and 20
    for (int i = 0; i <= 3; i++)
    {
        tempArray[i] = this->red.getPos(i+1);
        // If tempArray is off the board
        if (tempArray[i] == 0)
        {
            redHome++;
        }
        // If tempArray is home
        else if (tempArray[i] > 40)
        {
            ; // Do nothing
        }
        // If tempArray is at 1-30
        else if ((tempArray[i] > 0) && (tempArray[i] < 21))
        {
            tempArray[i] += 20;
        }
        // If tempArray is a 31-40
        else if ((tempArray[i] < 41) && (tempArray[i] > 20))
        {
            tempArray[i] -= 20;
        }

        // Update redPieces
        this->redPieces[i].pos = tempArray[i];
    }

    // Update bluePieces
    // Adjust by 30 and 10
    for (int i = 0; i <= 3; i++)
    {
        tempArray[i] = this->blue.getPos(i+1);
        // If tempArray is off the board
        if (tempArray[i] == 0)
        {
            blueHome++;
        }
        // If tempArray is home
        else if (tempArray[i] > 40)
        {
            ; // Do nothing
        }
        // If tempArray is at 1-30
        else if ((tempArray[i] > 0) && (tempArray[i] < 11))
        {
            tempArray[i] += 30;
        }
        // If tempArray is a 31-40
        else if ((tempArray[i] < 41) && (tempArray[i] > 10))
        {
            tempArray[i] -= 10;
        }
        // Update bluePieces
        this->bluePieces[i].pos = tempArray[i];
    }

}


/* Kill checks */

// Perform a killCheck in favor of userPieces
void GameBoard::userKillCheck()
{
    for (int u = 0; u <= 3; u++)
    {
        // Does not perform a kill check if the user piece is home or off board
        if ((this->userPieces[u].pos < 41) || (this->userPieces[u].pos > 0))
        {
            // green
            for (int g = 0; g <= 3; g++)
            {
                // Does not perform a kill check if the green piece is home or off board
                if ((this->greenPieces[g].pos < 41) || (this->greenPieces[g].pos > 0))
                {

                    if (this->userPieces[u] == this->greenPieces[g])
                    {
                        // Moves green peg off board
                        this->green.setPos(g+1, 0);
                    }
                }
            }

            // red
            for (int r = 0; r <= 3; r++)
            {
                // Does not perform a kill check if the red piece is home or off board
                if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))
                {
                    if (this->userPieces[u] == this->redPieces[r])
                    {
                        // Moves red peg off board
                        this->red.setPos(r+1, 0);
                    }
                }
            }

            // blue
            for (int b = 0; b <= 3; b++)
            {
                // Does not perform a kill check if the blue piece is home or off board
                if ((this->bluePieces[b].pos < 41) || (this->bluePieces[b].pos > 0))
                {
                    if (this->userPieces[u] == this->bluePieces[b])
                    {
                        // Moves blue peg off board
                        this->blue.setPos(b+1, 0);
                    }
                }
            }

        }
    }
}

// Perform a killCheck in favor of greenPieces
void GameBoard::greenKillCheck()
{
    for (int g = 0; g <= 3; g++)
    {
        // Does not perform a kill check if the blue piece is home or off board
        if ((this->greenPieces[g].pos < 41) || (this->greenPieces[g].pos > 0))
        {
            // user
            for (int u = 0; u <= 3; u++)
            {
                // Does not perform a kill check if the green piece is home or off board
                if ((this->userPieces[u].pos < 41) || (this->userPieces[u].pos > 0))
                {
                    if (this->greenPieces[g] == this->userPieces[u])
                    {
                        // Moves user peg off board
                        this->user.setPos(u+1, 0);
                    }
                }
            }

            // red
            for (int r = 0; r <= 3; r++)
            {
                // Does not perform a kill check if the red piece is home or off board
                if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))
                {
                    if (this->greenPieces[g] == this->redPieces[r])
                    {
                        // Moves red peg off board
                        this->red.setPos(r+1, 0);
                    }
                }
            }

            // blue
            for (int b = 0; b <= 3; b++)
            {
                // Does not perform a kill check if the blue piece is home or off board
                if ((this->bluePieces[b].pos < 41) || (this->bluePieces[b].pos > 0))
                {
                    if (this->greenPieces[g] == this->bluePieces[b])
                    {
                        // Moves blue peg off board
                        this->blue.setPos(b+1, 0);
                    }
                }
            }

        }

    }

    // Check against itself
    if (greenPieces[0] == greenPieces[1]) {this->green.setPos(2, 0);}
    if (greenPieces[0] == greenPieces[2]) {this->green.setPos(3, 0);}
    if (greenPieces[0] == greenPieces[3]) {this->green.setPos(4, 0);}

    if (greenPieces[1] == greenPieces[0]) {this->green.setPos(1, 0);}
    if (greenPieces[1] == greenPieces[2]) {this->green.setPos(3, 0);}
    if (greenPieces[1] == greenPieces[3]) {this->green.setPos(4, 0);}

    if (greenPieces[2] == greenPieces[1]) {this->green.setPos(2, 0);}
    if (greenPieces[2] == greenPieces[0]) {this->green.setPos(1, 0);}
    if (greenPieces[2] == greenPieces[3]) {this->green.setPos(4, 0);}

    if (greenPieces[3] == greenPieces[1]) {this->green.setPos(2, 0);}
    if (greenPieces[3] == greenPieces[2]) {this->green.setPos(3, 0);}
    if (greenPieces[3] == greenPieces[0]) {this->green.setPos(1, 0);}

}

// Perform a killCheck in favor of redPieces
void GameBoard::redKillCheck()
{
    for (int r = 0; r <= 3; r++)
    {
        // Does not perform a kill check if the blue piece is home or off board
        if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))
        {
            // green
            for (int g = 0; g <= 3; g++)
            {
                // Does not perform a kill check if the green piece is home or off board
                if ((this->greenPieces[g].pos < 41) || (this->greenPieces[g].pos > 0))
                {

                    if (this->redPieces[r] == this->greenPieces[g])
                    {
                        // Moves green peg off board
                        this->green.setPos(g+1, 0);
                    }
                }
            }

            // user
            for (int u = 0; u <= 3; u++)
            {
                // Does not perform a kill check if the green piece is home or off board
                if ((this->userPieces[u].pos < 41) || (this->userPieces[u].pos > 0))
                {
                    if (this->redPieces[r] == this->userPieces[u])
                    {
                        // Moves user peg off board
                        this->user.setPos(u+1, 0);
                    }
                }
            }

            // blue
            for (int b = 0; b <= 3; b++)
            {
                // Does not perform a kill check if the blue piece is home or off board
                if ((this->bluePieces[b].pos < 41) || (this->bluePieces[b].pos > 0))
                {
                    if (this->redPieces[r] == this->bluePieces[b])
                    {
                        // Moves blue peg off board
                        this->blue.setPos(b+1, 0);
                    }
                }
            }

        }

    }

    // Check against itself
    if (redPieces[0] == redPieces[1]) {this->red.setPos(2, 0);}
    if (redPieces[0] == redPieces[2]) {this->red.setPos(3, 0);}
    if (redPieces[0] == redPieces[3]) {this->red.setPos(4, 0);}

    if (redPieces[1] == redPieces[0]) {this->red.setPos(1, 0);}
    if (redPieces[1] == redPieces[2]) {this->red.setPos(3, 0);}
    if (redPieces[1] == redPieces[3]) {this->red.setPos(4, 0);}

    if (redPieces[2] == redPieces[1]) {this->red.setPos(2, 0);}
    if (redPieces[2] == redPieces[0]) {this->red.setPos(1, 0);}
    if (redPieces[2] == redPieces[3]) {this->red.setPos(4, 0);}

    if (redPieces[3] == redPieces[1]) {this->red.setPos(2, 0);}
    if (redPieces[3] == redPieces[2]) {this->red.setPos(3, 0);}
    if (redPieces[3] == redPieces[0]) {this->red.setPos(1, 0);}

}

// Perform a killCheck in favor of bluePieces
void GameBoard::blueKillCheck()
{
    for (int b = 0; b <= 3; b++)
    {
        // Does not perform a kill check if the blue piece is home or off board
        if ((this->bluePieces[b].pos < 41) || (this->bluePieces[b].pos > 0))
        {
            // green
            for (int g = 0; g <= 3; g++)
            {
                // Does not perform a kill check if the green piece is home or off board
                if ((this->greenPieces[g].pos < 41) || (this->greenPieces[g].pos > 0))
                {

                    if (this->bluePieces[b] == this->greenPieces[g])
                    {
                        // Moves green peg off board
                        this->green.setPos(g+1, 0);
                    }
                }
            }

            // red
            for (int r = 0; r <= 3; r++)
            {
                // Does not perform a kill check if the red piece is home or off board
                if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))
                {
                    if (this->bluePieces[b] == this->redPieces[r])
                    {
                        // Moves red peg off board
                        this->red.setPos(r+1, 0);
                    }
                }
            }

            // user
            for (int u = 0; u <= 3; u++)
            {
                // Does not perform a kill check if the green piece is home or off board
                if ((this->userPieces[u].pos < 41) || (this->userPieces[u].pos > 0))
                {
                    if (this->bluePieces[b] == this->userPieces[u])
                    {
                        // Moves user peg off board
                        this->user.setPos(u+1, 0);
                    }
                }
            }
        }

    }

    // Check against itself
    if (bluePieces[0] == bluePieces[1]) {this->blue.setPos(2, 0);}
    if (bluePieces[0] == bluePieces[2]) {this->blue.setPos(3, 0);}
    if (bluePieces[0] == bluePieces[3]) {this->blue.setPos(4, 0);}

    if (bluePieces[1] == bluePieces[0]) {this->blue.setPos(1, 0);}
    if (bluePieces[1] == bluePieces[2]) {this->blue.setPos(3, 0);}
    if (bluePieces[1] == bluePieces[3]) {this->blue.setPos(4, 0);}

    if (bluePieces[2] == bluePieces[1]) {this->blue.setPos(2, 0);}
    if (bluePieces[2] == bluePieces[0]) {this->blue.setPos(1, 0);}
    if (bluePieces[2] == bluePieces[3]) {this->blue.setPos(4, 0);}

    if (bluePieces[3] == bluePieces[1]) {this->blue.setPos(2, 0);}
    if (bluePieces[3] == bluePieces[2]) {this->blue.setPos(3, 0);}
    if (bluePieces[3] == bluePieces[0]) {this->blue.setPos(1, 0);}

}


/* Win checks */

bool GameBoard::userWinCheck()
{
    int winCount = 0;

    for (int i = 0; i <= 3; i++)
    {
        if (this->userPieces[i].pos > 40)
        {
            winCount++;
        }
    }

    if (winCount == 4)
    {
        gameOver(0);
        this->Endgame = true;
        return true;
    }
    else
    {
        winCount = 0;
        return false;
    }
}

bool GameBoard::greenWinCheck()
{
    int winCount = 0;

    for (int i = 0; i <= 3; i++)
    {
        if (this->greenPieces[i].pos > 40)
        {
            winCount++;
        }
    }

    if (winCount == 4)
    {
        gameOver(1);
        this->Endgame = true;
        return true;
    }
    else
    {
        winCount = 0;
        return false;
    }
}

bool GameBoard::redWinCheck()
{
    int winCount = 0;

    for (int i = 0; i <= 3; i++)
    {
        if (this->redPieces[i].pos > 40)
        {
            winCount++;
        }
    }

    if (winCount == 4)
    {
        gameOver(2);
        this->Endgame = true;
        return true;
    }
    else
    {
        winCount = 0;
        return false;
    }
}

bool GameBoard::blueWinCheck()
{
    int winCount = 0;

    for (int i = 0; i <= 3; i++)
    {
        if (this->bluePieces[i].pos > 40)
        {
            winCount++;
        }
    }

    if (winCount == 4)
    {
        gameOver(3);
        this->Endgame = true;
        return true;
    }
    else
    {
        winCount = 0;
        return false;
    }
}

// Game end function---------------------------------

void GameBoard::gameOver(int winner)
{
    // 100 new lines to clear the board
    for (int i = 0; i < 100; i++)
    {
        std::cout << '\n';
    }

    // Displays who won
    switch(winner)
    {
    case 0:
        std::cout << "\n Congratulations! You win!";
        break;
    case 1:
        std::cout << "\nGreen player won!";
        break;
    case 2:
        std::cout << "\nRed player won!";
        break;
    case 3:
        std::cout << "\nBlue player won!";
        break;
    default:
        break;
    }
}

// Game play function--------------------------------

void GameBoard::displayNewBoard()
{
    // Skip 100 lines to clear the screen
    for (int i = 0; i < 100; i++)
    {
        std::cout << '\n';
    }

    // 3 until board start
    // 4 between *
    // 38 to green

    // First line
    // With name of user and 'Green Corner'
    std::cout << std::setw(38) << std::left << userName << std::setw(16) << std::right << "Green Corner <G>" << std::endl;

    // Second line
    // With number of pegs of user and green
    std::string strU;
    for (int i = 0; i <=3; i++)
    {
        if (userPieces[i].pos == 0)
        {
            strU += "P";
        }
    }
    std::string strG;
    for (int i = 0; i <=3; i++)
    {
        if (greenPieces[i].pos == 0)
        {
            strG += "G";
        }
    }
    std::cout << std::setw(38) << std::left << strU << std::setw(16) << std::right << strG << std::endl;

    // Third line
    // Top row of locations
    std::cout << std::setw(4) << std::right << locationOutput(1)
        << std::setw(5) << std::right << locationOutput(2)
        << std::setw(5) << std::right << locationOutput(3)
        << std::setw(5) << std::right << locationOutput(4)
        << std::setw(5) << std::right << locationOutput(5)
        << std::setw(5) << std::right << locationOutput(6)
        << std::setw(5) << std::right << locationOutput(7)
        << std::setw(5) << std::right << locationOutput(8)
        << std::setw(5) << std::right << locationOutput(9)
        << std::setw(5) << std::right << locationOutput(10)
        << std::setw(5) << std::right << locationOutput(11)
        << std::endl;

    std::cout << std::endl;

    // Fourth line
    std::cout << std::setw(4) << std::right << locationOutput(40);
    // User home
    if (userPieces[0].pos > 40)
    {
        std::cout << std::setw(5) << std::right << "P1";
    }
    else {std::cout << std::setw(5) << std::right << "o";}
    // Green home
    if (greenPieces[0].pos > 40)
    {
        std::cout << std::setw(40) << std::right << "G1";
    }
    else {std::cout << std::setw(40) << std::right << "o";}
    // Location
    std::cout << std::setw(5) << std::right << locationOutput(12)
        << std::endl;

    std::cout << std::endl;

    // Fifth line
    std::cout << std::setw(4) << std::right << locationOutput(39);
    // User home
    if (userPieces[1].pos > 40)
    {
        std::cout << std::setw(10) << std::right << "P2";
    }
    else {std::cout << std::setw(10) << std::right << "o";}
    // Green home
    if (greenPieces[1].pos > 40)
    {
        std::cout << std::setw(30) << std::right << "G2";
    }
    else {std::cout << std::setw(30) << std::right << "o";}
    // Location
    std::cout << std::setw(10) << std::right << locationOutput(13)
        << std::endl;

    std::cout << std::endl;

    // Sixth line
    std::cout << std::setw(4) << std::right << locationOutput(38);
    // User home
    if (userPieces[2].pos > 40)
    {
        std::cout << std::setw(15) << std::right << "P3";
    }
    else {std::cout << std::setw(15) << std::right << "o";}
    // Green home
    if (greenPieces[2].pos > 40)
    {
        std::cout << std::setw(20) << std::right << "G3";
    }
    else {std::cout << std::setw(20) << std::right << "o";}
    // Location
    std::cout << std::setw(15) << std::right << locationOutput(14)
        << std::endl;

    std::cout << std::endl;
    // Seventh line
    std::cout << std::setw(4) << std::right << locationOutput(37);
    // User home
    if (userPieces[3].pos > 40)
    {
        std::cout << std::setw(20) << std::right << "P4";
    }
    else {std::cout << std::setw(20) << std::right << "o";}
    // Die border
    std::cout << std::setw(6) << std::right << "___";
    // Green home
    if (greenPieces[3].pos > 40)
    {
        std::cout << std::setw(4) << std::right << "G4";
    }
    else {std::cout << std::setw(4) << std::right << "o";}
    // Location
    std::cout << std::setw(20) << std::right << locationOutput(15)
        << std::endl;

    std::cout << std::endl;

    // Eighth line
    std::cout << std::setw(4) << std::right << locationOutput(36);
    // dieValue
    std::cout << std::setw(25) << std::right << this->dieValue;
    // Location
    std::cout << std::setw(25) << std::right << locationOutput(16)
        << std::endl;

    std::cout << std::endl;

    // Ninth line
    std::cout << std::setw(4) << std::right << locationOutput(35);
    // Blue home
    if (userPieces[3].pos > 40)
    {
        std::cout << std::setw(20) << std::right << "B4";
    }
    else {std::cout << std::setw(20) << std::right << "o";}
    // Die border
    std::cout << std::setw(6) << std::right << "___";
    // Red home
    if (greenPieces[3].pos > 40)
    {
        std::cout << std::setw(4) << std::right << "R4";
    }
    else {std::cout << std::setw(4) << std::right << "o";}
    // Location
    std::cout << std::setw(20) << locationOutput(17)
        << std::endl;

    std::cout << std::endl;
    // Tenth line
    std::cout << std::setw(4) << std::right << locationOutput(34);
    // Blue home
    if (bluePieces[2].pos > 40)
    {
        std::cout << std::setw(15) << std::right << "B3";
    }
    else {std::cout << std::setw(15) << std::right << "o";}
    // Red home
    if (redPieces[2].pos > 40)
    {
        std::cout << std::setw(20) << std::right << "R3";
    }
    else {std::cout << std::setw(20) << std::right << "o";}
    // Location
    std::cout << std::setw(15) << locationOutput(18)
        << std::endl;

    std::cout << std::endl;

    // Eleventh line
    std::cout << std::setw(4) << std::right << locationOutput(33);
    // Blue home
    if (bluePieces[1].pos > 40)
    {
        std::cout << std::setw(10) << std::right << "B2";
    }
    else {std::cout << std::setw(10) << std::right << "o";}
    // Red home
    if (redPieces[1].pos > 40)
    {
        std::cout << std::setw(30) << std::right << "R2";
    }
    else {std::cout << std::setw(30) << std::right << "o";}
    // Location
    std::cout << std::setw(10) << locationOutput(19)
        << std::endl;

    std::cout << std::endl;

    // Twelfth line
    std::cout << std::setw(4) << std::right << locationOutput(32);
    // Blue home
    if (bluePieces[0].pos > 40)
    {
        std::cout << std::setw(5) << std::right << "B1";
    }
    else {std::cout << std::setw(5) << std::right << "o";}
    // Red home
    if (redPieces[0].pos > 40)
    {
        std::cout << std::setw(40) << std::right << "R1";
    }
    else {std::cout << std::setw(40) << std::right << "o";}
    // Location
    std::cout << std::setw(5) << std::right << locationOutput(20)
        << std::endl;

    std::cout << std::endl;

    // Thirteenth line
    // Top row of locations
    std::cout << std::setw(4) << std::right << locationOutput(31)
        << std::setw(5) << std::right << locationOutput(30)
        << std::setw(5) << std::right << locationOutput(29)
        << std::setw(5) << std::right << locationOutput(28)
        << std::setw(5) << std::right << locationOutput(27)
        << std::setw(5) << std::right << locationOutput(26)
        << std::setw(5) << std::right << locationOutput(25)
        << std::setw(5) << std::right << locationOutput(24)
        << std::setw(5) << std::right << locationOutput(23)
        << std::setw(5) << std::right << locationOutput(22)
        << std::setw(5) << std::right << locationOutput(21)
        << std::endl;

    // Fourteenth line
    // With name of 'Blue Corner' and 'Red Corner'
    std::cout << std::setw(38) << std::left << "Blue Corner <B>" << std::setw(16) << std::right << "Red Corner <R>" << std::endl;

    // Fifteenth line
    // With number of pegs of blue and red
    std::string strB;
    for (int i = 0; i <=3; i++)
    {
        if (bluePieces[i].pos == 0)
        {
            strB += "B";
        }
    }
    std::string strR;
    for (int i = 0; i <=3; i++)
    {
        if (redPieces[i].pos == 0)
        {
            strR += "R";
        }
    }
    std::cout << std::setw(38) << std::left << strB << std::setw(16) << std::right << strR << std::endl;

}

void GameBoard::play()
{
    // Take the player's name
    std::cout << "Enter your name" << std::endl;
    std::cin >> this->userName;

    // Welcome the player
    for (int i = 0; i < 20; i++) {std::cout << '\n';}
    std::cout << "Welcome " << userName << "!"
        << "\nPress enter to begin the game!";
    std::cin.clear();
    std::cin.ignore();
    std::cin.ignore();

    while(this->Endgame == false)
    {
        /* Player turn */
        // Show board updated with computer turns
        this->dieValue = 0;
        displayNewBoard();

        // Wait for user input before performing user turn
        std::cout << "\nIt is your turn."
            << "\nPress enter to roll the dice.";
        std::cin.clear();
        std::cin.ignore();

        // Roll dice
        this->dieValue = this->user.rollDice();
        // Display board updated with die value
        displayNewBoard();
        std::cout << "\nYou rolled a " << this->dieValue
            << "!\nPress enter to continue with your turn.";
        std::cin.clear();
        std::cin.ignore();

        // Perform turn
        this->user.turnHuman();

        // Update board with turn results
        updateBoardPegPositions();
        userKillCheck();
        if (userWinCheck() == true) {return;}

        /* Green turn */
        std::cout << "\nIt is green player's turn.";//
        this->dieValue = this->green.rollDice();
        std::cout << "\nGreen rolled a " << this->dieValue;//

        // Perform turn
        this->green.turnComputer();

        //  Update board with turn results
        updateBoardPegPositions();
        greenKillCheck();
        if (greenWinCheck() == true) {return;}

        /* Red turn */
        std::cout << "\nIt is red player's turn.";//
        this->dieValue = this->red.rollDice();
        std::cout << "\nRed rolled a " << this->dieValue;//

        // Perform turn
        this->red.turnComputer();

        // Update board with turn results
        updateBoardPegPositions();
        redKillCheck();
        if (redWinCheck() == true) {return;}

        /* Blue turn */
        std::cout << "\nIt is blue player's turn.";//
        this->dieValue = this->blue.rollDice();
        std::cout << "\nBlue rolled a " << this->dieValue;//

        // Perform turn
        this->blue.turnComputer();

        // Update board with turn results
        updateBoardPegPositions();
        redKillCheck();
        if (blueWinCheck() == true) {return;}

    // Loop will exit when
    }
}

}
