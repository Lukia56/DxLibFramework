#include "SpriteRenderer.h"
#include <DxLib.h>
#include "../GameObject.h"
#include "System/ResourceManager.h"
#include "System/Resource/Resource.h"

SpriteRenderer::SpriteRenderer(GameObject* owner) :
	mTexture(nullptr),
	mHalfSize(Vector2::One),
	mOwner(owner)
{
}

SpriteRenderer::~SpriteRenderer()
{
	mTexture = nullptr;
}

void SpriteRenderer::Load(const char* const filePath)
{
	mTexture = ResourceManager::GetInstance().GetResource<Texture>(filePath);

	if (!mTexture) return;

	// ‰æ‘œ‚Ì”¼Œa‚ðŽæ“¾
	GetGraphSizeF(mTexture->GetHandle(), &mHalfSize.x, &mHalfSize.y);
	mHalfSize *= 0.5f;
}

void SpriteRenderer::Draw()
{
	if (!mTexture) return;

	const VECTOR pos = mOwner->GetTransform().GetWorldPosition().GetAsDxLibVector();
	const VECTOR rot = mOwner->GetTransform().GetWorldRotation().GetAsDxLibVector();
	const VECTOR scale = mOwner->GetTransform().GetWorldScale().GetAsDxLibVector();

	DrawRotaGraphFast3F(pos.x, pos.y, mHalfSize.x, mHalfSize.y, scale.x, scale.y, rot.z, mTexture->GetHandle(), true);
}
