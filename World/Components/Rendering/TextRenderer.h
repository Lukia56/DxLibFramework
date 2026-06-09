#pragma once

#include "Renderer.h"
#include "Utility/Color.h"

class TextRenderer : public Renderer<Font>
{
public:

	TextRenderer(GameObject* owner);
	~TextRenderer() = default;

	void Draw() override;

	/// <summary>
	/// 表示するテキストを変更する
	/// </summary>
	void SetText(const std::string& text) { mText = text; }
	/// <summary>
	/// テキストの色を設定する
	/// </summary>
	void SetColor(const Color& color) { mColor = color; }
	/// <summary>
	/// スケーリングを適用するかのフラグを設定する
	/// </summary>
	void SetScalingFlag(const bool flag) { mScalingFlag = flag; }

private:

	/// <summary>
	/// 表示するテキスト
	/// </summary>
	std::string mText;

	/// <summary>
	/// テキストの色
	/// </summary>
	Color mColor;

	/// <summary>
	/// スケーリングをするかどうか
	/// </summary>
	bool mScalingFlag;
};
