#include "input.h"

//�������O���
namespace {
	unsigned int state_key[256];
	static unsigned int mouse_left_key, mouse_right_key;

	//�L�[�̏�Ԃ̍X�V(�Q�[�������X���b�h�ōX�V����܂�)
	int GetHitKeyStateAll_2() {
		char GetHitKeyStateAll_Key[256];
		GetHitKeyStateAll(GetHitKeyStateAll_Key);
		for (int i = 0; i < 256; i++) {
			if (GetHitKeyStateAll_Key[i] == 1) {
				state_key[i]++;
			}
			else
				state_key[i] = 0;
		}
		return 0;
	}

	//���N���b�N��������Ă����,�ϐ����C���N�������g
	int GetHitMouseLeft() {
		if (GetMouseInput()& MOUSE_INPUT_LEFT)
			mouse_left_key++;

		else
			mouse_left_key = 0;
		return 0;
	}

	//�E�N���b�N��������Ă����,�ϐ����C���N�������g
	int GetHitMouseRight() {
		if (GetMouseInput()& MOUSE_INPUT_RIGHT)
			mouse_right_key++;

		else
			mouse_right_key = 0;
		return 0;
	}
}

namespace input {
	//������
	void Init() {
		memset(state_key, 0, sizeof(state_key));
		mouse_left_key = mouse_right_key = 0;
	}

	//�X�V
	void Update() {
		GetHitKeyStateAll_2();
		GetHitMouseLeft();
		GetHitMouseRight();
	}

	//�w�肵���L�[�̏�Ԃ̎擾(0������ĂȂ��A1�ȏ㉟���ꂽ�t���[����)
	//Handle�l���s���̎���-1��Ԃ�
	int CheckStateKey(unsigned char Handle) {
		if (Handle < 0 || Handle >= 256) {
			util::ErrorOutPut(__FILE__, __func__, __LINE__, "Handle�̒l���s���ł�");
			return -1;
		}
		return state_key[Handle];
	}

	//���N���b�N��������Ă���������Ԃ�
	int CheckMouseLeftKey() {
		return mouse_left_key;
	}

	//�E�N���b�N��������Ă���������Ԃ�
	int CheckMouseRightKey() {
		return mouse_right_key;
	}
}