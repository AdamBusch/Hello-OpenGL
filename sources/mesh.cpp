#include "mesh.h"

Mesh::Mesh(Vertex *verticies, unsigned int numVerticies)
{
    m_drawCount = numVerticies;

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER,
                 numVerticies * sizeof(verticies[0]),
                 verticies, GL_STATIC_DRAW);

    // Each vertex has one attrib: Position
    glEnableVertexAttribArray(0);
    // Position has (3) (GL_floats), or 1 vertex.
    // Starts at position 0.
    // This tells OpenGL how to access this array buffer
    // from GPU memory.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw()
{
    glBindVertexArray(m_vertexArrayObject);

    // Draw all of the data in the buffer.
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

    glBindVertexArray(0);
}