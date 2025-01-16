#include "DxLib.h"

#include "FPS_Controller.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// フレームレート調整用
	// 60fps
	//FPS_Controller FPS_Controller(60);

	// 画面モードを設定する
	SetGraphMode(
		SCREEN_SIZE_X, SCREEN_SIZE_Y,   // int ScreenSizeX, ScreenSizeY
		32                              // int ColorBitDepth
										// int RefreshRate = 60 デフォルト引数
);
	SetDrawScreen(DX_SCREEN_BACK);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)		
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ゲームクラスインスタンス作成
	Game game;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !ClearDrawScreen()) {

		// ゲームの本体
		game.MainGame();	
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End();				

	return 0;				// ソフトの終了 
}
