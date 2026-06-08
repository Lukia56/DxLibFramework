#pragma once

#include <string>

class GameObject;
class Resource;

/// <summary>
/// スプライト描画の管理をするクラス
/// </summary>
class TextRenderer
{
public:

	TextRenderer(GameObject* owner);
	~TextRenderer();

	/// <summary>
	/// フォントの読み込み
	/// フォントが見つからなかったらDxLibデフォルトのフォントを使用する
	/// </summary>
	void Load(const std::string& filePath);

	/// <summary>
	/// テキストの描画
	/// </summary>
	void Draw();

	void SetText(const std::string& text) { mText = text; }

private:

	/// <summary>
	/// 表示するテキスト
	/// </summary>
	std::string mText;

	Resource* mFont;

	/// <summary>
	/// 自身を所有するゲームオブジェクト
	/// </summary>
	GameObject* mOwner;
};
