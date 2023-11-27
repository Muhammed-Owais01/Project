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

void movepice(char board[][SIZE],int irow,int icol,int frow,int fcol,char a){
         board[irow][icol]=' ';
         board[frow][fcol]=a;
    return;
}

//this function chack if user move 2 col or row it can chack back
 int chackforbak(char board[][SIZE],int row,int col,int curent_row,int curent_col){
         char a=board[curent_row][curent_col];
         char c;
         char b=' ';
         if(a=='X'){
            c='O';
         }else
           c='X';
         if(board[row][col]==b){
            return 0;
         }else
          if(board[row][col]==a){
            return 0;
         }else
         {
            if(board[row][col]==c){
                board[row][col]=' ';
            }
       }
    return 1;
 }

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

//this function can take input from 1st person
void fsinput(char board[][SIZE]){
       int rowintial,colintial;//we use these veriabe for find courent location of guti
        int row,col;//we use these veribel for d
        int i=1;
        int a;
        //by this loop we take initil position of guti
        while(i==1){

           printf("Enter Row, Column Of The Man You Want To Move: ");
           scanf("%d %d", &rowintial, &colintial);
           //now call the conferm function to cahck at given location guti is present or not 
            a =  conferm1(board,rowintial,colintial,'X');//call the function to 
           if ((rowintial<0||rowintial>7)||(colintial<0||colintial>7) )
           {
            printf("INVALID INPUT: OUT OF BOUNDS!\n");
           }else if(a==0){
               printf("INVALID LOCATION ENTERED: YOU DONT HAVE A PIECE HERE\n");
           }else i=-1;
        }
          i=1;
        //take input for final loction of guti 
         while(i>0){

           printf("Enter Row, Column Where You Want To Move: ");
            scanf("%d %d", &row, &col);
           //now call the conferm function to cahck at given location guti is present or not 
            a =  conferm2(board,row,col);//call the function to know yha phaly sy hi goti to nhi gha
            int difrow=  rowintial-row  ;
            int  difcol=  colintial-col ;
            int b;//use as  a mode function for row
            int c;//use as a mode function for colume
            if(difrow<0){
                b = difrow*(-1);
             }else{
             b=difrow;
            }
            if(difcol<0){
                c = difcol*(-1);
            }else{
                c=difcol;
             }

           if ((row<0||row>7)||(col<0||col>7) )
           {
            printf("INVALID INPUT: OUT OF BOUNDS!\n");
           }else 
           if(a==0){
               printf("INVALID LOCATION ENTERED: A PIECE IS ALREADY THERE\n");
           }else 
           if(difcol>2||difrow>2){
              printf("You cannot move to this location\n");
           }else
           if (b!=c)
           {
              printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
           }else
            if(b==2&&c==2){
                if(difrow>0){
                    printf("INVALID LOCATION ENTERED!");
                }else
              if(difrow<0){
                switch(difcol){
                case -2:
                    if(chackforbak(board,row-1,col-1,rowintial,colintial)!=1){
                        printf("your move is roung enter valid adderass\n");
                    }
                    
                case 2: 
                    if(chackforbak(board,row-1,col+1,rowintial,colintial)!=1){
                        printf("your move is roung enter valid adderass\n");
                    }
                    
                default:i=-1;
                }//end of switcah
              }//end of if difcol > 0
            }//end of if b == 2 && a == 2
            else 
            if (b==1&&c==1){
                if (board[row][col]!=' '){
                 printf("you can't move hear becouse there is already an pice\n");
                }else
                i=-1;
            }else{
                i=-1;
                break;
              }//end else
            }
         
           movepice(board,rowintial,colintial,row,col,'X');
            
    return;
}//end of input of frist preson

// this functon checks for base condition to stop game
int check(char board[][SIZE]){
        bool flag=true;
        char searchChar='X';
        for(int i=0 ; i <SIZE;i++){
             if(strchr(board[i],searchChar)!=NULL){
                flag=false;   
                break;
            }
        }
        
        if (flag==true){
            return 0;
        }

         flag= true;
         searchChar='O';
         for(int i = 0; i < SIZE; i++){
             if(strchr(board[i], searchChar)!=NULL){
                flag=false;  
                break;
        }
         }
        
        if (flag==true){
            return 0;
        }else
      return 1;
}

void result(char board[][SIZE]){
    bool flag=true;
        char searchChar ='X';
      for(int i = 0; i < SIZE; i++){
        if(strchr(board[i],searchChar)!=NULL){
            flag=false;
            break;
        }
      }//end of for
      if(flag){
        printf("Player 2 Wins\n");
            return ;
      }else
      flag=true;

      searchChar='O';
      for (int i = 0 ; i < SIZE; i++){
        if(strchr(board[i],searchChar)!=NULL){
            flag=false;
            break;
        }
      }//end  of for loop 
      if (flag){
        printf("Player 1 Wins\n");
            return ;
      }
      return ;
}

///play game in the function
void playgame(char board[][SIZE],int i){
        int a=chack(board);
       if(a==0){
          result(board);
           return;
       }
       if(i%2==0){
        printf("Turn of Player 1\n");
        fsinput(board);//call the function  1st person input
       }
       else{
          printf("Turn of Player 2\n");
         scinput(board);//call the function 2nd person input
       }
       system("cls");
       display(board);
       playgame(board,i-1);

       return;
}
