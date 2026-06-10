#include "CameraDebugFree.h"
#include <cmath>
#include "System/InputManager.h"
#include "System/Input/Mouse.h"
#include "Utility/Math.h"
#include "Utility/Vector.h"

namespace
{
	constexpr float kMoveSpeed = 10.0f;
	constexpr float kRotSpeed = Math::ToRadian(10.0f);

	constexpr float kDistanceToTarget = 100.0f;

	constexpr float kPitchLimit = Math::ToRadian(89.0f);
}

CameraDebugFree::CameraDebugFree()
{
}

void CameraDebugFree::Update(Camera::View& view)
{
	if (Mouse::GetInstance().GetRelative() != Vector2::Zero && Mouse::GetInstance().IsDown(MOUSE_INPUT_LEFT)
	|| Mouse::GetInstance().GetRelative() == Vector2::Zero)
	{
		mRotation += InputManager::GetInstance().GetAsVector3(Input::Action::Look) * kRotSpeed;
	}

	mRotation.x = Math::Clamp(mRotation.x, -kPitchLimit, kPitchLimit);

	float pitchRad = mRotation.x;
	float yawRad = mRotation.y;

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
