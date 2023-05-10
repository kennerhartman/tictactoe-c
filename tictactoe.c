//
// Copyright (c) Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// gamestate; 1-9 = in play; -1 = game finished; needs to be global so it can be accessed by multiple functions
int gameState = 1;

// game logic related functions

void printBoard(char[9]);
void checkWin(char[9]);
int placeXorO(char [9], int response, int turn);

// text color related functions

void textColorIsRed(void);
void textColorIsGreen(void);
void textColorIsBlue(void);
void textColorReset(void);

int main(void) {
    // array to store the state of the game (what the board is looking like)
    char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'}; 

    // turn; 0 by default; 0 = X's turn; 1 = O's turn
    int turn = 0;

    // stores the response of any number between 1 and 9 so the program can place a X or O on the board
    int response;

    // pick a random number between 0 and 1 to determine who is going first
    srand(time(NULL));
    int randomNumber = rand() % 2;

    // logic to choose who will go first
    if(randomNumber == 1) {
        printf("X is first!\n\n");
        turn = 0;
    } else if (randomNumber == 0) {
        printf("O is first!\n\n");
        turn = 1;
    }

    // this is the integral part of the game; whenever gameState is >= 1 and <= 9, the game is in play and the players will be 
    // asked to give a number between 1 and 9 to place X or O on the board.
    while(gameState >= 1 && gameState <= 9) {
        
        // logic for telling the players who's turn it is
        if(turn == 0) {
            textColorIsGreen();
            printf("It is X's turn!\n");
            textColorReset();
        } else {
            textColorIsGreen();
            printf("It is O's turn!\n");
            textColorReset();
        }

        // printf() tells the player to select a position on the board 
        // scanf() takes that response and points to "int response" to store the inputted integer
        printf("Select a position on the board (1-9): ");
        scanf("%d", &response);

        // makes sure that no players can override any X or O
        if(board[response - 1] == 'X' || board[response - 1] == 'O') {
            textColorIsRed();
            printf("\nPick a different spot!\n");
            textColorReset();
        } else {
            switch(response) {
                case 1:
                    turn = placeXorO(board, response, turn);
                    break;
                case 2:
                    turn = placeXorO(board, response, turn);
                    break;
                case 3:
                    turn = placeXorO(board, response, turn);
                    break;
                case 4:
                    turn = placeXorO(board, response, turn);
                    break;
                case 5:
                    turn = placeXorO(board, response, turn);
                    break;
                case 6:
                    turn = placeXorO(board, response, turn);
                    break;
                case 7:
                    turn = placeXorO(board, response, turn);
                    break;
                case 8:
                    turn = placeXorO(board, response, turn);
                    break;
                case 9:
                    turn = placeXorO(board, response, turn);
                    break;
            }
        }

        printBoard(board);
        checkWin(board);
        
    }

    return 0;
}

// - when called, this function will place an X or O on the board, depending on where the player places it
// - the variable "response" in function "int main" stores the response of any number between 1 and 9 so the program can place a X or O on the board
// - all parameters in this function are named after the same variables in "int main"
int placeXorO(char board[9], int response, int turn) {
    if(turn == 0) {
        board[response - 1] = 'X';
        gameState++;
        turn = 1;
    } else if(turn == 1) {
        board[response - 1] = 'O';
        gameState++;
        turn = 0;
    }

    return turn;
}

// this function, when called, houses a for loop which prints the entire board 
void printBoard(char board[9]) {
    printf("\n");
    for(int i = 0; i < 9; i++){ 
        printf("%c", board[i]);
        if(i == 2 || i == 5 || i == 8) {
            printf("\n");
        }
    }
    printf("\n");
}

// after each response of X or O, this function checks if any player is in a winning "state"
void checkWin(char board[9]) {
    
    // row one win check
    if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
        textColorIsBlue();
        printf("X won!\n");
        exit(0);
    } else if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
        textColorIsBlue();
        printf("O won!\n");
        exit(0);
    }

    // row two win check

    if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
        textColorIsBlue();
        printf("X won!\n");
        exit(0);
    } else if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
        textColorIsBlue();
        printf("O won!\n");
        exit(0);
    }

    // row three win check

    if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
        textColorIsBlue();
        printf("X won!\n");
        exit(0);
    } else if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
        textColorIsBlue();
        printf("O won!\n");
        exit(0);
    }

    // column one win check

    if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
        textColorIsBlue();
        printf("X won!\n");
        exit(0);
    } else if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
        textColorIsBlue();
        printf("O won!\n");
        exit(0);
    }

    // column two win check

    if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
        textColorIsBlue();
        printf("X won!\n");
        exit(0);
    } else if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
        textColorIsBlue();
        printf("O won!\n");
        exit(0);
    }

    // column three win check

    if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
        textColorIsBlue();
        printf("X won!\n");
        exit(0);
    } else if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
        textColorIsBlue();
        printf("O won!\n");
        exit(0);
    }

    // both diagonal win check

    if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
        textColorIsBlue();
        printf("X won!\n");
        exit(0);
    } else if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
        textColorIsBlue();
        printf("O won!\n");
        exit(0);
    }

    if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
        textColorIsBlue();
        printf("X won!\n");
        exit(0);
    } else if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
        textColorIsBlue();
        printf("O won!\n");
        exit(0);
    }

    /*

        char board[9] if it were a tic-tac-toe board:

        0, 1, 2,
        3, 4, 5,
        6, 7, 8

    */
}

// changes console text color to bold red
void textColorIsRed(void) {
    printf("\e[1;31m");
}

// changes console text color to green
void textColorIsGreen(void) {
    printf("\e[0;32m");
}

// changes console text color to bold blue
void textColorIsBlue(void) {
    printf("\e[1;34m");
}

// resets console text color to white
void textColorReset(void) {
    printf("\e[0m");
}

