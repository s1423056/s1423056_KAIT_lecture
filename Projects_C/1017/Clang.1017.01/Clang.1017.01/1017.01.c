//�������j�b�g�@C����@���1�@10�̕ϐ��𗘗p���Ēl���L�����A���ϒl�����߂�
//1423056�@�n糁@�ā@2014/10/17

#include <stdio.h>

int main(){
	int num,i;
	float all = 0;
	for(i = 1;i<=10;i++){
		printf("%d��ڐ�������́F",i);
		scanf("%d",&num);
		all=all+num;
	}
	all=all/10.0;
	printf("���ς́F%f\n",all);
    return 0;
}