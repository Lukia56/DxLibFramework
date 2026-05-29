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
	/// トランスフォームを取得する
	/// </summary>
	Transform& GetTransform() { return mTransform; }

protected:

	/// <summary>
	/// 子オブジェクトに追加する
	/// </summary>
	/// <param name="gameObject">追加するゲームオブジェクトのスマートポインタ</param>
	/// <returns>追加したゲームオブジェクトの生ポインタ</returns>
	template <class T>
	requires std::derived_from<T, GameObject>
	T* Add(std::unique_ptr<T> gameObject);

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
};

template <class T>
requires std::derived_from<T, GameObject>
inline T* GameObject::Add(std::unique_ptr<T> gameObject)
{
	T* ptr = gameObject.get();
	ptr->Init();
	ptr->GetTransform().SetParent(std::move(gameObject), &mTransform);
	return ptr;
}
