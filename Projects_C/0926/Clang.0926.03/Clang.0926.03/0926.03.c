//�������j�b�g�@C����@���R�@�y�h�背�|�[�g�z����͎��Ǝ��ԂɎ��{���܂���B�h��Ƃ��Ď���ł������w�K���܂��傤�B���̃v���O��������́E���s���Ȃ����B���|�[�g�쐬���@�ɕ킢�A���P�E�Q�ō쐬�����t�@�C���ɒǉ����Ȃ����B
//1423056�@�n糁@�ā@2014/09/26

#include<stdio.h>
#include<conio.h>

void functionS();

int main() {
			int key=0, key2=0;
			do {
						if  (kbhit()) {
									key=getch();
									//printf("%x\n", key);

									switch(key) {
												case 0xe0:	printf("����");
																	key2 = getch();
																	switch(key2){
																			case 0x4b:		printf("��\n");				break;
																			case 0x4d:		printf("�E\n");				break;
																			case 0x48:		printf("��\n");				break;
																			case 0x50:		printf("��\n");				break;					
																	}break;
												case 'a':		printf("a�ł�\n");			break;
												case 's':		functionS();						break;
												case 'd':		printf("d�ł�\n");			break;
												case 'A':		printf("A�ł�\n");			break;
												case 'q':		printf("q�ŏI��\n");			break;
												default:		printf("���̃L�[�͗��p�ł��܂���[q]	�������ƏI��\n");
									}
						}
			}while(key!='q');
			printf("�����l�ł���\n\n");
			return 0;
}

void functionS(){
			printf("\n");
			printf("�G�X�ł�\n");
			printf("\n");
			return ;
}