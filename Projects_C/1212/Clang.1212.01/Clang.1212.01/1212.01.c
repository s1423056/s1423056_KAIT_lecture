//�������j�b�g�@C����@���1�@�\���̂̊�b�P
//1423056�@�n糁@�ā@2014/12/12

#include <stdio.h>
#include <string.h>
struct Address_data{
	char name[81];
	char phone[20];
};

int main(){
	struct Address_data data1,data2;
	// data1�̐ݒ�
	strcpy(data1.name,"Alex");
	strcpy(data1.phone,"046-000-0001");
	// data2�̐ݒ�
	strcpy(data2.name,"Bonnie");
	strcpy(data2.phone,"046-000-0002");

	// data1,data2�̓��e�\��
	printf("%s\t[%s]\n",data1.name,data1.phone);
	printf("%s\t[%s]\n",data2.name,data2.phone);
    return 0;
}