/**
* @file Entity.hpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que guarda los componentes que tiene cada entity.
**/

#pragma once
#include "Scene.hpp"
#include <map>
#include <string>
#include <memory>
#include "Component.hpp"
#include "Transform_Component.hpp"
#include "Render_Component.hpp"
#include "Music_Component.hpp"
#include "Sound_Component.hpp"
#include "Audio.hpp"
#include "Vector3.hpp"

//Declaraci�n adelanta de Model_Obj
namespace glt
{
	class Model_Obj;
}

namespace Engine
{
	//Declaraci�n adelantada de la clase Scene.
	class Scene;
	class Entity
	{
	public:
		//Si esta activada esa entidad, puede ser por ejemplo para controlar si esta visible o no
		bool active;

		//Referencia a la escena
		Scene * scene;
		
		//Mapa que gaurda, el nombre de la entidad y un puntero a un tipo de componente
		std::map<std::string, std::shared_ptr<Component>> components;

		//Referencia al tipo de componente: Transform component
		Transform_Component transform;

		Music_Component music;

		Sound_Component sound;

	public:
		//Constructor por defecto
		Entity(Scene*);

		///Funci�n para a�adir componentes, a la que se le pasa un nombre, y el componente
		void add_Component								(std::string, std::shared_ptr<Component>);

		//Conseguir valores como la posicio�n, rotacion o escala de la entidad.
		Math::Vector3 get_position						() { return transform.position; }
		Math::Vector3 get_rotation						() { return transform.rotation; }
		Math::Vector3 get_scale							() { return transform.scale;	}	



		//Funciones para saber si esta visible o no
		bool GetActive();
		void SetActive();

		//Setear la posicion de la entidad.
		void SetPosition(Math::Vector3);
	};
}


