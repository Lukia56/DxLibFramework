#include "ModelRenderer.h"
#include <DxLib.h>
#include "../GameObject.h"
#include "System/ResourceManager.h"
#include "System/Resource/Resource.h"

ModelRenderer::ModelRenderer(GameObject* owner) :
	mModel(nullptr),
	mOwner(owner)
{
}

ModelRenderer::~ModelRenderer()
{
	mModel = nullptr;
}

void ModelRenderer::Load(const char* const filePath)
{
	mModel = ResourceManager::GetInstance().GetResource<Model>(filePath);
}

void ModelRenderer::Draw()
{
	if (!mModel) return;

	const VECTOR pos = mOwner->GetTransform().GetWorldPosition().GetAsDxLibVector();
	const VECTOR rot = mOwner->GetTransform().GetWorldRotation().GetAsDxLibVector();
	const VECTOR scale = mOwner->GetTransform().GetWorldScale().GetAsDxLibVector();

	int handle = mModel->GetHandle();

	MV1SetPosition(handle, pos);
	MV1SetRotationXYZ(handle, rot);
	MV1SetScale(handle, scale);

	MV1DrawModel(handle);
}
