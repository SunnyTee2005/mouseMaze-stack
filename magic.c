#include <stdio.h>
#include <string.h>
#include "magic.h"

static char maze[SIZE][SIZE] ={
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
char mark[9][9] = {0};

//在迷宮中移動
coo_t findMove(stack_t *s, coo_t position){
    int dx[4] = { 1, 0,-1, 0};
    int dy[4] = { 0, 1, 0,-1};
    for(int d=0; d<4; d++){
      coo_t current;
      current.x = position.x + dx[d];
      current.y = position.y + dy[d];
      //checck
      if(maze[current.x][current.y] == 0 && mark[current.x][current.y] != 'x'){
        mark[current.x][current.y] = '*';
        push(s, current);
      }
    }
    return pop(s);
}

 
int main(void){
  stack_t pocket;       // 堆疊的資料結構，放 
  coo_t currentPosition;
  coo_t entry = {1,1};
  coo_t out = {7,7};
  coo_t noExit = {-1,-1};

  pocket.top = -1;
  currentPosition = entry;
  mark[currentPosition.x][currentPosition.y] = 'x';

  //不知道要執行幾次，用while loop
  while( currentPosition.x != out.x && currentPosition.y != out.y){
    currentPosition = findMove(&pocket, currentPosition);
    if(currentPosition.x == noExit.x && currentPosition.y == noExit.y/*現在位置==(-1,-1)*/){
      printf("There's no exit.\n");
      break;
    }
    printf("Move to %d, %d\n",currentPosition.x, currentPosition.y);
  }
  return 0;
}
