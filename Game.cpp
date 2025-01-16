#include "Game.h"

#include "Player.h"
#include "CPU.h"

Game::Game() {
	// フレームレート設定	
	_fpsController = new FPS_Controller(TARGET_FRAME_RATE);
	_playerScore = 0;
	_cpuScore = 0;
}

Game::~Game() {
	_fpsController = nullptr;
}

// 描画処理
void Game::DrawObjects() {
	// 全てのオブジェクトを描画
	_player.Draw();
	_cpu.Draw();
	_ball.Draw();
}

void Game::DrawUI() {
	// 全てのUIを描画
	// 得点の表示
	DrawFormatString(100, 50, GetColor(255, 255, 255), "player %d", _playerScore);
	DrawFormatString(SCREEN_SIZE_X - 100, 50, GetColor(255, 255, 255), "cpu %d", _cpuScore);
}

// 得点後のインターバル処理
void Game::Interval() {
	// ボールを止める
	_ball.SetSpeed(VGet(0, 0, 0));

	// 画面の中央座標計算
	float x = SCREEN_SIZE_X / 2;
	float y = SCREEN_SIZE_Y / 2;
	VECTOR centralPos = VGet(x, y, 0);  // float x, y, z
	// ボールを中央に移動
	_ball.SetPos(centralPos);

	x = PADDLE_POS_X;
	y = SCREEN_SIZE_Y / 2 - PADDLE_SIZE_Y / 2;
	// プレイヤーを初期位置に戻す
	_player.SetPos(VGet(x, y, 0));

	y = SCREEN_SIZE_Y / 2 - PADDLE_SIZE_Y / 2;
	x = SCREEN_SIZE_X - PADDLE_POS_X - PADDLE_SIZE_X;
	// cpuを初期位置に戻す
	_cpu.SetPos(VGet(x, y, 0));

	// 時間計測用
	int startTime = GetNowCount();

	// ３秒間インターバル
	while (GetNowCount() - startTime < INTERVAL_TIME) {
		// オブジェクト描画
		DrawObjects();
		// UI描画
		DrawUI();

		if (ScreenFlip() < 0) {
			return;
		}
	}

	//ボールのスピードを元に戻す
	_ball.SetSpeed(VGet(BALL_SPEED, BALL_SPEED, 0));
}

void Game::ResetGame() {

	_playerScore = 0;
	_cpuScore = 0;
}

void Game::EndGame() {

}

// ゲームの本体部分
void Game::MainGame() {
	// プレーヤーの移動処理
	_player.Move();

	// CPUにボールの座標を渡す
	_cpu.SetBallPos(_ball.GetPos());
	_cpu.SetBallSpeed(_ball.GetSpeed());
	// CPUの移動処理
	_cpu.Move();

	// ボールの移動処理
	_ball.Move(_player.GetPos(), _cpu.GetPos());

	// 得点のフラグを受け取る
	// プレーヤー得点
	if (_ball.GetPointFlag() == PADDLE_PLAYER) {
		// 得点追加
		++_playerScore;

		// 勝敗がついたら
		if (_playerScore >= GAME_POINT) {
			EndGame();
		}
		
		// インターバルを挟む
		Interval();
	}
	// CPU得点
	else if (_ball.GetPointFlag() == PADDLE_CPU) {
		// 得点追加
		++_cpuScore;

		// 勝敗がついたら
		if (_cpuScore >= GAME_POINT) {
			EndGame();
		}

		// インターバルを挟む
		Interval();
	}
	// 得点なしの場合は何もしない
	else {
		//何もしない
	}

	// オブジェクト描画
	DrawObjects();
	// UI描画
	DrawUI();

	if (ScreenFlip() < 0) {
		return ;
	}

	// FPS を一定に保つために待つ．
	_fpsController->Wait();
}


