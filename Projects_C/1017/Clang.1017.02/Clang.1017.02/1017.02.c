//�������j�b�g�@C����@���2�@�ő�E�ŏ��l�����߂�
//1423056�@�n糁@�ā@2014/10/17

#include <stdio.h>

int main(){
	int num,i,max,min;
	float all = 0;
	for(i = 1;i<=10;i++){
		printf("%d��ڐ�������́F",i);
		scanf("%d",&num);
		if(i == 1){
			max = num;
			min = num;
		}
		all=all+num;
		if(max < num)max = num;
		if(min > num)min = num;
	}
	all=all/10.0;
	printf("���ς́F%f\n",all);
	printf("�ő�l�́F%d\n",max);
	printf("�ŏ��l�́F%d\n",min);

    return 0;
}