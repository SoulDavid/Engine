/**
* @file Sound_Component.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 6 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena el objeto de sonido del componente
**/

#pragma once
#include <memory>
#include "Audio_Component.hpp"

///Declaracion adelantada para usar Mix_Chunk relativo a los sonidos. 
typedef struct Mix_Chunk;

namespace Engine
{
	//Al ser un Audio_Componente, este hereda de la clase Audio_Component, que a su vez esta, hereda de Component
	class Sound_Component : public Audio_Component
	{
	public:
		//Varaible que guarda el componente Sonido
		Mix_Chunk* sound;

	public:
		Sound_Component();
		//Funcion que recoge un puntero a Mix_Chunk y que se guardará en la variable en el componente de sonido creado antes
		Sound_Component(Mix_Chunk*);
	};
}


