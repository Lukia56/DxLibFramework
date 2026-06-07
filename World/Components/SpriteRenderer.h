#pragma once

#include "Utility/Vector.h"

class GameObject;
class Resource;

/// <summary>
/// スプライト描画の管理をするクラス
/// </summary>
class SpriteRenderer
{
public:

	SpriteRenderer(GameObject* owner);
	~SpriteRenderer();

	/// <summary>
	/// モデルの読み込み
	/// </summary>
	/// <param name="filePath"></param>
	void Load(const char* const filePath);

	/// <summary>
	/// モデルの描画
	/// </summary>
	void Draw();

private:

	Resource* mTexture;

	/// <summary>
	/// 画像のサイズの半径
	/// </summary>
	Vector2 mHalfSize;

	/// <summary>
	/// 自身を所有するゲームオブジェクト
	/// </summary>
	GameObject* mOwner;
};

