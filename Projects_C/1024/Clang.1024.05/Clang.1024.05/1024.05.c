//�������j�b�g�@C����@���5�@2�����z��̗��p
//1423056�@�n糁@�ā@2014/10/24

#include <stdio.h>

int main(){
	int num1,num2,repeat;
	int a[5][5] ={{0,3180,11540,14390,14920},{3240,0,10910,13660,14600},{11540,3240,0,6100,6840},{0,0,0,0,3240}};
	do{
		printf("�o���w�F");
		scanf("%d",&num1);
		printf("�����w�F");
		scanf("%d",&num2);
		
		switch(num1){
		case 1:
			printf("�����w");
			break;
		case 2:
			printf("�V���l�w");
			break;
		case 3:
			printf("���É��w");
			break;
		case 4:
			printf("���s�w");
			break;
		case 5:
			printf("�V���w");
			break;
		}
		printf("����");

		switch(num2){
		case 1:
			printf("�����w");
			break;
		case 2:
			printf("�V���l�w");
			break;
		case 3:
			printf("���É��w");
			break;
		case 4:
			printf("���s�w");
			break;
		case 5:
			printf("�V���w");
			break;
		}
	printf("�܂�");

	if(num1 > num2){
			int t = num2;
			num2 = num1;
			num1 = t;
		}
		printf("%d�~\n",a[num1-1][num2-1]);
		printf("������x�F1    �I���F0\n");
		scanf("%d",&repeat);
	}while(repeat == 1);
    return 0;
}