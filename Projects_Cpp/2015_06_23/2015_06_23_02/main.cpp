// �ۑ�2

#include <iostream>
using namespace std;
class Coord { 
	double x, y, z;
public: 
	void set(double u, double v, double w) { x = u; y = v; z = w; } 
	void show(); 
}; 
void Coord::show() { cout << "(" << x << "," << y << "," << z << ")"; }

void setCoord1(Coord ob) { // �l�n��
	double u, v, w; 
	cout << "������3���͂��Ă��������F"; 
	cin >> u >> v >> w; 
	ob.set(u, v, w); // ���ۂɂ͒l��ݒ�ł��Ȃ� 

}

void setCoord2(Coord *ob) { // �|�C���^�n�� 
	// ��L�֐����Q�l�ɒl��ݒ肷��R�[�h���L�q 
	double u, v, w; 
	cout << "������3���͂��Ă��������F"; 
	cin >> u >> v >> w; 
	ob->set(u, v, w);
} 

void setCoord3(Coord &ob) { // �Q�Ɠn�� 
	// ��L�֐����Q�l�ɒl��ݒ肷��R�[�h���L�q 
	double u, v, w; 
	cout << "������3���͂��Ă��������F"; 
	cin >> u >> v >> w; 
	ob.set(u, v, w); 
}

int main(){
	Coord obj;

	obj.set(1.1, 2.3, 5.5);
	cout << " �I�u�W�F�N�g�̏����l�F";
	obj.show();
	cout << "\n\n";

	cout << "�l�n���Ŋ֐��ɃI�u�W�F�N�g��n���܂�\n";
	setCoord1(obj);
	cout << "�I�u�W�F�N�g�̒l�F";
	obj.show();
	cout << "\n\n";

	cout << "�|�C���^�n���Ŋ֐��ɃI�u�W�F�N�g��n���܂�\n";
	// ��L���Q�l�Ɋ֐��Ăяo���ƒl�̕\���R�[�h���L�q
	Coord *p_obj = &obj;
	setCoord2(p_obj);
	obj.show();
	cout << "\n\n";

	cout << "�Q�Ɠn���Ŋ֐��ɃI�u�W�F�N�g��n���܂�\n";
	// ��L���Q�l�Ɋ֐��Ăяo���ƒl�̕\���̃R�[�h���L�q
	setCoord3(obj);
	obj.show();
	cout << "\n\n";

	return 0;
}