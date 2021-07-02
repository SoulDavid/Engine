/**
* @file Transform_Component.hpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 2 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que guarda la posicion, escala y rotaci�n de la entidad
**/

#pragma once
#include "Component.hpp"
#include <cmath>
#include "Vector3.hpp"

namespace Engine
{
	//Al ser un componente, este hereda de la clase Component
	class Transform_Component : public Component
	{
	public:
		//Vector que guarda la posici�n
		Math::Vector3 position;

		//Vector que guarda la rotacion
		Math::Vector3 rotation;

		//Vector que guarda la escala
		Math::Vector3 scale;
	};
}


