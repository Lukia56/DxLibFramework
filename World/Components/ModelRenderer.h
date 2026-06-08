#pragma once

#include "Renderer.h"

class ModelRenderer : public Renderer<Model>
{
public:

	ModelRenderer(GameObject* owner);
	~ModelRenderer() = default;

	void Draw() override;
};
