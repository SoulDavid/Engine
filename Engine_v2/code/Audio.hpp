/**
* @file Audio.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que guarda el comportamiento del audio, guardar el componente de sonido/musica, que se reproduzcan, se paren o reanudar la musica/sonido.
* Archivo que me ha ayudado mucho con el Audio: https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer.pdf#page=69&zoom=100,120,96
**/


#pragma once

#include "Window.hpp"
#include "Task.hpp"
#include "Sound_Component.hpp"
#include "Music_Component.hpp"
#include <memory>

//Declaración adelantada
typedef struct _Mix_Music Mix_Music;
typedef struct Mix_Chunk;

namespace Engine
{
	//Al ser una tarea, hereda las propiedades de Task
	class Audio : public Task
	{
	public:
		//El volumen de la musica
		int Decibels = 64;
	public: 
		//Constructor que coge referencia de la ventana, e inicia el sistema de audio de SDL
		Audio(Window &);

		///Función que crea un sonido (Mix_Chunk*) a través del path que le damos y  
		///lo que hace es retornar un Sound_Component que guarda la dirección de un componente de sonido nuevo.
		Sound_Component create_audio_sound(const char*);

		///Función que crea un sonido (Mix_Music*) a través del path que le damos y  
		///lo que hace es retornar un Music_Component que guarda la dirección de un componente de musica nuevo.
		Music_Component create_audio_music(const char*);

		///Función que sirve para reproducir el archivo de sonido que le pase
		void PlaySound(Mix_Chunk*);

		///Función que sirve para reproducir el archivo de música que le pase
		void PlayMusic(Mix_Music*);

		//Función para pausar el sonido
		void PauseSound(int);

		//Función para reanudar el sonido
		void ResumeSound(int);

		//Función para pausar la musica
		void PauseMusic();

		//Función para reanudar la música
		void ResumeMusic();

		//Update, funcion que estará llamandose desde el kernel, y controla el volumen
		void Update(float, Window &) override;

		//Destructor 
		~Audio();
	};
}


