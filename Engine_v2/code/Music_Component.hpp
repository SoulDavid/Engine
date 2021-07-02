/**
* @file Music_Component.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 6 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena el objeto de musica del componente
**/

#pragma once
#include <memory>
#include "Audio_Component.hpp"

///Declaracion adelantada para usar Mix_Music
typedef struct _Mix_Music Mix_Music;

namespace Engine
{
	//Al ser un Audio_Componente, este hereda de la clase Audio_Component, que a su vez esta, hereda de Component
	class Music_Component : public Audio_Component
	{
	public:
		//Varaible que guarda el componente Musica
		Mix_Music* music;

	public:
		Music_Component();
		//Funcion que recoge un puntero a Mix_Music y que se guardará en la variable en el compoennte musica creado antes
		Music_Component(Mix_Music*);
	};
}

