#include "TextRenderer.h"
#include <DxLib.h>
#include "../../GameObject.h"
#include "System/Resource/Resource.h"
#include "Utility/Color.h"

TextRenderer::TextRenderer(GameObject* owner) :
	Renderer(owner),
	mText("")
{
}

void TextRenderer::Draw()
{
	if (!mOwner) return;

	const VECTOR pos = mOwner->GetTransform().GetWorldPosition().GetAsDxLibVector();

	if (mResource)
	{
		DrawStringToHandle(pos.x, pos.y, mText.c_str(), Color::white.GetAsHexRGB(), mResource->GetHandle());
	}
	else
	{
		DrawString(pos.x, pos.y, mText.c_str(), Color::white.GetAsHexRGB());
	}
}
