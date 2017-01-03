//導入ユニット　C言語　問題4　複数ファイルで実行プログラムを作成する
//1423056　渡邉　翔　2014/1/9
#include "0109.04.mydef.h"

//この関数で呼び出すプロトタイプ宣言
int printALL(DTYPE data[], int Dnum);
int inputData(DTYPE data[], int *Dnum);

int main(){
	DTYPE data[DATANUM];
	int Dnum = 0;
	inputData(data, &Dnum); printALL(data, Dnum);
	printf("\n==Now Dnum=%d\n\n", Dnum);
	inputData(data, &Dnum); printALL(data, Dnum);
	return 0;
}