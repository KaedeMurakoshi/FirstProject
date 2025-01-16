#include "CPU.h"

CPU::CPU() {
	_pos.x = SCREEN_SIZE_X - PADDLE_POS_X - PADDLE_SIZE_X;
	_pos.y = SCREEN_SIZE_Y / 2 - PADDLE_SIZE_Y / 2;
	_upKey = KEY_INPUT_UP;
	_downKey = KEY_INPUT_DOWN;

	_ballPos = VGet(0, 0, 0);
	_ballSpeed = VGet(BALL_SPEED, BALL_SPEED, 0);
}

CPU::~CPU() {

}

// �����Ńp�h���𓮂�������
void CPU::MoveBase() {
	// �O�t���[���̍��W��ۑ����Ă���
	_lastPos = _pos;

	// �{�[������ʂ̉E�����ɂ��āA�����Ɍ������Ă��Ă���Ƃ������ړ�����
	if (_ballPos.x > SCREEN_SIZE_X * 0.7 && _ballSpeed.x > 0) {

		// �p�h���̒��S���W�����߂�
		float center = _pos.y + PADDLE_SIZE_Y / 2;

		// �������{�[����艺�ɂ������Ɉړ��A��������ɂ����牺�Ɉړ�����
		if (center > _ballPos.y) {
			_pos.y -= CPU_SPEED;
		}
		else{
			_pos.y += CPU_SPEED;
		}
	}
}