#pragma once
#include "DxLib.h"
#include "Common.h"

class Paddle
{
public:
	virtual void MoveBase() = 0;	// �������z�֐�

	Paddle();
	virtual ~Paddle();
	
	VECTOR GetPos() {
		return _pos;
	}

	void Move(); // �h���N���X��
	void Draw();

protected:
	void CheckPos();	// ��ʊO�ɏo�Ȃ��悤�Ɏ����̍��W���`�F�b�N

protected:
	VECTOR _pos;
	VECTOR _lastPos;	// �O�t���[���̍��W

	int _upKey;
	int _downKey;
};

