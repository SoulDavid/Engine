/**
* @file Kernel.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 19 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que recoge las tasks, y llama a sus updates, de tal manera, que todas las tasks estan funcionando al mismo tiempo.
**/
#pragma once
#include "Task.hpp"
#include <list>

namespace Engine { 

	/// Declaraciones adelantadas de las clases que utilizo
	class Window;
	class TaskRenderer;
	class Kernel
	{
	public:
		//Lista de tareas que recoge.
		std::list<Task*> tasks;

		//Booleano que indica si se sale o no se sale del circulo, normalmente para cerrar el engine. 
		bool exit = false;

		//Referencia a la tarea.
		Task* t;
	public:
		//Constructor por defecto
		Kernel(Window & w);

		//Función Update, que va a estar todo el rato funcionando
		void Update(Window & w);

		//Función de añadir una tarea nueva
		void Add_Task(Task * t);

		//Destructor del Kernel
		~Kernel();
	};
}


