#pragma once
#include "Paddle.h"

class CPU : public Paddle
{
public:
	CPU();
	virtual ~CPU();

	void MoveBase()override;

	void SetBallPos(VECTOR pos) {
		_ballPos = pos;
	}
	void SetBallSpeed(VECTOR speed) {
		_ballSpeed = speed;
	}

private:
	VECTOR _ballPos;
	VECTOR _ballSpeed;
};

