#pragma once

#include "Renderer.h"
#include "Utility/Vector.h"

/// <summary>
/// 画像リソースの描画管理を行うクラス
/// </summary>
class SpriteRenderer : public Renderer<Texture>
{
public:

	SpriteRenderer(GameObject* owner);
	~SpriteRenderer() = default;

	/// <summary>
	/// クラスのテンプレート引数のリソースの読み込みを行う
	/// 読み込みに成功したら画像の半径も取得する
	/// </summary>
	void Load(const std::string& filePath) override;

	/// <summary>
	/// リソースをゲームオブジェクトのトランスフォームで描画する
	/// </summary>
	void Draw() override;

private:

	/// <summary>
	/// 画像のサイズの半径
	/// </summary>
	Vector2 mHalfSize;
};

