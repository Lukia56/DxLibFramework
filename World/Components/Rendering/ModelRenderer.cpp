#include "ModelRenderer.h"
#include <DxLib.h>
#include "../../GameObject.h"
#include "System/Resource/Resource.h"

ModelRenderer::ModelRenderer(GameObject* owner) :
	Renderer(owner)
{
}

void ModelRenderer::Draw()
{
	if (!mOwner) return;
	if (!mResource) return;

	const VECTOR pos = mOwner->GetTransform().GetWorldPosition().GetAsDxLibVector();
	const VECTOR rot = mOwner->GetTransform().GetWorldRotation().GetAsDxLibVector();
	const VECTOR scale = mOwner->GetTransform().GetWorldScale().GetAsDxLibVector();

	int handle = mResource->GetHandle();

	MV1SetPosition(handle, pos);
	MV1SetRotationXYZ(handle, rot);
	MV1SetScale(handle, scale);

	MV1DrawModel(handle);
}
