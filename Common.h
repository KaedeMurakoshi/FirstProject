#pragma once

// フレームレート ６０で
#define TARGET_FRAME_RATE (60)

// 画面サイズ設定用
#define SCREEN_SIZE_X   (1280)
#define SCREEN_SIZE_Y   (720)

// 弾の大きさ
#define BALL_SIZE (4)
// 弾の速度
#define BALL_SPEED  (8.0f)

//パドル（板）のサイズ
#define PADDLE_SIZE_X   (16)
#define PADDLE_SIZE_Y   (64)
// パドルのX座標ww
#define PADDLE_POS_X    (64)
// パドルの移動速度
#define PLAYER_SPEED    (10)
#define CPU_SPEED		(8)

// １１点先取
#define GAME_POINT (11)

// 得点後のインターバル
#define INTERVAL_TIME (3000) // 3秒

// パドル管理用列挙型
typedef enum{
	PADDLE_NONE,
	PADDLE_PLAYER,
	PADDLE_CPU
} PADDLE_TYPE;