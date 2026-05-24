#pragma once

#include "../GameObject.h"

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

private:

	std::unique_ptr<Collision3D::AABB3D> mCollider;
};
