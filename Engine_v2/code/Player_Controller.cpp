/**
* @file Player_Controller.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que controla el comportamiento del Player dependiendo del mensaje que reciba y controla las colisiones.
**/

#include "Player_Controller.hpp"
#include"Math.hpp"
#include "Transform_Component.hpp"
#include "TaskRenderer.hpp"
#include<SDL.h>

namespace Engine
{
	//Constructor que recoge la escena y la guarda
	Player_Controller::Player_Controller(Scene* given_scene)
	{
		scene = given_scene;
		//Pone el primer objetivo a la primera caja
		_numberList = NumberList::UNO;

		//Inicializa el booleano a false
		GameOver = false;
	}

	//Para pasar de std::string (el mensaje) a integer y así poder controlar acciones mediante un switch
	int Player_Controller::SelectAction(std::string id)
	{
		if (id == "MoveForward")
			return 1;
		else if (id == "MoveDown")
			return 2;
		else if (id == "MoveRight")
			return 3;
		else if (id == "MoveLeft")
			return 4;
		else if (id == "SoundMusic")
			return 5;
		else if (id == "LowMusic")
			return 6;
		else if (id == "HighMusic")
			return 7;
		else if (id == "PauseMusic")
			return 8;
		else
			return 0;
	}

	///Función que se llama cuando se manda un mensaje
	void Player_Controller::handle(const Message& m)
	{
		//Recoge el mensaje y le asigna una valor

		switch (Action = SelectAction(m.id))
		{
			case 1:
				//Si el personaje tiene margen para moverse (es decir, no esta chocando con un limite) entonces se movera en esa dirección con una speed que le hemos dado antes 
				//y se guardará la posicion. Y si se esta chocando con el limite de arriba entonces saldrá un sonido que le dira al jugador que no puede seguir

				if ((scene->Player->transform.position.y() < scene->LimitUp->transform.position.y() - 8.f) || _numberList == NumberList::SEIS)
				{
					scene->tr->TranslateComponents("MainCharacter", 0, speed, 0);
					scene->Player->transform.position.y() += speed;
				}
				else
				{
					scene->at->PlaySound(scene->LimitUp->sound.sound);
				}
				break;
			
			case 2:
				//Si el personaje tiene margen para moverse (es decir, no esta chocando con un limite) entonces se movera en esa dirección con una speed que le hemos dado antes 
				//y se guardará la posicion. Y si se esta chocando con el limite de arriba entonces saldrá un sonido que le dira al jugador que no puede seguir

				if ((scene->Player->transform.position.y() > scene->LimitDown->transform.position.y() + 8.f) || _numberList == NumberList::SEIS)
				{
					scene->tr->TranslateComponents("MainCharacter", 0, -speed, 0);
					scene->Player->transform.position.y() -= speed;
				}
				else
				{
					scene->at->PlaySound(scene->LimitDown->sound.sound);
				}
				break;

			case 3:
				//Si el personaje tiene margen para moverse (es decir, no esta chocando con un limite) entonces se movera en esa dirección con una speed que le hemos dado antes 
				//y se guardará la posicion. Y si se esta chocando con el limite de arriba entonces saldrá un sonido que le dira al jugador que no puede seguir

				if ((scene->Player->transform.position.x() < scene->LimitRight->transform.position.x() - 8.f) || _numberList == NumberList::SEIS)
				{
					scene->tr->TranslateComponents("MainCharacter", speed, 0, 0);
					scene->Player->transform.position.x() += speed;
				}
				else
				{
					scene->at->PlaySound(scene->LimitRight->sound.sound);
				}
				break;
			
			case 4:
				//Si el personaje tiene margen para moverse (es decir, no esta chocando con un limite) entonces se movera en esa dirección con una speed que le hemos dado antes 
				//y se guardará la posicion. Y si se esta chocando con el limite de arriba entonces saldrá un sonido que le dira al jugador que no puede seguir

				if ((scene->Player->transform.position.x() > scene->LimitLeft->transform.position.x() + 8.f) || _numberList == NumberList::SEIS)
				{
					scene->tr->TranslateComponents("MainCharacter", -speed, 0, 0);
					scene->Player->transform.position.x() -= speed;
				}
				else
				{
					scene->at->PlaySound(scene->LimitLeft->sound.sound);
				}
				break;

			case 5:
				//Se llamará a la funcion de resumeMusic, solo hara efecto cuando la musica este parada
				scene->at->ResumeMusic();
				break;

			case 6:
				//Bajará el valor de la variable decibelios de la tarea de Audio
				scene->at->Decibels--;
				break;
		
			case 7:
				//Subirá el valor de la variable decibelios de la tarea de Audio
				scene->at->Decibels++;
				break;
			
			case 8:
				scene->at->PauseMusic();
				break;
		}

		//controlar la distancia para las colisiones y cuales estan activas

		switch (_numberList)
		{
			case NumberList::UNO:
				//control de que cajas estan activas
				scene->tr->SetVisible("Box1", true);
				scene->tr->SetVisible("Box2", false);
				scene->tr->SetVisible("Box3", false);
				scene->tr->SetVisible("Box4", false);
				scene->tr->SetVisible("Box5", false);
				
				//Se comprueba si la posicion tanto en x como en y sean iguales, de esta manera, estaremos comprobando la distancia entre ambos y si estan colisionando
				if ((scene->Player->transform.position.x() == scene->Box1->get_position().x() - 0.5 || scene->Player->transform.position.x() == scene->Box1->get_position().x() + 0.5 || scene->Player->transform.position.x() == scene->Box1->get_position().x())
					&&
					(scene->Player->transform.position.y() == scene->Box1->get_position().y() - 0.5 || scene->Player->transform.position.x() == scene->Box1->get_position().y() + 0.5 || scene->Player->transform.position.y() == scene->Box1->get_position().y()))
				{
					//Saltará el sonido que contiene la entidad de Box1, se ocultará y se pasará a la siguiente caja
					scene->at->PlaySound(scene->Box1->sound.sound);
					scene->tr->SetVisible("Box1", false);
					_numberList = NumberList::DOS;
				}
				break;

			case NumberList::DOS:
				//control de que cajas estan activas
				scene->tr->SetVisible("Box1", false);
				scene->tr->SetVisible("Box2", true);
				scene->tr->SetVisible("Box3", false);
				scene->tr->SetVisible("Box4", false);
				scene->tr->SetVisible("Box5", false);

				//Se comprueba si la posicion tanto en x como en y sean iguales, de esta manera, estaremos comprobando la distancia entre ambos y si estan colisionando
				if ((scene->Player->transform.position.x() == scene->Box2->get_position().x() - 0.5 || scene->Player->transform.position.x() == scene->Box2->get_position().x() + 0.5 || scene->Player->transform.position.x() == scene->Box2->get_position().x())
					&&
					(scene->Player->transform.position.y() == scene->Box2->get_position().y() - 0.5 || scene->Player->transform.position.x() == scene->Box2->get_position().y() + 0.5 || scene->Player->transform.position.y() == scene->Box2->get_position().y()))
				{
					//Saltará el sonido que contiene la entidad de Box2, se ocultará y se pasará a la siguiente caja
					scene->at->PlaySound(scene->Box2->sound.sound);
					scene->tr->SetVisible("Box2", false);
					_numberList = NumberList::TRES;
				}
				break;
			
			case NumberList::TRES:
				//control de que cajas estan activas
				scene->tr->SetVisible("Box1", false);
				scene->tr->SetVisible("Box2", false);
				scene->tr->SetVisible("Box3", true);
				scene->tr->SetVisible("Box4", false);
				scene->tr->SetVisible("Box5", false);

				//Se comprueba si la posicion tanto en x como en y sean iguales, de esta manera, estaremos comprobando la distancia entre ambos y si estan colisionando
				if ((scene->Player->transform.position.x() == scene->Box3->get_position().x() - 0.5 || scene->Player->transform.position.x() == scene->Box3->get_position().x() + 0.5 || scene->Player->transform.position.x() == scene->Box3->get_position().x())
					&&
					(scene->Player->transform.position.y() == scene->Box3->get_position().y() - 0.5 || scene->Player->transform.position.x() == scene->Box3->get_position().y() + 0.5 || scene->Player->transform.position.y() == scene->Box3->get_position().y()))
				{
					//Saltará el sonido que contiene la entidad de Box3, se ocultará y se pasará a la siguiente caja
					scene->at->PlaySound(scene->Box3->sound.sound);
					scene->tr->SetVisible("Box3", false);
					_numberList = NumberList::CUATRO;
				}
				break;

			case NumberList::CUATRO:
				//control de que cajas estan activas
				scene->tr->SetVisible("Box1", false);
				scene->tr->SetVisible("Box2", false);
				scene->tr->SetVisible("Box3", false);
				scene->tr->SetVisible("Box4", true);
				scene->tr->SetVisible("Box5", false);

				//Se comprueba si la posicion tanto en x como en y sean iguales, de esta manera, estaremos comprobando la distancia entre ambos y si estan colisionando
				if ((scene->Player->transform.position.x() == scene->Box4->get_position().x() - 0.5 || scene->Player->transform.position.x() == scene->Box4->get_position().x() + 0.5 || scene->Player->transform.position.x() == scene->Box4->get_position().x())
					&&
					(scene->Player->transform.position.y() == scene->Box4->get_position().y() - 0.5 || scene->Player->transform.position.x() == scene->Box4->get_position().y() + 0.5 || scene->Player->transform.position.y() == scene->Box4->get_position().y()))
				{
					//Saltará el sonido que contiene la entidad de Box4, se ocultará y se pasará a la siguiente caja
					scene->at->PlaySound(scene->Box4->sound.sound);
					scene->tr->SetVisible("Box4", false);
					_numberList = NumberList::CINCO;
				}
				break;
			
			case NumberList::CINCO:
				//control de que cajas estan activas
				scene->tr->SetVisible("Box1", false);
				scene->tr->SetVisible("Box2", false);
				scene->tr->SetVisible("Box3", false);
				scene->tr->SetVisible("Box4", false);
				scene->tr->SetVisible("Box5", true);

				//Se comprueba si la posicion tanto en x como en y sean iguales, de esta manera, estaremos comprobando la distancia entre ambos y si estan colisionando
				if ((scene->Player->transform.position.x() == scene->Box5->get_position().x() - 0.5 || scene->Player->transform.position.x() == scene->Box5->get_position().x() + 0.5 || scene->Player->transform.position.x() == scene->Box5->get_position().x())
					&&
					(scene->Player->transform.position.y() == scene->Box5->get_position().y() - 0.5 || scene->Player->transform.position.x() == scene->Box5->get_position().y() + 0.5 || scene->Player->transform.position.y() == scene->Box5->get_position().y()))
				{
					//Saltará el sonido que contiene la entidad de Box5, se ocultará y se pasará al siguiente estado que será la victoria
					scene->tr->SetVisible("Box5", false);
					_numberList = NumberList::SEIS;
				}
				break;

			case NumberList::SEIS:
				{
					//control de que limites estan ocultos
					scene->tr->SetVisible("LimitRight", false);
					scene->tr->SetVisible("LimitLeft", false);
					scene->tr->SetVisible("LimitUp", false);
					scene->tr->SetVisible("LimitDown", false);

					//Si se dice que es victoria entonces se reproducira unicamente el sonido, una sola vez.
					if (!GameOver)
					{
						scene->at->PlaySound(scene->Player->sound.sound);
						GameOver = true;
					}

					break;
				}
		}
	}

	void Player_Controller::Update(float time)
	{

	}
}
