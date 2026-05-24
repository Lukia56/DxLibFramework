#pragma once

#include "SceneBase.h"

class SceneTest : public SceneBase
{
public:

	SceneTest();
	~SceneTest() = default;

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Init() override;

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>次のシーンのポインタ</returns>
	std::unique_ptr<SceneBase> Update() override;
};
