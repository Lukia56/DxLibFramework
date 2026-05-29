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
	mCamera = Add(std::make_unique<Camera>());
	mPlayer = Add(std::make_unique<Player>());
	mCrate = Add(std::make_unique<Crate>());
	mUI = Add(std::make_unique<UI>());

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
	
}

void SceneTest::Finalize()
{
}

std::unique_ptr<SceneBase> SceneTest::Update()
{
	return nullptr;
}
