//�������j�b�g�@C����@���5�@�t�@�C���ɂ��鐔�������ׂēǂݍ���
//1423056�@�n糁@�ā@2014/10/31

#include <stdio.h>

int main(){
	FILE *fp;
	double num = 0,sum = 0,ave = 0,var = 0,pro = 0;
	int count = 0;

	if((fp = fopen("input.txt","r")) == NULL){
		printf("�t�@�C�����J���܂���B\n");
		return 1;
	}
	while((fscanf(fp,"%lf",&num) != EOF)){
		sum += num;
		pro += (num*num);
		
		count++;
		printf("%lf\n",num);
	}
	ave = sum / count;
	rewind(fp);

	while((fscanf(fp,"%lf",&num) != EOF)){
		var += (num-ave)*(num-ave);
	}
	var /= count;

	printf("���v�F%lf\n",sum);
	printf("���l�̌��F%d\n",count);
	printf("���ϒl�F%lf\n",ave);
	printf("���U�F%lf\n",var);

	fclose(fp);

    return 0;
}