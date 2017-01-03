#include "mydef.h"

void printData(int data[WMAX][HMAX]){
	int x,y;

	for(y=0;y<HMAX;y++){
		for(x=0;x<WMAX;x++){
			switch(data[x][y]){
			case WHITE:printf(" ");break;
			case BLACK:printf("¡");break;
			case START:printf("‚r");break;
			case GOAL:printf("‚f");break;
			}
		}
		printf("\n");
	}
	return;
}