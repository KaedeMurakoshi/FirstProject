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

	// �O�̍��W�ɃX�s�[�h�̒l��������
	_pos = VAdd(_pos, _speed);// const VECTOR &In1, &In2

	// Player�̍��W��n���ē����蔻����s��
	if (IntersectPointRect(playerPos.x, playerPos.y, playerPos.x + PADDLE_SIZE_X, playerPos.y + PADDLE_SIZE_Y)) {
		// �������Ă�������W��߂��Ĕ���
		_pos = _lastPos;
		_speed.x *= -1;
	}

	// CPU�̍��W��n���ē����蔻����s��
	if (IntersectPointRect(cpuPos.x, cpuPos.y, cpuPos.x + PADDLE_SIZE_X, cpuPos.y + PADDLE_SIZE_Y)) {
		// �������Ă�������W��߂��Ĕ���
		_pos = _lastPos;
		_speed.x *= -1;
	}

	// ��������ǂƂ̏Փ˔���
	// ��ʏ㉺�[�ɓ����������ɔ���
	if (_pos.y >= SCREEN_SIZE_Y || _pos.y < 0) {
		_pos = _lastPos;
		_speed.y *= -1;
	}

	// ���E�̕ǂɓ��������瓾�_�ǉ�
	// ��ʉE�[�ɓ��������獶�ɔ���
	if (_pos.x >= SCREEN_SIZE_X) {
		_pos = _lastPos;
		_speed.x *= -1;	

		// �v���[���[���_
		_pointFlag = PADDLE_PLAYER;
	}
	// ��ʍ��[�ɓ���������E�ɔ���
	else if (_pos.x < 0) {
		_pos = _lastPos;
		_speed.x *= -1;

		// CPU���_
		_pointFlag = PADDLE_CPU;
	}
	else {
		// ���_���Ȃ�
		_pointFlag = PADDLE_NONE;
	}
}

void Ball::Draw() {
	// �`�揈���D
	// �~�i�e�j��`�悷��
	DrawCircle((int)_pos.x, _pos.y, BALL_SIZE, GetColor(0xff, 0xff, 0xff));
}

// �_�Ƌ�`�̓����蔻��
bool Ball::IntersectPointRect(float rectLeft, float rectTop, float rectRight, float rectBottom)
{
	// �_�̍��W����`�͈͓̔��Ȃ�true��Ԃ�
	return (_pos.x > rectLeft)
		&& (_pos.x < rectRight)
		&& (_pos.y > rectTop)
		&& (_pos.y < rectBottom);
}