#include "SceneTest.h"
#include "../World/Characters/Player.h"

SceneTest::SceneTest()
{
	Add(std::make_unique<Player>());
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
