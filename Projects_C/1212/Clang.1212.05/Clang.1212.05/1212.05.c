//�������j�b�g�@C����@���4�@�\���̂̔z�񗘗p
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

void datasort(struct Address_data data[10]){
	int i,i2;
	struct Address_data dummy;
	for(i = 0; i<9;i++)
	{
		for(i2 = i+1;i2<10;i2++)
		{
			if(data[i].age > data[i2].age)
			{
				dummy = data[i];
				data[i] = data[i2];
				data[i2] = dummy;
			}
		}
	}
}

int main(){
	struct Address_data data[10];
	int i;
	for(i = 0;i<10;i++)
	{
		printf("data%d�̓���\n",i+1);
		input(&data[i]);
	}
	datasort(data);
	printf("�\��\n");
	for(i = 0;i<10;i++)
	{
		printf("%s\t(%d)\t%s\n",data[i].name,data[i].age,data[i].phone);
	}
    return 0;
}