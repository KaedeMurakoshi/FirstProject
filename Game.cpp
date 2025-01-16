#include "Game.h"

#include "Player.h"
#include "CPU.h"

Game::Game() {
	// �t���[�����[�g�ݒ�	
	_fpsController = new FPS_Controller(TARGET_FRAME_RATE);
	_playerScore = 0;
	_cpuScore = 0;
}

Game::~Game() {
	_fpsController = nullptr;
}

// �`�揈��
void Game::DrawObjects() {
	// �S�ẴI�u�W�F�N�g��`��
	_player.Draw();
	_cpu.Draw();
	_ball.Draw();
}

void Game::DrawUI() {
	// �S�Ă�UI��`��
	// ���_�̕\��
	DrawFormatString(100, 50, GetColor(255, 255, 255), "player %d", _playerScore);
	DrawFormatString(SCREEN_SIZE_X - 100, 50, GetColor(255, 255, 255), "cpu %d", _cpuScore);
}

// ���_��̃C���^�[�o������
void Game::Interval() {
	// �{�[�����~�߂�
	_ball.SetSpeed(VGet(0, 0, 0));

	// ��ʂ̒������W�v�Z
	float x = SCREEN_SIZE_X / 2;
	float y = SCREEN_SIZE_Y / 2;
	VECTOR centralPos = VGet(x, y, 0);  // float x, y, z
	// �{�[���𒆉��Ɉړ�
	_ball.SetPos(centralPos);

	x = PADDLE_POS_X;
	y = SCREEN_SIZE_Y / 2 - PADDLE_SIZE_Y / 2;
	// �v���C���[�������ʒu�ɖ߂�
	_player.SetPos(VGet(x, y, 0));

	y = SCREEN_SIZE_Y / 2 - PADDLE_SIZE_Y / 2;
	x = SCREEN_SIZE_X - PADDLE_POS_X - PADDLE_SIZE_X;
	// cpu�������ʒu�ɖ߂�
	_cpu.SetPos(VGet(x, y, 0));

	// ���Ԍv���p
	int startTime = GetNowCount();

	// �R�b�ԃC���^�[�o��
	while (GetNowCount() - startTime < INTERVAL_TIME) {
		// �I�u�W�F�N�g�`��
		DrawObjects();
		// UI�`��
		DrawUI();

		if (ScreenFlip() < 0) {
			return;
		}
	}

	//�{�[���̃X�s�[�h�����ɖ߂�
	_ball.SetSpeed(VGet(BALL_SPEED, BALL_SPEED, 0));
}

void Game::ResetGame() {

	_playerScore = 0;
	_cpuScore = 0;
}

void Game::EndGame() {

}

// �Q�[���̖{�̕���
void Game::MainGame() {
	// �v���[���[�̈ړ�����
	_player.Move();

	// CPU�Ƀ{�[���̍��W��n��
	_cpu.SetBallPos(_ball.GetPos());
	_cpu.SetBallSpeed(_ball.GetSpeed());
	// CPU�̈ړ�����
	_cpu.Move();

	// �{�[���̈ړ�����
	_ball.Move(_player.GetPos(), _cpu.GetPos());

	// ���_�̃t���O���󂯎��
	// �v���[���[���_
	if (_ball.GetPointFlag() == PADDLE_PLAYER) {
		// ���_�ǉ�
		++_playerScore;

		// ���s��������
		if (_playerScore >= GAME_POINT) {
			EndGame();
		}
		
		// �C���^�[�o��������
		Interval();
	}
	// CPU���_
	else if (_ball.GetPointFlag() == PADDLE_CPU) {
		// ���_�ǉ�
		++_cpuScore;

		// ���s��������
		if (_cpuScore >= GAME_POINT) {
			EndGame();
		}

		// �C���^�[�o��������
		Interval();
	}
	// ���_�Ȃ��̏ꍇ�͉������Ȃ�
	else {
		//�������Ȃ�
	}

	// �I�u�W�F�N�g�`��
	DrawObjects();
	// UI�`��
	DrawUI();

	if (ScreenFlip() < 0) {
		return ;
	}

	// FPS �����ɕۂ��߂ɑ҂D
	_fpsController->Wait();
}


