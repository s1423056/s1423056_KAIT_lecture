//導入ユニット　C言語　問題4　構造体の配列利用
//1423056　渡邉　翔　2014/12/12

#include <stdio.h>
#include <string.h>

struct Address_data{
	char name[81];
	char phone[20];
	int age;
};

void input(struct Address_data *ad){
	int i;
	printf("名前：");
	scanf("%s",ad -> name);
	printf("年齢：");
	scanf("%d",&i);
	ad -> age = i;
	printf("電話番号：");
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
		printf("data%dの入力\n",i+1);
		input(&data[i]);
	}
	datasort(data);
	printf("表示\n");
	for(i = 0;i<10;i++)
	{
		printf("%s\t(%d)\t%s\n",data[i].name,data[i].age,data[i].phone);
	}
    return 0;
}