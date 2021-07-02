/**
* @file Task.hpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 19 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que contiene la funci�n que tienen que tener las tareas que hereden de esta clase.
**/

#pragma once
namespace Engine {
	//Declaracion adelantada de window
	class Window;
	class Task
	{
	public: 
		//Prioridad de la tarea
		int priority;
	public:
		//Funci�n Update que van a heredar el resto de tareas.
		virtual void Update(float t, Window & window) = 0;
	};

}

