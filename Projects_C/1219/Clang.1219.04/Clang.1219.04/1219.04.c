//導入ユニット　C言語　問題4　ポインタの理解4
//1423056　渡邉　翔　2014/12/19

#include <stdio.h>
struct Dtype{
	int ID;
	double dnum[3];
};

int main(){
	struct Dtype data[4] ={
	{1001, {1.1, 2.2, 3.3} },
	{1002, {4.4, 5.5, 6.6} },
	{1003, {7.7, 8.8, 9.9} },
	{1004, {1.2, 2.3, 3.4} }
	};
	struct Dtype *SP;
	SP = data;
	printf("A:%d\n",SP -> ID);
	printf("%f-%f-%f\n",SP->dnum[0],SP->dnum[1],SP->dnum[2]);

	SP = SP + 1;
	printf("B:%d\n",SP -> ID);
	printf("%f-%f-%f\n",SP->dnum[0],SP->dnum[1],SP->dnum[2]);

	SP = SP + 1;
	printf("C:%d\n",SP -> ID);
	printf("%f-%f-%f\n",SP->dnum[0],SP->dnum[1],SP->dnum[2]);

    return 0;
}