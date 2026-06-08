#include "SpriteRenderer.h"
#include <DxLib.h>
#include "../GameObject.h"
#include "System/Resource/Resource.h"

SpriteRenderer::SpriteRenderer(GameObject* owner) :
	Renderer(owner),
	mHalfSize(Vector2::One)
{
}

void SpriteRenderer::Load(const std::string& filePath)
{
	Renderer::Load(filePath);

	if (!mResource) return;

	// ‰æ‘œ‚Ì”¼Œa‚ðŽæ“¾
	GetGraphSizeF(mResource->GetHandle(), &mHalfSize.x, &mHalfSize.y);
	mHalfSize *= 0.5f;
}

void SpriteRenderer::Draw()
{
	if (!mOwner) return;
	if (!mResource) return;

	const VECTOR pos = mOwner->GetTransform().GetWorldPosition().GetAsDxLibVector();
	const VECTOR rot = mOwner->GetTransform().GetWorldRotation().GetAsDxLibVector();
	const VECTOR scale = mOwner->GetTransform().GetWorldScale().GetAsDxLibVector();

	DrawRotaGraphFast3F(pos.x, pos.y, mHalfSize.x, mHalfSize.y, scale.x, scale.y, rot.z, mResource->GetHandle(), true);
}
