//�������j�b�g�@C����@���5�@��������̘a
//1423056�@�n糁@�ā@2014/10/17

#include <stdio.h>

int main(){
	float begin,end,dif = 0,total = 0;
	int num,i;
	printf("�����F");
	scanf("%f",&begin);
	printf("�����F");
	scanf("%f",&end);
	printf("�����F");
	scanf("%d",&num);

	printf("�����𗘗p���ċ��߂�ꍇ�F%f\n",num*(begin+end)/2);

	dif = (end - begin)/(num - 1);

	for(i = 0;i<num;i++){
		total += (begin+dif*i);
	}
	printf("1���̍��������������킹��ꍇ�F%f\n",total);
    return 0;
}