//�������j�b�g�@C����@���2�@�\���̂̊�b�Q
//1423056�@�n糁@�ā@2014/12/12

#include <stdio.h>
#include <string.h>
struct Address_data{
	char name[81];
	char phone[20];
	int age;
};

int main(){
	struct Address_data data1,data2;
	// data1�̐ݒ�
	strcpy(data1.name,"Alex");
	strcpy(data1.phone,"046-000-0001");
	data1.age = 12;
	// data2�̐ݒ�
	strcpy(data2.name,"Bonnie");
	strcpy(data2.phone,"046-000-0002");
	data2.age = 13;
	// data1,data2�̓��e�\��
	printf("%s\t(%d)\t[%s]\n",data1.name,data1.age,data1.phone);
	printf("%s\t(%d)\t[%s]\n",data2.name,data2.age,data2.phone);
    return 0;
}