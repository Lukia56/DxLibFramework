#pragma once

class GameObject;

/// <summary>
/// モデルの管理をするクラス
/// </summary>
class ModelRenderer
{
public:

	ModelRenderer(GameObject* owner);
	~ModelRenderer();

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

	/// <summary>
	/// モデルハンドル
	/// </summary>
	int mHandle;

	/// <summary>
	/// 自身を所有するゲームオブジェクト
	/// </summary>
	GameObject* mOwner;
};
