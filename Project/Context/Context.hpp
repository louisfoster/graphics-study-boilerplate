#ifndef CONTEXT_H
#define CONTEXT_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>

void checkGLErrors( );

bool createContext( SDL_Window *&, SDL_GLContext & );

void close( SDL_Window *&, SDL_GLContext & );

bool eventLoop( SDL_Window *& );

#endif