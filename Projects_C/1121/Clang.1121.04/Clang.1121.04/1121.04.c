//�������j�b�g�@C����@���4�@�t�@�C�����o��
//1423056�@�n糁@�ā@2014/11/21

#include <stdio.h>

int main(){
	FILE *fp1,*fp2;
	char moji[80];
	int loop;

	fp1 = fopen("input.txt","r");
	fp2 = fopen("output.txt","w");

	fscanf(fp1,"%s",moji);
	for(loop = 0; loop < 80;loop++){
		if('a'<=moji[loop] && moji[loop] <= 'z'){
			moji[loop]-=('a'-'A');
		}else if('A'<=moji[loop] && moji[loop] <= 'Z'){
			moji[loop]+=('a'-'A');
		}
	}
	printf("%s\n",moji);
	fprintf(fp2,"%s",moji);
	fclose(fp2);
	fclose(fp1);
    return 0;
}