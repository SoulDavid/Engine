/**
* @file Window.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 2 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena las variables y propiedades que tiene la ventana del Motor. Así como su constructor por defecto, los tipos de eventos y su medida. 
**/

//Si no lo coge, crea una clase window_exercise para no repetir codigo máquina
#ifndef Window_exercise
#define Window_exercise

#include <string>

//Declaración adelantada : existe en algun lugar una estructura llamada SDL window, SDL_GLContext (OpenGL) y SDL_Event
struct SDL_Window;
typedef void* SDL_GLContext;
typedef union SDL_Event;


namespace Engine {
	class Window
	{

	private:
		//Puntero a ventana, para guardar la referencia
		SDL_Window * window;

		//Guarda el contexto de OpenGL
		SDL_GLContext gl_context;

	public:

		bool closeWindow;

		//Struct que lleva las propiedades del evento
		struct Event
		{
			/// Enumeracion que describe el estado del input: si una tecla ha sido pulsada, soltada, cuando se cierra y cuando no se ha pulsado una tecla.
			enum Type
			{
				UNKNOWN,
				CLOSE,
				KEY_PRESSED,
				KEY_RELEASED
			}
			type;

			/// Recoge el valor de la tecla pulsada, o si usamos el raton o pantalla tactil, tambien deberiamos de incluirlas dentro de este union
			union Data
			{
				struct { int key_code; } keyboard;

				struct 
				{ 
					float x, y; 
					int buttons;
				}
				mouse;
			}
			data;
		};

	public:
		/// <summary>
		/// Constructor por defecto
		/// </summary>
		/// <param name="title"></param>
		/// <param name="window_width"></param>
		/// <param name="window_height"></param>
		Window(const char* title, int window_width, int window_height);

		/// <summary>
		/// Función que recoge el evento y cambia el estado del input
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool poll(Event& event);

		/// <summary>
		/// Función que devuelve el ancho de la ventana
		/// </summary>
		/// <returns></returns>
		unsigned get_width() const;

		/// <summary>
		/// Función que devuelve el largo de la ventana
		/// </summary>
		/// <returns></returns>
		unsigned get_height() const;

		/// <summary>
		/// Función para limpiar la ventana
		/// </summary>
		void clear() const;

		/// <summary>
		/// Cambia nuestro buffer para mostrar el contenido actual del buffer en la pantalla
		/// </summary>
		void swap_buffer() const;

		/// <summary>
		/// Destructor de la ventana
		/// </summary>
		~Window();
	};
}

#endif
