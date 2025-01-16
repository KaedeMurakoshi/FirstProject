#include "CPU.h"

CPU::CPU() {
	_pos.x = SCREEN_SIZE_X - PADDLE_POS_X - PADDLE_SIZE_X;
	_pos.y = SCREEN_SIZE_Y / 2 - PADDLE_SIZE_Y / 2;
	_upKey = KEY_INPUT_UP;
	_downKey = KEY_INPUT_DOWN;

	_ballPos = VGet(0, 0, 0);
	_ballSpeed = VGet(BALL_SPEED, BALL_SPEED, 0);
}

CPU::~CPU() {

}

// 自動でパドルを動かす処理
void CPU::MoveBase() {
	// 前フレームの座標を保存しておく
	_lastPos = _pos;

	// ボールが画面の右半分にいて、自分に向かってきているときだけ移動する
	if (_ballPos.x > SCREEN_SIZE_X * 0.7 && _ballSpeed.x > 0) {

		// パドルの中心座標を求める
		float center = _pos.y + PADDLE_SIZE_Y / 2;

		// 自分がボールより下にいたら上に移動、自分が上にいたら下に移動する
		if (center > _ballPos.y) {
			_pos.y -= CPU_SPEED;
		}
		else{
			_pos.y += CPU_SPEED;
		}
	}
}