/**
* @file Task_Renderer.hpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 19 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que pinta por pantalla todos los componentes de la escena
**/

#pragma once
#include "Task.hpp"
#include <string>
#include <memory>
#include <vector>
#include "Render_Component.hpp"
#include "Light_Component.hpp"
#include "Camera_Component.hpp"

//Declaracion adelantada de Render_Node
namespace glt
{
	class Render_Node;
}

namespace Engine
{
	///Declaraciones adelantadas de Window y Render_Component
	class Render_Component;
	class Light_Component;
	class Camera_Component;
	class Window;

	//A traves de la libreria openGL
	class TaskRenderer : public Task
	{
	public:
		//Puntero de render Node, se encarga de por as� decirlo, el lienzo de la escena, donde se a�adiran los objetos para pintarse
		std::unique_ptr<glt::Render_Node> renderer;
	public:
		//Constructor para inicializar el TaskRenderer
		TaskRenderer(Window&);

		//Funci�n que recibe el id, y un n�mero para escalar ese objeto. Se escala en x, y y z con el esa misma escala que le pasamos
		void ScaleComponents(const std::string&, const float);

		//Funci�n que recibe el id y tres medidas para escalar el objeto. Diferencia con la otra funci�n, esta es m�s detallada
		void ScaleComponentsDetail(const std::string&, const float, const float, const float);

		//Funci�n que recoge el id y tres medidas para trasladar ese componente 
		void TranslateComponents(const std::string&, const float, const float, const float);

		//Funci�n que recoge el id y tres medidas para rotar ese componente.
		void RotateComponent(const std::string&, const float, const float, const float);

		//Funci�n que recoge el id y el bool para hacer un item visible o no visible
		void SetVisible(const std::string&, bool);

		///Funci�n que crea un model y lo a�ade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la direcci�n de un componente de render nuevo.
		std::shared_ptr <Render_Component> create_render_component(const std::string&, const std::string&);

		///Funci�n que crea una luz y lo a�ade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la direcci�n de un componente de luz nuevo.
		std::shared_ptr<Light_Component> create_light_component(const std::string&);

		///Funci�n que crea una camera y lo a�ade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la direcci�n de un componente de camera nuevo.
		std::shared_ptr<Camera_Component> create_camera_component(const std::string&, const float, const float, const float, const float);

		///Funci�n que se llama desde el kernel
		virtual void Update(float, Window&) override;

		//Destructor del constructor.
		~TaskRenderer();
	};
}


