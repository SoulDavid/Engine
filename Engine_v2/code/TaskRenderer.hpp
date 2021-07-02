/**
* @file Task_Renderer.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
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
		//Puntero de render Node, se encarga de por así decirlo, el lienzo de la escena, donde se añadiran los objetos para pintarse
		std::unique_ptr<glt::Render_Node> renderer;
	public:
		//Constructor para inicializar el TaskRenderer
		TaskRenderer(Window&);

		//Función que recibe el id, y un número para escalar ese objeto. Se escala en x, y y z con el esa misma escala que le pasamos
		void ScaleComponents(const std::string&, const float);

		//Función que recibe el id y tres medidas para escalar el objeto. Diferencia con la otra función, esta es más detallada
		void ScaleComponentsDetail(const std::string&, const float, const float, const float);

		//Función que recoge el id y tres medidas para trasladar ese componente 
		void TranslateComponents(const std::string&, const float, const float, const float);

		//Función que recoge el id y tres medidas para rotar ese componente.
		void RotateComponent(const std::string&, const float, const float, const float);

		//Función que recoge el id y el bool para hacer un item visible o no visible
		void SetVisible(const std::string&, bool);

		///Función que crea un model y lo añade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de render nuevo.
		std::shared_ptr <Render_Component> create_render_component(const std::string&, const std::string&);

		///Función que crea una luz y lo añade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de luz nuevo.
		std::shared_ptr<Light_Component> create_light_component(const std::string&);

		///Función que crea una camera y lo añade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de camera nuevo.
		std::shared_ptr<Camera_Component> create_camera_component(const std::string&, const float, const float, const float, const float);

		///Función que se llama desde el kernel
		virtual void Update(float, Window&) override;

		//Destructor del constructor.
		~TaskRenderer();
	};
}


