//�������j�b�g�@C����@���2�@�֐��̍Ŋ�b�Q
//1423056�@�n糁@�ā@2014/11/28

#include <stdio.h>

int Lnumber(int a, int b){
	int n;
	if(a > b)return a;
	else return b;
}

int main(){
	int num;
	num = Lnumber(5,8);
	printf("%d\n",num);
    return 0;
}