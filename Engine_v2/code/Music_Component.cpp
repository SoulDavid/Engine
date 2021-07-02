/**
* @file Music_Component.cpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 6 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena el objeto de musica del componente
**/

#include "Music_Component.hpp"

namespace Engine
{
	Music_Component::Music_Component() {};
	/// <summary>
	/// Funci�n que sirve para igualar el componente musica al componente que le pasamos. 
	/// </summary>
	/// <param name="objeto"></param>
	Music_Component::Music_Component(Mix_Music* given_music)
	{
		music = given_music;
	}
}
