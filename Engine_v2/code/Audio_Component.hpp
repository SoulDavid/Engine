/**
* @file Audio_Component.hpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 3 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que funciona como padre de SoundComponent y MusicComponent. 
* Sirve como para tener m�s ordenada la estructura del motor.
**/

#pragma once
#include "Component.hpp"

namespace Engine
{
	//Al ser un componente, este hereda de la clase Component
	class Audio_Component : public Component
	{
	};
}


