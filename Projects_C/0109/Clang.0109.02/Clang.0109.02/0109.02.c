//�������j�b�g�@C����@���Q�@�񋓌^�ɐG���
//1423056�@�n糁@�ā@2014/1/9

#include <stdio.h>

enum WeekT{Sun, Mon, Tue, Wed, Thu, Fri, Sat};

int main(){
	enum WeekT input;
	printf("�����̗j����ԍ��œ���Ă�������\n");
	printf("0:Sun\n1:Mon\n2:Tue\n3:Wed\n4:Thu\n5:Fri\n6:Sat\n");
	scanf("%d",&input);
	switch(input){
		case Sun:printf("���j���ł�\n");break;
		case Mon:printf("���j���ł�\n");break;
		case Tue:printf("�Ηj���ł�\n");break;
		case Wed:printf("���j���ł�\n");break;
		case Thu:printf("�ؗj���ł�\n");break;
		case Fri:printf("���j���ł�\n");break;
		case Sat:printf("�y�j���ł�\n");break;
		default:printf("���͂��s���ł�");
	}
	printf("----------\n");
	printf("Sum:%d\n",Sun);
	printf("Mon:%d\n",Mon);
	printf("Tue:%d\n",Tue);
    return 0;
}