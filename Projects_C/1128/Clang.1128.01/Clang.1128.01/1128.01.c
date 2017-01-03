//導入ユニット　C言語　問題1　関数の最基礎１
//1423056　渡邉　翔　2014/11/28

#include <stdio.h>

int printKAIT(){
	printf("*  *");printf("      **");printf("       ***");printf("   *********\n");
	printf("* *");printf("      *  *");printf("       *");printf("        *\n");
	printf("**");printf("      * ** *");printf("      *");printf("        *\n");
	printf("* *");printf("    *      *");printf("     *");printf("        *\n");
	printf("*  *");printf("  *        *");printf("   ***");printf("       *\n");
	return 0;
}
int main(){
	int i;
	for(i = 0;i<10;i++)printKAIT();
    return 0;
}