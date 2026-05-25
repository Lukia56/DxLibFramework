#include "Crate.h"
#include <memory>
#include <DxLib.h>
#include "../Components/Collision3D.h"

Crate::Crate() :
	mCollider(nullptr)
{
	mCollider = std::make_unique<Collision3D::Sphere3D>(Vector3::Zero, 60.0f);
	//mCollider = std::make_unique<Collision3D::AABB3D>(Vector3::Zero, Vector3(120.0, 120.0f, 120.0f));
}

void Crate::Init()
{
}

void Crate::Update()
{
}

void Crate::Draw()
{
	mCollider->DebugDraw();
}
