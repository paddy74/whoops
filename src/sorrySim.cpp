//Problem Solving and Programming II
//Name: Patrick T Cox
//Date: 24 November 2015
//Final Project
//main.cpp

//Program Directives
#include "peg.h"
#include "board.h"

//name space
using namespace std;//standard

//Pause at end of main, acts like system("pause")
//Does not need to be included in any function
void pause() __attribute__((destructor));
void pause()
{
    //Flush the input buffer
    std::cin.sync();
    //User input is not actually needed
    std::cin.ignore();
}

//==========================================================================================
//==========================================================================================
//main

//Performs program operations
int main()
{

    play();

    return 0;
}//end of main

//==========================================================================================
//==========================================================================================
