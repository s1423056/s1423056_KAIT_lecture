//�������j�b�g�@C����@���3�@�啶���������ϊ�
//1423056�@�n糁@�ā@2014/11/21

#include <stdio.h>

int main(){
	char moji[80];
	int loop;
	scanf("%s",moji);
	for(loop = 0; loop < 80;loop++){
		if('a'<=moji[loop] && moji[loop] <= 'z'){
			moji[loop]-=32;
		}else if('A'<=moji[loop] && moji[loop] <= 'Z'){
			moji[loop]+=32;
		}
	}
	printf("%s\n",moji);

    return 0;
}