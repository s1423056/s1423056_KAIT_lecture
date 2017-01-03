#include "DxLib.h"
#include "charactor.h"
#include "system.h"

#include <crtdbg.h>
#include <stdlib.h>

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
            LPSTR lpCmdLine, int nCmdShow )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	ChangeWindowMode( TRUE );

    // ��ʃ��[�h�̐ݒ�
    SetGraphMode( 640 , 480 , 24 ) ;
	
	// �c�w���C�u��������������
    if( DxLib_Init() == -1 )
        return -1;  
	SetFontSize( 16 );
    CSystem system;
	system.Initialize();

    // ESC�L�[��������邩�A���炩�̓����G���[����������܂Ń��[�v����
    while( ScreenFlip() == 0 &&  !ProcessMessage() && ClearDrawScreen() == 0 && ( CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) )
    {
		system.Update();	// �X�V
		system.Draw();		// �`��
		if( system.GetEnd() ) break;
	}
    

    // �c�w���C�u�����̏I������
    DxLib_End() ;
    return 0 ;
}