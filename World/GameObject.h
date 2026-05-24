#pragma once

#include <memory>
#include <vector>
#include "Components/Transform.h"

/// <summary>
/// ゲームオブジェクトクラス
/// </summary>
class GameObject
{
public:

	using GameObjectContainer = std::vector<std::unique_ptr<GameObject>>;

	GameObject();
	virtual ~GameObject();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Init() = 0;

	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void Finalize() {};

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() {};

	/// <summary>
	/// 削除処理が呼ばれているかチェックし
	/// 呼ばれていたら削除を行う
	/// </summary>
	/// <returns>自身を削除するならtrue</returns>
	bool CheckDestroy();

public:

	/// <summary>
	/// 親オブジェクトを取得する
	/// </summary>
	GameObject* GetParent() const { return mParent; }

	/// <summary>
	/// 子オブジェクトを取得する
	/// </summary>
	GameObjectContainer& GetChildren() { return mChildren; }

protected:

	/// <summary>
	/// 子オブジェクトに追加する
	/// </summary>
	void Add(std::unique_ptr<GameObject> gameObject);

	/// <summary>
	/// ゲームオブジェクトを削除する
	/// 更新処理の後に削除する
	/// </summary>
	/// <param name="gameObject">削除するゲームオブジェクトのポインタ</param>
	void Destroy(GameObject* gameObject);

protected:

	/// <summary>
	/// トランスフォーム
	/// </summary>
	Transform mTransform;

private:

	/// <summary>
	/// 削除処理が呼ばれたかどうか
	/// 更新処理後に削除するかを判定する
	/// </summary>
	bool mIsCalledDestroy;

	/// <summary>
	/// 親オブジェクト
	/// </summary>
	GameObject* mParent;

	/// <summary>
	/// 子オブジェクト
	/// </summary>
	GameObjectContainer mChildren;
};

