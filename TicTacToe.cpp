// TicTacToe console app
// new comment in branch Module B

#include <iostream>

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };    // Array for the board

void displayBoard();                                // display the tictactoe board
int playerTurn(int player);                         // returns players choice of square
void updateBoard(int choice, int player);           // update the board with players choice
bool checkForWin();                                 // check array for 3 in a row - winner - return true if winner
bool checkIfSquareTaken(int square);                // returns true if square chosen already has X or O in it

// new unused variable for branch test of Module B
int test = 0;

int main()
{
    displayBoard();             // set out the board for the players to see

    int playerNumber{ 1 };      // 2 players - player 1 and player 2 - set to player 1
    int playerChoice;           // square on the board chosen by the player - 1 to 9
    int gameOver{ 1 };          // only 9 moves possible - increased after each move - draw if it gets to 9

    // keep playing the game until a win or a draw when gameOver is 10
    while (gameOver < 10)
    {
        playerChoice = playerTurn(playerNumber);        // takes turn and returns new player number
        updateBoard(playerChoice, playerNumber);        // update the board with player choice
        displayBoard();                                 // display the board with the new move
        
        // check if there is a winner after the last move and display winner and end game if there is
        if (checkForWin())
        {
            std::cout << "\nPlayer " << playerNumber << " is the WINNER! \n";
            return 0;
        }
        
        // player number changed to next player
        if (++playerNumber > 2)
            playerNumber = 1;

        gameOver += 1;
    }
    
    std::cout << "\nDRAW - the games is tied!\n\n";
}

void displayBoard()
{
    std::cout << "\tPLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    std::cout << "\t\t_____|_____|_____\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    std::cout << "\t\t_____|_____|_____\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    std::cout << "\t\t     |     |     \n";
}

// return square number on board chosen by player in player (1 or 2)
int playerTurn(int player)
{
    int choice{ 0 };       // set square choice to 1 to make while loop true

    // loop until player chooses a square from 1 to 9 that hasn't yet been chosen
    while (choice < 1 || choice > 9)
    {
        std::cout << "\nPlayer " << player << " choose your square: \n";
        std::cin >> choice;

        if (checkIfSquareTaken(choice)) choice = 0;   // check square hasn't already been chosen
    }

    return choice;
}

// update the board with a X or 0 if player 1 or 2
// and with choice giving the square number 
void updateBoard(int choice, int player)
{
    int row, column;        // row and column for the board

    // change player choice from square number to row and column on the board
    switch (choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        std::cout << "Invalid Move";        // not currently needed
    }

    // fill board with X if player 1 or O if player 2
    if (player == 1) 
        board[row][column] = 'X';
    else 
        board[row][column] = 'O';
}

// check the board for 3 of a kind in a row - winner!
// return true if winner
bool checkForWin()
{
    // check the rows and columns for 3 of a kind
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] || board[i][0] == board[i][1] && board[i][0] == board[i][2]) return true;
    
    // check the diagonals for 3 of a kind
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) return true;

    return false;
}

// check the board to make sure square chosen has not already been taken
// return true if already taken
bool checkIfSquareTaken(int square)
{
    int row, column;

    // turn the square number into row and grid
    switch (square) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        std::cout << "Invalid Move";
    }

    // check if a square on the grid has already been taken with X or O
    return (board[row][column] == 'X' || board[row][column] == 'O');    // return true if X or O in the square
}
