/**
* @file Input_Task.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 19 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que guarda el comportamiento cuando se pulsa una tecla.
**/

#pragma once
#include "Task.hpp"
#include "Player_Controller.hpp"

namespace Engine
{
	//Declaracion adelantada de las clases que necesitamos
	//class Window;
	class Message;
	class Message_Observer;
	class Player_Controller;
	class Scene;
	//Al ser una tarea, hereda las propiedades de Task
	class Input_Task : public Task
	{
	public:
		//Referencia a la escena
		Scene* scene;

	public:
		//Constructor que recoge referencia a la escena
		Input_Task(Scene*);

		//Función que contiene todo el comportamiento del input y que funcion hace cuando se pulsa una tecla, o hay un evento con esta
		//Se llama desde el kernel
		virtual void Update(float t, Window & window) override;

		//Destructor de Input_Task
		~Input_Task();
	};
}


