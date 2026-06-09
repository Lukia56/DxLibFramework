#include "Application.h"
#include <chrono>
#include <memory>
#include <DxLib.h>
#include "Scene/SceneManager.h"
#include "System/InputManager.h"
#include "System/ResourceManager.h"
#include "Utility/Random.h"

Application::Application()
{
}

Application::~Application()
{
}

bool Application::Initialize()
{
	bool result;

	ChangeWindowMode(true);
	SetWaitVSyncFlag(false);

	// DxLibを初期化
	result = DxLib_Init() != -1;
	// DxLibの初期化に失敗していたら早期リターン
	if (!result) return false;

	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(false);
	SetBackgroundColor(128, 128, 128);

	// シーンマネージャーを初期化
	mSceneManager = std::make_unique<SceneManager>();
	mSceneManager->Initialize();

	// 入力マネージャーを初期化
	InputManager::GetInstance().Initialize();

	ResourceManager::GetInstance().Init();

	// 乱数生成機を初期化
	Random::Init();

	// ここまで問題が起きなかったらtrue
	return true;
}

void Application::Finalize()
{
	// メンバの後処理
	mSceneManager->Finalize();

	ResourceManager::GetInstance().Finalize();

	// メモリリークが起きる可能性があるため最後に呼ぶ
	DxLib_End();
}

void Application::GameLoop()
{
	// 問題が起きない限り処理を繰り返す
	while (ProcessMessage() == 0)
	{
		ProcessInput();
		Update();
		ProcessOutput();

#ifdef _DEBUG
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
#endif
	}
}

void Application::ProcessInput()
{
	InputManager::GetInstance().Update();
}

void Application::Update()
{
	using clock = std::chrono::steady_clock;
	auto start = clock::now();

	mSceneManager->Update();

	while (std::chrono::duration_cast<std::chrono::microseconds>(clock::now() - start) < std::chrono::microseconds(16667)) {}
}

void Application::ProcessOutput()
{
	// 描画
	ClearDrawScreen();
	clsDx();

	mSceneManager->Draw();
	mSceneManager->DebugDraw();

	// 画面に表示
	ScreenFlip();
}
