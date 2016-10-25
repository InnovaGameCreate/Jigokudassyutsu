#ifndef JIGOKUDASSYUTSU_UTIL_INPUT_H_
#define JIGOKUDASSYUTSU_UTIL_INPUT_H_

#include "DxLib.h"
#include "util.h"

namespace input {
	//�������A�X�V
	extern void Init();
	extern void Update();
	//�󂯎�����L�[�ԍ��̌��݂̓��͏�Ԃ�Ԃ�
	extern int CheckStateKey(unsigned char Handle);
	//�}�E�X�̓��͏�Ԃ�Ԃ�
	extern int CheckMouseLeftKey();
	extern int CheckMouseRightKey();
	//�Ăяo���ꂽ�t���[���ɉ����L�[���}�E�X�N���b�N�������true��Ԃ�
	extern bool CheckPushAnyButton();
}

#endif