//�������j�b�g�@C����@���3�@�t�@�C�����琔�l�̓ǂݎ��
//1423056�@�n糁@�ā@2014/10/31

#include <stdio.h>

int main(){
	FILE *fp;
	int num[20],loop,ave = 0,max = 0,min = 0;
	fp = fopen("input.txt","w");
	fprintf(fp,"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n");
	fclose(fp);
	fp = fopen("input.txt","r");
	for(loop = 0;loop<20;loop++){
		
		fscanf(fp,"%d",&num[loop]);
		printf("%d�Ԗڂ̐��l�F%d\n",loop+1,num[loop]);
		ave += num[loop];
		if(max < num[loop]) max = num[loop];
		if(min > num[loop]) min = num[loop];
		if(loop == 0){
			min = max = num[0];
		}else{
			if(max < num[loop]) max = num[loop];
			if(min > num[loop]) min = num[loop];
		}
	}
	ave /= 20;
	
	printf("�ő�l�F%d\n",max);
	printf("�ŏ��l�F%d\n",min);
	printf("���ϒl�F%d\n",ave);
    return 0;
}