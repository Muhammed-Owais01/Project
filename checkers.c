#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 8


// Initializing board
char board[SIZE][SIZE] =  {{'X', ' ', 'X', ' ','X', ' ', 'X', ' '},
                          {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
                          {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
                          {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
                          {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'}};
// To confirm is a piece is present on the location
int confirm_piece(char board[][SIZE],int current_row,int current_column,char ch)
{
 	// c for col 
 	// r for row
 	if (board[current_row][current_column] == ch)
 		return 1;
    else
        return 0;
}//end of confirm_piece

// Confirming if there is a space or not (when moving to a location where a piece is already present)
int confirm_space(char board[][SIZE],int final_row,int final_column) 
{
    // if there is space or not
 	if (board[final_row][final_column] == 'O'|| board[final_row][final_column] == 'X')
 		return 0;
 	else
        return 1;
}//end of confirm_space

// this function is responsible for removing a piece on the board
int capture_piece(char board[][SIZE],int diag_row,int diag_col,int curent_row,int curent_col)
{
    char current_piece = board[curent_row][curent_col];
 	char diag_piece;
 	char space = ' ';

    // checks which piece is at current location
 	if (current_piece == 'X' || current_piece == 'K') {
        diag_piece = 'O';
 	} else if (current_piece == 'O' || current_piece == 'Q') {
        diag_piece = 'X';
    }

 	// if middle location empty, return 0
 	if (board[diag_row][diag_col] == space) {
 	     return 0;
 	}
    // if middle location has the players piece present in current location return 0
    else if (board[diag_row][diag_col] == current_piece) {
 	     	return 0;
    }
    // replace the middle piece with space
    else {
        if (board[diag_row][diag_col] == diag_piece) {
 	     	board[diag_row][diag_col] = ' ';
        }
 	}
 	return 1;
}

//Display the board
void display(char board[][SIZE])
{
    printf("====================\n");
    printf("  ||0|1|2|3|4|5|6|7|\n");
    printf(" _|=================\n");

    for (int i = 0; i < SIZE;i++) {
      	printf("|%d|", i);
        for (int j = 0; j < SIZE; j++) {
      		printf("|");
      		printf("%c",board[i][j]);
      	}
      	printf("|");
        if (i==7) {
         	printf("\n====================");
        }
      	printf("\n");
    }

    printf("Player 1 is: X\nPlayer 2 is: O\n");

    return;
}//end of display


// this function moves a piece, and replaces space in a previous location the piece was at
// it also is responsible for creating king piece
void move_piece(char board[][SIZE],int irow,int icol,int frow,int fcol,char a)
{
    // checks if a piece should become king
    // if piece reaches final row
    // player 1 
    if (a == 'X' && frow == 7) {
        board[irow][icol] = ' ';
        char b = 'K';
        board[frow][fcol] = b;
    }
    // player 2 condition
    else if (a == 'O' && frow == 0) {
        board[irow][icol] = ' ';
        board[frow][fcol] = 'Q';
    }
    // normal piece condition
    else {
        board[irow][icol] = ' ';
        board[frow][fcol] = a;
    }
    return;
}

// king function 
int king(char board[][SIZE],int current_row,int current_col,int diag_row,int diag_col, int up_or_down,int left_or_right,int b,int c)
{
    // b and c are mod of up_or_down and left_or_right
    // if it can move 2 rows and 2 cols (simple words: will it move 2 spaces diagonally)
    if (b == 2 && c == 2) {
        // basically checks if king is to move up or downwards
        if (up_or_down > 0) {
            switch (left_or_right) {
                // when moving rightwards
                case 2:
                    // if capture_piece is not 1 then that means incorrect final location was entered
                    if (capture_piece(board, diag_row + 1,diag_col + 1, current_row, curent_col) != 1) {
                        printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                        return 1;
                    }
                // when moving leftwards
                case -2:
                    if (capture_piece(board, diag_row + 1, diag_col - 1, current_row, curent_col) != 1) {
                        printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                        return 1;
                    }
                default: return 0;
            }//end of switch
        }//end of if (up_or_down > 0)
        // same as above but for downwards
        else if (up_or_down < 0) {
            switch (left_or_right) {
                case -2:
                    if (capture_piece(board, diag_row - 1, diag_col - 1, current_row, current_col) != 1) {
                        printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                        return 1;
                    }
                case 2: 
                    if (capture_piece(board, diag_row - 1, diag_col + 1, current_row, current_col) != 1) {
                        printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                        return 1;
                    }    
                default: return 0;
            }//end of switcah
        }//end of if (left_or_right > 0)
    }//end of if b == 2 && a == 2

    //for king
    else 
    // if user wants to move 1 space only
    if (b == 1 && c == 1) {
        // if piece already there or not
        if (board[row][col] != ' ') {
            printf("INVALID LOCATION ENTERED: A PIECE IS ALREADY THERE\n");
            return 1;
        } else return 0;
    } else
        return 0;
}//end of king function

//this function can take input from 1st person
void firstPlayerInput(char board[][SIZE])
{
    // to find current location of the piece
    int current_row, current_col;
    // to get location to move to
    int final_row, final_col;
    int i = 1;
    int a;

    //loop ends when correct location is entered by the user
    while (i == 1) {
        printf("Enter Row, Column Of The Man You Want To Move: ");
        scanf("%d %d", &current_row, &current_col);
        // confirm_piece returns 1 if input was valid 
        a =  confirm_piece(board, current_row, current_col, 'X');
        // checks if input was out of bounds
        if ((current_row < 0 || current_row > 7) || (current_col < 0 || current_col > 7)) {
       	    printf("INVALID INPUT: OUT OF BOUNDS!\n");
        } 
        // a = 1 means input by user was correct
        else {
            if (a == 0) {
                // if king is there then i = -1, so that loop can end
                if (board[current_row][current_col] != 'K') {
                    printf("INVALID LOCATION ENTERED: YOU DONT HAVE A PIECE HERE\n");
                } else i = -1;
            } else i = -1;
        }
    }

    i = 1;
    //loop ends when location to move to is correctly entered by the user
    while (i > 0) {
        printf("Enter Row, Column Where You Want To Move: ");
        scanf("%d %d", &final_row, &final_col);

        // returns 0 if the location to move to is empty
        a =  confirm_space(board, final_row, final_col);

        int difrow = current_row - final_row;
        int difcol = current_col - final_col;
        int b; // use as a mod function for row
        int c; // use as a mod function for col

        if (difrow < 0) {
            b = difrow * (-1);
        } else {
            b = difrow;
        }

        if (difcol < 0) {
        	c = difcol * (-1);
        } else {
        	c = difcol;
        }

        if ((final_row < 0 || final_row > 7) || (final_col < 0 || final_col > 7)) {
       	    printf("INVALID INPUT: OUT OF BOUNDS!\n");
        }
          // to check if user wants to move more than 2 locations
          else if (difcol > 2 || difrow > 2) {
       	    printf("You cannot move to this location\n");
        } else if (b != c) {
            printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
        } else if (board[current_row][current_col] == 'K') {
            // ki stores 0 if king can move, 1 if king cant move
            int ki = king(board, current_row, current_col, final_row, final_col, difrow, difcol, b, c);

            if (ki == 0) {
                i = -1;
            }
        } else if (a == 0) {
            printf("INVALID LOCATION ENTERED: A PIECE IS ALREADY THERE\n");
        }
        // b = 2 and c = 2 means user is to move two locations
        else if (b == 2 && c == 2) {
        	if (difrow > 0) {
        		printf("INVALID LOCATION ENTERED!");
        	} else if (difrow < 0) {
                switch(difcol) {
                    case -2:
                        // final_row-1, final_col-1 gives the middle location
       	  		        if (capture_piece(board, final_row - 1, final_col - 1, current_row, current_col) != 1) {
                            printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
       	  		        }
                    case 2: 
       	  		        if (capture_piece(board, final_row - 1, final_col + 1, current_row, current_col) != 1) {
       	  			       printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
       	  		        }
                    default: i = -1;
                }//end of switch
            }//end of if difcol > 0
       	}//end of if b == 2 && c == 2

       	else if (b == 1 && c == 1) {
       		if (board[final_row][final_col] != ' ') {
       		   printf("INVALID LOCATION ENTERED: A PIECE IS ALREADY THERE\n");
       		} else
                i = -1; 
        } else if (difrow > 0) {
            printf("INVALID LOCATION ENTERED!\n");
        } else {
       		i = -1;
       		break;
        }//end else
    }
    // moves the piece to the final location after middle location has been set to space
    move_piece(board, current_row, current_col, final_row, final_col, board[current_row][current_col]);
    return;
}//end of input of first player


//in this function we take input for second person 
void secondPlayerInput(char board[][SIZE])
{
    // to find current location of the piece
    int current_row, current_col;
    // to get location to move to
    int final_row, final_col;
    int i = 1;
    int a;

    // loop ends when correct location is entered by the user
    while (i == 1) {
        printf("Enter Row, Column Of The Man You Want To Move: ");
        scanf("%d %d", &current_row, &current_col);
        // confirm_piece returns 1 if input was valid 
        a =  confirm_piece(board, current_row, current_col, 'O');
        if ((current_row < 0 || current_row > 7) || (current_col < 0 || current_col > 7)) {
       	    printf("INVALID INPUT: OUT OF BOUNDS!\n");
        } else if (a == 0) {
            if (board[current_row][current_col] != 'Q') {
                printf("INVALID LOCATION ENTERED: YOU DONT HAVE A PIECE HERE\n");
            } else
                i = -1;
        } else i = -1;
    }

    i = 1;
    // loop ends when location to move to is correctly entered by the user 
    while (i == 1) {
        printf("Enter Row, Column Where You Want To Move: ");
        scanf("%d %d", &final_row, &final_col);

        // Call the confirm function to check if the new location is valid
        a = confirm_space(board, final_row, final_col);
        int difrow = (current_row - final_row);
        int difcol = (current_col - final_col);
        int b, c;//use as mod function

        if (difrow < 0) {
        	b = difrow * (-1);
        } else
            b = difrow;

        if (difcol < 0) {
         	c = difcol * (-1);
        } else
            c = difcol;

        if (final_row < 0 || final_row >= SIZE || final_col < 0 || final_col >= SIZE) {
            printf("INVALID INPUT: OUT OF BOUNDS!\n");
        } else if (difrow > 2 || difcol > 2) {
            printf("You cannot move to this location\n");
        } else if (b != c) {
            printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
        } else if (board[current_row][current_col] == 'Q') {
            int ki = king(board, current_row, current_col, final_row, final_col, difrow, difcol, b, c);
            if(ki == 0) {
                i = -1;
            }
        } else if (a == 0) {
            printf("INVALID LOCATION ENTERED: A PIECE IS ALREADY THERE!\n");
        } else if (b == 2 && c == 2) {
            if (difrow > 0) {
                switch (difcol) {
                    case 2:
                        if (capture_piece(board, final_row + 1,final_col + 1, current_row, current_col) != 1) {
                            printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                        }
                    case -2:
                       	if (capture_piece(board, final_row + 1, final_col - 1, current_row, current_col) != 1) {
                       		printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                       	}
                    default:
                        i = -1;
                }
            }
        } else if (b == 1 && c == 1) {
            if (board[final_row][final_col] != ' ') {
                printf("INVALID LOCATION ENTERED: A PIECE IS ALREADY THERE!\n");
            } else {
            	i = -1;
            }
        } else if (difrow < 0) {
            printf("INVALID LOCATION ENTERED!\n");
        } else {
           i = -1;
        }
    }

    move_piece(board, current_row, current_col, final_row, final_col, board[current_row][current_col]);
    return;
}//end of input of second player


// this functon checks for base condition to stop game
int check(char board[][SIZE])
{
    bool flag = true;
    // search for player 1 piece
    char searchChar = 'X';

    for (int i = 0; i < SIZE; i++) {
        // strchr checks every column of a row without the need of another for loop
        if (strchr(board[i], searchChar) != NULL) {
            // if a piece is found then set to false and break
            flag = false;   
            break;
        }
    }
    
    if (flag==true) {
        printf("Player 2 Wins\n");
    	return 0;
    }

    flag = true;
    // search for player 2 piece
    searchChar = 'O';
    for (int i = 0; i < SIZE; i++) {
        if (strchr(board[i], searchChar) != NULL) {
            // if a piece is found then set to false and break
            flag = false;   
            break;
        }
    }
    
    if (flag == true) {
        printf("Player 1 Wins\n");
    	return 0;
    } else
        return 1;
}


///play game in the function
void playgame(char board[][SIZE], int i)
{
    int a = check(board);

    if (a == 0) {
   	   return;
    }

    // if i is even then player 1 plays
    if (i % 2 == 0) {
   	    printf("Turn of Player 1\n");
        // Call the function for player 1 input
   	    firstPlayerInput(board);
    }
    // else player 2 plays
    else {
   	    printf("Turn of Player 2\n");
        // Call the function for player 2 input
   	    secondPlayerInput(board);
    }

    system("cls");
    display(board);
    playgame(board,i-1);

   return;
}

int main(int argc, char const *argv[])
{
	system("cls");
	display(board);
    	// c for col, r for row
	int c,r;
    
    	playgame(board,3000);
     
	return 0;
}
