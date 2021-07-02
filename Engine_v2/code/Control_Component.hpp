#pragma once
#include "Controller.hpp"
#include "Component.hpp"

namespace Engine
{
	class Control_Component : public Component
	{
		Controller* controller;
	};
}


