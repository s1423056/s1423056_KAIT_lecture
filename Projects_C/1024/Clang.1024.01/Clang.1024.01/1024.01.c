//�������j�b�g�@C����@���1�@���K(�\���E�J��Ԃ��E��������)
//1423056�@�n糁@�ā@2014/10/24

#include <stdio.h>

int main(){
	int num,x,y;
	printf("3�ȏ�40�ȉ��̐���:");
	scanf("%d",&num);
	for(x = 0;x<num;++x){
		for(y=0;y<num;++y){
			if(x==0||y==0||x==(num-1)||y==(num-1))printf("*");
			else printf(" ");
		}
		printf("\n");
	}
    return 0;
}