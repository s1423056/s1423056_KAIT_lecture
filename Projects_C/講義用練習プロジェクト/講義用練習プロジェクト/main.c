#include <stdio.h>
#include <string.h>

int main(){
	char input[81];
	int loop,num = 0;
	printf("��������͂��Ă�������\n");
	scanf("%s",input);

	for(loop = 0;loop < strlen(input); loop++){
		if( ('0' <= input[loop]) && (input[loop] <= '9') ){
			num = 10*num+input[loop]-'0';
		}else{
			printf("�������͂ɂȂ��Ă��܂���\n");
			return 1;
		}
	}

	printf("���l�F%d\n",num);
	return 0;
}