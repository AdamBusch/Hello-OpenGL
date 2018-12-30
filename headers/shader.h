#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader
{
  public:
    Shader(const std::string &fileName);

    void Bind();

    virtual ~Shader();

  protected:
  private:
    static const unsigned int NUM_SHADERS = 2; // Only deal with vertex and fragment shaders

    Shader(const Shader &other){};
    Shader &operator=(const Shader &other){};

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
};
#endif