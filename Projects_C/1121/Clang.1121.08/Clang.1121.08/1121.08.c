//�������j�b�g�@C����@���8�@�����ƕ�����̒u��
//1423056�@�n糁@�ā@2014/11/21
#include <stdio.h>
#include <string.h>

int main(){
	char moji[80],moji2[2],moji3[160];
	int loop,loop2;

	printf("�Ώە�����F");
	scanf("%s",moji);
	printf("�u���������F");
	scanf("%s",moji2);
	printf("�u��������F");
	scanf("%s",moji3);

	for(loop = 0;loop < strlen(moji);loop++){
		if(moji[loop] == moji2[0]){
			for(loop2 = strlen(moji); loop2 > loop; loop2--){
				moji[loop2+strlen(moji3)-1] = moji[loop2];
			}
			for(loop2 = loop;loop2<loop+strlen(moji3);loop2++){
				moji[loop2] = moji3[loop2-loop];
			}
		}
	}
	printf("���ʕ�����F%s\n",moji);
	return 0;
}