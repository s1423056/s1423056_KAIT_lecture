//�������j�b�g�@C����@���4�@���H�̑���
//1423056�@�n糁@�ā@2014/1/16

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