#include "SceneTest.h"
#include "../World/Characters/Player.h"
#include "../World/Objects/Crate.h"

SceneTest::SceneTest() :
	mPlayer(nullptr),
	mCrate(nullptr)
{
	auto crate = std::make_unique<Crate>();
	auto player = std::make_unique<Player>(crate.get());

	mCrate = crate.get();
	Add(std::move(crate));
	mPlayer = player.get();
	Add(std::move(player));
}

SceneTest::~SceneTest()
{
	mCrate = nullptr;
	mPlayer = nullptr;
}

void SceneTest::Init()
{
	// カメラのクリッピング距離の設定
	SetCameraNearFar(5.0f, 5.0f);
	// カメラの視野角を設定
	SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
	// カメラの視点、注視点の初期設定
	SetCameraPositionAndTarget_UpVecY(
		VGet(0.0f, 0.0f, -400.0f),
		VGet(0.0f, 0.0f, 0.0f)
	);
}

void SceneTest::Finalize()
{
}

std::unique_ptr<SceneBase> SceneTest::Update()
{
	return nullptr;
}
