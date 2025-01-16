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

	void MainGame();	// ゲームの本体。毎フレーム呼ぶ

private:
	void DrawObjects(); // 全てのオブジェクトを描画。毎フレーム呼ぶ
	void DrawUI();		// UI描画。毎フレーム呼ぶ　
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

