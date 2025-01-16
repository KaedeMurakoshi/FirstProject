#pragma once
#include "DxLib.h"

#include "Common.h"
#include "Paddle.h"


class Ball
{
public:
	Ball();
	virtual ~Ball();

	// �ړ�
	void Move(VECTOR playerPos, VECTOR cpuPos);
	// �����i�~�j��`��
	void Draw();

	// �{�[���̍��W�擾�p
	const VECTOR GetPos() const{
		return _pos;
	}

	// �{�[���̍��W�㏑��
	void SetPos(VECTOR newPos) {
		_pos = VGet(newPos.x, newPos.y, 0);
	}

	// �{�[���̃X�s�[�h�擾�p
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
	// �_�Ƌ�`�̓����蔻��
	bool IntersectPointRect(float rectLeft, float rectTop, float rectRight, float rectBottom);

private:
	VECTOR _pos;		// ���݂̍��W
	VECTOR _lastPos;	// �O�t���[���̍��W
	VECTOR _speed;		// ���x

	PADDLE_TYPE _pointFlag;
};

