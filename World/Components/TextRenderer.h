#pragma once

#include "Renderer.h"

class TextRenderer : public Renderer<Font>
{
public:

	TextRenderer(GameObject* owner);
	~TextRenderer() = default;

	void Draw() override;

	void SetText(const std::string& text) { mText = text; }

private:

	/// <summary>
	/// 表示するテキスト
	/// </summary>
	std::string mText;
};
