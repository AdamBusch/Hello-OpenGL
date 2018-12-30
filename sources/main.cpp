#include <iostream>
#include "display.h"
#include <GL/glew.h>

int main(int argc, char **args)
{
    Display display(500, 500, "Hello OpenGL!");

    while (!display.isClosed())
    {
        display.Clear(0.2f, 0.15f, 0.5f, 1.0f);
        display.Update();
    }
}
