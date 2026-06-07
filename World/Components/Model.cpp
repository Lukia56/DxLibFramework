#include "Model.h"
#include <DxLib.h>
#include "../GameObject.h"

ModelRenderer::ModelRenderer(GameObject* owner) :
	mHandle(-1),
	mOwner(owner)
{
}

ModelRenderer::~ModelRenderer()
{
	// ƒ‚ƒfƒ‹‚ð‰ð•ú‚·‚é
	if (mHandle != -1) DeleteGraph(mHandle);
}

void ModelRenderer::Load(const char* const filePath)
{
	mHandle = MV1LoadModel(filePath);
}

void ModelRenderer::Draw()
{
	if (mHandle == -1) return;

	const VECTOR pos = mOwner->GetTransform().GetWorldPosition().GetAsDxLibVector();
	const VECTOR rot = mOwner->GetTransform().GetWorldRotation().GetAsDxLibVector();
	const VECTOR scale = mOwner->GetTransform().GetWorldScale().GetAsDxLibVector();

	MV1SetPosition(mHandle, pos);
	MV1SetRotationXYZ(mHandle, rot);
	MV1SetScale(mHandle, scale);

	MV1DrawModel(mHandle);
}
