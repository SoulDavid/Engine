/**
* @file Message.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que guarda el id del mensaje
**/

#pragma once
#include <string>

namespace Engine
{
	class Message
	{
	public:
		//Se guarda el id del mensaje que luego se pasara a los observadores y dependiendo del contenido de este, hara una cosa u otra
		std::string id;
	};
}

