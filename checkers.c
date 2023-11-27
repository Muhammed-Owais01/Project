#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 8


// board initialization
char board[SIZE][SIZE] =  {{'X', ' ', 'X', ' ','X', ' ', 'X', ' '},
                          {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
                          {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
                          {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
                          {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'}};
// in this function we confermed k goti ha ya nhi frist person ki
 int conferm1(char board[][SIZE],int r,int c,char ch){
    //c stand for colume 
    //r stand for row
    if(board[r][c]==ch){
        return 1;
    }else
    return 0;
 }//end of confer1

//in this function we confermed k goti ha ya nhi secand person ki
 int conferm2(char board[][SIZE],int r,int c){
    //c stand for colume 
    //r stand for row
    if(board[r][c]=='O'||board[r][c]=='X'){
        return 0;
    }else
    return 1;
 }//end of conferm2

// Display board
void display(char board[][SIZE]){
      printf("====================\n");
      printf("  ||0|1|2|3|4|5|6|7|\n");
      printf(" _|=================\n");
      for ( int i = 0; i < SIZE;i++){
        printf("|%d|", i);
        for (int j = 0; j < SIZE; j++){
            printf("|");
            printf("%c",board[i][j] );
        }
         printf("|");
         if(i==7){
            printf("\n====================");
         }
        printf("\n");
      }
       printf("Player 1 is: X\nPlayer 2 is: O\n");
      return;
}//end of display
