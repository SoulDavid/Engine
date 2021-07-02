/**
* @file Scene.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script donde se crean todas las entidades y se crean sus componentes 8Debería de ir en el main pero por falta de tiempo lo puse en este script.
**/

#pragma once
#include "Kernel.hpp"
#include "Input_Task.hpp"
#include "TaskRenderer.hpp"
#include "Audio.hpp"
#include "Message_Dispatcher.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "Vector3.hpp"
#include "stdlib.h"
#include <map>

namespace Engine {
	//Declaraciones adelantadas
	class Window;
	class Input_Task;
	class Audio;
	class Scene
	{
	public:

		#pragma region Tareas/Referencias
		Scene * scene;
		Kernel * kernel;
		Input_Task * it;
		TaskRenderer * tr;
		Audio * at;
		Message_Dispatcher message_dispatcher;
		#pragma endregion

		#pragma region Entidades
		//Entidad del player
		Entity * Player;

		//Entidades de las esferas que tiene que recoger el jugador
		Entity * Box1;
		Entity * Box2;
		Entity * Box3;
		Entity * Box4;
		Entity * Box5;

		//Entidades de los limites
		Entity* LimitRight;
		Entity* LimitLeft;
		Entity* LimitUp;
		Entity* LimitDown;

		//Entidad de la luz
		Entity* Light;

		//Entidad de la camara
		Entity* Camera;

		//Entidad del cartel de victoria
		Entity* WinningSound;
		#pragma endregion

		//Mapa donde se almacena las entidades
		std::map<std::string, std::shared_ptr<Entity>> entities;


	public:
		///Constructor que recoge el nombre de la escena y la referencia a la ventana
		Scene(const char*, Window &);	

		//Funcion para añadir luces y una camara a la escena
		void AddLightAndCamera();

		//Funcion para añadir el jugador a la escena
		void AddPlayer();

		//Funcion para añadir las esferas a la escena
		void AddSpheres();

		//Funcion para añadir los limites.
		void AddLimits();

		//Funcion para recoge el message_dispatcher
		Message_Dispatcher& get_message_dispatcher();

		///Funcion para añadir un observador, de esta manera incluimos el player_controller.
		void add_observer(const std::string &, Message_Observer *);

		//Funcion que llama al update del kernel
		void Update(Window & w);

		//Destructor de escena
		~Scene();
	};
}



