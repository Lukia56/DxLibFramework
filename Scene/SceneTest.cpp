#include "SceneTest.h"
#include "../World/Characters/Player.h"

void SceneTest::Init()
{
	Add(std::make_unique<Player>());
}

void SceneTest::Finalize()
{
}

std::unique_ptr<SceneBase> SceneTest::Update()
{
	return nullptr;
}
