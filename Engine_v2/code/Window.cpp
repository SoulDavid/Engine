/**
* @file Window.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 2 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que contiene todo el funcionamiento de la ventana, así como de las funciones creadas en su hpp.
**/

#include "Window.hpp"
#include <SDL.h>
#include "Keyboard.hpp"
#include <OpenGL.hpp>


namespace Engine {

	/// <summary>
	/// Constructor por defecto de la ventana
	/// </summary>
	/// <param name="title"></param>
	/// <param name="window_width"></param>
	/// <param name="window_height"></param>
	Window::Window(const char* title, int window_width, int window_height)
	{
        window = nullptr;
        gl_context = nullptr;

        //Función para establecer un atributo de ventana OpenGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2); (SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

        ///Constructor => Parámetros que pilla CreateWindow (titulo, posición de la x de la pantalla, posición de la Y de la pantalla, ancho, largo, y flags ("https://wiki.libsdl.org/SDL_GetWindowFlags")
        window = SDL_CreateWindow (title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

        //Si no se ha creado la ventana, pondrá ese mensaje por consola
        if (not window)
        {
            SDL_Log("No se ha podido crear una ventana");
        }
        //Si se ha creado
        else
        {
            //Tomamos el buffer de la ventana para dibujar en el
            gl_context = SDL_GL_CreateContext(window);
            //Se inicializa las extensiones de OpenGL
            ///Importante para introducir modelos 3D. 
            glt::initialize_opengl_extensions();

            closeWindow = false;
		}
	}

    /// <summary>
    /// Funcion que recoge un evento e indica y cambai parametro segun lo que se haya pulsado
    /// </summary>
    /// <param name="event"></param>
    /// <returns></returns>
    bool Window::poll(Event& event)
    {
        //El evento es inicialmente desconocido, para que no detecte por duplicado las pulsaciones de la tecla. 
        event.type = Event::UNKNOWN;

        //Si hay una ventana creada
        if (window)
        {
            //Se crea un evento
            SDL_Event sdl_event;

            ///Función utilizada para sondear los eventos actualmente pendientes
            ///https://wiki.libsdl.org/SDL_PollEvent
            if (SDL_PollEvent(&sdl_event) > 0)
            {
                //Dependiendo del evento
                switch (sdl_event.type)
                {
                    //Si se ha pulsado la X para salir, entonces se cambiará el tipo a CLOSE
                    case SDL_QUIT:
                        closeWindow = true;
                        SDL_Log("Cerrando_Programa");
                        event.type = Event::CLOSE;
                        break;

                    //Si se detecta que una tecla ha sido presionada, se cambia el tipo a KEY_PRESSED y se recoge a través del script
                    //Keyboard la tecla que ha sido pulsada y se guarda. 
                    case SDL_KEYDOWN:
                        event.type = Event::KEY_PRESSED;
                        event.data.keyboard.key_code = Keyboard::translate_sdl_key_code(sdl_event.key.keysym.sym);
                        break;

                    //Si se detecta que una tecla ha sido soltada se cambia el tipo a KEY_RELEASED y se recoge a través del script
                    //Keyboard la tecla que ha sido pulsada y se guarda. 
                    case SDL_KEYUP:
                        event.type = Event::KEY_RELEASED;
                        event.data.keyboard.key_code = Keyboard::translate_sdl_key_code(sdl_event.key.keysym.sym);
                        break;
                }    

                //Devuelve true, si ha ocurrido alguno de estos sucesos 
                return true;
            }
        }
        //Si no devolvera false, como si no hubiera pasado nada
        return false;
    }

    /// <summary>
    /// Función que devuelve el ancho de la ventana
    /// </summary>
    /// <returns></returns>
    unsigned Window::get_width() const {
        //Si se quiere recoge el width, entonces el puntero a esta debe retornar 0
        int width = 0;
        int height;

        if (window)
        {
            ///Recoge el size de la ventana
            //https://wiki.libsdl.org/SDL_GetWindowSize
            SDL_GetWindowSize(window, &width, &height);
        }

        //Devuelve el valor de width
        return unsigned(width);
    }

    /// <summary>
    /// Función que devuelve el largo de la ventana
    /// </summary>
    /// <returns></returns>
    unsigned Window::get_height() const {
        //Si se quiere recoge el height, entonces el puntero a esta debe retornar 0
        int width;
        int height = 0;

        if (window)
        {
            ///Recoge el size de la ventana
            //https://wiki.libsdl.org/SDL_GetWindowSize
            SDL_GetWindowSize(window, &width, &height);
        }

        //Devuelve el valor de height
        return unsigned(height);
    }

    /// <summary>
    /// Función para limpiar la ventana
    /// </summary>
    void Window::clear() const
    {
        //Si hay un contexto de OpenGL lo limpia
        if (gl_context)
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    /// <summary>
    /// Cambia nuestro buffer para mostrar el contenido actual del buffer en la pantalla
    /// </summary>
    void Window::swap_buffer() const
    {
        //Si hay contexto de OpenGL, la actualiza
        if (gl_context)
            SDL_GL_SwapWindow(window);
    }

	/// <summary>
	/// Destrcutor de ventana
	/// </summary>
	Window::~Window()
	{
        //Si hay contexto OpenGL lo destruye
        //https://wiki.libsdl.org/SDL_GL_DeleteContext
        if (gl_context)
            SDL_GL_DeleteContext(gl_context);

        //Si hay ventana creada, la destruye
        //https://wiki.libsdl.org/SDL_DestroyWindow
		if (window)
			SDL_DestroyWindow(window);
	}
}