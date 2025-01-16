#include "Player.h"

Player::Player() {
	_pos.x = PADDLE_POS_X;
	_pos.y = SCREEN_SIZE_Y / 2 - PADDLE_SIZE_Y / 2;
	_upKey = KEY_INPUT_W;
	_downKey = KEY_INPUT_S;
}

Player::~Player() {

}

void Player::MoveBase() {
	// �O�t���[���̍��W��ۑ����Ă���
	_lastPos = _pos;

	// �p�h������
	if (CheckHitKey(_upKey)) {
		_pos.y -= PADDLE_SPEED;
	}

	if (CheckHitKey(_downKey)) {
		_pos.y += PADDLE_SPEED;
	}
}