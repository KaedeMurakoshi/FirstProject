#pragma once
#include "DxLib.h"

#include "Common.h"
#include "Paddle.h"


class Ball
{
public:
	Ball();
	virtual ~Ball();

	// 移動
	void Move(VECTOR playerPos, VECTOR cpuPos);
	// 自分（円）を描画
	void Draw();

	// ボールの座標取得用
	const VECTOR GetPos() const{
		return _pos;
	}

	// ボールの座標上書き
	void SetPos(VECTOR newPos) {
		_pos = VGet(newPos.x, newPos.y, 0);
	}

	// ボールのスピード取得用
	const VECTOR GetSpeed() const {
		return _speed;
	}

	void SetSpeed(VECTOR newSpeed) {
		_speed = newSpeed;
	}

	const PADDLE_TYPE GetPointFlag() {
		return _pointFlag;
	}

private :
	// 点と矩形の当たり判定
	bool IntersectPointRect(float rectLeft, float rectTop, float rectRight, float rectBottom);

private:
	VECTOR _pos;		// 現在の座標
	VECTOR _lastPos;	// 前フレームの座標
	VECTOR _speed;		// 速度

	PADDLE_TYPE _pointFlag;
};

