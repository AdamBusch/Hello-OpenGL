#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

extern "C"
{
#include <SDL2/SDL.h>
}

class Display
{
public:
  Display(int width, int height, const std::string &title);
  virtual ~Display();
  void Update();
  void Clear(float red, float green, float blue, float alpha);

  bool isClosed();

protected:
private:
  Display(const Display &other){};
  Display &operator=(const Display &other){};

  SDL_Window *m_window;
  SDL_GLContext m_glContext;

  bool m_isClosed;
};

#endif //DISPLAY_H