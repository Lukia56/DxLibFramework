#pragma once

#include "ICamera.h"

class Transform;

/// <summary>
/// ‹“_‚ğ‘€ì‚Å‚«‚ÄA”íÊ‘Ì‚ğ’Ç”ö‚·‚éƒJƒƒ‰
/// </summary>
class CameraFollow : public ICamera
{
public:

	CameraFollow();
	~CameraFollow() = default;

	void Update(Camera::View& view) override;

private:

	/// <summary>
	/// ”íÊ‘Ì‚Æ‚Ì‹——£
	/// </summary>
	float mDistance;

	Vector3 mPosition;

	Vector3 mRotation;

	Transform* mTarget;
};
