#include <iostream>
#include <ctime>
using namespace std;

class Schedule {
	int mon;
	int day;
	char *str;
public:
	Schedule() { mon = 0; day = 0; str = NULL; }
	Schedule( const Schedule &o );
	~Schedule() { if (str) delete [] str; }
	void set( int m, int d, char *s );
	int get_mon() { return mon; }
	int get_day() { return day; }
	char *get_str() { return str; }
};

Schedule::Schedule( const Schedule &o ) {
	// �R�s�[�R���X�g���N�^�̓��e���L�q
	mon = o.mon;
	day = o.day;
	int l = strlen( o.str )+1;
	str = new char[l];
	if(!str){
		cout << "���������蓖�ăG���[" << endl;
		exit(1);
	}
	strcpy( str, o.str );
}

void Schedule::set( int m, int d, char *s ) {
	int flag = 0;
	if ( m < 1 || m > 12 || d < 1 ) {
		flag = 1;
	} else {
		switch( m ) {
		case 1: case 3: case 5: case 7:case 8: case 10: case 12:	// 31���܂ł��錎
			if ( d > 31 ) {
				flag = 1;
			}
			break;
		case 4: case 6: case 9: case 11:	// 30���܂ł����Ȃ���
			if ( d > 30 ) {
				flag = 1;
			}
			break;
		case 2:
			if ( d > 29 ) { // ���邤�N�͍l���Ȃ�
				flag = 1;
			}
		break;
		}
	}
	if ( flag ) {
		cout << "���t���s���ł�\n";
	} else {
		// �l�̐ݒ�
		mon = m;	// ���������o�ϐ�mon�ɑ��
		day = d;		// ���������o�ϐ�day�ɑ��
		int l = strlen(s)+1;
		str = new char[l];			// ������̃������m��
		if(!str){
			cout << "���������蓖�ăG���[" << endl;
			exit(1);
		}
		strcpy(str,s);
	}
}

bool today( Schedule ob ) {
	time_t now = time( NULL );
	struct tm *date = localtime(&now);
	
	if ( ob.get_mon() == date -> tm_mon+1 && 
		ob.get_day() == date -> tm_mday )
		return true;
	else
		return false;
}

void main(){
	Schedule sc[5];
	sc[0].set( 4,4,"���w��" );
	sc[1].set( 5,7,"�n���L�O��" );
	sc[2].set( 6,30,"�n�[�t�^�C���f�[" );
	sc[3].set( 7,9,"��u��" );
	sc[4].set( 7,20,"�C�̓��i���Ɠ��j" );
	
	cout << "�����̗\��" << endl;
	for( int i = 0;i < 365;i++ ){
		if( today(sc[i]) ) {
			cout << "\t" <<sc[i].get_str() << endl;
			break;
		}
	}
	cout << "�S�\��\��" << endl;
	for( int i = 0; i < 5; i++){
		if( sc[i].get_mon() != 0 )
			cout << sc[i].get_mon() << "��" <<
			sc[i].get_day() << "��\t" <<
			sc[i].get_str() << endl;
	}
	return;
}