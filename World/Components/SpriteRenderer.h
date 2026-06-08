#pragma once

#include "Renderer.h"
#include "Utility/Vector.h"

class SpriteRenderer : public Renderer<Texture>
{
public:

	SpriteRenderer(GameObject* owner);
	~SpriteRenderer() = default;

	void Load(const std::string& filePath) override;

	void Draw() override;

private:

	/// <summary>
	/// ‰æ‘œ‚ÌƒTƒCƒY‚Ì”¼Œa
	/// </summary>
	Vector2 mHalfSize;
};

