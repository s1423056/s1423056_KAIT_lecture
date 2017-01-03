//導入ユニット　C言語　問題2　関数の最基礎２
//1423056　渡邉　翔　2014/11/28

#include <stdio.h>

int Lnumber(int a, int b){
	int n;
	if(a > b)return a;
	else return b;
}

int main(){
	int num;
	num = Lnumber(5,8);
	printf("%d\n",num);
    return 0;
}