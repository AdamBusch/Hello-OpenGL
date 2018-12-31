#include <iostream>
#include <GL/glew.h>

#include "display.h"
#include "mesh.h"
#include "shader.h"

int main(int argc, char **args)
{
    Display display(500, 500, "Hello OpenGL!");

    Shader shader("./shaders/basicShader");

    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5, -0.5, 0)),
        Vertex(glm::vec3(0, 0.5, 0)),
        Vertex(glm::vec3(0.5, -0.5, 0))};

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    while (!display.isClosed())
    {
        display.Clear(0.2f, 0.15f, 0.5f, 1.0f);

        shader.Bind();
        mesh.Draw();

        display.Update();
    }
}
