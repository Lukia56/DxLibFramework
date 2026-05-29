#include "Crate.h"
#include <memory>
#include <DxLib.h>
#include "../Components/Collision3D.h"
#include "../Components/Model.h"

namespace
{
	constexpr Vector3 kInitScale{ 0.25f, 0.25f, 0.25f };

	constexpr Vector3 kCollisionSize{ 50.0f, 50.0f, 50.0f };

	const char* const kModelHandlePath = "Resource\\Model\\Cube_Crate.mv1";
}

Crate::Crate() :
	mModel(nullptr),
	mCollider(nullptr)
{
	mModel = std::make_unique<Model>(this);
	mCollider = std::make_unique<Collision3D::AABB3D>(Vector3::Zero, kCollisionSize);
}

Crate::~Crate()
{
	mCollider = nullptr;
	mModel = nullptr;
}

void Crate::Init()
{
	GameObject::mTransform.localScale = kInitScale;

	mModel->Load(kModelHandlePath);
}

void Crate::Finalize()
{
}

void Crate::Update()
{
}

void Crate::Draw()
{
	mModel->Draw();

	mCollider->DebugDraw();
}
