#include "Sprite.h"
#include <DxLib.h>
#include "../GameObject.h"

Sprite::Sprite(GameObject* owner) :
	mHandle(-1),
	mSize(Vector2::One),
	mOwner(owner)
{
}

Sprite::~Sprite()
{
	// スプライトを解放する
	if (mHandle != -1) DeleteGraph(mHandle);
}

void Sprite::Load(const char* const filePath)
{
	mHandle = LoadGraph(filePath);

	GetGraphSizeF(mHandle, &mSize.x, &mSize.y);
}

void Sprite::Draw()
{
	if (mHandle == -1) return;

	const VECTOR pos = mOwner->GetTransform().GetWorldPosition().GetAsDxLibVector();
	const VECTOR rot = mOwner->GetTransform().GetWorldRotation().GetAsDxLibVector();
	const VECTOR scale = mOwner->GetTransform().GetWorldScale().GetAsDxLibVector();

	MV1SetPosition(mHandle, pos);
	MV1SetRotationXYZ(mHandle, rot);
	MV1SetScale(mHandle, scale);

	DrawRotaGraphFast3F(pos.x, pos.y, mSize.x * 0.5f, mSize.y * 0.5f, scale.x, scale.y, rot.z, mHandle, true);
}
