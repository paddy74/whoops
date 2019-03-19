#include "peg.h"
#include "board.h"


/**
 * @brief Pause at the end of main, acts like system("pause").
 *  Does not need to be included in any function.
 *
 */
void pause() __attribute__((destructor));
void pause()
{
    //Flush the input buffer
    std::cin.sync();
    //User input is not actually needed
    std::cin.ignore();
}


int main(int argc, const char * argv[])
{
    //Seed the random number generator
    srand(static_cast <unsigned int> (time(0)));

    whoops::GameBoard board = whoops::GameBoard();
    board.play();

    return 0;
}
