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

	const VECTOR pos = mOwner->GetTransform().CalculateWorldPosition().GetAsDxLibVector();
	const VECTOR rot = mOwner->GetTransform().CalculateWorldRotation().GetAsDxLibVector();
	const VECTOR scale = mOwner->GetTransform().CalculateWorldScale().GetAsDxLibVector();

	int handle = mResource->GetHandle();

	MV1SetPosition(handle, pos);
	MV1SetRotationXYZ(handle, rot);
	MV1SetScale(handle, scale);

	MV1DrawModel(handle);

	MV1DeleteModel(handle);
}
