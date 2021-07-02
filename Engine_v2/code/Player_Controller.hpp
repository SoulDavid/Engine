/**
* @file Player_Controller.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que controla el comportamiento del Player dependiendo del mensaje que reciba y controla las colisiones.
**/

#pragma once
#include <iostream>
#include "Controller.hpp"
#include "Message_Observer.hpp"
#include "Scene.hpp"
#include "Entity.hpp"
#include "TaskRenderer.hpp"
#include "Input_Task.hpp"

namespace Engine
{
	//Declaraciones adelantadas
	class Entity;
	class TaskRenderer;
	class Input_Task;
	class Player_Controller : public Controller, public Message_Observer
	{
	public:
		//Referencia a la escena
		Scene* scene;

		///Velocidad con la que se mueve el personaje
		const float speed = 0.5f;

		///Enumeracion para que vayan apareciendo las cajas, tambn sirve para que no colisione con alguna caja que este oculta
		enum NumberList { UNO, DOS, TRES, CUATRO, CINCO, SEIS };
		NumberList _numberList;

		///Booleano para saber si ha ganado, y que así no se repita el sonido final todo el rato
		bool GameOver;

		//Varaible creada para pasar de string a int (parecido a un código hash) y así meter las acciones en un switch (a modo de optimizacion)
		int Action;

	public: 
		//Constructor que recoge la escena y la guarda
		Player_Controller(Scene*);

		//Para pasar de std::string (el mensaje) a integer y así poder controlar acciones mediante un switch
		int SelectAction(std::string);

		///Función que se llama cuando se manda un mensaje
		void handle(const Message& m) override;

		//Update del player Controller
		void Update(float time) override;
	};
}


