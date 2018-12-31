#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
  public:
    Vertex(const glm::vec3 &pos)
    {
        this->pos = pos;
    }

  protected:
  private:
    glm::vec3 pos;
};

class Mesh
{
  public:
    Mesh(Vertex *verticies, unsigned int numVerticies);
    virtual ~Mesh();

    void Draw();

  protected:
  private:
    Mesh(const Mesh &other){};
    Mesh &operator=(const Mesh &other){};

    enum
    {
        POSITION_VB,

        NUM_BUFFERS
    };

    // Mesh data
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};
#endif