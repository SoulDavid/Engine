/**
* @file Audio.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que guarda el comportamiento del audio, guardar el componente de sonido/musica, que se reproduzcan, se paren o reanudar la musica/sonido.
* Archivo que me ha ayudado mucho con el Audio: https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer.pdf#page=69&zoom=100,120,96
**/


#include "Audio.hpp"
#include <SDL.h>
#include <SDL_mixer.h>
#include "Window.hpp"
#include "Keyboard.hpp"
#include "Sound_Component.hpp"
#include "Music_Component.hpp"

namespace Engine
{
	//Constructor que coge referencia de la ventana, e inicia el sistema de audio de SDL
	Audio::Audio(Window & window)
	{
		///https://wiki.libsdl.org/SDL_Init
		if (SDL_Init (SDL_INIT_AUDIO) < 0)
		{
			SDL_Log("No se ha podido inicializar SDL2.");
		}
		else
		{
			///https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_11.html
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
			{
				SDL_Log("No se ha podido iniciar el subsistema de audio");
			}
		}
	}

	///Función que crea un sonido (Mix_Chunk*) a través del path que le damos y  
	///lo que hace es retornar un Sound_Component que guarda la dirección de un componente de sonido nuevo.
	Sound_Component Audio::create_audio_sound(const char* path)
	{
		Mix_Chunk* sound;

		//Carga del sonido que le pasamos
		///https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_19.html
		sound = Mix_LoadWAV(path);

		return Sound_Component{ sound };
	}

	///Función que crea un sonido (Mix_Music*) a través del path que le damos y  
	///lo que hace es retornar un Music_Component que guarda la dirección de un componente de musica nuevo.
	Music_Component Audio::create_audio_music(const char* path)
	{
		Mix_Music* music;

		//Carga de la música que le pasamos
		///https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_55.html
		music = Mix_LoadMUS(path);

		return Music_Component{ music };
	}

	///Función que sirve para reproducir el archivo de sonido que le pase
	void Audio::PlaySound(Mix_Chunk* sound)
	{
		///https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_28.html
		//Valor de -1, si se quiere reproducir todo el rato, pero podría ser un valor que se pase por funcion, por eso es 0, para que solo se reproduzca una vez
		//y si el canal es -1, coge el primero libre
		Mix_PlayChannel(-1, sound, 0);
	}

	///Función que sirve para reproducir el archivo de música que le pase
	void Audio::PlayMusic(Mix_Music* music)
	{
		///https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_58.html
		//-1 si se quiere reproucir infinitamente y 0 solo una vez. 4000 son los ms que tarda el efecto de fade in en completarse
		Mix_FadeInMusic(music, -1, 4000);
	}

	//Función para reanudar el sonido
	void Audio::ResumeSound(int canal)
	{
		Mix_Resume(canal);
	}

	//Función para pausar el sonido
	void Audio::PauseSound(int canal)
	{
		Mix_Pause(canal);
	}

	//Función para pausar la musica
	void Audio::PauseMusic()
	{
		Mix_PauseMusic();
	}

	//Función para reanudar la música
	void Audio::ResumeMusic()
	{
		Mix_ResumeMusic();
	}

	///Update, funcion que estará llamandose desde el kernel, y controla el volumen
	void Audio::Update(float t, Window & window)
	{
		//Hay un limite con los decibelios, y es que la musica va desde los 0 hasta los 128, por eso hay que hacer estos limites
		if (Decibels < 0)
			Decibels = 0;
		else if (Decibels > 128)
			Decibels = 128;

		//https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_61.html
		Mix_VolumeMusic(Decibels);
	}

	//Destructor 
	Audio::~Audio()
	{
		Mix_CloseAudio();
	}

}