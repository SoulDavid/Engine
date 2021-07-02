/**
* @file Scene.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 1 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script donde se crean todas las entidades y se crean sus componentes 8Debería de ir en el main pero por falta de tiempo lo puse en este script.
**/

#include "SDL.h"
#include "Scene.hpp"
#include "Kernel.hpp"
#include "Entity.hpp"
#include "Input_Task.hpp"
#include "TaskRenderer.hpp"
#include "Message_Observer.hpp"
#include "Vector3.hpp"
#include "Component.hpp"
#include "Audio.hpp"

namespace Engine
{
	Scene::Scene(const char* title, Window& w)
	{
		//Inicializamos todas las tareas, 
		scene = this;
		tr = new TaskRenderer(w);
		it = new Input_Task(scene);
		at = new Audio(w);
		kernel = new Kernel(w);
		AddLightAndCamera();
		AddPlayer();
		AddSpheres();
		AddLimits();

		Player_Controller* player_controller = new Player_Controller(scene);

		#pragma region Añadir Observadores
		add_observer("MoveForward", player_controller);
		add_observer("MoveLeft", player_controller);
		add_observer("MoveRight", player_controller);
		add_observer("MoveDown", player_controller);
		add_observer("SoundMusic", player_controller);
		add_observer("LowMusic", player_controller);
		add_observer("HighMusic", player_controller);
		add_observer("PauseMusic", player_controller);
		#pragma endregion

		//Añadir tareas al kernel para hacer su update
		kernel->Add_Task(it);
		kernel->Add_Task(tr);
		kernel->Add_Task(at);
	}

	void Scene::add_observer(const std::string& id, Message_Observer* o)
	{
		message_dispatcher.add_observer(id, o);
	}

	void Scene::AddLightAndCamera()
	{
		#pragma region Camera
		//Creamos la entidad de camera
		Camera = new Entity(scene);
		//La incluimos en el mapa de entidades
		entities.insert({ "Camera", (std::shared_ptr<Entity>) Camera });
		//Le añadimos el componente de render component llamando a la funcion de create
		Camera->add_Component("CameraModel", tr->create_camera_component("MainCamera", 20.f, 1.f, 50.f, 1.f));
		//Se traslada y se  guarda la posicion
		tr->TranslateComponents("MainCamera", 0.f, 0.f, 5.f);
		Camera->transform.position.x() = 0.f;
		Camera->transform.position.y() = 0.f;
		Camera->transform.position.z() = 5.f;
		#pragma endregion

		#pragma region Light
		//Creamos la entidad de la iluminación
		Light = new Entity(scene);
		//La incluimos en el mapa de entidades
		entities.insert({ "Light", (std::shared_ptr<Entity>) Light });
		//Le añadimos el componente de render component llamando a la función de create
		Light->add_Component("LightModel", tr->create_light_component("MainLight"));
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("MainLight", 10.f, 10.f, 10.f);
		Light->transform.position.x() = 10.f;
		Light->transform.position.y() = 10.f;
		Light->transform.position.z() = 10.f;
		#pragma endregion
	}

	void Scene::AddPlayer()
	{
		//Se crea la entidad
		Player = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "Player", (std::shared_ptr <Entity>) Player });
		//Se le crea el render_component y se pinta en la escena
		Player->add_Component("ModelPlayer", tr->create_render_component("MainCharacter", "../../assets/Modelos/Cube/Cube.obj"));
		//Se le crea un music_component y se guarda en la variable music
		Player->music = at->create_audio_music("../../assets/Music/MainMusica.ogg");
		//Se le crea un sound_component y se guarda en la variable sound
		Player->sound = at->create_audio_sound("../../assets/Sounds/GG.mp3");
		//Se toca la musica
		at->PlayMusic(Player->music.music);
		//Se escala el personaje
		tr->ScaleComponents("MainCharacter", 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("MainCharacter", 0, 0, 0);
		Player->transform.position.x() = 0.f;
		Player->transform.position.y() = 0.f;
		Player->transform.position.z() = 0.f;
	}

	void Scene::AddSpheres()
	{
		#pragma region Entity - Caja Numero 1
		//Se crea la entidad
		Box1 = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "Box1", (std::shared_ptr <Entity>) Box1 });
		//Se añade el render_component
		Box1->add_Component("ModelBox1", tr->create_render_component("Box1", "../../assets/Modelos/Sphere/Sphere.obj"));
		//Se añade el sound_component y se guarda en la variable sound
		Box1->sound = at->create_audio_sound("../../assets/Sounds/SuccessSound.ogg");
		//Se escala el component
		tr->ScaleComponents("Box1", 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("Box1", 30, 0, 0);
		Box1->transform.position.x() = 30;
		Box1->transform.position.y() = 0.f;
		Box1->transform.position.z() = 0.f;
		#pragma endregion

		#pragma region Entity - Caja Numero 2
		//Se crea la entidad
		Box2 = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "Box2", (std::shared_ptr<Entity>) Box2 });
		//Se añade el render_component
		Box2->add_Component("ModelBox2", tr->create_render_component("Box2", "../../assets/Modelos/Sphere/Sphere.obj"));
		//Se añade el sound_component y se guarda en la variable sound
		Box2->sound = at->create_audio_sound("../../assets/Sounds/Success2.mp3");
		//Se escala el component
		tr->ScaleComponents("Box2", 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("Box2", -40, -5, 0);
		Box2->transform.position.x() = -40.f;
		Box2->transform.position.y() = -5.f;
		Box2->transform.position.z() = 0.f;
		#pragma endregion

		#pragma region Entity - Caja Numero 3
		//Se crea la entidad
		Box3 = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "Box3", (std::shared_ptr<Entity>) Box3 });
		//Se añade el render_component
		Box3->add_Component("ModelBox3", tr->create_render_component("Box3", "../../assets/Modelos/Sphere/Sphere.obj"));
		//Se añade el sound_component y se guarda en la variable sound
		Box3->sound = at->create_audio_sound("../../assets/Sounds/Success3.mp3");
		//Se escala el component
		tr->ScaleComponents("Box3", 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("Box3", -10, 20, 0);
		Box3->transform.position.x() = -10.f;
		Box3->transform.position.y() = 20.f;
		Box3->transform.position.z() = 0.f;
		#pragma endregion

		#pragma region Entity - Caja Numero 4
		//Se crea la entidad
		Box4 = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "Box4", (std::shared_ptr<Entity>) Box4 });
		//Se añade el render_component
		Box4->add_Component("ModelBox4", tr->create_render_component("Box4", "../../assets/Modelos/Sphere/Sphere.obj")); 
		//Se añade el sound_component y se guarda en la variable sound
		Box4->sound = at->create_audio_sound("../../assets/Sounds/Success4.mp3");
		//Se escala el component
		tr->ScaleComponents("Box4", 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("Box4", 10, -25, 0);
		Box4->transform.position.x() = 10.f;
		Box4->transform.position.y() = -25.f;
		Box4->transform.position.z() = 0.f;
		#pragma endregion

		#pragma region Entity - Caja Numero 5
		//Se crea la entidad
		Box5 = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "Box5", (std::shared_ptr<Entity>) Box5 });
		//Se añade el render_component
		Box5->add_Component("ModelBox5", tr->create_render_component("Box5", "../../assets/Modelos/Sphere/Sphere.obj"));
		//Se añade el sound_component y se guarda en la variable sound
		Box5->sound = at->create_audio_sound("../../assets/Sounds/SuccessSound.ogg");
		//Se escala el component
		tr->ScaleComponents("Box5", 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("Box5", 0, -20, 0);
		Box5->transform.position.x() = 0.f;
		Box5->transform.position.y() = -20.f;
		Box5->transform.position.z() = 0.f;
		#pragma endregion
	}

	void Scene::AddLimits()
	{
		#pragma region Entidad - Limite Derecho
		//Se crea la entidad
		LimitRight = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "LimitRight", (std::shared_ptr <Entity>) LimitRight });
		//Se añade el render_component
		LimitRight->add_Component("ModelLimitRight", tr->create_render_component("LimitRight", "../../assets/Modelos/Limit/Limit.obj"));
		//Se añade el sound_component y se guarda en la variable sound
		LimitRight->sound = at->create_audio_sound("../../assets/Sounds/Limit_Sound.wav");
		//Se escala el component
		tr->ScaleComponentsDetail("LimitRight", 0.1, 3, 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("LimitRight", 50, 0, 0);
		LimitRight->transform.position.x() = 50.f;
		LimitRight->transform.position.y() = 0.f;
		LimitRight->transform.position.z() = 0.f;
		#pragma endregion

		#pragma region Entidad - Limite Izquierdo
		//Se crea la entidad
		LimitLeft = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "LimitLeft", (std::shared_ptr <Entity>) LimitLeft });
		//Se añade el render_component
		LimitLeft->add_Component("ModelLimitLeft", tr->create_render_component("LimitLeft", "../../assets/Modelos/Limit/Limit.obj"));
		//Se añade el sound_component y se guarda en la variable sound
		LimitLeft->sound = at->create_audio_sound("../../assets/Sounds/Limit_Sound.wav");
		//Se escala el component
		tr->ScaleComponentsDetail("LimitLeft", 0.1, 3, 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("LimitLeft", -50, 0, 0);
		LimitLeft->transform.position.x() = -50.f;
		LimitLeft->transform.position.y() = 0.f;
		LimitLeft->transform.position.z() = 0.f;
		#pragma endregion

		#pragma region Entidad - Limite Arriba
		//Se crea la entidad
		LimitUp = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "LimitUp", (std::shared_ptr <Entity>) LimitUp });
		//Se añade el render_component
		LimitUp->add_Component("ModelLimitUp", tr->create_render_component("LimitUp", "../../assets/Modelos/Limit/Limit.obj"));
		//Se añade el sound_component y se guarda en la variable sound
		LimitUp->sound = at->create_audio_sound("../../assets/Sounds/Limit_Sound.wav");
		//Se escala el component
		tr->ScaleComponentsDetail("LimitUp", 3, 0.1, 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("LimitUp", 0, 35, 0);
		LimitUp->transform.position.x() = 0.f;
		LimitUp->transform.position.y() = 35.f;
		LimitUp->transform.position.z() = 0.f;
		#pragma endregion

		#pragma region Entidad - Limite Abajo
		//Se crea la entidad
		LimitDown = new Entity(scene);
		//Se añade al mapa de entidades
		entities.insert({ "LimitDown", (std::shared_ptr <Entity>) LimitDown });
		//Se añade el render_component
		LimitDown->add_Component("LimitDown", tr->create_render_component("LimitDown", "../../assets/Modelos/Limit/Limit.obj"));
		//Se añade el sound_component y se guarda en la variable sound
		LimitDown->sound = at->create_audio_sound("../../assets/Sounds/Limit_Sound.wav");
		//Se escala el component
		tr->ScaleComponentsDetail("LimitDown", 3, 0.1, 0.1);
		//Se traslada y se guarda la posicion
		tr->TranslateComponents("LimitDown", 0, -35, 0);
		LimitDown->transform.position.x() = 0.f;
		LimitDown->transform.position.y() = -35.f;
		LimitDown->transform.position.z() = 0.f;
		#pragma endregion
	}

	Message_Dispatcher& Scene::get_message_dispatcher()
	{
		return message_dispatcher;
	}

	void Scene::Update(Window& w)
	{
		//llama al update del kernel
		kernel->Update(w);
	}	

	Scene::~Scene()
	{

	}
}
