//導入ユニット　C言語　問題2　構造体の基礎２
//1423056　渡邉　翔　2014/12/12

#include <stdio.h>
#include <string.h>
struct Address_data{
	char name[81];
	char phone[20];
	int age;
};

int main(){
	struct Address_data data1,data2;
	// data1の設定
	strcpy(data1.name,"Alex");
	strcpy(data1.phone,"046-000-0001");
	data1.age = 12;
	// data2の設定
	strcpy(data2.name,"Bonnie");
	strcpy(data2.phone,"046-000-0002");
	data2.age = 13;
	// data1,data2の内容表示
	printf("%s\t(%d)\t[%s]\n",data1.name,data1.age,data1.phone);
	printf("%s\t(%d)\t[%s]\n",data2.name,data2.age,data2.phone);
    return 0;
}