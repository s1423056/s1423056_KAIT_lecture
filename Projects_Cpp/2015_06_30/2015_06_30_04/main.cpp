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
	// コピーコンストラクタの内容を記述
	mon = o.mon;
	day = o.day;
	int l = strlen( o.str )+1;
	str = new char[l];
	if(!str){
		cout << "メモリ割り当てエラー" << endl;
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
		case 1: case 3: case 5: case 7:case 8: case 10: case 12:	// 31日まである月
			if ( d > 31 ) {
				flag = 1;
			}
			break;
		case 4: case 6: case 9: case 11:	// 30日までしかない月
			if ( d > 30 ) {
				flag = 1;
			}
			break;
		case 2:
			if ( d > 29 ) { // うるう年は考えない
				flag = 1;
			}
		break;
		}
	}
	if ( flag ) {
		cout << "日付が不正です\n";
	} else {
		// 値の設定
		mon = m;	// 月をメンバ変数monに代入
		day = d;		// 日をメンバ変数dayに代入
		int l = strlen(s)+1;
		str = new char[l];			// 文字列のメモリ確保
		if(!str){
			cout << "メモリ割り当てエラー" << endl;
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
	sc[0].set( 4,4,"入学式" );
	sc[1].set( 5,7,"創立記念日" );
	sc[2].set( 6,30,"ハーフタイムデー" );
	sc[3].set( 7,9,"補講日" );
	sc[4].set( 7,20,"海の日（授業日）" );
	
	cout << "今日の予定" << endl;
	for( int i = 0;i < 365;i++ ){
		if( today(sc[i]) ) {
			cout << "\t" <<sc[i].get_str() << endl;
			break;
		}
	}
	cout << "全予定表示" << endl;
	for( int i = 0; i < 5; i++){
		if( sc[i].get_mon() != 0 )
			cout << sc[i].get_mon() << "月" <<
			sc[i].get_day() << "日\t" <<
			sc[i].get_str() << endl;
	}
	return;
}