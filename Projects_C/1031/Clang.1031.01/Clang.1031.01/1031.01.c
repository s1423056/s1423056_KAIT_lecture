//�������j�b�g�@C����@���1�@�v���O�������s�J�E���^�̍쐬
//1423056�@�n糁@�ā@2014/10/31

#include <stdio.h>

int main(){
	FILE *FP;
	int num;
	if((FP = fopen("log.txt","r")) == NULL){
		printf("���߂Ă̎��s\n");
		num = 1;
	}else{
		fscanf(FP,"%d",&num);
		num++;
		printf("%d��ڂ̎��s\n",num);
		fclose(FP);
	}
	if((FP = fopen("log.txt","w")) == NULL){
		printf("File���J���܂���\n");
		return(1);
	}
	fprintf(FP,"%d",num);
	fclose(FP);
	return (0);

}