#pragma once

#include "ICamera.h"
#include "Utility/Vector.h"

/// <summary>
/// フリーに移動できるデバッグ用カメラ
/// </summary>
class CameraDebugFree : public ICamera
{
public:

	CameraDebugFree();
	~CameraDebugFree() = default;

	void Update(Camera::View& view) override;

private:

	Vector3 mPosition;
	Vector3 mRotation;
};
