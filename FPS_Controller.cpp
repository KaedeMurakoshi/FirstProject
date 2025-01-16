#include "FPS_Controller.h"

#include <cmath>
#include <string>

#include <Dxlib.h>

FPS_Controller::FPS_Controller(const int target_fps)
    : kTargetFpsValue(target_fps)
    , kOneFrameTime(static_cast<int>(1000.0 / target_fps))
    , kListMax(target_fps * 2)
    , need_skip_draw_screen_(false) {}

void FPS_Controller::Wait() {
    if (!TargetFpsIsValid()) { return; }

    // �҂ׂ����Ԃ��擾���đ҂D
    int wait_time = 0;

    if (CheckNeedSkipDrawScreen(&wait_time)) {
        WaitTimer(wait_time);   // �擾�������ԕ��҂D
        // Sleep(wait_time);    // windows API�ŁD

        RegisterTime(GetNowCount());  // ���݂̎������L�^����D
    }
    else {
        // ���ԃI�[�o�[���Ă���̂ŁC�R�}�����̏���������D
        // ���̃t���[���͗��z�I�ȏ������������̂Ƃ��āC�L�^����D
        RegisterTime(time_list_.back() + kOneFrameTime);

        need_skip_draw_screen_ = true;  // �`����΂��t���O�𗧂Ă�D
    }
}


bool FPS_Controller::SkipDrawScene() {
    if (!TargetFpsIsValid()) { return false; }

    // �X�L�b�v�t���O�������Ă���Ȃ�΁C���̃t���O��܂�C�V�[�����X�L�b�v����D
    if (need_skip_draw_screen_) {
        need_skip_draw_screen_ = false;
        return true;
    }

    return false;
}

void FPS_Controller::RegisterTime(const int now_time) {
    time_list_.push_back(now_time);  // ���݂̎������L���D

    if (time_list_.size() > kListMax) {
        // �킩��R�ꂽ��폜����D
        time_list_.pop_front();
    }
}

bool FPS_Controller::CheckNeedSkipDrawScreen(int* time) const {
    // �������������D
    (*time) = 0;

    // �������X�g����Ȃ�CWait���Ԃ�0�b�D
    if (time_list_.empty()) {
        (*time) = 0;
        return true;
    }

    // ���ۂɂ����������Ԃ����߂�D
    int actually_took_time = GetNowCount() - time_list_.back();

    // �v�Z�ォ����ׂ����� - ���ۂɂ����������ԁ@�͂��Ȃ킿�҂ׂ����ԁD
    int wait_time = kOneFrameTime - actually_took_time;

    if (wait_time >= 0) {
        // �҂����Ԃ����̒l�ł���Ƃ��C
        // (�܂�C������ׂ����Ԃ����ۂɂ����������Ԃ���������)�͂��̂܂ܒl��Ԃ��D
        (*time) = wait_time;
        return true;
    }
    else {
        // �҂����Ԃ����̒l�ł���Ƃ��D
        if (static_cast<int>(abs(wait_time)) < kOneFrameTime) {
            // �P�t���[���ȏ�x��Ă��Ȃ��Ȃ�΁C�������s���D
            return false;
        }
    }

    // �ǂ�ɂ�����������Ȃ������ꍇ�O��Ԃ��D
    (*time) = 0;
    return true;
}

bool FPS_Controller::TargetFpsIsValid() const {
    // �}�C�i�X�̒l�͋��e���Ȃ��D
    if (kTargetFpsValue <= 0) { return false; }

    // �P�b�ԂɂP�t���[���ȏ�͋��e���Ȃ��D
    if (kTargetFpsValue > 60) { return false; }

    return true;
}
