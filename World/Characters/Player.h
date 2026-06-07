#pragma once

#include "../GameObject.h"

class ModelRenderer;
class Crate;
class Ball;

namespace Collision3D
{
	class AABB3D;
}

class Player : public GameObject
{
public:

	Player();
	~Player();

	void Init() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;

public:

	void SetCrate(Crate* crate) { mCrate = crate; }

	void SetBall(Ball* ball) { mBall = ball; }

private:

	std::unique_ptr<ModelRenderer> mModel;

	std::unique_ptr<Collision3D::AABB3D> mCollider;

	Crate* mCrate;

	Ball* mBall;
};
