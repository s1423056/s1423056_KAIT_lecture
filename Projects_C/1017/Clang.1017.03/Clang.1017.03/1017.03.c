//�������j�b�g�@C����@���3�@���U�����߂�
//1423056�@�n糁@�ā@2014/10/17

#include <stdio.h>

int main(){
	int num1,num2,num3,num4;
	float all,var;
		printf("1��ڐ�������́F");
		scanf("%d",&num1);
		printf("2��ڐ�������́F");
		scanf("%d",&num2);
		printf("3��ڐ�������́F");
		scanf("%d",&num3);
		printf("4��ڐ�������́F");
		scanf("%d",&num4);

	all = (num1+num2+num3+num4)/4.0;
	var = ((num1 - all)*(num1 - all)+(num2 - all)*(num2 - all)+(num3 - all)*(num3 - all)+(num4 - all)*(num4 - all))/4;

	printf("���ς́F%f\n",all);
	printf("���U�́F%f\n",var);
    return 0;
}