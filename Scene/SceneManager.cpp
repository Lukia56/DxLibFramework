#include "SceneManager.h"
#include <memory>
#include "SceneBase.h"
#include "SceneInit.h"
#include "Camera/CameraManager.h"
#include "Camera/CameraDebugFree.h"

SceneManager::SceneManager() :
	mCurrentScene(nullptr),
	mCameraManager(nullptr)
{
	mCameraManager = std::make_unique<CameraManager>();
}

SceneManager::~SceneManager() = default;

void SceneManager::Initialize()
{
	// 初期シーンの作成
	CreateScene<SceneInit>();

	mCameraManager->AddCamera(Camera::Type::DebugFree, std::make_unique<CameraDebugFree>());
	mCameraManager->SetCurrentCameraType(Camera::Type::DebugFree);
}

void SceneManager::Finalize()
{
	mCameraManager.reset();

	mCurrentScene->Finalize();
	mCurrentScene.reset();
}

void SceneManager::Update()
{
	mCurrentScene->UpdateRootObjects();

	mCameraManager->Update();

	auto nextScene = mCurrentScene->Update();
	if (nextScene == nullptr) return;

	// シーンを切り替える
	mCurrentScene->Finalize();
	mCurrentScene = std::move(nextScene);
	mCurrentScene->Init();
}

void SceneManager::Draw()
{
	mCameraManager->Bind();

	mCurrentScene->DrawRootObjects();
}

void SceneManager::DebugDraw()
{
	mCameraManager->DebugDraw();
}
