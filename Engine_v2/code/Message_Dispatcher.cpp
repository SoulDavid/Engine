/**
* @file Message_Dispatcher.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que hace de intermediario entre message_observer y el input.
* El input llama a este script y este hace el handle de los observers que se ha guardado previamente en un map.
**/

#include "Message_Dispatcher.hpp"
#include "Message_Observer.hpp"
#include <SDL.h>

namespace Engine
{
	///Introducir en el mapa creado con anterioridad, el observador que le pasamos, con su propio id. 
	void Message_Dispatcher::add_observer(std::string id, Message_Observer* observer)
	{
		message_observers[id].push_back(observer);
	}

	///Recorre el array de message_observers y crea un observer por cada uno, con el mensaje, y se lo pasa a todos aquellos que heredan de este mediante la funcion handle
	void Message_Dispatcher::send(const Message& m)
	{
		for (auto& observer : message_observers[m.id])
		{
			observer->handle(m);
		}
	}
}
