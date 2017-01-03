//導入ユニット　C言語　問題4　迷路の第一歩
//1423056　渡邉　翔　2014/1/16

#include "mydef.h"
#include <stdlib.h>
#include <time.h>
void initialize(int data[WMAX][HMAX]);
void randPlot(int data[WMAX][HMAX],BLOCK_IMAGE CO);
void printData(int data[WMAX][HMAX]);

int main(){
	int maze[WMAX][HMAX],loop;
	initialize(maze);
	srand((unsigned)time(NULL));
	for(loop = 0;loop<20;loop++)
		randPlot(maze,BLACK);
	printData(maze);
    return 0;
}