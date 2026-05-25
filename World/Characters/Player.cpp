#include "Player.h"
#include <cassert>
#include <memory>
#include <DxLib.h>
#include "../Objects/Bullet.h"
#include "../Objects/Crate.h"
#include "../Components/Collision3D.h"
#include "System/InputManager.h"

namespace
{
	constexpr float kSpeed = 10.0f;
}

Player::Player() :
	mCollider(nullptr),
	mCrate(nullptr)
{
	mCollider = std::make_unique<Collision3D::AABB3D>(Vector3::Zero, Vector3(80.0, 200.0f, 80.0f));
}

Player::Player(Crate* crate) :
	mCollider(nullptr),
	mCrate(crate)
{
	mCollider = std::make_unique<Collision3D::AABB3D>(Vector3::Zero, Vector3(80.0, 200.0f, 80.0f));
}

Player::~Player()
{
	mCrate = nullptr;
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
	GameObject::mTransform.position += InputManager::GetInstance().GetAsVector3(Input::Action::Move) * kSpeed;
	mCollider->SetPosition(mTransform.position);
}

void Player::Draw()
{
	mCollider->DebugDraw();

	Collision3D::Result result = mCollider->CheckCollision(mCrate->GetColiider());
	if (result.isHit)
	{
		printfDx("è’ìÀÇµÇƒÇ¢ÇÈ\n");
		printfDx("Result.penetration = %f\n", result.penetration);
		printfDx("Result.normal.x = %f\n", result.normal.x);
		printfDx("Result.normal.y = %f\n", result.normal.y);
		printfDx("Result.normal.z = %f\n", result.normal.z);
	}
}
