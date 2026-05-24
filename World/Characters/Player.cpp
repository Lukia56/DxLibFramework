#include "Player.h"
#include <cassert>
#include <memory>
#include <DxLib.h>
#include "../Objects/Bullet.h"

namespace
{
	bool kLog[2] = { false, false };
}

Player::~Player()
{
}

void Player::Init()
{
	for (int i = 0; i < 5; i++)
	{
		Add(std::make_unique<Bullet>());
	}
}

void Player::Finalize()
{
}

void Player::Update()
{
	if (kLog[0] && GetChildren().size() > 0)
	{
		Destroy(GetChildren().front().get());
	}

	kLog[1] = kLog[0];
	kLog[0] = CheckHitKey(KEY_INPUT_SPACE);
}
