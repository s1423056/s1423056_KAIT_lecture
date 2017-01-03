//導入ユニット　C言語　問題6　総合復習
//1423056　渡邉　翔　2014/12/19

#include <stdio.h>

typedef struct ITEM{
	int itemID;
	int num;
}Item;

//データ初期化
void initialize(Item *i[]){
	i[0]->itemID = 4;
	i[0]->num = 3;
	i[1]->itemID = 1;
	i[1]->num = 5;
	i[2]->itemID = 2;
	i[2]->num = 10;
	i[3]->itemID = 5;
	i[3]->num = 2;
	i[4]->itemID = 3;
	i[4]->num = 6;
}

//データ表示
void itemlist(Item *i[]){
	int loop;
	for(loop = 0; loop < 5; loop++)
		printf("ID:%d、%d個\n",i[loop]->itemID,i[loop]->num);
}

//データソート
int sort(Item *i[]){
	int n,loop,loop2;
	Item *tmp;	
	printf("1:番号順、2:個数が多い順、0:終了\n");
	scanf("%d",&n);
	switch(n){
	case 1:
		for(loop = 0;loop < 4;loop++){
			for(loop2 = loop;loop2 < 5;loop2++){
				if(i[loop]->itemID > i[loop2]->itemID){
					tmp = i[loop];
					i[loop] = i[loop2];
					i[loop2] = tmp;
				}
			}
		}
		itemlist(i);
		break;
	case 2:
		for(loop = 0;loop < 4;loop++){
			for(loop2 = loop;loop2 < 5;loop2++){
				if(i[loop]->num < i[loop2]->num){
					tmp = i[loop];
					i[loop] = i[loop2];
					i[loop2] = tmp;
				}
			}
		}
		itemlist(i);
		break;
	case 0:
		printf("終了します。\n");
		break;
	default:
		printf("不正な入力です。\n");
	}
	return n;
}

//メイン関数
int main(){
	Item item[5];
	Item *ptr[5];
	int loop,num;
	for(loop = 0;loop < 5;loop++)
		ptr[loop] = &item[loop];
	initialize(ptr);
	itemlist(ptr);
	do{
		printf("ソートします。整数を入力してください。\n");
		num = sort(ptr);//sort関数内で0が入力された場合whileループ終了
	}while(num != 0);
    return 0;
}