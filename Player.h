#pragma once
#include "Paddle.h"


class Player : public Paddle
{
public:
	Player();
	virtual ~Player();

	void MoveBase()override;

private:

};

