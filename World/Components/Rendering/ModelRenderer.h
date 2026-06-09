#pragma once

#include "Renderer.h"

/// <summary>
/// モデルリソースの描画管理を行うクラス
/// </summary>
class ModelRenderer : public Renderer<Model>
{
public:

	ModelRenderer(GameObject* owner);
	~ModelRenderer() = default;

	/// <summary>
	/// リソースをゲームオブジェクトのトランスフォームで描画する
	/// </summary>
	void Draw() override;
};
