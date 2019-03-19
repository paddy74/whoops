#include "peg.h"


namespace whoops
{

/* Constructors */

//  Empty constructor
peg::peg()
{
    // 0 is off board
    this->pos = 0;
}

void peg::move(int rh)
{
    if (rh == 0)
    {
        this->pos = 0;
    }
    else
    {
        this->pos += rh;
    }
}

// Operator overloads for ADT peg---------------------

// '=='
bool peg::operator ==(const peg& rh)
{
    if (this->pos == rh.pos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ==========================================================================================
// ==========================================================================================
// ADT member functions
// class player

// Roll the dice
int player::rollDice()
{
    int d;
    d = ((rand() % 6) + 1);

    this->dieValue = d;

    return d;
}

// Finds the first peg at start
int player::startFinder()
{
    if (this->p1.pos == 0)
    {
        return 1;
    }
    else if (this->p2.pos == 0)
    {
        return 2;
    }
    else if (this->p3.pos == 0)
    {
        return 3;
    }
    else if (this->p4.pos == 0)
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

// Returns number of pegs at position 0
int player::startCount()
{
    int d = 0;

    if (this->p1.pos == 0)
    {
        d++;
    }
    if (this->p2.pos == 0)
    {
        d++;
    }
    if (this->p3.pos == 0)
    {
        d++;
    }
    if (this->p4.pos == 0)
    {
        d++;
    }

    return d;
}

// Checks if a given peg is at start
bool player::startTest(int whichPeg)
{
    int d;

    switch(whichPeg)
    {
    case 1:
        {
            d = this->p1.pos;
            break;
        }
    case 2:
        {
            d = this->p2.pos;
            break;
        }
    case 3:
        {
            d = this->p3.pos;
            break;
        }
    case 4:
        {
            d = this->p4.pos;
            break;
        }
    default:
        {
            break;
        }
    }

    if (d == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Returns true if a specified peg is home
bool player::homeTest(int whichPeg)
{
    int d;

    switch(whichPeg)
    {
    case 1:
        {
            d = this->p1.pos;
            break;
        }
    case 2:
        {
            d = this->p2.pos;
            break;
        }
    case 3:
        {
            d = this->p3.pos;
            break;
        }
    case 4:
        {
            d = this->p4.pos;
            break;
        }
    default:
        {
            break;
        }
    }

    if (d > 40)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Increments specified peg position by rh
void player::jump(int whichPeg, int rh)
{
        switch(whichPeg)
    {
    case 1:
        {
            p1.move(rh);
            break;
        }
    case 2:
        {
            p2.move(rh);
            break;
        }
    case 3:
        {
            p3.move(rh);
            break;
        }
    case 4:
        {
            p4.move(rh);
            break;
        }
    default:
        {
            break;
        }
    }
}

// Sets specified peg position to 0
// Exactly the same as jump but exists for organizational purposes
void player::setPos(int whichPeg, int rh)
{
    switch(whichPeg)
    {
    case 1:
        {
            p1.move(rh);
        }
    case 2:
        {
            p2.move(rh);
        }
    case 3:
        {
            p3.move(rh);
        }
    case 4:
        {
            p4.move(rh);
        }
    default:
        {
            break;
        }
    }
}

// Returns position of specified peg
int player::getPos(int whichPeg)
{
    int d;

    switch(whichPeg)
    {
    case 1:
        {
            d = this->p1.pos;
            return d;
            break;
        }
    case 2:
        {
            d = this->p2.pos;
            return d;
            break;
        }
    case 3:
        {
            d = this->p3.pos;
            return d;
            break;
        }
    case 4:
        {
            d = this->p4.pos;
            return d;
            break;
        }
    default:
        {
            break;
        }
    }

    return 0;
}

// Human member functions-------------------------

// Performs a human turn
void player::turnHuman()
{
    int diceValue = this->dieValue;
    int start = startCount();

    // If all pegs are at start
    if (start == 4)
    {
        if (diceValue == 6)
        {
            jump(1, 1);
        }
    }

    // If at least one peg is at start
    else if (start > 0)
    {
        if (diceValue == 6)
        {
            jump(startFinder(), 1);
        }
        else
        {
            int choice;

            bool Endloop = false;
            while(!Endloop)
            {
                // Take user input
                std::cout << "\nPlease enter the peg index you would like to move: ";
                std::cin >> choice;

                // In case of bad user input
                if ((choice > 4) or (choice < 1))
                {
                    std::cout << "\nThat peg does not exist.";
                }
                else if (homeTest(choice))
                {
                    std::cout << "\nThat peg is already home.";
                    Endloop = false;
                }
                else if (startTest(choice))
                {
                    std::cout << "\nThat peg is still at start.";
                    Endloop = false;
                }
                else
                {
                    jump(choice, diceValue);
                    Endloop = true;
                }
            }
        }
    }

    // If no pegs are at start
    else
    {
        int choice;

        bool Endloop = false;
        while(!Endloop)
        {
            // Take user input
            std::cout << "\nPlease enter the peg index you would like to move: ";
            std::cin >> choice;

            // In case of bad user input
            if ((choice > 4) or (choice < 1))
            {
                std::cout << "\nThat peg does not exist.";
            }
            else if (homeTest(choice))
            {
                std::cout << "\nThat peg is already home.";
                Endloop = false;
            }
            else
            {
                jump(choice, diceValue);
                Endloop = true;
            }// End of else
        }// End of while(!Endloop)
    }// End of else

}// End of turnHuman()

// Computer member functions-------------------------

// Randomly selects a peg choice
int player::choiceFinder()
{
    int d;
    d = ( (rand() % 4) + 1 );

    return d;
}

// Performs a computer turn
// Same as turnHuman() except receives choice input from choiceFinder()
void player::turnComputer()
{
    int diceValue = this->dieValue;
    int start = startCount();

    // If all pegs are at start
    if (start == 4)
    {
        if (diceValue == 6)
        {
            jump(1, 1);
        }
    }

    // If at least one peg is at start
    else if (start > 0)
    {
        if (diceValue == 6)
        {
            jump(startFinder(), 1);
        }
        else
        {
            int choice;

            bool Endloop = false;
            while(!Endloop)
            {
                // Take random input
                choice = choiceFinder();

                if (homeTest(choice))
                {
                    Endloop = false;
                }
                else if (startTest(choice))
                {
                    Endloop = false;
                }
                else
                {
                    jump(choice, diceValue);
                    Endloop = true;
                }
            }
        }
    }

    // If no pegs are at start
    else
    {
        int choice;

        bool Endloop = false;
        while(!Endloop)
        {
            // Take random input
            choice = choiceFinder();

            if (homeTest(choice))
            {
                Endloop = false;
            }
            else
            {
                jump(choice, diceValue);
                Endloop = true;
            }
        }
    }

}

}
