#pragma once

#include "SceneBase.h"

class Player;
class Crate;
class Ball;

class SceneTest : public SceneBase
{
public:

	SceneTest();
	~SceneTest();

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

private:

	Player* mPlayer;
	Crate* mCrate;
	Ball* mBall;
};
