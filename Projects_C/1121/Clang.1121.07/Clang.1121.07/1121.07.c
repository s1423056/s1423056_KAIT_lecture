//�������j�b�g�@C����@���7�@strcmp()�̗��p
//1423056�@�n糁@�ā@2014/11/21

#include <stdio.h>
#include <string.h>

int main(){
	FILE *fp;
	char str[16],input[80];
	int hindo = 0;
	if( (fp = fopen("input3.txt","r")) == NULL ) {
		printf("File Open Error!\n");
		return 1;
	}
	printf("����������������F");
	scanf("%s",str);
	while(fscanf(fp,"%s",input) != EOF){
		if(strcmp(str,input) == 0){
			hindo += 1;
		}
	}
	printf("����������̐��F%d\n",hindo);
    return 0;
}