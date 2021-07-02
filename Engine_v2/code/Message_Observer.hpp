/**
* @file Message_Observer.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que contiene la funcion handle, de la cual heredará los distintos observadores
* de modo, que el player_controller tenga esa función, y se llamara desde el Message_Dispatcher
**/
#pragma once
#include "Message.hpp"

namespace Engine
{
	class Scene;
	class Message_Observer
	{
	public:
		///Funcion handle que herederarán los hijos como el player_controller
		virtual void handle(const Message &) = 0;
	};
}


