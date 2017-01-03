// EnumCreate.h
// ������Ɨ񋓑̘̂A�z�z����쐬����}�N��
// �쐬���F2016/6/8
// �Q�lweb�Fhttp://qiita.com/nunu-e64/items/e29075bdd82fad8ec28c

#include <map>
#include <string>
#include <stdarg.h>

using namespace std;

// enum�̒�`�ƊǗ��pmap�̎����쐬�������Ȃ��}�N��
#define ENUM( _name, ... )																					\
    struct _name {																									\
        enum type {__VA_ARGS__, NUM};																\
        std::map < std::string, type > converter;														\
        _name() {																										\
            createEnumMap( converter, #__VA_ARGS__, NUM, __VA_ARGS__ );		\
        }																														\
    }_name;

// �񋓎q��������������L�[�Ƃ��A�񋓒萔�̐��l��l�Ƃ���map���쐬����
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