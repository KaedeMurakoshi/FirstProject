#include "Ball.h"


Ball::Ball() {
	_pos = VGet(0, 0, 0);  // float x, y, z
	_lastPos = _pos;
	_speed = VGet(BALL_SPEED, BALL_SPEED, 0);   // float x, y, z
	_pointFlag = PADDLE_NONE;
}

Ball::~Ball() {

}

void Ball::Move(VECTOR playerPos, VECTOR cpuPos) {
	_lastPos = _pos;

	// 前の座標にスピードの値を加える
	_pos = VAdd(_pos, _speed);// const VECTOR &In1, &In2

	// Playerの座標を渡して当たり判定を行う
	if (IntersectPointRect(playerPos.x, playerPos.y, playerPos.x + PADDLE_SIZE_X, playerPos.y + PADDLE_SIZE_Y)) {
		// 当たっていたら座標を戻して反射
		_pos = _lastPos;
		_speed.x *= -1;
	}

	// CPUの座標を渡して当たり判定を行う
	if (IntersectPointRect(cpuPos.x, cpuPos.y, cpuPos.x + PADDLE_SIZE_X, cpuPos.y + PADDLE_SIZE_Y)) {
		// 当たっていたら座標を戻して反射
		_pos = _lastPos;
		_speed.x *= -1;
	}

	// ここから壁との衝突判定
	// 画面上下端に当たったら上に反射
	if (_pos.y >= SCREEN_SIZE_Y || _pos.y < 0) {
		_pos = _lastPos;
		_speed.y *= -1;
	}

	// 左右の壁に当たったら得点追加
	// 画面右端に当たったら左に反射
	if (_pos.x >= SCREEN_SIZE_X) {
		_pos = _lastPos;
		_speed.x *= -1;	

		// プレーヤー得点
		_pointFlag = PADDLE_PLAYER;
	}
	// 画面左端に当たったら右に反射
	else if (_pos.x < 0) {
		_pos = _lastPos;
		_speed.x *= -1;

		// CPU得点
		_pointFlag = PADDLE_CPU;
	}
	else {
		// 得点がない
		_pointFlag = PADDLE_NONE;
	}
}

void Ball::Draw() {
	// 描画処理．
	// 円（弾）を描画する
	DrawCircle((int)_pos.x, _pos.y, BALL_SIZE, GetColor(0xff, 0xff, 0xff));
}

// 点と矩形の当たり判定
bool Ball::IntersectPointRect(float rectLeft, float rectTop, float rectRight, float rectBottom)
{
	// 点の座標が矩形の範囲内ならtrueを返す
	return (_pos.x > rectLeft)
		&& (_pos.x < rectRight)
		&& (_pos.y > rectTop)
		&& (_pos.y < rectBottom);
}