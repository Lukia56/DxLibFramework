#include "InputManager.h"
#include <cmath>
#include <memory>
#include "Input/Keyboard.h"
#include "Input/Mouse.h"
#include "Input/Gamepad.h"
#include "Input/Device/InputDeviceKeyboard.h"
#include "Input/Device/InputDeviceMouse.h"
#include "Input/Device/InputDeviceGamepad.h"
#include "Input/Literal/InputProperty.h"
#include "Input/Literal/InputActions.h"
#include "Input/Modifier/InputModifierNegate.h"
#include "Input/Modifier/InputModifierSwizzleAxis.h"
#include "Utility/Math.h"
#include "Utility/Vector.h"

InputManager& InputManager::GetInstance()
{
	static InputManager instance;
	
	return instance;
}

bool InputManager::Initialize()
{
	// 入力デバイスを登録
	RegisterDevice<InputDeviceKeyboard>(Input::Device::Keyboard);
	RegisterDevice<InputDeviceMouse>(Input::Device::Mouse);
	RegisterDevice<InputDeviceGamepad>(Input::Device::Gamepad);

	// アクションデータを初期化
	for (int i = 0; i < static_cast<int>(Input::Action::Length); i++)
	{
		mActions.emplace(static_cast<Input::Action>(i), Input::ActionProperty());
	}

	Bind(Input::Action::Up, Input::Device::Keyboard, KeyCode::Button::W);
	Bind(Input::Action::Up, Input::Device::Keyboard, KeyCode::Button::UpArrow);
	Bind(Input::Action::Down, Input::Device::Keyboard, KeyCode::Button::S);
	Bind(Input::Action::Down, Input::Device::Keyboard, KeyCode::Button::DownArrow);
	Bind(Input::Action::Left, Input::Device::Keyboard, KeyCode::Button::A);
	Bind(Input::Action::Left, Input::Device::Keyboard, KeyCode::Button::LeftArrow);
	Bind(Input::Action::Right, Input::Device::Keyboard, KeyCode::Button::D);
	Bind(Input::Action::Right, Input::Device::Keyboard, KeyCode::Button::RightArrow);

	Bind(Input::Action::Up, Input::Device::Gamepad, KeyCode::Button::GpFaceUp);
	Bind(Input::Action::Down, Input::Device::Gamepad, KeyCode::Button::GpFaceDown);
	Bind(Input::Action::Left, Input::Device::Gamepad, KeyCode::Button::GpFaceLeft);
	Bind(Input::Action::Right, Input::Device::Gamepad, KeyCode::Button::GpFaceRight);

	Bind(Input::Action::Move, Input::Device::Gamepad, KeyCode::Button::GpLeftThumb, {std::make_shared<InputModifierNegate>(false, true, false)});
	Bind(Input::Action::Move, Input::Device::Keyboard, KeyCode::Button::W,
		{
			std::make_shared<InputModifierSwizzleAxis>(InputModifierSwizzleAxis::Order::ZYX)
		});
	Bind(Input::Action::Move, Input::Device::Keyboard, KeyCode::Button::S,
		{
			std::make_shared<InputModifierNegate>(true, true, true),
			std::make_shared<InputModifierSwizzleAxis>(InputModifierSwizzleAxis::Order::ZYX)
		});
	Bind(Input::Action::Move, Input::Device::Keyboard, KeyCode::Button::A,
		{
			std::make_shared<InputModifierNegate>(true, true, true)
		});
	Bind(Input::Action::Move, Input::Device::Keyboard, KeyCode::Button::D);

	return true;
}

void InputManager::Update()
{
	Keyboard::GetInstance().Update();
	Mouse::GetInstance().Update();
	Gamepad::GetInstance().Update();

	for (const auto& device : mDevices)
	{
		device.second->Update();
	}
}

bool InputManager::IsDown(Input::Action action) const
{
	return GetState(action, InputType::Down);
}

bool InputManager::IsPressed(Input::Action action) const
{
	return GetState(action, InputType::Pressed);
}

bool InputManager::IsReleased(Input::Action action) const
{
	return GetState(action, InputType::Released);
}

bool InputManager::IsHeld(Input::Action action, int frame) const
{
	return GetState(action, InputType::Held, frame);
}

float InputManager::GetAsFloat(Input::Action action) const
{
	const Input::ActionProperty actionProperty = mActions.at(action);

	float result = 0.0f;

	// アクションに割り当てられたボタンをすべてチェックする
	for (const auto& bind : actionProperty.binds)
	{
		auto device = mDevices.at(bind.device).get();
		
		Vector3 value = device->GetValue(bind.keyCode);

		// バインドに割り当てられた加工をする
		for (const auto& modifier : bind.modifiers)
		{
			modifier->ModifyRaw(&value);
		}
		
		// 絶対値が大きい方を使用する
		if (std::abs(result) < std::abs(value.x)) result = value.x;
	}

	return result;
}

const Vector2& InputManager::GetAsVector2(Input::Action action) const
{
	const Input::ActionProperty actionProperty = mActions.at(action);

	Vector2 result = Vector2::Zero;

	// アクションに割り当てられたボタンをすべてチェックする
	for (const auto& bind : actionProperty.binds)
	{
		auto device = mDevices.at(bind.device).get();
		
		Vector3 value = device->GetValue(bind.keyCode);

		// バインドに割り当てられた加工をする
		for (const auto& modifier : bind.modifiers)
		{
			modifier->ModifyRaw(&value);
		}
		
		// 絶対値が大きい方を使用する
		if (std::abs(result.x) < std::abs(value.x)) result.x = value.x;
		if (std::abs(result.y) < std::abs(value.y)) result.y = value.y;
	}

	if (result != Vector2::Zero) result = result.GetNormalize();

	return result;
}

const Vector3& InputManager::GetAsVector3(Input::Action action) const
{
	const Input::ActionProperty actionProperty = mActions.at(action);

	Vector3 result = Vector3::Zero;

	// アクションに割り当てられたボタンをすべてチェックする
	for (const auto& bind : actionProperty.binds)
	{
		auto device = mDevices.at(bind.device).get();
		
		Vector3 value = device->GetValue(bind.keyCode);

		// バインドに割り当てられた加工をする
		for (const auto& modifier : bind.modifiers)
		{
			modifier->ModifyRaw(&value);
		}
		
		// 絶対値が大きい方を使用する
		if (std::abs(result.x) < std::abs(value.x)) result.x = value.x;
		if (std::abs(result.y) < std::abs(value.y)) result.y = value.y;
		if (std::abs(result.z) < std::abs(value.z)) result.z = value.z;
	}

	if (result != Vector3::Zero) result = result.GetNormalize();

	return result;
}

bool InputManager::GetState(Input::Action action, InputType inputType, int frame) const
{
	const Input::ActionProperty actionProperty = mActions.at(action);

	// アクションに割り当てられたボタンをすべてチェックする
	for (const auto& bind : actionProperty.binds)
	{
		auto device = mDevices.at(bind.device).get();

		// 押下状態を取得する
		// 割り当てられたボタンのどれかが押されていたらtrueとする
		switch (inputType)
		{
		case InputType::Down:
			if (device->IsDown(bind.keyCode)) return true;
			break;

		case InputType::Pressed:
			if (device->IsPressed(bind.keyCode)) return true;
			break;

		case InputType::Released:
			if (device->IsReleased(bind.keyCode)) return true;
			break;

		case InputType::Held:
			if (device->IsHeld(bind.keyCode, frame)) return true;
			break;
		}
	}

	// ここまで来たら押されていないためfalse
	return false;
}

void InputManager::Bind(Input::Action action, Input::Device device, KeyCode::Button button, std::vector<std::shared_ptr<IInputModifier>> modifiers, Input::PadSlot slot)
{
	Input::BindProperty bind;
	bind.device = device;
	bind.keyCode = button;
	bind.modifiers = modifiers;
	bind.slot = slot;
	mActions.at(action).binds.emplace_back(bind);
}
