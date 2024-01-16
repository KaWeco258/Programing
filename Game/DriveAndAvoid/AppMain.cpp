/*
車避けゲームを作ってみよう！
*/

#include "DxLib.h"
#include "Scene/SceneManager.h"

//メイン関数(プログラムはここから始まります。)
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//例外処理(異常が発生したら、catch文に飛びます)
	try
	{
		//シーンマネジャー機能の生成
		SceneManager manager;

		//シーンマネジャー機能の初期化処理
		manager.Initialize();

		//シーンマネジャー機能の更新処理
		manager.Update();

		//シーンマネジャー機能の終了時処理
		manager.Finalize();
	}
	catch (const char* err_log)
	{
		//エラー発生内容の出力
		OutputDebugString(err_log);

		//エラー終了を通知
		return -1;
	}

	//正常終了を通知
	return 0;
}