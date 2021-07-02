/**
* @file Message_Observer.cpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que contiene la funcion handle, de la cual heredar� los distintos observadores
* de modo, que el player_controller tenga esa funci�n, y se llamara desde el Message_Dispatcher
**/

#include "Message_Observer.hpp"
#include <SDL.h>

namespace Engine
{
	///Funci�n que heredan los hijos como Player_Controller
	void Message_Observer::handle(const Message& m)
	{
	}
}
