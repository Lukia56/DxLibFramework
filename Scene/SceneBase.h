#pragma once

#include <memory>
#include <vector>

class GameObject;

/// <summary>
/// シーンの基礎となるクラス
/// ゲームオブジェクトの管理を行う
/// </summary>
class SceneBase
{
public:

	using GameObjectContainer = std::vector<std::unique_ptr<GameObject>>;

	SceneBase();
	virtual ~SceneBase();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Init() = 0;

	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void Finalize() = 0;

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>次のシーンのポインタ</returns>
	virtual std::unique_ptr<SceneBase> Update() = 0;

	/// <summary>
	/// ルートオブジェクトの更新処理を呼ぶ
	/// </summary>
	void UpdateRootObjects();

	/// <summary>
	/// ルートオブジェクトの描画処理を呼ぶ
	/// </summary>
	void DrawRootObjects();

protected:

	/// <summary>
	/// ルートオブジェクトに追加する
	/// </summary>
	void Add(std::unique_ptr<GameObject> gameObject);

private:

	/// <summary>
	/// ゲームオブジェクトの更新処理
	/// </summary>
	void Update(GameObject* gameObject);

	/// <summary>
	/// ゲームオブジェクトの描画処理
	/// </summary>
	void Draw(GameObject* gameObject);

private:
	
	/// <summary>
	/// ルートオブジェクト
	/// </summary>
	GameObjectContainer mRootObjects;
};
