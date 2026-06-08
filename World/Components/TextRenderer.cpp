#include "TextRenderer.h"
#include <DxLib.h>
#include "../GameObject.h"
#include "System/ResourceManager.h"
#include "System/Resource/Resource.h"
#include "Utility/Color.h"

TextRenderer::TextRenderer(GameObject* owner) :
	mText(""),
	mFont(nullptr),
	mOwner(owner)
{
}

TextRenderer::~TextRenderer()
{
	mFont = nullptr;
}

void TextRenderer::Load(const char* const filePath)
{
	mFont = ResourceManager::GetInstance().GetResource<Font>(filePath);
}

void TextRenderer::Draw()
{
	if (!mOwner) return;

	const VECTOR pos = mOwner->GetTransform().GetWorldPosition().GetAsDxLibVector();

	if (mFont)
	{
		DrawStringToHandle(pos.x, pos.y, mText.c_str(), Color::white.GetAsHexRGB(), mFont->GetHandle());
	}
	else
	{
		DrawString(pos.x, pos.y, mText.c_str(), Color::white.GetAsHexRGB());
	}
}
