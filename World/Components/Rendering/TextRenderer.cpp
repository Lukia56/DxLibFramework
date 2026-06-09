#include "TextRenderer.h"
#include <DxLib.h>
#include "../../GameObject.h"
#include "System/Resource/Resource.h"
#include "Utility/Color.h"

TextRenderer::TextRenderer(GameObject* owner) :
	Renderer(owner),
	mText(""),
	mColor(Color::white),
	mScalingFlag(false)
{
}

void TextRenderer::Draw()
{
	if (!mOwner) return;

	const VECTOR pos = mOwner->GetTransform().GetWorldPosition().GetAsDxLibVector();
	
	// 必要な場合のみワールドスケールを計算して取得
	VECTOR scale = VGet(0.0f, 0.0f, 0.0f);
	if (mScalingFlag)
		scale = mOwner->GetTransform().GetWorldScale().GetAsDxLibVector();

	// フォントが読み込まれていたらフォントを使用してテキストを表示する
	if (mResource)
	{
		if (mScalingFlag)
			DrawExtendStringFToHandle(pos.x, pos.y, scale.x, scale.y, mText.c_str(), mColor.GetAsHexRGB(), mResource->GetHandle());
		else
			DrawStringFToHandle(pos.x, pos.y, mText.c_str(), mColor.GetAsHexRGB(), mResource->GetHandle());
	}
	// フォントが読み込まれていなかったらデフォルトのフォントを使用してテキストを表示する
	else
	{
		if (mScalingFlag)
			DrawExtendStringF(pos.x, pos.y, scale.x, scale.y, mText.c_str(), mColor.GetAsHexRGB());
		else
			DrawStringF(pos.x, pos.y, mText.c_str(), mColor.GetAsHexRGB());
	}
}
