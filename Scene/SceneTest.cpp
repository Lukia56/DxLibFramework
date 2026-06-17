#include "SceneTest.h"
#include "../World/Characters/Player.h"
#include "../World/Objects/Crate.h"
#include "../World/Others/UI.h"
#include "Camera/CameraDebugFree.h"
#include "Camera/CameraManager.h"

SceneTest::SceneTest() :
	mPlayer(nullptr),
	mCrate(nullptr),
	mUI(nullptr)
{
	mPlayer = AddToRoot(std::make_unique<Player>());
	mCrate = AddToRoot(std::make_unique<Crate>());
	mUI = AddToRoot(std::make_unique<UI>());

	mPlayer->SetCrate(mCrate);

	GetCameraManager()->AddCamera(Camera::Type::DebugFree, std::make_unique<CameraDebugFree>());
	GetCameraManager()->SetCurrentCameraType(Camera::Type::DebugFree);
}

SceneTest::~SceneTest()
{
	mUI = nullptr;
	mCrate = nullptr;
	mPlayer = nullptr;
}

void SceneTest::Init()
{
	
}

void SceneTest::Finalize()
{
}

std::unique_ptr<SceneBase> SceneTest::Update()
{
	return nullptr;
}
