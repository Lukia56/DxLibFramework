#include "Player.h"
#include <cassert>
#include <memory>
#include <DxLib.h>
#include "../Components/Collision3D.h"
#include "../Components/ModelRenderer.h"
#include "../Objects/Ball.h"
#include "../Objects/Bullet.h"
#include "../Objects/Crate.h"
#include "System/InputManager.h"

namespace
{
	constexpr float kSpeed = 10.0f;

	constexpr Vector3 kInitScale{ 0.3f, 0.3f, 0.3f };

	constexpr Vector3 kCollisionSize{ 40.0f, 40.0f, 40.0f };

	const char* const kModelHandlePath = "Resource\\Model\\Bee.mv1";
}

Player::Player() :
	mModel(nullptr),
	mCollider(nullptr),
	mCrate(nullptr),
	mBall(nullptr)
{
	mModel = std::make_unique<ModelRenderer>(this);
	mCollider = std::make_unique<Collision3D::AABB3D>(Vector3::Zero, kCollisionSize);
}

Player::~Player()
{
	mBall = nullptr;
	mCrate = nullptr;
	mCollider = nullptr;
	mModel = nullptr;
}

void Player::Init()
{
	GameObject::mTransform.localScale = kInitScale;

	mModel->Load(kModelHandlePath);

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
	GameObject::mTransform.localPosition += InputManager::GetInstance().GetAsVector3(Input::Action::Move) * kSpeed;
	mCollider->SetPosition(GameObject::mTransform.GetWorldPosition());
}

void Player::Draw()
{
	mModel->Draw();

	mCollider->DebugDraw();
	
	Collision3D::Result result;
	result = mCollider->CheckCollision(mCrate->GetColiider());
	if (result.isHit)
	{
		printfDx("AABB vs AABB | è’ìÀÇµÇƒÇ¢ÇÈ\n");
		printfDx("Result.penetration = %f\n", result.penetration);
		printfDx("Result.normal.x = %f\n", result.normal.x);
		printfDx("Result.normal.y = %f\n", result.normal.y);
		printfDx("Result.normal.z = %f\n", result.normal.z);
	}
	//result = mCollider->CheckCollision(mBall->GetColiider());
	//if (result.isHit)
	//{
	//	printfDx("AABB vs Sphere | è’ìÀÇµÇƒÇ¢ÇÈ\n");
	//	printfDx("Result.penetration = %f\n", result.penetration);
	//	printfDx("Result.normal.x = %f\n", result.normal.x);
	//	printfDx("Result.normal.y = %f\n", result.normal.y);
	//	printfDx("Result.normal.z = %f\n", result.normal.z);
	//}
}
