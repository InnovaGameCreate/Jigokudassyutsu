#ifndef JIGOKUDASSYUTSU_UTIL_FPS_H_
#define JIGOKUDASSYUTSU_UTIL_FPS_H_

#include "DxLib.h"
#include "util.h"

class Fps {
private:
	int default_fps_;			//設定したFPS

	unsigned int starttime_;		//測定開始時刻
	unsigned int count_;			//カウンタ
	int sampleing_count_;		//平均を取るサンプル数
	int waittime_sum_;			//待機時間のサンプリングフレーム間での合計

	double waittime_avg_;		//待機時間の平均
	double fps_avg_;				//平均fps
	unsigned int totai_count_;	//経過フレームのカウント

	void Initialize();
	double ComputeAverageTimepar() const;
public:
	Fps();
	Fps(int fps);
	void Update();				//FPS関連の情報更新(平均フレームレートの計算等)
	void Wait();				//FPS制御のための待機関数
	double get_fps_avg() const;		//現在の平均FPSの取得
	int get_totai_count() const;		//起動してから現在までのフレームカウント数の取得
	void Draw(int x0, int y0) const;	//現在のFPS状況の詳細を画面に描画
};

#endif