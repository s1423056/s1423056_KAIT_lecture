//�������j�b�g�@C����@���3�@�\���̂̊�b�R
//1423056�@�n糁@�ā@2014/12/12

#include <stdio.h>
#include <string.h>

struct Address_data{
	char name[81];
	char phone[20];
	int age;
};

void input(struct Address_data *ad){
	int i;
	printf("���O�F");
	scanf("%s",ad -> name);
	printf("�N��F");
	scanf("%d",&i);
	ad -> age = i;
	printf("�d�b�ԍ��F");
	scanf("%s",ad -> phone);
}

int main(){
	struct Address_data data1,data2;
	// data1�̐ݒ�
	printf("data1�̐ݒ�\n");
	input(&data1);
	// data2�̐ݒ�
	printf("data2�̐ݒ�\n");
	input(&data2);
	// data1,data2�̓��e�\��
	printf("%s\t(%d)\t[%s]\n",data1.name,data1.age,data1.phone);
	printf("%s\t(%d)\t[%s]\n",data2.name,data2.age,data2.phone);
    return 0;
}