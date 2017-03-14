//Problem Solving and Programming II
//Name: Patrick T Cox
//Date: 24 November 2015
//Final Project
//board.cpp

//Program Directives
#include "peg.h"
#include "board.h"

//name space
using namespace std;//standard

//==========================================================================================
//==========================================================================================
//ADT member functions
//class board

//Constructor board()
board :: board()
{

    this->Endgame = false;

    this->dieValue = 0;

    //Sets starting home counts to 0
    userHome = 0;
    greenHome = 0;
    redHome = 0;
    blueHome = 0;

}//End of board :: board()

std::string board :: locationOutput(int x)
{
    //Will hold the output
    string str;

    //Determines whether to continue with computer pieces
    bool con = false;

    //userPieces
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
    //Exits this functions
    if (con == true) {return str;}

    //greenPieces
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
    //redPieces
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

    //bluePieces
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

    //Empty location
    else
    {
        str = "*";
    }

    return str;
}

void board :: updateBoardPegPositions()
{

    //Update userPieces
    this->userPieces[0].pos = this->user.getPos(1);
    this->userPieces[1].pos = this->user.getPos(2);
    this->userPieces[2].pos = this->user.getPos(3);
    this->userPieces[3].pos = this->user.getPos(4);

    //Holds temp values to adjust computer locations
    int tempArray[4];

    //Update greenPieces--------------------------------
    //Adjust by 10 and 30
    for (int i = 0; i <= 3; i++)
    {
        tempArray[i] = this->green.getPos(i+1);
        //If tempArray is off the board
        if (tempArray[i] == 0)
        {
            greenHome++;
        }
        //If tempArray is home
        else if (tempArray[i] > 40)
        {
            ;//Do nothing
        }
        //If tempArray is at 1-30
        else if ((tempArray[i] > 0) && (tempArray[i] < 31))
        {
            tempArray[i] += 10;
        }
        //If tempArray is a 31-40
        else if ((tempArray[i] < 41) && (tempArray[i] > 30))
        {
            tempArray[i] -= 30;
        }
        //Update greenPieces
        this->greenPieces[i].pos = tempArray[i];
    }//End for loop

    //Update redPieces----------------------------------
    //Adjust by 20 and 20
    for (int i = 0; i <= 3; i++)
    {
        tempArray[i] = this->red.getPos(i+1);
        //If tempArray is off the board
        if (tempArray[i] == 0)
        {
            redHome++;
        }
        //If tempArray is home
        else if (tempArray[i] > 40)
        {
            ;//Do nothing
        }
        //If tempArray is at 1-30
        else if ((tempArray[i] > 0) && (tempArray[i] < 21))
        {
            tempArray[i] += 20;
        }
        //If tempArray is a 31-40
        else if ((tempArray[i] < 41) && (tempArray[i] > 20))
        {
            tempArray[i] -= 20;
        }
        //Update redPieces
        this->redPieces[i].pos = tempArray[i];
    }//End for loop

    //Update bluePieces---------------------------------
    //Adjust by 30 and 10
    for (int i = 0; i <= 3; i++)
    {
        tempArray[i] = this->blue.getPos(i+1);
        //If tempArray is off the board
        if (tempArray[i] == 0)
        {
            blueHome++;
        }
        //If tempArray is home
        else if (tempArray[i] > 40)
        {
            ;//Do nothing
        }
        //If tempArray is at 1-30
        else if ((tempArray[i] > 0) && (tempArray[i] < 11))
        {
            tempArray[i] += 30;
        }
        //If tempArray is a 31-40
        else if ((tempArray[i] < 41) && (tempArray[i] > 10))
        {
            tempArray[i] -= 10;
        }
        //Update bluePieces
        this->bluePieces[i].pos = tempArray[i];
    }//End for loop

}//End of void board :: updateBoardPegPositions()

//Kill checks---------------------------------------

//Perform a killCheck in favor of userPieces
void board :: userKillCheck()
{
    for (int u = 0; u <= 3; u++)
    {
        //Does not perform a kill check if the user piece is home or off board
        if ((this->userPieces[u].pos < 41) || (this->userPieces[u].pos > 0))
        {
            //green
            for (int g = 0; g <= 3; g++)
            {
                //Does not perform a kill check if the green piece is home or off board
                if ((this->greenPieces[g].pos < 41) || (this->greenPieces[g].pos > 0))
                {

                    if (this->userPieces[u] == this->greenPieces[g])
                    {
                        //Moves green peg off board
                        this->green.setPos(g+1, 0);
                    }
                }
            }//End of green for

            //red
            for (int r = 0; r <= 3; r++)
            {
                //Does not perform a kill check if the red piece is home or off board
                if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))
                {
                    if (this->userPieces[u] == this->redPieces[r])
                    {
                        //Moves red peg off board
                        this->red.setPos(r+1, 0);
                    }
                }
            }//End of red for

            //blue
            for (int b = 0; b <= 3; b++)
            {
                //Does not perform a kill check if the blue piece is home or off board
                if ((this->bluePieces[b].pos < 41) || (this->bluePieces[b].pos > 0))
                {
                    if (this->userPieces[u] == this->bluePieces[b])
                    {
                        //Moves blue peg off board
                        this->blue.setPos(b+1, 0);
                    }
                }
            }//End of blue for

        }//End of if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))

    }//End of red for
}//End of void board :: userKillCheck()

//Perform a killCheck in favor of greenPieces
void board :: greenKillCheck()
{
    for (int g = 0; g <= 3; g++)
    {
        //Does not perform a kill check if the blue piece is home or off board
        if ((this->greenPieces[g].pos < 41) || (this->greenPieces[g].pos > 0))
        {
            //user
            for (int u = 0; u <= 3; u++)
            {
                //Does not perform a kill check if the green piece is home or off board
                if ((this->userPieces[u].pos < 41) || (this->userPieces[u].pos > 0))
                {
                    if (this->greenPieces[g] == this->userPieces[u])
                    {
                        //Moves user peg off board
                        this->user.setPos(u+1, 0);
                    }
                }
            }//End of user for

            //red
            for (int r = 0; r <= 3; r++)
            {
                //Does not perform a kill check if the red piece is home or off board
                if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))
                {
                    if (this->greenPieces[g] == this->redPieces[r])
                    {
                        //Moves red peg off board
                        this->red.setPos(r+1, 0);
                    }
                }
            }//End of red for

            //blue
            for (int b = 0; b <= 3; b++)
            {
                //Does not perform a kill check if the blue piece is home or off board
                if ((this->bluePieces[b].pos < 41) || (this->bluePieces[b].pos > 0))
                {
                    if (this->greenPieces[g] == this->bluePieces[b])
                    {
                        //Moves blue peg off board
                        this->blue.setPos(b+1, 0);
                    }
                }
            }//End of blue for

        }//End of if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))

    }//End of red for

    //Check against itself
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

}//End of void board :: greenKillCheck()

//Perform a killCheck in favor of redPieces
void board :: redKillCheck()
{
    for (int r = 0; r <= 3; r++)
    {
        //Does not perform a kill check if the blue piece is home or off board
        if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))
        {
            //green
            for (int g = 0; g <= 3; g++)
            {
                //Does not perform a kill check if the green piece is home or off board
                if ((this->greenPieces[g].pos < 41) || (this->greenPieces[g].pos > 0))
                {

                    if (this->redPieces[r] == this->greenPieces[g])
                    {
                        //Moves green peg off board
                        this->green.setPos(g+1, 0);
                    }
                }
            }//End of green for

            //user
            for (int u = 0; u <= 3; u++)
            {
                //Does not perform a kill check if the green piece is home or off board
                if ((this->userPieces[u].pos < 41) || (this->userPieces[u].pos > 0))
                {
                    if (this->redPieces[r] == this->userPieces[u])
                    {
                        //Moves user peg off board
                        this->user.setPos(u+1, 0);
                    }
                }
            }//End of user for

            //blue
            for (int b = 0; b <= 3; b++)
            {
                //Does not perform a kill check if the blue piece is home or off board
                if ((this->bluePieces[b].pos < 41) || (this->bluePieces[b].pos > 0))
                {
                    if (this->redPieces[r] == this->bluePieces[b])
                    {
                        //Moves blue peg off board
                        this->blue.setPos(b+1, 0);
                    }
                }
            }//End of blue for

        }//End of if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))

    }//End of red for

    //Check against itself
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

}//End of void board :: redKillCheck()

//Perform a killCheck in favor of bluePieces
void board :: blueKillCheck()
{
    for (int b = 0; b <= 3; b++)
    {
        //Does not perform a kill check if the blue piece is home or off board
        if ((this->bluePieces[b].pos < 41) || (this->bluePieces[b].pos > 0))
        {
            //green
            for (int g = 0; g <= 3; g++)
            {
                //Does not perform a kill check if the green piece is home or off board
                if ((this->greenPieces[g].pos < 41) || (this->greenPieces[g].pos > 0))
                {

                    if (this->bluePieces[b] == this->greenPieces[g])
                    {
                        //Moves green peg off board
                        this->green.setPos(g+1, 0);
                    }
                }
            }//End of green for

            //red
            for (int r = 0; r <= 3; r++)
            {
                //Does not perform a kill check if the red piece is home or off board
                if ((this->redPieces[r].pos < 41) || (this->redPieces[r].pos > 0))
                {
                    if (this->bluePieces[b] == this->redPieces[r])
                    {
                        //Moves red peg off board
                        this->red.setPos(r+1, 0);
                    }
                }
            }//End of red for

            //user
            for (int u = 0; u <= 3; u++)
            {
                //Does not perform a kill check if the green piece is home or off board
                if ((this->userPieces[u].pos < 41) || (this->userPieces[u].pos > 0))
                {
                    if (this->bluePieces[b] == this->userPieces[u])
                    {
                        //Moves user peg off board
                        this->user.setPos(u+1, 0);
                    }
                }
            }//End of user for
        }//End of if ((this->bluePieces[b].pos < 41) || (this->bluePieces[b].pos > 0))

    }//End of blue for

    //Check against itself
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

}//End of void board :: blueKillCheck()

//Win checks----------------------------------------

bool board :: userWinCheck()
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

bool board :: greenWinCheck()
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

bool board :: redWinCheck()
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

bool board :: blueWinCheck()
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

//Game end function---------------------------------

void board :: gameOver(int winner)
{
    //100 new lines to clear the board
    for (int i = 0; i < 100; i++)
    {
        cout << '\n';
    }

    //Displays who won
    switch(winner)
    {
    case 0:
        cout << "\n Congratulations! You win!";
        break;
    case 1:
        cout << "\nGreen player won!";
        break;
    case 2:
        cout << "\nRed player won!";
        break;
    case 3:
        cout << "\nBlue player won!";
        break;
    default:
        break;
    }
}

//Game play function--------------------------------

void board :: displayNewBoard()
{
    //Skip 100 lines to clear the screen
    for (int i = 0; i < 100; i++)
    {
        cout << '\n';
    }

    //3 until board start
    //4 between *
    //38 to green

//--First line
    //With name of user and 'Green Corner'
    cout << setw(38) << left << userName << setw(16) << right << "Green Corner <G>" << endl;

//--Second line
    //With number of pegs of user and green
    string strU;
    for (int i = 0; i <=3; i++)
    {
        if (userPieces[i].pos == 0)
        {
            strU += "P";
        }
    }
    string strG;
    for (int i = 0; i <=3; i++)
    {
        if (greenPieces[i].pos == 0)
        {
            strG += "G";
        }
    }
    cout << setw(38) << left << strU << setw(16) << right << strG << endl;

//--Third line
    //Top row of locations
    cout << setw(4) << right << locationOutput(1)
        << setw(5) << right << locationOutput(2)
        << setw(5) << right << locationOutput(3)
        << setw(5) << right << locationOutput(4)
        << setw(5) << right << locationOutput(5)
        << setw(5) << right << locationOutput(6)
        << setw(5) << right << locationOutput(7)
        << setw(5) << right << locationOutput(8)
        << setw(5) << right << locationOutput(9)
        << setw(5) << right << locationOutput(10)
        << setw(5) << right << locationOutput(11)
        << endl;

    cout << endl;
//--Fourth line
    cout << setw(4) << right << locationOutput(40);
    //User home
    if (userPieces[0].pos > 40)
    {
        cout << setw(5) << right << "P1";
    }
    else {cout << setw(5) << right << "o";}
    //Green home
    if (greenPieces[0].pos > 40)
    {
        cout << setw(40) << right << "G1";
    }
    else {cout << setw(40) << right << "o";}
    //Location
    cout << setw(5) << right << locationOutput(12)
        << endl;

    cout << endl;
//--Fifth line
    cout << setw(4) << right << locationOutput(39);
    //User home
    if (userPieces[1].pos > 40)
    {
        cout << setw(10) << right << "P2";
    }
    else {cout << setw(10) << right << "o";}
    //Green home
    if (greenPieces[1].pos > 40)
    {
        cout << setw(30) << right << "G2";
    }
    else {cout << setw(30) << right << "o";}
    //Location
    cout << setw(10) << right << locationOutput(13)
        << endl;

    cout << endl;
//--Sixth line
    cout << setw(4) << right << locationOutput(38);
    //User home
    if (userPieces[2].pos > 40)
    {
        cout << setw(15) << right << "P3";
    }
    else {cout << setw(15) << right << "o";}
    //Green home
    if (greenPieces[2].pos > 40)
    {
        cout << setw(20) << right << "G3";
    }
    else {cout << setw(20) << right << "o";}
    //Location
    cout << setw(15) << right << locationOutput(14)
        << endl;

    cout << endl;
//--Seventh line
    cout << setw(4) << right << locationOutput(37);
    //User home
    if (userPieces[3].pos > 40)
    {
        cout << setw(20) << right << "P4";
    }
    else {cout << setw(20) << right << "o";}
    //Die border
    cout << setw(6) << right << "___";
    //Green home
    if (greenPieces[3].pos > 40)
    {
        cout << setw(4) << right << "G4";
    }
    else {cout << setw(4) << right << "o";}
    //Location
    cout << setw(20) << right << locationOutput(15)
        << endl;

    cout << endl;
//--Eighth line
    cout << setw(4) << right << locationOutput(36);
    //dieValue
    cout << setw(25) << right << this->dieValue;
    //Location
    cout << setw(25) << right << locationOutput(16)
        << endl;

    cout << endl;
//--Ninth line
    cout << setw(4) << right << locationOutput(35);
    //Blue home
    if (userPieces[3].pos > 40)
    {
        cout << setw(20) << right << "B4";
    }
    else {cout << setw(20) << right << "o";}
    //Die border
    cout << setw(6) << right << "___";
    //Red home
    if (greenPieces[3].pos > 40)
    {
        cout << setw(4) << right << "R4";
    }
    else {cout << setw(4) << right << "o";}
    //Location
    cout << setw(20) << locationOutput(17)
        << endl;

    cout << endl;
//--Tenth line
    cout << setw(4) << right << locationOutput(34);
    //Blue home
    if (bluePieces[2].pos > 40)
    {
        cout << setw(15) << right << "B3";
    }
    else {cout << setw(15) << right << "o";}
    //Red home
    if (redPieces[2].pos > 40)
    {
        cout << setw(20) << right << "R3";
    }
    else {cout << setw(20) << right << "o";}
    //Location
    cout << setw(15) << locationOutput(18)
        << endl;

    cout << endl;
//--Eleventh line
    cout << setw(4) << right << locationOutput(33);
    //Blue home
    if (bluePieces[1].pos > 40)
    {
        cout << setw(10) << right << "B2";
    }
    else {cout << setw(10) << right << "o";}
    //Red home
    if (redPieces[1].pos > 40)
    {
        cout << setw(30) << right << "R2";
    }
    else {cout << setw(30) << right << "o";}
    //Location
    cout << setw(10) << locationOutput(19)
        << endl;

    cout << endl;
//--Twelfth line
    cout << setw(4) << right << locationOutput(32);
    //Blue home
    if (bluePieces[0].pos > 40)
    {
        cout << setw(5) << right << "B1";
    }
    else {cout << setw(5) << right << "o";}
    //Red home
    if (redPieces[0].pos > 40)
    {
        cout << setw(40) << right << "R1";
    }
    else {cout << setw(40) << right << "o";}
    //Location
    cout << setw(5) << right << locationOutput(20)
        << endl;

    cout << endl;
//--Thirteenth line
    //Top row of locations
    cout << setw(4) << right << locationOutput(31)
        << setw(5) << right << locationOutput(30)
        << setw(5) << right << locationOutput(29)
        << setw(5) << right << locationOutput(28)
        << setw(5) << right << locationOutput(27)
        << setw(5) << right << locationOutput(26)
        << setw(5) << right << locationOutput(25)
        << setw(5) << right << locationOutput(24)
        << setw(5) << right << locationOutput(23)
        << setw(5) << right << locationOutput(22)
        << setw(5) << right << locationOutput(21)
        << endl;

//--Fourteenth line
    //With name of 'Blue Corner' and 'Red Corner'
    cout << setw(38) << left << "Blue Corner <B>" << setw(16) << right << "Red Corner <R>" << endl;

//--Fifteenth line
    //With number of pegs of blue and red
    string strB;
    for (int i = 0; i <=3; i++)
    {
        if (bluePieces[i].pos == 0)
        {
            strB += "B";
        }
    }
    string strR;
    for (int i = 0; i <=3; i++)
    {
        if (redPieces[i].pos == 0)
        {
            strR += "R";
        }
    }
    cout << setw(38) << left << strB << setw(16) << right << strR << endl;

}//End of void board :: displayNewBoard()

void board :: play()
{
    //Take the player's name
    cout << "Enter your name" << endl;
    cin >> this->userName;

    //Welcome the player
    for (int i = 0; i < 20; i++) {cout << '\n';}
    cout << "Welcome " << userName << "!"
        << "\nPress enter to begin the game!";
    cin.clear();
    cin.ignore();
    cin.ignore();

    while(this->Endgame == false)
    {
//------user turn
        //Show board updated with computer turns
        this->dieValue = 0;
        displayNewBoard();

        //Wait for user input before performing user turn
        cout << "\nIt is your turn."
            << "\nPress enter to roll the dice.";
        cin.clear();
        cin.ignore();

        //Roll dice
        this->dieValue = this->user.rollDice();
        //Display board updated with die value
        displayNewBoard();
        cout << "\nYou rolled a " << this->dieValue
            << "!\nPress enter to continue with your turn.";
        cin.clear();
        cin.ignore();

        //Perform turn
        this->user.turnHuman();

        //Update board with turn results
        updateBoardPegPositions();
        userKillCheck();
        if (userWinCheck() == true) {return;}

//------green turn
        cout << "\nIt is green player's turn.";//
        this->dieValue = this->green.rollDice();
        cout << "\nGreen rolled a " << this->dieValue;//

        //Perform turn
        this->green.turnComputer();

        //Update board with turn results
        updateBoardPegPositions();
        greenKillCheck();
        if (greenWinCheck() == true) {return;}

//------red turn
        cout << "\nIt is red player's turn.";//
        this->dieValue = this->red.rollDice();
        cout << "\nRed rolled a " << this->dieValue;//

        //Perform turn
        this->red.turnComputer();

        //Update board with turn results
        updateBoardPegPositions();
        redKillCheck();
        if (redWinCheck() == true) {return;}

//------blue turn
        cout << "\nIt is blue player's turn.";//
        this->dieValue = this->blue.rollDice();
        cout << "\nBlue rolled a " << this->dieValue;//

        //Perform turn
        this->blue.turnComputer();

        //Update board with turn results
        updateBoardPegPositions();
        redKillCheck();
        if (blueWinCheck() == true) {return;}

    //Loop will exit when
    }//End of while(this->Endgame == false)
}//End of void board :: play()

//==========================================================================================
//==========================================================================================
//Game play

void play()
{
    //Seed the random number generator
    srand(static_cast <unsigned int> (time(0)));

    board gameBoard;

    gameBoard.play();

}//End of void play()
