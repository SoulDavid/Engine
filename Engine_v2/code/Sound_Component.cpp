/**
* @file Sound_Component.cpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 6 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena el objeto de sonido del componente
**/
#include "Sound_Component.hpp"

namespace Engine
{
	Sound_Component::Sound_Component() {};
	/// <summary>
	/// Funci�n que sirve para igualar el componente sonido al componente que le pasamos. 
	/// </summary>
	/// <param name="objeto"></param>
	Sound_Component::Sound_Component(Mix_Chunk* given_sound)
	{
		sound = given_sound;
	}
}

