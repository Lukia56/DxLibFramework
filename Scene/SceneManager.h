#pragma once

#include <memory>

class SceneBase;
class CameraManager;

/// <summary>
/// シーンの遷移やライフサイクルの管理をするクラス
/// </summary>
class SceneManager
{
public:

	SceneManager();
	~SceneManager();

	/// <summary>
	/// 初期化処理
	/// 初期シーンの作成を行う
	/// </summary>
	void Initialize();

	/// <summary>
	/// 現在のシーンの終了処理
	/// </summary>
	void Finalize();

	/// <summary>
	/// シーンの更新処理
	/// シーン遷移の判定も行う
	/// </summary>
	void Update();

	/// <summary>
	/// シーンの描画
	/// </summary>
	void Draw();

	/// <summary>
	/// デバッグ情報の描画
	/// </summary>
	void DebugDraw();

private:

	/// <summary>
	/// シーンの作成を行う
	/// </summary>
	template <class T>
	requires std::derived_from<T, SceneBase>
	void CreateScene();

private:

	std::unique_ptr<SceneBase> mCurrentScene;

	std::unique_ptr<CameraManager> mCameraManager;
};

template<class T>
requires std::derived_from<T, SceneBase>
inline void SceneManager::CreateScene()
{
	auto scene = std::make_unique<T>();
	scene->Init();
	mCurrentScene = std::move(scene);
}
