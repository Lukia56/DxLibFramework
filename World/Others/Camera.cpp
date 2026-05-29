#include "Camera.h"
#include "Utility/Math.h"

namespace
{
	constexpr float kInitNearClip = 5.0f;
	constexpr float kInitFarClip = 5.0f;

	constexpr float kInitFOV = 60.0f;

	constexpr float kInitDistance = 400.0f;
}

Camera::Camera() :
	mNearClip(kInitNearClip),
	mFarClip(kInitFarClip),
	mFOV(kInitFOV),
	mDistanceToTarget(kInitDistance),
	mOffsetPos(Vector3::Zero),
	mTarget(nullptr)
{
}

void Camera::Init()
{
	//mTransform.Translate(Vector3(0.0f, 0.0f, -mDistanceToTarget));
	mTransform.localPosition += Vector3(0.0f, 0.0f, -mDistanceToTarget);
	SetCameraPositionAndTarget_UpVecY(mTransform.localPosition.GetAsDxLibVector(), VGet(0.0f, 0.0f, 0.0f));
}

void Camera::Update()
{
	SetCameraNearFar(mNearClip, mFarClip);
	SetupCamera_Perspective(Math::ToRadian(mFOV));

	if (mTarget)
	{
		VECTOR cameraPos = (mTransform.localPosition + mOffsetPos).GetAsDxLibVector();
		VECTOR targetPos = mTarget->localPosition.GetAsDxLibVector();
		SetCameraPositionAndTarget_UpVecY(cameraPos, targetPos);
	}
}
