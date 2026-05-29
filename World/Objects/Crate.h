#pragma once
#include "../GameObject.h"

class Model;

namespace Collision3D
{
	class Sphere3D;
	class AABB3D;
}

class Crate : public GameObject
{
public:

	Crate();
	~Crate();

	void Init() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;

	const Collision3D::AABB3D* GetColiider() const { return mCollider.get(); }

private:

	std::unique_ptr<Model> mModel;

	std::unique_ptr<Collision3D::AABB3D> mCollider;
};
