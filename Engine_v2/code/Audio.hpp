/**
* @file Audio.hpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
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

//Declaraci�n adelantada
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

		///Funci�n que crea un sonido (Mix_Chunk*) a trav�s del path que le damos y  
		///lo que hace es retornar un Sound_Component que guarda la direcci�n de un componente de sonido nuevo.
		Sound_Component create_audio_sound(const char*);

		///Funci�n que crea un sonido (Mix_Music*) a trav�s del path que le damos y  
		///lo que hace es retornar un Music_Component que guarda la direcci�n de un componente de musica nuevo.
		Music_Component create_audio_music(const char*);

		///Funci�n que sirve para reproducir el archivo de sonido que le pase
		void PlaySound(Mix_Chunk*);

		///Funci�n que sirve para reproducir el archivo de m�sica que le pase
		void PlayMusic(Mix_Music*);

		//Funci�n para pausar el sonido
		void PauseSound(int);

		//Funci�n para reanudar el sonido
		void ResumeSound(int);

		//Funci�n para pausar la musica
		void PauseMusic();

		//Funci�n para reanudar la m�sica
		void ResumeMusic();

		//Update, funcion que estar� llamandose desde el kernel, y controla el volumen
		void Update(float, Window &) override;

		//Destructor 
		~Audio();
	};
}


