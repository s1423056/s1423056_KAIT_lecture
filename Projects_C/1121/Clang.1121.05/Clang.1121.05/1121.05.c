//�������j�b�g�@C����@���5�@strcmp()�̗��p
//1423056�@�n糁@�ā@2014/11/21

#include <stdio.h>
#include <string.h>

int main(){
	char str[80];
	do{
		printf("�uYes�v�Ɠ��͂��Ă��������F");
		scanf("%s",str);
	}while(strcmp(str,"Yes") != 0);
    return 0;
}