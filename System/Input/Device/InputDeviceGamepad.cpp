#include "InputDeviceGamepad.h"
#include "../Format/InputFormatGamepadButton.h"
#include "../Format/InputFormatGamepadTrigger.h"
#include "../Format/InputFormatGamepadThumb.h"

void InputDeviceGamepad::InitDevice()
{
	RegisterFormat<InputFormatGamepadButton>();
	RegisterFormat<InputFormatGamepadTrigger>();
	RegisterFormat<InputFormatGamepadThumb>();
}
