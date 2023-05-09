
# Tic-tac-toe in C

I have made a game of Tic-tac-toe before using [Javascript](https://github.com/kennerhartman/tictactoe-js), so I thought about make a console based game of Tic-tac-toe using C!

<br>

### Compiling and Running the Program <hr>

Compiler used: GNU GCC 

To compile and run the program, 

(1) git clone https://github.com/kennerhartman/tictactoe-c.git

In the console,

(2) gcc tictactoe.c

(3) ./a.out or ./a.exe

<br>

## What I Have Learned <hr>

### Using a Function to Place an X or O <hr>

The code I originally had for the switch case ([lines 75-104](tictactoe.c)) was too repetitive and it made the code longer than it had be.  I figured I could use a function to place a X or O on the board.  

This function ([lines 117](tictactoe.c)) works by taking in three parameters: (1) the current state of the board using the variable ```char board[9]```; (2) the response of the player and where they chose to put the X or O using the variable ```response```; and (3) if it is X's or O's turn using the variable ```turn```.  The function would then increase ```int gameState``` (a global variable) by one and would return an integer to tell the if statement in ```int main ``` whose turn it is next.  This process will repeat itself (through the while loop and switch case statements in [lines 51-109](tictactoe.c)) until the game ends.

Without the function, I would have an additional ~81 lines of code, but with the function I would only have 13 additional lines of code, excluding the call of the function in each of the nine cases.  Here is how I originally handled placing an X or O in each of the 9 switch case statements:

```
if(turn == 0) {
    board[n] = 'X';
    turn = 1;
    gameState++;
} else {
    board[n] = 'O';
    turn = 0;
    gameState++;
}
break;
```

where n equals the index in the array.

Here is how I now handled placing an X or O with the switch case statement:

```
turn = placeXorO(board, response, turn);
break;
```

where the function ```placeXorO()``` has the following code:

```
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
```

From this, I now better understand passing multiple parameters with different types, as well as returning a value from a function in C.  I must sepcify if the parameter I am passing is, for example, a ```char``` or an ```int```.  To return a value, I must specify when declaring the fuction if I am returning a string/character (char) or an integer (int).  (Otherwise, I simply state ```void```, as seen in majority of my function declarations.)  

## Handy Resources <hr>

[RabaDabaDoba](https://gist.github.com/RabaDabaDoba) provides an excellent resource for all ANSI color codes to change the console text color and font, found [here](https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a).


<br>

## License <hr>

This project uses the MIT license.  Please ensure you retain the license notice if you use any part of my program. For more information about the licensing of this project, please see [LICENSE.md](LICENSE.md).  
