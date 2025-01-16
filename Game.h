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
	void ResetGame();
	void EndGame();
	

public:
	Player _player;
	CPU _cpu;
	Ball _ball;

private:
	FPS_Controller* _fpsController;
	int _playerScore;
	int _cpuScore;
};

