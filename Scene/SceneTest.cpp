#include "SceneTest.h"
#include "../World/Characters/Player.h"
#include "../World/Objects/Crate.h"
#include "../World/Others/Camera.h"
#include "../World/Others/UI.h"

SceneTest::SceneTest() :
	mCamera(nullptr),
	mPlayer(nullptr),
	mCrate(nullptr),
	mUI(nullptr)
{
	auto camera = std::make_unique<Camera>();
	auto player = std::make_unique<Player>();
	auto crate = std::make_unique<Crate>();
	auto ui = std::make_unique<UI>();

	mCamera = camera.get();
	Add(std::move(camera));
	mPlayer = player.get();
	Add(std::move(player));
	mCrate = crate.get();
	Add(std::move(crate));
	mUI = ui.get();
	Add(std::move(ui));

	mPlayer->SetCrate(mCrate);
}

SceneTest::~SceneTest()
{
	mUI = nullptr;
	mCrate = nullptr;
	mPlayer = nullptr;
	mCamera = nullptr;
}

void SceneTest::Init()
{
	//// カメラのクリッピング距離の設定
	//SetCameraNearFar(5, 5);
	//// カメラの視野角を設定
	//SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
	//// カメラの視点、注視点の初期設定
	//SetCameraPositionAndTarget_UpVecY(
	//	VGet(0.0f, 0.0f, -400.0f),
	//	VGet(0.0f, 0.0f, 0.0f)
	//);
}

void SceneTest::Finalize()
{
}

std::unique_ptr<SceneBase> SceneTest::Update()
{
	return nullptr;
}
