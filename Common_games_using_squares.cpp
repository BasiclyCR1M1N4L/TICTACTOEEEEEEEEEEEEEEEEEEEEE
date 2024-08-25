#include <iostream>
#include <chrono>


using namespace std;

class GridSquare{
  public:
    int state = -1;//-1 means empty 0 means O 1 means X
    int pos;// what part of the board is this square
    GridSquare(int x){
      pos = x;
      state = -1;
    }
    char drawSpace(){
      if(state == 0){
        return 'O';
      }
      else if (state == 1){
        return 'X';
      }
      else{
        cout << pos;
        return (char) pos;
      }
    }
};

class TicTacToe{
  public:
    int cols = 3;
    int rows = 3;
    int totalTurns =0;
    int winner = -1;

    enum GameState{
      OVER, RUNNING
    };
    enum GameState currentState = OVER;
    GridSquare board[3][3];
    TicTacToe() : board{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    } {
      currentState = RUNNING;
      playGame();

    }
    void playGame(){
      while (currentState == RUNNING){
        drawBoard();
        makeMove();
      }
      if (currentState == OVER){
        displayGameOver();
      }
    }
    void drawBoard(){
      cout << " " << board[0][0].drawSpace() << " | " << board[0][1].drawSpace() << " | " << board[0][2].drawSpace() << endl;
      cout << "-----------" << endl;
      cout << " " << board[1][0].drawSpace() << " | " << board[1][1].drawSpace() << " | " << board[1][2].drawSpace() << endl;
      cout << "-----------" << endl;
      cout << " "/* space? */ << board[2][0].drawSpace() << " | " << board[2][1].drawSpace() <<" | " << board[2][2].drawSpace() << endl;
    }

    void makeMove(){
      cout << "Hey, player " << getPlayer() << ", enter a number from 1-9 to make your move" << endl;
      int spot;
      cin >> spot;
      for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
          if (board[i][j].pos == spot && board[i][j].state == -1){
            board[i][j].state = totalTurns % 2;
            totalTurns++;
            checkWin(i,j, board[i][j].state);
          }
        }
      }
    }
    void displayGameOver(){
      drawBoard();
      cout << "Game Over" << endl;
      if (winner == 0){
        cout << "O Wins" << endl;
      }
      else if (winner == 1){
        cout << "X Wins" << endl;
      }
      else if (totalTurns == 9){
        cout << "Tie" << endl;
      }
    }
    char getPlayer(){
      if (totalTurns % 2 == 0){
        return 'O';
      }
      return 'X';
    }
    void checkWin(int x, int y, int turn){
      int colWin = 0;
      int rowWin = 0;
      int diag1Win = 0;
      int diag2Win = 0;
      for (int next = 0; next<3; next++){
        if (board[x][next].state == turn){
          colWin++;
        }
        if (board[next][y].state == turn){
          rowWin++;
        }
        if (board[next][next].state == turn){
          diag1Win++; 
        }
        if (board[next][2- next].state == turn){
          diag2Win++;
        }
      }
      if (colWin == 3 || rowWin == 3 || diag1Win == 3 || diag2Win == 3){
        winner = turn;
        if (winner != -1){
          currentState = OVER;
        }
      }
      if (totalTurns==9){
        currentState = OVER;
      }
    }
};

int main() {
  TicTacToe game;
  

  return 0;
  
}
