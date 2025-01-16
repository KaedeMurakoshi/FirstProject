#pragma once

#include <list>

class FPS_Controller final {
public:
    FPS_Controller() = delete;
    explicit FPS_Controller(int target_fps);

    // @brief ��������������ꍇ�CFPS�����ɂ��邽�߂ɑ҂D
    void Wait();

    // @brief 60Hz�ȏ�̃��j�^�[�g�p���ɏ������l�܂��ĉ�ʂ�������Ȃ��悤�ɁC
    // �`�揈�����X�L�b�v���邩�ǂ����𔻒肷��D
    // @return �������l�܂��ĕ`����΂������Ƃ���
    // true ��Ԃ��D���̌�t���O�� false �ɂ���D
    bool SkipDrawScene();

private:
    // @brief ���݂̎������L�^����֐��D
    // @param[in] now_time ���݂̎���(�~���b)
    void RegisterTime(int now_time);

    // @brief �ǂꂾ���҂Ă΂悢���Ԃ��֐��D
    // @param[out] wait_time �҂ׂ����� (�~���b)�D
    // @return �R�}�������Ă���ꍇ�� false�D
    bool CheckNeedSkipDrawScreen(int* wait_time) const;

    // @brief �ڕW��FPS�����������ǂ����𔻒肷��֐��D
    // @return ���̒l�C�܂���60���傫���l�ł���� false�D
    bool TargetFpsIsValid() const;


private:
    const int kTargetFpsValue;

    // 1�t���[��������ɂ����鎞��(�~���b)
    const int kOneFrameTime;

    // ���X�g��2�b���̃t���[�����Ƃɂ����������Ԃ��L�^���邽�߁C
    // ���X�g�̍ő�T�C�Y�����߂�D
    const int kListMax;

    // 1�t���[�����Ƃɂ����������Ԃ��L�^���郊�X�g�D
    std::list<int> time_list_;

    // �R�}�������������邽�߂̃t���O�D
    // true�ł���� 1�t���[���`����΂��C���̌�t���O��܂�
    bool need_skip_draw_screen_;
};

