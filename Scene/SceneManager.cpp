#include "SceneManager.h"
#include "SceneBase.h"
#include "SceneInit.h"

SceneManager::SceneManager() :
	mCurrentScene(nullptr)
{
}

SceneManager::~SceneManager() = default;

void SceneManager::Initialize()
{
	// 初期シーンの作成
	CreateScene<SceneInit>();
}

void SceneManager::Finalize()
{
	mCurrentScene->Finalize();
}

void SceneManager::Update()
{
	mCurrentScene->UpdateRootObjects();

	auto nextScene = mCurrentScene->Update();
	if (nextScene == nullptr) return;

	// シーンを切り替える
	mCurrentScene->Finalize();
	mCurrentScene = std::move(nextScene);
}

void SceneManager::Draw()
{

}

void SceneManager::DebugDraw()
{
	
}
