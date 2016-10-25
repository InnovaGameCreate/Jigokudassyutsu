#include "input.h"

//無名名前空間
namespace {
	unsigned int state_key[256];
	static unsigned int mouse_left_key, mouse_right_key;
	bool is_pushed_any_button;

	//キーの状態の更新(ゲーム処理スレッドで更新されます)
	int GetHitKeyStateAll_2() {
		char GetHitKeyStateAll_Key[256];
		GetHitKeyStateAll(GetHitKeyStateAll_Key);
		for (int i = 0; i < 256; i++) {
			if (GetHitKeyStateAll_Key[i] == 1) {
				state_key[i]++;
				if (state_key[i] == 1)
					is_pushed_any_button = true;
			}
			else
				state_key[i] = 0;
		}
		return 0;
	}

	//左クリックが押されている間,変数をインクリメント
	int GetHitMouseLeft() {
		if (GetMouseInput()& MOUSE_INPUT_LEFT) {
			mouse_left_key++;
			if (mouse_left_key == 1)
				is_pushed_any_button = true;
		}
		else
			mouse_left_key = 0;
		return 0;
	}

	//右クリックが押されている間,変数をインクリメント
	int GetHitMouseRight() {
		if (GetMouseInput()& MOUSE_INPUT_RIGHT) {
			mouse_right_key++;
			if (mouse_right_key == 1)
				is_pushed_any_button = true;
		}
		else
			mouse_right_key = 0;
		return 0;
	}
}

namespace input {
	//初期化
	void Init() {
		memset(state_key, 0, sizeof(state_key));
		mouse_left_key = mouse_right_key = 0;
		is_pushed_any_button = false;
	}

	//更新
	void Update() {
		is_pushed_any_button = false;
		GetHitKeyStateAll_2();
		GetHitMouseLeft();
		GetHitMouseRight();
	}

	//指定したキーの状態の取得(0押されてない、1以上押されたフレーム数)
	//Handle値が不正の時は-1を返す
	int CheckStateKey(unsigned char Handle) {
		return state_key[Handle];//unsigned char のサイズは0~255の範囲なのでエラー確認はしない
	}

	//左クリックが押されていた長さを返す
	int CheckMouseLeftKey() {
		return mouse_left_key;
	}

	//右クリックが押されていた長さを返す
	int CheckMouseRightKey() {
		return mouse_right_key;
	}

	//呼び出されたフレームに何かキーかマウスクリックがあればtrueを返す
	bool CheckPushAnyButton() {
		return is_pushed_any_button;
	}
}