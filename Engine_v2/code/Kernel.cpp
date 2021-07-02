/**
* @file Kernel.cpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 19 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que recoge las tasks, y llama a sus updates, de tal manera, que todas las tasks estan funcionando al mismo tiempo.
**/
#include "Kernel.hpp"
#include "TaskRenderer.hpp"

namespace Engine
{
	Kernel::Kernel(Window & w)
	{

	}
	///Funci�n que llama al update de cada tarea de lista. 
	void Kernel::Update(Window & w)
	{
		do
		{
			for (auto* t : tasks)
			{
				t->Update(100, w);
			}

		} while (!exit);
	}

	///Funci�n que a�ade una tarea a la lista de tareas
	void Kernel::Add_Task(Task * t)
	{
		tasks.push_back(t);
	}
}