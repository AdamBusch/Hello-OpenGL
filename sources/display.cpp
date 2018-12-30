#include "display.h"
#include <GL/glew.h>
#include <iostream>

// Basic display class which initalizes SDL for window purposes
Display::Display(int width, int height, const std::string &title)
{
    // Initalize SDL for window purposes
    SDL_Init(SDL_INIT_EVERYTHING);

    // Set GL flags for buffer size so OpenGL knows how much
    // data we are going to load to it for each vertex.
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Create SDL window
    m_window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL);

    // Gather OpenGL context from SDL
    m_glContext = SDL_GL_CreateContext(m_window);

    GLenum status = glewInit();

    if (status != GLEW_OK)
    {
        std::cout << "GLEW failed to initalize!" << std::endl;
    }
}

Display::~Display()
{
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Display::isClosed()
{
    return m_isClosed;
}

void Display::Clear(float red, float green, float blue, float alpha)
{
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Display::Update()
{
    SDL_GL_SwapWindow(m_window);

    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            m_isClosed = true;
        }
    }
}
