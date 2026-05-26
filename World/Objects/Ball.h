#pragma once

#include "../GameObject.h"

namespace Collision3D
{
	class Sphere3D;
	class AABB3D;
}

class Ball : public GameObject
{
public:

	Ball();
	~Ball() = default;

	void Init() override;

	void Update() override;

	void Draw() override;

	const Collision3D::Sphere3D* GetColiider() const { return mCollider.get(); }

private:

	std::unique_ptr<Collision3D::Sphere3D> mCollider;
};

