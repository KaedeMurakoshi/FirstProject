#include "DxLib.h"

#include "FPS_Controller.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �t���[�����[�g�����p
	// 60fps
	//FPS_Controller FPS_Controller(60);

	// ��ʃ��[�h��ݒ肷��
	SetGraphMode(
		SCREEN_SIZE_X, SCREEN_SIZE_Y,   // int ScreenSizeX, ScreenSizeY
		32                              // int ColorBitDepth
										// int RefreshRate = 60 �f�t�H���g����
);
	SetDrawScreen(DX_SCREEN_BACK);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)		
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �Q�[���N���X�C���X�^���X�쐬
	Game game;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !ClearDrawScreen()) {

		// �Q�[���̖{��
		game.MainGame();	
	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();				

	return 0;				// �\�t�g�̏I�� 
}
