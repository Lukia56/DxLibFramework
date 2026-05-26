#include "Ball.h"
#include <memory>
#include <DxLib.h>
#include "../Components/Collision3D.h"

Ball::Ball() :
	mCollider(nullptr)
{
	mCollider = std::make_unique<Collision3D::Sphere3D>(Vector3::Zero, 60.0f);
}

void Ball::Init()
{
}

void Ball::Update()
{
}

void Ball::Draw()
{
	mCollider->DebugDraw();
}
