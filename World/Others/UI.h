#pragma once

#include "../GameObject.h"

class SpriteRenderer;
class TextRenderer;

class UI : public GameObject
{
public:

	UI();
	~UI();

	void Init() override;

	void Update() override;

	void Draw() override;

private:

	int mGraphHandle;

	std::unique_ptr<SpriteRenderer> mSprite;

	std::unique_ptr<TextRenderer> mText;
};

