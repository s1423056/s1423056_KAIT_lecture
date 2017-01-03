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

    // 画面モードの設定
    SetGraphMode( 640 , 480 , 24 ) ;
	
	// ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 )
        return -1;  
	SetFontSize( 16 );
    CSystem system;
	system.Initialize();

    // ESCキーが押されるか、何らかの内部エラーが発生するまでループする
    while( ScreenFlip() == 0 &&  !ProcessMessage() && ClearDrawScreen() == 0 && ( CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) )
    {
		system.Update();	// 更新
		system.Draw();		// 描画
		if( system.GetEnd() ) break;
	}
    

    // ＤＸライブラリの終了処理
    DxLib_End() ;
    return 0 ;
}