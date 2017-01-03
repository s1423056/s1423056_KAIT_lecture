//導入ユニット　C言語　問題1　構造体の基礎１
//1423056　渡邉　翔　2014/12/12

#include <stdio.h>
#include <string.h>
struct Address_data{
	char name[81];
	char phone[20];
};

int main(){
	struct Address_data data1,data2;
	// data1の設定
	strcpy(data1.name,"Alex");
	strcpy(data1.phone,"046-000-0001");
	// data2の設定
	strcpy(data2.name,"Bonnie");
	strcpy(data2.phone,"046-000-0002");

	// data1,data2の内容表示
	printf("%s\t[%s]\n",data1.name,data1.phone);
	printf("%s\t[%s]\n",data2.name,data2.phone);
    return 0;
}