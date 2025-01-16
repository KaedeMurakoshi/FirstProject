#pragma once

// �t���[�����[�g �U�O��
#define TARGET_FRAME_RATE (60)

// ��ʃT�C�Y�ݒ�p
#define SCREEN_SIZE_X   (1280)
#define SCREEN_SIZE_Y   (720)

// �e�̑傫��
#define BALL_SIZE (4)
// �e�̑��x
#define BALL_SPEED  (8.0f)

//�p�h���i�j�̃T�C�Y
#define PADDLE_SIZE_X   (16)
#define PADDLE_SIZE_Y   (64)
// �p�h����X���Www
#define PADDLE_POS_X    (64)
// �p�h���̈ړ����x
#define PLAYER_SPEED    (10)
#define CPU_SPEED		(8)

// �P�P�_���
#define GAME_POINT (11)

// ���_��̃C���^�[�o��
#define INTERVAL_TIME (3000) // 3�b

// �p�h���Ǘ��p�񋓌^
typedef enum{
	PADDLE_NONE,
	PADDLE_PLAYER,
	PADDLE_CPU
} PADDLE_TYPE;