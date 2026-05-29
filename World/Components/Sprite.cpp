#include "Sprite.h"
#include <DxLib.h>
#include "../GameObject.h"

Sprite::Sprite(GameObject* owner) :
	mHandle(-1),
	mHalfSize(Vector2::One),
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

	// 画像の半径を取得
	GetGraphSizeF(mHandle, &mHalfSize.x, &mHalfSize.y);
	mHalfSize *= 0.5f;
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

	DrawRotaGraphFast3F(pos.x, pos.y, mHalfSize.x, mHalfSize.y, scale.x, scale.y, rot.z, mHandle, true);
}
