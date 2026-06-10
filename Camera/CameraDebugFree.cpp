#include "CameraDebugFree.h"
#include <cmath>
#include "System/InputManager.h"
#include "Utility/Math.h"
#include "Utility/Vector.h"

namespace
{
	constexpr float kMoveSpeed = 10.0f;

	constexpr float kDistanceToTarget = 100.0f;
}

CameraDebugFree::CameraDebugFree()
{
}

void CameraDebugFree::Update(Camera::View& view)
{
	float pitchRad = Math::ToRadian(mRotation.x);
	float yawRad = Math::ToRadian(mRotation.y);

	Vector3 forward;
	forward.x = std::cos(pitchRad) * std::sin(yawRad);
	forward.y = std::sin(pitchRad);
	forward.z = std::cos(pitchRad) * std::cos(yawRad);

	Vector3 right;
	right.x = std::cos(yawRad);
	right.y = 0.0f;
	right.z = -std::sin(yawRad);

	Vector3 moveDir = InputManager::GetInstance().GetAsVector3(Input::Action::Move);
	mPosition += forward * kMoveSpeed * moveDir.z;
	mPosition += right * kMoveSpeed * moveDir.x;

	mPosition.y += kMoveSpeed * InputManager::GetInstance().GetAsFloat(Input::Action::Fly);

	view.eyePosition = mPosition;
	view.targetPosition = mPosition + forward * kDistanceToTarget;
}
