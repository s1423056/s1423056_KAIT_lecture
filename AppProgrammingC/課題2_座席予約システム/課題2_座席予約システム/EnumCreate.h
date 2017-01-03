// EnumCreate.h
// 文字列と列挙体の連想配列を作成するマクロ
// 作成日：2016/6/8
// 参考web：http://qiita.com/nunu-e64/items/e29075bdd82fad8ec28c

#include <map>
#include <string>
#include <stdarg.h>

using namespace std;

// enumの定義と管理用mapの自動作成をおこなうマクロ
#define ENUM( _name, ... )																					\
    struct _name {																									\
        enum type {__VA_ARGS__, NUM};																\
        std::map < std::string, type > converter;														\
        _name() {																										\
            createEnumMap( converter, #__VA_ARGS__, NUM, __VA_ARGS__ );		\
        }																														\
    }_name;

// 列挙子を示す文字列をキーとし、列挙定数の数値を値としたmapを作成する
template <class T> void createEnumMap( map<string, T> &_map, char* _list, int _num, ... ) {
    char* listCopy = new char[255];
    char* tmpKey;
	char* temp;
    strcpy_s( listCopy, 255, _list );

    va_list args;
    va_start( args, _num );

    if ( ( tmpKey = strtok_s( listCopy,  ", ", &temp ) ) != NULL ) _map[tmpKey] = static_cast<T>( va_arg( args, int ) );
    for ( int i = 1; i < _num; i++) {
        if ( ( tmpKey = strtok_s( NULL, ", ", &temp ) ) != NULL ) _map[tmpKey] = static_cast<T>( va_arg( args, int ) );
    }
    va_end( args );
    delete[] listCopy;
}