/**
* @file Message_Dispatcher.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que hace de intermediario entre message_observer y el input.
* El input llama a este script y este hace el handle de los observers que se ha guardado previamente en un map.
**/

#pragma once
#include <map>
#include <string>
#include <list>
#include "Message_Observer.hpp"
#include "Message.hpp"

namespace Engine
{
	//Declaración adelantada de la clase Scene
	class Scene;
	class Message_Dispatcher
	{
		//Puntero a la escena
		Scene* scene;

		//Mapa que guarda un id de string y una lista de Message_Observer
		std::map<std::string, std::list<Message_Observer*>> message_observers;
	public:
		///Añadir observador al mapa creado anteriormente. 
		void add_observer(std::string, Message_Observer*);

		///Llama al handle de cada observador creado con anterioridad
		void send(const Message&);
	};
}


