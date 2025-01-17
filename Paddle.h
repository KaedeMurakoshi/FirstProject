#pragma once
#include "DxLib.h"
#include "Common.h"

class Paddle
{
public:
	virtual void MoveBase() = 0;	// 純粋仮想関数

	Paddle();
	virtual ~Paddle();
	
	// 座標取得用
	VECTOR GetPos() {
		return _pos;
	}

	// 座標上書き用
	void SetPos(VECTOR newPos){
		_pos = newPos;
	}

	void Move(); // 派生クラスの
	void Draw();

protected:
	void CheckPos();	// 画面外に出ないように自分の座標をチェック

protected:
	VECTOR _pos;
	VECTOR _lastPos;	// 前フレームの座標

	int _upKey;
	int _downKey;
};

