//�������j�b�g�@C����@���Q�@��������
//1423056�@�n糁@�ā@2014/1/16

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int l;
	srand((unsigned)time(NULL));
	for(l = 0;l<10;l++)
		printf("%2d:%d\n",l+1,rand()%10+1);
	
    return 0;
}