#include "Paddle.h"

// �R���X�g���N�^
Paddle::Paddle() {
	_pos.x = PADDLE_POS_X;
	_pos.y = SCREEN_SIZE_Y / 2 - PADDLE_SIZE_Y / 2;

	_lastPos = _pos;

	_upKey = KEY_INPUT_W;
	_downKey = KEY_INPUT_S;
}

// �f�X�g���N�^
Paddle::~Paddle() {

}

void Paddle::Move() {
	// �h���N���X��MoveBase���Ă�
	MoveBase();
	CheckPos();
}

void Paddle::Draw() {
	// // �p�h����`��
	// �����͒��_�ƐF�i���j
	DrawBox(_pos.x, _pos.y, _pos.x + PADDLE_SIZE_X, _pos.y + PADDLE_SIZE_Y, 0xffffff, TRUE);
}

void Paddle::CheckPos() {
	// �p�h������ʂ���͂ݏo�Ȃ��悤��

	if (_pos.y + PADDLE_SIZE_Y >= SCREEN_SIZE_Y) {
		_pos = _lastPos;
	}
	if (_pos.y < 0) {
		_pos = _lastPos;
	}
}
