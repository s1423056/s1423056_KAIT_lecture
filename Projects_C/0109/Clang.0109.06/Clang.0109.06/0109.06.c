//導入ユニット　C言語　問題６　問題解決のためにプログラムを考える１
//1423056　渡邉　翔　2014/1/9

#include <stdio.h>

int main(){
	// 仕入れ価格、仕入れ個数、目標利益（純利益）
	int codeprice,codenum,targetprofit;
	// 販売個数、販売額、在庫数、合計売り上げ
	int num = 0,price = 0,totalstock = 0,totalsales = 0;

	printf("仕入れ価格："); scanf("%d",&codeprice);
	printf("仕入れ個数："); scanf("%d",&codenum);
	printf("目標利益："); scanf("%d",&targetprofit);
	printf("========================================\n");
	totalstock = codenum;

	do{
	printf("今の在庫数：%d\n",totalstock);
	printf("赤字にならない最低価格：%d\n", (codeprice - totalsales) / totalstock);
	printf("目標利益達成に必要な最低価格：%d\n", ( (codeprice + targetprofit) - totalsales ) / totalstock );
	printf("----------------------------------------\n");

	do{
	printf("販売個数："); scanf("%d",&num);
	if(num > totalstock)printf("入力された個数が不正です。\n");
	}while(num > totalstock);

	printf("販売価格："); scanf("%d",&price);
	printf("========================================\n");
	printf("\n");
	printf("========================================\n");
	totalsales += (price*num);
	totalstock -= num;
	}while(totalstock > 0);

	printf("純利益：%d\n",totalsales - codeprice);
	printf("========================================\n");
	return 0;
}