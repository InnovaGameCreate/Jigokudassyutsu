#ifndef JIGOKUDASSYUTSU_UTIL_INPUT_H_
#define JIGOKUDASSYUTSU_UTIL_INPUT_H_

#include "DxLib.h"
#include "util.h"

namespace input {
	//初期化、更新
	extern void Init();
	extern void Update();
	//受け取ったキー番号の現在の入力状態を返す
	extern int CheckStateKey(unsigned char Handle);
	//マウスの入力状態を返す
	extern int CheckMouseLeftKey();
	extern int CheckMouseRightKey();
	//呼び出されたフレームに何かキーかマウスクリックがあればtrueを返す
	extern bool CheckPushAnyButton();
}

#endif