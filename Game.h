#pragma once
#include "DxLib.h"

#include "FPS_Controller.h"
#include "Common.h"
#include "Ball.h"
#include "Player.h"
#include "CPU.h"

class Game
{
public:
	Game();
	~Game();

	void MainGame();	// �Q�[���̖{�́B���t���[���Ă�

private:
	void DrawObjects(); // �S�ẴI�u�W�F�N�g��`��B���t���[���Ă�
	void DrawUI();		// UI�`��B���t���[���Ăԁ@
	void Interval();    // ���_��̃C���^�[�o��
	void ResetGame();	// �Q�[�������Z�b�g
	void EndGame();		// �Q�[���I�����̏���
	
	
public:
	Player _player;
	CPU _cpu;
	Ball _ball;

private:
	FPS_Controller* _fpsController;	// FPS�����p
	int _playerScore;
	int _cpuScore;
};

