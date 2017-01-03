#include <iostream>
#include <fstream> // �t�@�C�����o�͂ɕK�v
using namespace std;

int main() {
	char header[54]; // �w�b�_�i�[�p�z��
	char inputlen[100];
	char outputlen[100];
	cout << "���̓t�@�C�����F";
	cin >> inputlen;
	cout << "�o�̓t�@�C�����F";
	cin >> outputlen;
	ifstream fin( inputlen , ios::in | ios::binary ); // �o�C�i�����[�h�œ��̓t�@�C�����I�[�v��
	if(!fin){
		cout << "input file open error!" << endl; 
		return 1;
	}

	ofstream fout( outputlen, ios::out | ios::binary ); // �o�C�i�����[�h�ŏo�̓t�@�C�����I�[�v��
	if(!fout){
		cout << "output file open error!" << endl;
		return 1;
	}

	fin.read(header, 54); // �w�b�_�ǂݍ���
	fout.write(header, 54); // �w�b�_��������

	char a; // �f�[�^��ǂݍ��ނ��߂̃o�b�t�@

	while(!fin.eof()) { // ���̓t�@�C���̏I���܂ŌJ��Ԃ�
		fin.get(a);// ���̓X�g���[������ 1 �o�C�g�f�[�^�ǂݍ���
		a = ~a;// �r�b�g���]
		fout.put(a);// �o�̓X�g���[���Ƀr�b�g���]�����f�[�^����������
	}

	fin.close();
	fout.close();

	return 0;
}