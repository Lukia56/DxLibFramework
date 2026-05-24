#include "Player.h"
#include <cassert>
#include <memory>
#include <DxLib.h>
#include "../Objects/Bullet.h"
#include "../Components/Collision3D.h"

namespace
{
}

Player::Player() :
	mCollider(nullptr)
{
	mCollider = std::make_unique<Collision3D::AABB3D>();
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
}

void Player::Draw()
{
}
