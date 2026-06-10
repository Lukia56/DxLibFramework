#include "CameraManager.h"
#include <cassert>
#include <DxLib.h>
#include "ICamera.h"
#include "Utility/Color.h"
#include "Utility/Math.h"

namespace
{
	constexpr float kInitFOV = 70.0f;

	constexpr float kInitNearClip = 5.0f;
	constexpr float kInitFarClip = 5000.0f;

	constexpr float kCrossHairLength = 10.0f;
}

CameraManager::CameraManager() :
	mCurrentCameraType(Camera::Type::Follow),
	mView{ .fov = Math::ToRadian(kInitFOV), .nearClip = kInitNearClip, .farClip = kInitFarClip }
{
	// .fillÇæÇ∆ÉGÉâÅ[Ç…Ç»ÇÈÇΩÇﬂforÉãÅ[Év
	for (auto& it : mCameras)
	{
		it = nullptr;
	}
}

CameraManager::~CameraManager()
{
}

void CameraManager::Update()
{
	ICamera* camera = mCameras[static_cast<size_t>(mCurrentCameraType)].get();

	if (!camera)
	{
		assert(false && "CameraManager // åªç›ÇÃÉJÉÅÉâÇ™nullptrÇ≈Ç∑");
		return;
	}

	camera->Update(mView);
}

void CameraManager::DebugDraw() const
{
	Vector3 targetPos = mView.targetPosition;

	// Xé≤Çï`âÊ
	DrawLine3D(
		targetPos.GetAsDxLibVector(),
		(targetPos + Vector3::XAxis * kCrossHairLength).GetAsDxLibVector(),
		Color::red.GetAsHexRGB()
	);
	// Yé≤Çï`âÊ
	DrawLine3D(
		targetPos.GetAsDxLibVector(),
		(targetPos + Vector3::YAxis * kCrossHairLength).GetAsDxLibVector(),
		Color::green.GetAsHexRGB()
	);
	// Zé≤Çï`âÊ
	DrawLine3D(
		targetPos.GetAsDxLibVector(),
		(targetPos + Vector3::ZAxis * kCrossHairLength).GetAsDxLibVector(),
		Color::blue.GetAsHexRGB()
	);
}

void CameraManager::Bind() const
{
	SetupCamera_Perspective(mView.fov);
	SetCameraNearFar(mView.nearClip, mView.farClip);

	SetCameraPositionAndTarget_UpVecY(mView.eyePosition.GetAsDxLibVector(), mView.targetPosition.GetAsDxLibVector());
}

void CameraManager::AddCamera(Camera::Type type, std::unique_ptr<ICamera> camera)
{
	mCameras[static_cast<size_t>(type)] = std::move(camera);
}
