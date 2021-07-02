/**
* @file Message_Observer.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que contiene la funcion handle, de la cual heredará los distintos observadores
* de modo, que el player_controller tenga esa función, y se llamara desde el Message_Dispatcher
**/

#include "Message_Observer.hpp"
#include <SDL.h>

namespace Engine
{
	///Función que heredan los hijos como Player_Controller
	void Message_Observer::handle(const Message& m)
	{
	}
}
