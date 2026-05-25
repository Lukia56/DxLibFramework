#pragma once
#include "../GameObject.h"

namespace Collision3D
{
	class Sphere3D;
	class AABB3D;
}

class Crate : public GameObject
{
public:

	Crate();
	~Crate() = default;

	void Init() override;

	void Update() override;

	void Draw() override;

	const Collision3D::Sphere3D* GetColiider() const { return mCollider.get(); }
	//const Collision3D::AABB3D* GetColiider() const { return mCollider.get(); }

private:

	std::unique_ptr<Collision3D::Sphere3D> mCollider;
	//std::unique_ptr<Collision3D::AABB3D> mCollider;
};
