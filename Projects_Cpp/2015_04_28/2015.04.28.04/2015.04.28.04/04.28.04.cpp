#include <iostream>
using namespace std;

#define SIZE 10

// ������ۑ�����stack�N���X��錾����
class stack{
	char stck[SIZE];			// �X�^�b�N�̈���m�ۂ���
	int tos;							// �X�^�b�N�擪�̍���
public:
	void init();					// �X�^�b�N������������
	void push(char ch);		// �X�^�b�N�ɕ������v�b�V������
	char pop();					// �X�^�b�N���當�����|�b�v����
	void dup();					// �g�b�v�𕡐�����
	char peek();				// �l��ǂݏo��
	void swap();				// ��2�̃A�C�e�������ւ�
	void rot_r();					// �E��]
	void rot_l();					// ����]
};

// �X�^�b�N������������
void stack::init(){
	tos = 0;
}

// �������v�b�V������
void stack::push(char ch){
	if(tos == SIZE){
		cout << "�X�^�b�N�͂����ς��ł�";
		return;
	}
	stck[tos] = ch;
	tos++;
}

// �������|�b�v����
char stack::pop(){
	if(tos == 0){
		cout << "�X�^�b�N�͋�ł�";
		return 0;
	}
	tos--;
	return stck[tos];
}

void stack::dup(){
	stck[tos + 1] = stck[tos];
	return;
}

char stack::peek(){
	return stck[tos];
}

void stack::swap(){
	char tmp = stck[tos];
	stck[tos] = stck[tos-1];
	stck[tos -1] = tmp;
	return;
}

void rot_r(){

};

int main(){
	stack s1;
	int i;
}