//導入ユニット　C言語　問題6　座席予約システム
//1423056　渡邉　翔　2014/11/28

#include <stdio.h>
#include <string.h>

// プロトタイプ関数
int regist();					// 予約
int counter();				// 予約数を確認
int registmax();			// 予約最大数を確認
int changemax();		// 予約最大数を変更
int clear();					// 予約を全消去

// メイン関数
int main()
{
	int num,num2;

	if( counter() >= registmax())
	{
		printf("予約数が最大です\n");
		return 1;
	}
	printf("数値を入力して動作を選択してください。\n1：予約　2：予約数確認　3：最大予約数変更　0：予約を全消去\n");
	scanf("%d",&num);
	switch(num)
	{
		case 0:
			clear();
			break;
		case 1:
			regist();
			break;
		case 2:
			printf("現在の予約数は%d件です\n",counter());
			break;
		case 3:
			changemax();
			break;
		default:
			printf("不正な入力です。\n");
	}
	
    return 0;
}

// 予約数を確認
int counter()
{
	FILE *fp;
	int i = 0,count = 0;
	char name[100];

	fp = fopen("zaseki.txt","r");
	while(fgets(name, 100, fp) != NULL)
	{
		if(i > 0)count++;
		i++;
	}
	fclose(fp);
	return count;
}

// 予約
int regist()
{
	FILE *fp;
	char name[100];

	if((fp = fopen("zaseki.txt","a")) == NULL)
	{
		printf("File Open Error\n");
		return 1;
	}
	printf("座席を予約します。\n名前：");
	gets_s(name,sizeof(name) - 1);
	gets_s(name,sizeof(name) - 1);
	if(name[0] != NULL)
	{
		fprintf(fp,"%s\n",name);
		printf("予約しました。\n");
	}
	else
		printf("名前の入力に失敗しました。\n");
	fclose(fp);
	return 0;
}

// 予約最大数を確認
int registmax()
{
	FILE *fp;
	char cnum[8];
	int inum = 0,loop;

	if((fp = fopen("max.txt","r")) == NULL)
	{
		printf("File Open Error\n");
		return 1;
	}
	fgets(cnum,sizeof(cnum),fp);
	for(loop = 0;loop < strlen(cnum);loop++)
	{
		if('0'<=cnum[loop] && cnum[loop] <= '9') 
		inum = inum*10+cnum[loop]-'0';
	}
	fclose(fp);
	return inum;
}

// 予約最大数を変更
int changemax()
{
	FILE *fp;
	char num[8];
	int n,loop;

	printf("座席の最大数を入力してください：");
	scanf("%d",&n);
	if((fp = fopen("max.txt","w")) == NULL)
	{
		printf("File Open Error\n");
		return 1;
	}
	sprintf(num,"%d",n);
	fputs(num,fp);
	fclose(fp);
	printf("座席の最大数を%d席に変更しました。\n",registmax());
	return 0;
}

// 予約を全消去
int clear(){
	FILE *fp;
	int num;

	printf("予約を全消去します。よろしいですか？\n");
	printf("数値を入力して選択してください。\n1：はい　0：いいえ\n");
	scanf("%d",&num);
	if(num == 1)
	{
		if((fp = fopen("zaseki.txt","w")) == NULL)
		{
			printf("File Open Error\n");
			return 1;
		}
		fprintf(fp,"");
		fclose(fp);
		printf("予約を全消去しました。\n");
	}
	else
		printf("予約の全消去をキャンセルしました。\n");
	return 0;
}