/**
* @file Entity.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que guarda el comportamiento de cada funcion de Entity.
**/

#include <string>
#include "Entity.hpp"
#include <SDL.h>
#include "Music_Component.hpp"

namespace Engine
{
	Entity::Entity(Scene* given_Scene)
	{
		scene = given_Scene;
	}

	//Añade un componente al mapa con un id y el componente
	void Entity::add_Component(std::string name, std::shared_ptr<Component> component)
	{
		//https://www.cplusplus.com/reference/map/map/insert/
		components.insert({ name, component });	
	}

	//Devuelve si esta activa
	bool Entity::GetActive()
	{
		return active;
	}

	//Si esta activa se pone a false, y viceversa
	void Entity::SetActive()
	{
		if (!GetActive())
		{
			active = true;
		}
		else
		{
			active = false;
		}
	}

	//Setea la posicion de la entidad
	void Entity::SetPosition(Math::Vector3 new_position)
	{
		transform.position = new_position;
	}
}
