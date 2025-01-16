#include "Paddle.h"

// コンストラクタ
Paddle::Paddle() {
	_pos.x = PADDLE_POS_X;
	_pos.y = SCREEN_SIZE_Y / 2 - PADDLE_SIZE_Y / 2;

	_lastPos = _pos;

	_upKey = KEY_INPUT_W;
	_downKey = KEY_INPUT_S;
}

// デストラクタ
Paddle::~Paddle() {

}

void Paddle::Move() {
	// 派生クラスのMoveBaseを呼ぶ
	MoveBase();
	CheckPos();
}

void Paddle::Draw() {
	// // パドルを描画
	// 引数は頂点と色（白）
	DrawBox(_pos.x, _pos.y, _pos.x + PADDLE_SIZE_X, _pos.y + PADDLE_SIZE_Y, 0xffffff, TRUE);
}

void Paddle::CheckPos() {
	// パドルが画面からはみ出ないように

	if (_pos.y + PADDLE_SIZE_Y >= SCREEN_SIZE_Y) {
		_pos = _lastPos;
	}
	if (_pos.y < 0) {
		_pos = _lastPos;
	}
}
