
 #include <bits/stdc++.h>
 #include <string>
 
 using namespace std;
 
 /*******************************************************************************
  *                                'left()'                                     *
  *         A function that returns the rest of the Eclidian division           *
  *   the division happens in one direction the first integer on the left side  *
  *                   divided by the second on the right                        *
  * Parameters: 1)x: the first integer.                                         *
  *             2)y: the second integer.                                        *
  * Returns: the rest of the Eclidian division.                                 *
  *******************************************************************************/
  int left(int x,int y)
  {
      int rest=x-y;
      if(y>x)
      {return(x);}
      else
      {
        while(1)
        {
          if(rest>=y)
          {rest=rest-y;}
                    
          else
          {return(rest);}
        }
      } 
  }
  
  
 /*****************************************************************************************
  *                                 'check_input_move()'                                  *
  *      A functions that checks the input of the next move then do the following         *
  * -if the input was valid the function will do the necessary changes on the board array.*
  * -if the input is invalid the error integer will receive the value one otherwise it    *
  *     will receive the value zero without making any changes to the board array.        *
  * Parameters: 1) move: an array of characters that holds the next tmp .                 *
  *             2) board: an array(matrix) of integers that contains the board's data.    *
  *             3) error: an integer refers to whether a mistake has been made or not.    *
  *             4) turn: an integer that refers to which player is going to play.         *
  * Returns: the last move                                                                *
  *****************************************************************************************/
 
 int check_input_move(char move[5],int board[][8],int &error,int &turn)
 {
      error=0; // assuming there is no input error.
      //////////// testing the input ////////////    
      char tmp[5]; // temporary storage for move.
      int index; // index to tmp.
      for(index=0;index!=5;index++)
      {tmp[index]=move[index];}   
      
      
      if(((move[0]=='e')||(move[0]=='E'))&&((move[1]=='x')||(move[1]=='X'))&&((move[2]=='i')||
             (move[2]=='I'))&&((move[3]=='t')||(move[3]=='T'))&&((move[4]=='g')||(move[4]=='G')))
             {
                              error=15;/*it is not an error, it means that the user asked to exit the game*/
              }
      else
      {
        if(((move[0]=='n')||(move[0]=='N'))&&((move[1]=='g')||(move[1]=='G'))&&((move[2]=='a')||
             (move[2]=='A'))&&((move[3]=='m')||(move[3]=='M'))&&((move[4]=='e')||(move[4]=='E')))
             {
                              error=14;/*it is not an error ,it means that a new_game has been asked.*/
              }
      
      else{if(((move[0]=='u')||(move[0]=='U'))&&((move[1]=='n')||(move[1]=='N'))&&((move[2]=='d')||
             (move[2]=='D'))&&((move[3]=='o')||(move[3]=='O'))&&((move[4]=='m')||(move[4]=='M'))){
                              error=13;/*It is not an error, it means that an undo_move has been asked. */   }
           else{                                                   
                                                         
      for(index=0;index!=5;index++){
                                   
          if((index==0)||(index==3)){
          switch(tmp[index]){
          case'A':tmp[index]='0'; break;
          case'B':tmp[index]='1'; break;
          case'C':tmp[index]='2'; break;
          case'D':tmp[index]='3'; break;
          case'E':tmp[index]='4'; break;
          case'F':tmp[index]='5'; break;
          case'G':tmp[index]='6'; break;
          case'H':tmp[index]='7'; break;
          case'a':tmp[index]='0'; break;
          case'b':tmp[index]='1'; break;
          case'c':tmp[index]='2'; break;
          case'd':tmp[index]='3'; break;
          case'e':tmp[index]='4'; break;
          case'f':tmp[index]='5'; break;
          case'g':tmp[index]='6'; break;
          case'h':tmp[index]='7'; break;
          default:error=1;   }      }
         
          else{if((index==1)||(index==4)){
          switch(tmp[index]){
          case'1':tmp[index]='7'; break;
          case'2':tmp[index]='6'; break;
          case'3':tmp[index]='5'; break;
          case'4':tmp[index]='4'; break;
          case'5':tmp[index]='3'; break;
          case'6':tmp[index]='2'; break;
          case'7':tmp[index]='1'; break;
          case'8':tmp[index]='0'; break;
          default:error=1;   }      }}
          if(tmp[2]!='-'){error=1;}}
                           }}}
                           
    ////////////// if there is no input error / checking the move ///////////// 
    

      int y1,x1,y2,x2; // the coordinate in the board./ old position. / new position.
    
    y1=int(tmp[1])-48; x1=int(tmp[0])-48; // we use int()-48 because int('0')==48
    y2=int(tmp[4])-48; x2=int(tmp[3])-48;
    
    /////////////////////////////// testing if it is a valid move ///////////////


    if(error==0){ // means that there is no input error. 
       if(board[y1][x1]==0){error=2;}
          else{if((y1==y2)&&(x1==x2)){error=3;}
               else{if(((turn==1)&(left(board[y1][x1],2)!=0))||((turn==2)&(left(board[y1][x1],2)==0))){error=4;}
                           /////////////////////////////////// pieces movements //////////////////////////////////////
                                                    //////////////// the king //////////////////
                    else{if((board[y1][x1]==10)||(board[y1][x1]==100)){ // a king may only move one space in any direction.
                                           if((board[y1][x1]==100)&&(y2==7)&&((x2==6)||(x2==2))){
                                                       if((board[7][5]==0)&&(board[7][6]==0)&&(board[7][7]==300)){
                                                           board[7][4]=0; board[7][5]=30; board[7][6]=10; board[7][7]=0;}
                                                       else{if((board[7][0]==300)&&(board[7][1]==0)&&(board[7][2]==0)&&(board[7][3]==0)){
                                                                    board[7][0]=0; board[7][2]=10; board[7][3]=30; board[7][4]=0;}
                                                            else{if((x2==6)&&(board[7][5]!=0))error=16;
                                                                 else{if((x2==2)&&((board[7][1]!=0)||(board[7][3]!=0))){error=16;}}
                                                                  } }}
                                           else{if(((y1!=y2)&&(y2!=y1+1)&&(y1!=y2+1))||((x1!=x2)&&(x1!=x2+1)&&(x2!=x1+1)))error=5;
                                           else{if((left(board[y2][x2],2)==0)&&(board[y2][x2]!=0))error=6;}}//checking for a blocked path.
                                           if((board[y1][x1]==100)&&(error==0)){board[y1][x1]=10;}                 }
                                           
                    else{if((board[y1][x1]==11)||(board[y1][x1]==101)){
                                           if((board[y1][x1]==101)&&(y2==0)&&((x2==6)||(x2==2))){
                                                       if((board[0][5]==0)&&(board[0][6]==0)&&(board[0][7]==301)){
                                                           board[0][4]=0; board[0][5]=31; board[0][6]=11; board[0][7]=0;}
                                                       else{if((board[0][0]==301)&&(board[0][1]==0)&&(board[0][2]==0)&&(board[0][3]==0)){
                                                                    board[0][0]=0; board[0][2]=11; board[0][3]=31; board[0][4]=0;}
                                                            else{if((x2==6)&&(board[0][5]!=0))error=16;
                                                                 else{if((x2==2)&&((board[0][1]!=0)||(board[0][3]!=0))){error=16;}}
                                                                  } }}    
                                           else{if(((y1!=y2)&&(y2!=y1+1)&&(y1!=y2+1))||((x1!=x2)&&(x1!=x2+1)&&(x2!=x1+1)))error=5;
                                           else{if((left(board[y2][x2],2)!=0)&&(board[y2][x2]!=0))error=6;}}//checking for a blocked path.
                                           if((board[y1][x1]==100)&&(error==0)){board[y1][x1]=11;}                 }
                         
                                                     /////////////// the queen ///////////////// 
                    else{if(board[y1][x1]==20){// Queens may move any number of spaces in any of the eight directions in a straight line.
                               if((y1==y2)||(x1==x2)){// rook's moves.
                                                                      int index; // index to the loop.
                                                    if(x1==x2){if(y1>y2){ //  checking for a blocked path.
                                                                 for(index=(y1-1);index!=y2;index--){
                                                                 if(board[index][x2]!=0){error=6;break;}}}
                                                               else{if(y1<y2){
                                                                      for(index=(y1+1);index!=y2;index++){
                                                                     if(board[index][x2]!=0){error=6;break;}}}}}
                                                    else{if(y1==y2){if(x1>x2){
                                                                 for(index=(x1-1);index!=x2;index--){
                                                                 if(board[y1][index]!=0){error=6;break;}}}
                                                               else{if(x1<x2){
                                                                      for(index=(x1+1);index!=x2;index++){
                                                                      if(board[y1][index]!=0){error=6;break;}}}}}}
                                                    if((left(board[y2][x2],2)==0)&&(board[y2][x2]!=0)){error=6;}
                                                                      }
                               else{if((y1!=y2)&&(x1!=x2)){// bishop's moves.
                                              if((x1-x2!=y1-y2)&&(x2-x1!=y1-y2)&&(x1-x2!=y2-y1)&&(x2-x1!=y2-y1)){error=10;}//worng move.
                                              else{int index;// index to the loop.
                                                   if((y1>y2)&&(x1>x2)){for(index=1;index!=(y1-y2);index++){// checking for a blocked path.
                                                                            if(board[y1-index][x1-index]!=0){error=6;break;}}}
                                                   else{if((y1>y2)&&(x1<x2)){
                                                                             for(index=1;index!=(y1-y2);index++){
                                                                                 if(board[y1-index][x1+index]!=0){error=6;break;}}}
                                                        else{if((y1<y2)&&(x1<x2)){
                                                                                  for(index=1;index!=(y2-y1);index++){
                                                                                      if(board[y1+index][x1+index]!=0){error=6;break;}}}
                                                             else{if((y1<y2)&&(x1>x2)){
                                                                                       for(index=1;index!=(y2-y1);index++){
                                                                                       if(board[y1+index][x1-index]!=0){error=6;break;}}}
                                                                 }}}
                                                         if((left(board[y2][x2],2)==0)&&(board[y2][x2]!=0)){error=6;}}}
                                                     else{error=10;}}}
                    
                    else{if(board[y1][x1]==21){
                               if((y1==y2)||(x1==x2)){// rook's moves.
                                                      int index; // index to the loop.
                                                     if(x1==x2){if(y1>y2){ //  checking for a blocked path.
                                                                 for(index=(y1-1);index!=y2;index--){
                                                                 if(board[index][x2]!=0){error=6;break;}}}
                                                               else{if(y1<y2){
                                                                      for(index=(y1+1);index!=y2;index++){
                                                                     if(board[index][x2]!=0){error=6;break;}}}}}
                                                     else{if(y1==y2){if(x1>x2){
                                                                 for(index=(x1-1);index!=x2;index--){
                                                                 if(board[y1][index]!=0){error=6;break;}}}
                                                               else{if(x1<x2){
                                                                      for(index=(x1+1);index!=x2;index++){
                                                                      if(board[y1][index]!=0){error=6;break;}}}}}}
                                                    if((left(board[y2][x2],2)!=0)&&(board[y2][x2]!=0)){error=6;}
                                                                      }
                               else{if((y1!=y2)&&(x1!=x2)){// bishop's moves.
                                              if((x1-x2!=y1-y2)&&(x2-x1!=y1-y2)&&(x1-x2!=y2-y1)&&(x2-x1!=y2-y1)){error=10;}//worng move.
                                              else{int index;// index to the loop.
                                                   if((y1>y2)&&(x1>x2)){for(index=1;index!=(y1-y2);index++){// checking for a blocked path.
                                                                            if(board[y1-index][x1-index]!=0){error=6;break;}}}
                                                   else{if((y1>y2)&&(x1<x2)){
                                                                             for(index=1;index!=(y1-y2);index++){
                                                                                 if(board[y1-index][x1+index]!=0){error=6;break;}}}
                                                        else{if((y1<y2)&&(x1<x2)){
                                                                                  for(index=1;index!=(y2-y1);index++){
                                                                                      if(board[y1+index][x1+index]!=0){error=6;break;}}}
                                                             else{if((y1<y2)&&(x1>x2)){
                                                                                       for(index=1;index!=(y2-y1);index++){
                                                                                       if(board[y1+index][x1-index]!=0){error=6;break;}}}
                                                                 }}}
                                                         if((left(board[y2][x2],2)!=0)&&(board[y2][x2]!=0)){error=6;}}}
                                                         else{error=10;}}}
                         
                         
                                                     //////////////// the rook /////////////////
                    else{if((board[y1][x1]==30)||(board[y1][x1]==300)){/*Rooks may move up,down,left or right any number of spaces in a straight line.*/
                                               if((y1!=y2)&&(x1!=x2)){error=7;} // wrong move.
                                               else{int index; // index to the loop.
                                                    if(x1==x2){if(y1>y2){ //  checking for a blocked path.
                                                                 for(index=(y1-1);index!=y2;index--){
                                                                 if(board[index][x2]!=0){error=6;break;}}}
                                                               else{if(y1<y2){
                                                                      for(index=(y1+1);index!=y2;index++){
                                                                     if(board[index][x2]!=0){error=6;break;}}}}}
                                                    else{if(y1==y2){if(x1>x2){
                                                                 for(index=(x1-1);index!=x2;index--){
                                                                 if(board[y1][index]!=0){error=6;break;}}}
                                                               else{if(x1<x2){
                                                                      for(index=(x1+1);index!=x2;index++){
                                                                      if(board[y1][index]!=0){error=6;break;}}}}}}
                                                    if((left(board[y2][x2],2)==0)&&(board[y2][x2]!=0)){error=6;}}
                                               if((error==0)&&(board[y1][x1]==300)){board[y1][x1]=30;move[2]='r';}
                                               }
                        
                        
                    else{if((board[y1][x1]==31)||(board[y1][x1]==301)){if((y1!=y2)&&(x1!=x2)){error=7;} // wrong move.
                                               else{int index; // index to the loop.
                                                    if(x1==x2){if(y1>y2){ //  checking for a blocked path.
                                                                 for(index=(y1-1);index!=y2;index--){
                                                                 if(board[index][x2]!=0){error=6;break;}}}
                                                               else{if(y1<y2){
                                                                      for(index=(y1+1);index!=y2;index++){
                                                                     if(board[index][x2]!=0){error=6;break;}}}}}
                                                    else{if(y1==y2){if(x1>x2){
                                                                 for(index=(x1-1);index!=x2;index--){
                                                                 if(board[y1][index]!=0){error=6;break;}}}
                                                               else{if(x1<x2){
                                                                      for(index=(x1+1);index!=x2;index++){
                                                                      if(board[y1][index]!=0){error=6;break;}}}}}}
                                                    if((left(board[y2][x2],2)==0)&&(board[y2][x2]!=0)){error=6;}}
                                               if((error==0)&&(board[y1][x1]==301)){board[y1][x1]=31;}
                                               }
                         
                           
                                                     /////////////// the pawn //////////////////
                    else{if((board[y1][x1]==40)||(board[y1][x1]==400)){
                             if((x1!=x2)&&(x2-x1!=1)&&(x1-x2!=1)){error=11;}
                             else{if((y1-y2!=2)&&(y1-y2!=1)){error=11;}
                                  else{ if(x1==x2){if(board[y1][x1]==400){
                                                               if(y1-y2==2){
                                                                    if(board[y1-1][x1]!=0){error=6;}// checking for blocked path.
                                                                    else{if(board[y2][x2]!=0){error=11;}}}
                                                               else{/*y1-y2==1*/
                                                                    if(board[y2][x2]!=0){error=11;}}
                                                                         
                                                               if(error==0){board[y1][x1]=40;}}
                                                    else{/*board[y1][x1]==40*/
                                                       if(y1-y2!=1){error=11;}//wrong move.
                                                       else{if(board[y2][x2]!=0){error=11;}}}}
                                          else{if(y1-y2!=1){error=11;}
                                               else{if((left(board[y2][x2],2)==0)||(board[y2][x2]==0)){error=11;}}
                                               if((board[y1][x1]==400)&&(error==0)){board[y1][x1]=40;}}}
                                  if((y2==0)&&(error==0)){error=12;}/* it is not an error ,it means that the pawn is
                                                                        going to be transformed to another piece.*/    
                                 }
                                                                      }
                    
                    else{if((board[y1][x1]==41)||(board[y1][x1]==401)){
                             if((x1!=x2)&&(x2-x1!=1)&&(x1-x2!=1)){error=11;}
                             else{if((y2-y1!=2)&&(y2-y1!=1)){error=11;}
                                  else{ if(x1==x2){if(board[y1][x1]==401){
                                                               if(y2-y1==2){
                                                                    if(board[y2-1][x1]!=0){error=6;}// checking for blocked path.
                                                                    else{if(board[y2][x2]!=0){error=11;}}}
                                                               else{/*y2-y1==1*/
                                                                    if(board[y2][x2]!=0){error=11;}}
                                                                         
                                                               if(error==0){board[y1][x1]=41;}}
                                                    else{/*board[y1][x1]==40*/
                                                       if(y2-y1!=1){error=11;}//wrong move.
                                                       else{if(board[y2][x2]!=0){error=11;}}}}
                                          else{if(y2-y1!=1){error=11;}
                                               else{if((left(board[y2][x2],2)!=0)||(board[y2][x2]==0)){error=11;}}
                                               if((board[y1][x1]==401)&&(error==0)){board[y1][x1]=41;}}}
                                  if((y2==7)&&(error==0)){error=12;}/* it is not an error ,it means that the pawn is
                                                                        going to be transformed to another piece.*/    
                                 }
                                                                      }
                             
                             
                             
                              
                         
                                                     /////////////// the knight //////////////// 
                    else{if(board[y1][x1]==50){/*Knight may move one space up or down and tow spaces right or left vice versa.
                                                      The knight is the only piece that can jump over the other pieces.*/ 
                                               if(((x2-x1==1)||(x1-x2==1))&&((y1-y2!=2)&&(y2-y1!=2))){error=8;} // wrong move.
                                               else{if(((y2-y1==1)||(y1-y2==1))&&((x1-x2!=2)&&(x2-x1!=2))){error=8;}
                                                    else{if(((x1-x2!=1)&&(x2-x1!=1))&&((y1-y2!=1)&&(y2-y1!=1))){error=8;}
                                                         else{if((x1==x2)||(y1==y2)){error=8;}
                                                              else{ //checking for a blocked path.
                                                                   if((left(board[y2][x2],2)==0)&&(board[y2][x2]!=0)){error=6;} }}}}
                                              }
                    else{if(board[y1][x1]==51){
                                               if(((x2-x1==1)||(x1-x2==1))&&((y1-y2!=2)&&(y2-y1!=2))){error=8;} // wrong move.
                                               else{if(((y2-y1==1)||(y1-y2==1))&&((x1-x2!=2)&&(x2-x1!=2))){error=8;}
                                                    else{if(((x1-x2!=1)&&(x2-x1!=1))&&((y1-y2!=1)&&(y2-y1!=1))){error=8;}
                                                         else{if((x1==x2)||(y1==y2)){error=8;}
                                                              else{// checking for a blocked path.
                                                                   if((left(board[y2][x2],2)!=0)&&(board[y2][x2]!=0)){error=6;} }}}}
                                              }
                         
                         
                                                     /////////////// the bishop ////////////////
                    else{if(board[y1][x1]==60){
                                         if((x1==x2)||(y1==y2)){error=9;}
                                         else{if((x1-x2!=y1-y2)&&(x2-x1!=y1-y2)&&(x1-x2!=y2-y1)&&(x2-x1!=y2-y1)){error=9;}//worng move.
                                              else{int index;// index to the loop.
                                                   if((y1>y2)&&(x1>x2)){for(index=1;index!=(y1-y2);index++){// checking for a blocked path.
                                                                            if(board[y1-index][x1-index]!=0){error=6;break;}}}
                                                   else{if((y1>y2)&&(x1<x2)){
                                                                             for(index=1;index!=(y1-y2);index++){
                                                                                 if(board[y1-index][x1+index]!=0){error=6;break;}}}
                                                        else{if((y1<y2)&&(x1<x2)){
                                                                                  for(index=1;index!=(y2-y1);index++){
                                                                                      if(board[y1+index][x1+index]!=0){error=6;break;}}}
                                                             else{if((y1<y2)&&(x1>x2)){
                                                                                       for(index=1;index!=(y2-y1);index++){
                                                                                       if(board[y1+index][x1-index]!=0){error=6;break;}}}
                                                                 }}}
                                                         if((left(board[y2][x2],2)==0)&&(board[y2][x2]!=0)){error=6;}}}}
                                                                   
                    else{if(board[y1][x1]==61){
                                         if((x1==x2)||(y1==y2)){error=9;}
                                         else{if((x1-x2!=y1-y2)&&(x2-x1!=y1-y2)&&(x1-x2!=y2-y1)&&(x2-x1!=y2-y1)){error=9;}//worng move.
                                              else{int index;// index to the loop.
                                                   if((y1>y2)&&(x1>x2)){for(index=1;index!=(y1-y2);index++){// checking for a blocked path.
                                                                            if(board[y1-index][x1-index]!=0){error=6;break;}}}
                                                   else{if((y1>y2)&&(x1<x2)){
                                                                             for(index=1;index!=(y1-y2);index++){
                                                                                 if(board[y1-index][x1+index]!=0){error=6;break;}}}
                                                        else{if((y1<y2)&&(x1<x2)){
                                                                                  for(index=1;index!=(y2-y1);index++){
                                                                                      if(board[y1+index][x1+index]!=0){error=6;break;}}}
                                                             else{if((y1<y2)&&(x1>x2)){
                                                                                       for(index=1;index!=(y2-y1);index++){
                                                                                       if(board[y1+index][x1-index]!=0){error=6;break;}}}
                                                                 }}}
                                                         if((left(board[y2][x2],2)!=0)&&(board[y2][x2]!=0)){error=6;}}}} 
                         
                         }}}}}} }}}}}} }}}              
    /////////////// if there is no error applying the move ///////////////////
     
     if (error==0){if(turn==1){turn=2;}else{turn=1;}
                   board[y2][x2]=board[y1][x1];
                   board[y1][x1]=0;} 
    return(y1*1000+x1*100+y2*10+x2);
}
 
 
 
 
 /****************************************************************************************
  *                                  'show screen()'                                     *
  *                 A function that shows the screen of a chess game.                    *
  * Parameters : 1) board: an array(matrix) of integers containing the board's data.     *
  *              2) old_moves: an array of characters wish holds the last 28 moves.      *
  *              3) turn: an integer that refers to wish player is going to play now.    *
  *              4) error: an integer that refers to wish mistake that has been made.    *
  * Returns: void                                                                        *
  ****************************************************************************************/
 
 
  
 void show_screen (int board[][8],char old_moves[],int turn,int error){
////////////////////////////////////////// pieces initialization ///////////////////////////////////
 
 char empty[2][6]; strcpy(empty[0], "      "); strcpy(empty[1], "      ");   // represented by 0.
 char king[2][6]; strcpy(king[0], " King "); strcpy(king[1], "      ");      // represented by 10 (if black by 11).
 char queen[2][6]; strcpy(queen[0], " Queen"); strcpy(queen[1], "      ");   // represented by 20 (if black by 21).
 char rook[2][6]; strcpy(rook[0], " Rook "); strcpy(rook[1], "      ");      // represented by 30 (if black by 31).
 char pawn[2][6]; strcpy(pawn[0], " Pawn "); strcpy(pawn[1], "      ");      // represented by 40 (if black by 41).
 char knight[2][6]; strcpy(knight[0], "Knight"); strcpy(knight[1], "      ");// represented by 50 (if black by 51).
 char bishop[2][6]; strcpy(bishop[0], "Bishop"); strcpy(bishop[1], "      ");// represented by 60 (if black by 61).
 
 
////////////////////////////////////////// board initialization ////////////////////////////////////

      char screen_board[30][80];
      int index_i,index_j; // index to screen_board.
       for (index_i=0;index_i!=30;index_i++){
          for(index_j=0;index_j!=80;index_j++){screen_board[index_i][index_j]='\0' ;}}
      
      strcpy(screen_board[0], "     +------+------+------+------+------+------+------+------+                  ");
      strcpy(screen_board[1], "     |   A  |   B  |   C  |   D  |   E  |   F  |   G  |   H  |                  ");
      strcpy(screen_board[2], "     +------|------|------|------|------|------|------|------+ +---------------+");
      strcpy(screen_board[3], "                                                               |  'Old moves'  |");
      strcpy(screen_board[4], "+-+  +------|------|------|------|------|------|------|------+ |---------------+");
      strcpy(screen_board[5], "|8|  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[6], "| |  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[7], "+-|  |------|------|------|------|------|------|------|------| |               |");
      strcpy(screen_board[8], "|7|  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[9], "| |  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[10],"+-|  |------|------|------|------|------|------|------|------| |               |");
      strcpy(screen_board[11],"|6|  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[12],"| |  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[13],"+-|  |------|------|------|------|------|------|------|------| |               |");
      strcpy(screen_board[14],"|5|  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[15],"| |  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[16],"+-|  |------|------|------|------|------|------|------|------| |               |");
      strcpy(screen_board[17],"|4|  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[18],"| |  |      |      |      |      |      |      |      |      | |               |");
      strcpy(screen_board[19],"+-|  |------|------|------|------|------|------|------|------| |---------------|");
      strcpy(screen_board[20],"|3|  |      |      |      |      |      |      |      |      | |***************|");
      strcpy(screen_board[21],"| |  |      |      |      |      |      |      |      |      | |*             *|");
      strcpy(screen_board[22],"+-|  |------|------|------|------|------|------|------|------| |*             *|");
      strcpy(screen_board[23],"|2|  |      |      |      |      |      |      |      |      | |*       player*|");
      strcpy(screen_board[24],"| |  |      |      |      |      |      |      |      |      | |*  your turn  *|");
      strcpy(screen_board[25],"+-|  |------|------|------|------|------|------|------|------| |*             *|");
      strcpy(screen_board[26],"|1|  |      |      |      |      |      |      |      |      | |*             *|");
      strcpy(screen_board[27],"| |  |      |      |      |      |      |      |      |      | |***************|");
      strcpy(screen_board[28],"+-+  +------|------|------|------|------|------|------|------+ +---------------+");
   
//////////////////////////////////////////// putting everything in the right place /////////////////
 
 /////////////////////////////////////// first the board ///////////////////////////////////
      int index1,index2; /* index to board (the caller), in this case index_i and index_j
                                                                    indicate to the position of the piece in the board .*/
                                              int a,b; // applying the kiss principle (keep it simple stupid).
      int tmp_b[8][8];// temporary storage array for the board.
  
      if(turn==1){for(index1=0;index1!=8;index1++){
                     for(index2=0;index2!=8;index2++){tmp_b[index1][index2]=board[index1][index2];}}
                  for(index1=0;index1!=8;index1++){screen_board[index1*3+5][1]=char(56-index1);}   
                  }
      else{/*turn==2*/
           for(index1=0;index1!=8;index1++){
                     for(index2=0;index2!=8;index2++){tmp_b[index1][index2]=board[7-index1][index2];}}
                  for(index1=0;index1!=8;index1++){screen_board[index1*3+5][1]=char(index1+49);}
                  }
      
      for (index_i=0;index_i!=8;index_i++){
          for(index_j=0;index_j!=8;index_j++){ 
                                              
                                              a=(index_i*3)+5; 
                                              b=(index_j+1)*7-1; 
                                              
                                          ///////////////////// testing if it is an empty cell. /////////////////////
                                          if(tmp_b[index_i][index_j]==0)
                                          { for(index1=0;index1!=2;index1++){
                                               for(index2=0;index2!=6;index2++){ 
                                               screen_board[index1+a][index2+b]=empty[index1][index2];}}}
                                             
                                          ///////////////////// testing if it is a king /////////////////////////////
                                          else{if((tmp_b[index_i][index_j]==10)||(tmp_b[index_i][index_j]==11)||
                                                   (tmp_b[index_i][index_j]==100)||(tmp_b[index_i][index_j]==101))
                                          { if((tmp_b[index_i][index_j]==11)||(tmp_b[index_i][index_j]==101)){king[1][2]='B';}
                                            else{ king[1][2]='W';}
                                            for(index1=0;index1!=2;index1++){
                                               for(index2=0;index2!=(6);index2++){ 
                                               screen_board[index1+a][index2+b]=king[index1][index2];}}}
                                                  
                                          ///////////////////// testing if it is a queen ////////////////////////////
                                          else{if((tmp_b[index_i][index_j]==20)||(tmp_b[index_i][index_j]==21))
                                          { if(tmp_b[index_i][index_j]==21)queen[1][2]='B';
                                            else{ queen[1][2]='W';}
                                            for(index1=0;index1!=2;index1++){
                                               for(index2=0;index2!=(6);index2++){ 
                                               screen_board[index1+a][index2+b]=queen[index1][index2];}}} 
                                                        
                                          //////////////////// testing if it is a rook /////////////////////////////
                                          else{if((tmp_b[index_i][index_j]==30)||(tmp_b[index_i][index_j]==31)||
                                                   (tmp_b[index_i][index_j]==300)||(tmp_b[index_i][index_j]==301)){
                                            if((tmp_b[index_i][index_j]==31)||(tmp_b[index_i][index_j]==301))rook[1][2]='B';
                                            else{ rook[1][2]='W';}
                                            for(index1=0;index1!=2;index1++){
                                                for(index2=0;index2!=(6);index2++){ 
                                                screen_board[index1+a][index2+b]=rook[index1][index2];}}}
                                                            
                                          //////////////////// testing if it is a pawn /////////////////////////////
                                          else{if((tmp_b[index_i][index_j]==40)||(tmp_b[index_i][index_j]==41)||
                                                   (tmp_b[index_i][index_j]==400)||(tmp_b[index_i][index_j]==401))
                                          { if((tmp_b[index_i][index_j]==41)||(tmp_b[index_i][index_j]==401))pawn[1][2]='B';
                                            else{ pawn[1][2]='W';}
                                            for(index1=0;index1!=2;index1++){
                                               for(index2=0;index2!=(6);index2++){ 
                                               screen_board[index1+a][index2+b]=pawn[index1][index2];}}} 
                                                                  
                                         //////////////////// testing if it is a knight ////////////////////////////
                                         else{if((tmp_b[index_i][index_j]==50)||(tmp_b[index_i][index_j]==51))
                                         { if(tmp_b[index_i][index_j]==51){knight[1][2]='B';}
                                           else{ knight[1][2]='W';}
                                           for(index1=0;index1!=2;index1++){
                                              for(index2=0;index2!=(6);index2++){ 
                                              screen_board[index1+a][index2+b]=knight[index1][index2];}}}
                                                                       
                                         /////////////////// testing if it is a bishop /////////////////////////////
                                         else{if((tmp_b[index_i][index_j]==60)||(tmp_b[index_i][index_j]==61))
                                         { if(tmp_b[index_i][index_j]==61){bishop[1][2]='B';}
                                           else{ bishop[1][2]='W';}
                                           for(index1=0;index1!=2;index1++){
                                              for(index2=0;index2!=(6);index2++){ 
                                              screen_board[index1+a][index2+b]=bishop[index1][index2];}}}      }}}}}
                                              }
                                             }
                                          }
 
  ////////////////////// second the old moves area /////////////////////////////////////////
      char gap[3]; strcpy(gap," , ");
      int index=0;
       for (index_i=5;index_i!=19;index_i++){int inc=0;
           for(index_j=65;index_j!=78;index_j++){if(old_moves[index]=='\0'){break;}
                                                 if((index_j<70)||(index_j>72)){// the gap between the moves.
                                                 screen_board[index_i][index_j]=old_moves[index];
                                                 index++;}
                                                 else{screen_board[index_i][index_j]=gap[inc];
                                                      inc++;
                                                      }}}  
 
 /////////////////////// third the turn action /////////////////////////////////////////////
       char turn1[2][6]; strcpy(turn1[0]," white"); strcpy(turn1[1]," black");
        if (turn==1){for (index_j=65;index_j!=71;index_j++){screen_board[23][index_j]=turn1[0][index_j-65] ;} } 
        else{for (index_j=65;index_j!=71;index_j++){screen_board[23][index_j]=turn1[1][index_j-65] ;}}
 
 
 /////////////////////// error handling //////////////////////////////////////////////////
       char error_array[14][70]; // array to hold the error message.
       for (index_i=0;index_i!=13;index_i++){
          for(index_j=0;index_j!=69;index_j++){error_array[index_i][index_j]='\0' ;}}
       
     if(error!=0){  
       switch (error){        
       case 1: // input error.  
               strcpy(error_array[0],"*********************************"); 
               strcpy(error_array[1],"*                               *");
               strcpy(error_array[2],"* wrong input please try again. *");
               strcpy(error_array[3],"*                               *");
               strcpy(error_array[4],"*********************************");
               for (index_i=12;index_i!=17;index_i++){
           for(index_j=23;index_j!=56;index_j++){screen_board[index_i][index_j]=error_array[index_i-12][index_j-23];}}
               break;
               // move error. //
       case 2:   
               strcpy(error_array[0],"*********************************"); 
               strcpy(error_array[1],"*                               *");
               strcpy(error_array[2],"* error you can't move an empty *");
               strcpy(error_array[3],"*             space.            *");
               strcpy(error_array[4],"*                               *");
               strcpy(error_array[5],"*********************************");
               for (index_i=11;index_i!=17;index_i++){
           for(index_j=23;index_j!=56;index_j++){screen_board[index_i][index_j]=error_array[index_i-11][index_j-23];}}
               break;
       case 3:   
               strcpy(error_array[0],"*********************************"); 
               strcpy(error_array[1],"*                               *");
               strcpy(error_array[2],"*     error duplicate move.     *");
               strcpy(error_array[3],"*                               *");
               strcpy(error_array[4],"*********************************");
               for (index_i=12;index_i!=17;index_i++){
           for(index_j=23;index_j!=56;index_j++){screen_board[index_i][index_j]=error_array[index_i-12][index_j-23];}}
               break;
       case 4:   
               strcpy(error_array[0],"*********************************"); 
               strcpy(error_array[1],"*                               *");
               strcpy(error_array[2],"*    error it's white's turn.   *");
               strcpy(error_array[3],"*                               *");
               strcpy(error_array[4],"*********************************");
               if(turn==2){char black[5]; strcpy(black,"black");
                           for (index_j=16;index_j!=21;index_j++){error_array[2][index_j]=black[index_j-16] ;}}
               for (index_i=12;index_i!=17;index_i++){
           for(index_j=23;index_j!=56;index_j++){screen_board[index_i][index_j]=error_array[index_i-12][index_j-23];}}
               break;        
       case 5:   
               strcpy(error_array[0],"**********************************"); 
               strcpy(error_array[1],"*                                *");
               strcpy(error_array[2],"* A king may only move one space *");
               strcpy(error_array[3],"*        in any direction.       *");
               strcpy(error_array[4],"*                                *");
               strcpy(error_array[5],"**********************************");
               for (index_i=11;index_i!=17;index_i++){
           for(index_j=22;index_j!=56;index_j++){screen_board[index_i][index_j]=error_array[index_i-11][index_j-22];}}
               break;
       case 6:   
               strcpy(error_array[0],"*********************************"); 
               strcpy(error_array[1],"*                               *");
               strcpy(error_array[2],"*   error the path is blocked.  *");
               strcpy(error_array[3],"*                               *");
               strcpy(error_array[4],"*********************************");
               for (index_i=12;index_i!=17;index_i++){
           for(index_j=23;index_j!=56;index_j++){screen_board[index_i][index_j]=error_array[index_i-12][index_j-23];}}
               break;
       case 7:   
               strcpy(error_array[0],"**********************************"); 
               strcpy(error_array[1],"*                                *");
               strcpy(error_array[2],"* Rooks may move up,down,left or *");
               strcpy(error_array[3],"* right any number of spaces in  *");
               strcpy(error_array[4],"*       a straight line          *");
               strcpy(error_array[5],"*                                *");
               strcpy(error_array[6],"**********************************");
               for (index_i=11;index_i!=18;index_i++){
           for(index_j=22;index_j!=56;index_j++){screen_board[index_i][index_j]=error_array[index_i-11][index_j-22];}}
               break;
       case 8:   
               strcpy(error_array[0],"**********************************************"); 
               strcpy(error_array[1],"*                                            *");
               strcpy(error_array[2],"* Knights may move one space up or down and  *");
               strcpy(error_array[3],"*   two spaces right or left vice-versa.     *");
               strcpy(error_array[4],"* The knight is the only piece that can jump *");
               strcpy(error_array[5],"*   over the other pieces.                   *");
               strcpy(error_array[6],"*                                            *");
               strcpy(error_array[7],"**********************************************");
               for (index_i=10;index_i!=18;index_i++){
           for(index_j=16;index_j!=62;index_j++){screen_board[index_i][index_j]=error_array[index_i-10][index_j-16];}}
               break; 
       case 9:     
               strcpy(error_array[0],"***********************************"); 
               strcpy(error_array[1],"*                                 *");
               strcpy(error_array[2],"* bishops may move diagonally any *");
               strcpy(error_array[3],"*  number of spaces in the same   *");
               strcpy(error_array[4],"*            diagonal             *");
               strcpy(error_array[5],"*                                 *");
               strcpy(error_array[6],"***********************************");
               for (index_i=11;index_i!=18;index_i++){
           for(index_j=21;index_j!=56;index_j++){screen_board[index_i][index_j]=error_array[index_i-11][index_j-21];}}
               break;
       case 10:     
               strcpy(error_array[0],"****************************************"); 
               strcpy(error_array[1],"*                                      *");
               strcpy(error_array[2],"* Queens may move any number of spaces *");
               strcpy(error_array[3],"*  in any of the eight directions in   *");
               strcpy(error_array[4],"*          a straight line.            *");
               strcpy(error_array[5],"*                                      *");
               strcpy(error_array[6],"****************************************");
               for (index_i=11;index_i!=18;index_i++){
           for(index_j=18;index_j!=58;index_j++){screen_board[index_i][index_j]=error_array[index_i-11][index_j-18];}}
               break;  
       case 11:   
               strcpy(error_array[0],"************************************************"); 
               strcpy(error_array[1],"*                                              *");
               strcpy(error_array[2],"* Pawns may only move one space forward or two *");
               strcpy(error_array[3],"*          if they didn't move before.         *");
               strcpy(error_array[4],"* Pawns can capture other pieces by moving up  *");
               strcpy(error_array[5],"*            one space diagonally.             *");
               strcpy(error_array[6],"*                                              *");
               strcpy(error_array[7],"************************************************");
               for (index_i=10;index_i!=18;index_i++){
           for(index_j=15;index_j!=63;index_j++){screen_board[index_i][index_j]=error_array[index_i-10][index_j-15];}}
               break; 
       case 12:     
               strcpy(error_array[0],"********************************************"); 
               strcpy(error_array[1],"*                                          *");
               strcpy(error_array[2],"* The pawn is about to transform to one of *");
               strcpy(error_array[3],"*  these pieces please enter your choice   *");
               strcpy(error_array[4],"*   for a queen enter 1                    *");
               strcpy(error_array[5],"*   for a rook enter 2                     *");
               strcpy(error_array[6],"*   for a knight enter 3                   *");
               strcpy(error_array[7],"*   for a bishop enter 4                   *");
               strcpy(error_array[8],"*                                          *");
               strcpy(error_array[9],"********************************************");
               for (index_i=10;index_i!=20;index_i++){
           for(index_j=16;index_j!=60;index_j++){screen_board[index_i][index_j]=error_array[index_i-10][index_j-16];}}
               break;
        case 16:     
               strcpy(error_array[0], "********************************************"); 
               strcpy(error_array[1], "*                                          *");
               strcpy(error_array[2], "*                                          *");
               strcpy(error_array[3], "*                                          *");
               strcpy(error_array[4], "*                                          *");
               strcpy(error_array[5], "*                                          *");
               strcpy(error_array[6], "*                                          *");
               strcpy(error_array[7], "*                                          *");
               strcpy(error_array[8], "*                                          *");
               strcpy(error_array[9], "*                                          *");
               strcpy(error_array[10],"*                                          *");
               strcpy(error_array[11],"*                                          *");
               strcpy(error_array[12],"********************************************");
               for (index_i=8;index_i!=21;index_i++){
           for(index_j=16;index_j!=60;index_j++){screen_board[index_i][index_j]=error_array[index_i-8][index_j-16];}}
               break;                                                   }}               
 ///////////////////////////////////////////////////////////// showing the screen //////////////////
      for (index_i=0;index_i!=30;index_i++){for(index_j=0;index_j!=80;index_j++)cout<<screen_board[index_i][index_j];}}
 
 
 
 
 /*******************************************************
  *                   'Delay()'                         *
  *  A function that cause a time delay to show the     *
  *                     screen.                         *
  * Parameters: 1)time: an integer to define the delay  *
  *                    time.                            *
  * Return: void.                                       *
  *******************************************************/
  void delay(int time){   
    long int delay=0;
     while(delay<time*100000000){++delay;}}


 /***************************************************************
  *                     'welcome()'                             *
  * A function that shows the welcome screen.                   *
  * Parameters: 1) choice: an char represent the user's choice. *
  * Returns: void.                                              *
  ***************************************************************/
 void welcome(char &choice){ 

  
    cout<<"********************************************************************************";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*        ******     **                                                         *";
    cout<<"*      **********   **                                                         *";
    cout<<"*    ***            **                                                         *";
    cout<<"*   ***             **            ****       ****        ****                  *";
    cout<<"*   ***             **          ********   ***  ***    ***  ***                *";
    cout<<"*   ***             ** ****    ***    *** ***         ***                      *";
    cout<<"*   ***             ****  **   **********   ******      ******                 *";
    cout<<"*    ***            ***    **  ***             *****       *****               *";
    cout<<"*      **********   **     **   ****       ***   **    ***   **                *";
    cout<<"*       *******     **     **     ****       *****       *****                 *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                        ' welcome to chess game '                             *";
    cout<<"*                                                                              *";
    cout<<"*                         press enter to continue.                             *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                          v1.0*";
    cout<<"********************************************************************************";
  
  cin.get();
  system("cls");
  
    cout<<"********************************************************************************";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*   Hello this is the chess v1.0 ,a chess game that applies to the standards   *";
    cout<<"*   rules of the chess game, please enter your choice.                         *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*   1. How to play ?.                                                          *";
    cout<<"*   2. Play the game.                                                          *";
    cout<<"*   3. exit the game.                                                          *";
    cout<<"*                                                                              *";
    cout<<"*   4. credits.                                                                *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                          v1.0*";
    cout<<"********************************************************************************";
  
  while(1){ 
  cin>>choice;
  
  if(int(choice)-48==1){
    system("cls");            
    cout<<"********************************************************************************";
    cout<<"*                                                                              *";
    cout<<"*   To move a piece you need to enter the coordinates of the old position in   *";
    cout<<"*   the board followed by '-' then the coordinates of the new position in the  *";
    cout<<"*   board.                                                                     *";
    cout<<"*                                                                              *";
    cout<<"*  For example to move the black queen from A1 to C2 you simply enter A1-C2    *";
    cout<<"*  - before the  black queen is in the position A1 .                           *";
    cout<<"*      +------+------+------+------+                                           *";
    cout<<"*      |   A  |   B  |   C  |   D  |                                           *";
    cout<<"*      +------|------|------|------|                                           *";
    cout<<"* +-+  +------|------|------|------|                                           *";
    cout<<"* |1|  | Queen|      |      |      |                                           *";
    cout<<"* | |  |  B   |      |      |      |                                           *";
    cout<<"* +-|  |------|------|------|------|                                           *";
    cout<<"* |2|  |      |      |      |      |  - after you entered A1-C2 .              *";
    cout<<"* | |  |      |      |      |      |             +------+------+------+------+ *";
    cout<<"* +-|  |------|------|------|------|             |   A  |   B  |   C  |   D  | *";
    cout<<"*                                                +------|------|------|------| *";
    cout<<"*                                           +-+  +------|------|------|------| *";
    cout<<"*                                           |1|  |      |      |      |      | *";
    cout<<"*                                           | |  |      |      |      |      | *";
    cout<<"*                                           +-|  |------|------|------|------| *";
    cout<<"*                                           |2|  |      |      | Queen|      | *";
    cout<<"*                                           | |  |      |      |  B   |      | *";
    cout<<"*                                           +-|  |------|------|------|------| *";
    cout<<"*                                                                              *";
    cout<<"*                           press enter to continue.                           *";
    cout<<"*                                                                          v1.0*";
    cout<<"********************************************************************************";
    
    cin.get(); 
    cin.get(); 
    system("cls");
    
    cout<<"********************************************************************************";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*   After you knew how to play now her is some key words you might need        *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*      To undo the last move you simply enter 'undom' or 'UNDOM'.              *";
    cout<<"*                                                                              *";
    cout<<"*      To restart the game over again you enter 'ngame' or 'NGAME'.            *";
    cout<<"*                                                                              *";
    cout<<"*      To exit the game you enter 'exitg' or 'EXITG'.                          *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                                                                              *";
    cout<<"*                      press enter to start the game.                          *";
    cout<<"*                                                                          v1.0*";
    cout<<"********************************************************************************";
    
    choice='2';
    cin.get(); 
    system("cls");
    break; }
    
    else{if(int(choice)-48==2){system("cls");
                               break;}
         else{if(int(choice)-48==3){system("cls");
                   cout<<"********************************************************************************";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*   ok thanks , it feels sad to see you go                                     *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                          v1.0*";
                   cout<<"********************************************************************************";
                                    delay(3);
                                    break;}
              else{if(int(choice)-48==4){system("cls");
                                         cout<<"********************************************************************************";
                                         cout<<"*                                                                              *";
                                         cout<<"*            By the name of Allah the merciful ,the compassionate              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*             Essalamo alikom wa rahmato Allah taala wa barakatoh .            *";
                                         cout<<"*                                                                              *";
                                         cout<<"*          My full name is Nasreddine Galfout but I like to be named           *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                          Nacereddine Abed elillah                            *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                This is my first game in c++ I hope you like it.              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*       If you found any bugs please send me an email describing the bug       *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                     My email is nacereddin.14@hotmail.com                    *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                         press enter to continue.                             *";
                                         cout<<"*                                                                          v1.0*";
                                         cout<<"********************************************************************************";
                                         cin.get(); cin.get(); 
                                         
                                         system("cls");
  
                                         cout<<"********************************************************************************";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*   Hello this is the chess v1.0 ,a chess game that applies to the standars    *";
                                         cout<<"*   rules of the chess game, please enter your choice.                         *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*   1. How to play ?.                                                          *";
                                         cout<<"*   2. Play the game.                                                          *";
                                         cout<<"*   3. exit the game.                                                          *";
                                         cout<<"*                                                                              *";
                                         cout<<"*   4. credits.                                                                *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                              *";
                                         cout<<"*                                                                          v1.0*";
                                         cout<<"********************************************************************************";
                                         }
                   else{system("cls"); choice='\0';
                   cout<<"********************************************************************************";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*   Invalid entry please try again.                                            *";
                   cout<<"*                                                                              *";
                   cout<<"*   1. How to play ?.                                                          *";
                   cout<<"*   2. Play the game.                                                          *";
                   cout<<"*   3. exit the game.                                                          *";
                   cout<<"*                                                                              *";
                   cout<<"*   4. credits.                                                                *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                              *";
                   cout<<"*                                                                          v1.0*";
                   cout<<"********************************************************************************";}}}}
                   }
    
    
    }  

/***************************************************************************************
 *                                   'start_up()'                                      *
 *     A function that puts all the pieces in there start up positions,also initialize *
 *                    the turn integer and the old_moves array                         *
 * Parameters: 1)board: an array to hold the start up positions.                       *
 *             2)old_moves: an array of characters wish holds the last 28 moves.       *
 *             3)turn: an integer that refers to wish player is going to play now.     *
 * Returns: void.                                                                      *
 ***************************************************************************************/
 
 
 void start_up(int board[][8],char old_moves[],int &turn){
     int index; // index to board.
     
     turn=1;// first turn white.
     
     for (index=0;index!=140;index++){old_moves[index]='\0';} // clear old_moves.
     
     
  //the empty : represented by 0.
  //the king : represented by 10 (if black by 11).
  //the queen : represented by 20 (if black by 21).
  //the rook : represented by 30 (if black by 31).
  //the pawn : represented by 40 (if black by 41) 401 and 400 before the first move.
  //the knight : represented by 50 (if black by 51).
  //the bishop : represented by 60 (if black by 61).

  board[0][0]=301;  board[0][1]=51;  board[0][2]=61;  board[0][3]=21;  board[0][4]=101;  board[0][5]=61;  board[0][6]=51;  board[0][7]=301;
//black rook       black knight     black bishop     black queen      black king       black bishop     black knight     black rook
  board[1][0]=401;  board[1][1]=401;  board[1][2]=401;  board[1][3]=401;  board[1][4]=401;  board[1][5]=401;  board[1][6]=401;  board[1][7]=401;
//black pawn       black pawn       black pawn       black pawn       black pawn       black pawn       black pawn       black pawn  
  board[2][0]=0;   board[2][1]=0;   board[2][2]=0;   board[2][3]=0;   board[2][4]=0;   board[2][5]=0;   board[2][6]=0;   board[2][7]=0;
//empty            empty            empty            empty            empty            empty            empty            empty  
  board[3][0]=0;   board[3][1]=0;   board[3][2]=0;   board[3][3]=0;   board[3][4]=0;   board[3][5]=0;   board[3][6]=0;   board[3][7]=0;
//empty            empty            empty            empty            empty            empty            empty            empty  
  board[4][0]=0;   board[4][1]=0;   board[4][2]=0;   board[4][3]=0;   board[4][4]=0;   board[4][5]=0;   board[4][6]=0;   board[4][7]=0;
//empty            empty            empty            empty            empty            empty            empty            empty    
  board[5][0]=0;   board[5][1]=0;   board[5][2]=0;   board[5][3]=0;   board[5][4]=0;   board[5][5]=0;   board[5][6]=0;   board[5][7]=0;
//empty            empty            empty            empty            empty            empty            empty            empty   
  board[6][0]=400;  board[6][1]=400;  board[6][2]=400;  board[6][3]=400;  board[6][4]=400;  board[6][5]=400;  board[6][6]=400;  board[6][7]=400;
//white pawn       white pawn       white pawn       white pawn       white pawn       white pawn       white pawn       white pawn
  board[7][0]=300;  board[7][1]=50;  board[7][2]=60;  board[7][3]=20;  board[7][4]=100;  board[7][5]=60;  board[7][6]=50;  board[7][7]=300;
//white rook       white knight     white bishop     white queen      white king       white bishop     white knight     white rook
    }
