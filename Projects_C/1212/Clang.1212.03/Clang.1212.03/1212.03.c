//導入ユニット　C言語　問題3　構造体の基礎３
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

int main(){
	struct Address_data data1,data2;
	// data1の設定
	printf("data1の設定\n");
	input(&data1);
	// data2の設定
	printf("data2の設定\n");
	input(&data2);
	// data1,data2の内容表示
	printf("%s\t(%d)\t[%s]\n",data1.name,data1.age,data1.phone);
	printf("%s\t(%d)\t[%s]\n",data2.name,data2.age,data2.phone);
    return 0;
}