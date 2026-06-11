#pragma once

#include <memory>
#include <vector>

class GameObject;
class CameraManager;

/// <summary>
/// シーンの基礎となるクラス
/// ゲームオブジェクトの更新やライフサイクルの管理を行う
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
	/// 基底の更新処理
	/// </summary>
	/// <returns>次のシーンのポインタ</returns>
	std::unique_ptr<SceneBase> UpdateBase();

	/// <summary>
	/// 基底の描画処理
	/// </summary>
	void DrawBase();

public:

	CameraManager* GetCameraManager() const { return mCameraManager.get(); }

protected:

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>次のシーンのポインタ</returns>
	virtual std::unique_ptr<SceneBase> Update() = 0;

	/// <summary>
	/// ルートオブジェクトに追加する
	/// </summary>
	/// <param name="gameObject">追加するルートオブジェクトのスマートポインタ</param>
	/// <returns>追加したルートオブジェクトの生ポインタ</returns>
	template <class T>
	requires std::derived_from<T, GameObject>
	T* Add(std::unique_ptr<T> gameObject);

private:

	/// <summary>
	/// ルートオブジェクトの更新処理を呼ぶ
	/// </summary>
	void UpdateRootObjects();

	/// <summary>
	/// ルートオブジェクトの描画処理を呼ぶ
	/// </summary>
	void DrawRootObjects();

	/// <summary>
	/// ゲームオブジェクトの更新処理
	/// </summary>
	void Update(GameObject* gameObject);

	/// <summary>
	/// ゲームオブジェクトの描画処理
	/// </summary>
	void Draw(GameObject* gameObject);

private:
	
	GameObjectContainer mRootObjects;

	std::unique_ptr<CameraManager> mCameraManager;
};

template <class T>
requires std::derived_from<T, GameObject>
inline T* SceneBase::Add(std::unique_ptr<T> gameObject)
{
	T* ptr = gameObject.get();
	ptr->Init();
	mRootObjects.emplace_back(std::move(gameObject));
	return ptr;
}
