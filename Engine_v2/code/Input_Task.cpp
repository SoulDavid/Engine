/**
* @file Input_Task.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 19 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que guarda el comportamiento cuando se pulsa una tecla.
**/

#include "Input_Task.hpp"
#include "Keyboard.hpp"
#include "Window.hpp"
#include <SDL.h>
#include <iostream>
#include "TaskRenderer.hpp"
#include "Player_Controller.hpp"
#include "Audio.hpp"
#include "Message.hpp"
#include "Scene.hpp"

namespace Engine
{
	//Constructor para guardar una referencia a la escena
	Input_Task::Input_Task(Scene * given_scene) 
	{
		scene = given_scene;
	}

	//Funcion que se llama desde el kernel
	void Input_Task::Update(float t, Window & window)
	{
		//Referencia a los eventos creados en la ventana
		Window::Event event;

		//Se llama al poll event, para ver si se ha registrado una tecla pulsada, soltada o no se ha pulsado nada
		while (window.poll(event))
		{
			switch (event.type)
			{
				case Window::Event::KEY_PRESSED:
				{
					///Si el key_code de la tecla es la que le decimos, mandara un determinado mensaje y se lo pasara a la funcion handle del observador
					if (event.data.keyboard.key_code == Keyboard::KEY_W || event.data.keyboard.key_code == Keyboard::KEY_UPARROW)
					{
						Message m{		"MoveForward"	};
						scene->get_message_dispatcher().send(m);
	
					}
					else if (event.data.keyboard.key_code == Keyboard::KEY_A || event.data.keyboard.key_code == Keyboard::KEY_LEFTARROW)
					{
						Message m{		"MoveLeft"		};
						scene->get_message_dispatcher().send(m);
					}
					else if (event.data.keyboard.key_code == Keyboard::KEY_D || event.data.keyboard.key_code == Keyboard::KEY_RIGHTARROW )
					{
						Message m{		"MoveRight" };
						scene->get_message_dispatcher().send(m);
					}
					else if (event.data.keyboard.key_code == Keyboard::KEY_S || event.data.keyboard.key_code == Keyboard::KEY_DOWNARROW)
					{
						Message m{		"MoveDown"		};
						scene->get_message_dispatcher().send(m);
					}
					else if (event.data.keyboard.key_code == Keyboard::KEY_Z)
					{
						Message m{		"SoundMusic"	};
						scene->get_message_dispatcher().send(m);
					}
					else if (event.data.keyboard.key_code == Keyboard::KEY_X)
					{
						Message m{		"LowMusic"		};
						scene->get_message_dispatcher().send(m);
					}
					else if (event.data.keyboard.key_code == Keyboard::KEY_C)
					{
						Message m{		"HighMusic"		};
						scene->get_message_dispatcher().send(m);
					}
					else if (event.data.keyboard.key_code == Keyboard::KEY_V)
					{
						Message m{		"PauseMusic"	};
						scene->get_message_dispatcher().send(m);
					}

					break;
				}
				case Window::Event::KEY_RELEASED:
				{
					break;
				}
				//Si se pulsa la X
				case Window::Event::CLOSE:
				{
					//Se llama al kernel para que deje de hacer el update, y se cierre la aplicacion del motor.
					scene->kernel->exit = true;
				}
			}
		}
	}

	//Destructor del Input_Task
	Input_Task::~Input_Task()
	{

	}
}