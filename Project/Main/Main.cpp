#include <Context/Context.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

int main( int, char *[] )
{
    SDL_Window *window    = NULL;
    SDL_GLContext context = NULL;

    if ( !createContext( window, context ) )
    {
        return EXIT_FAILURE;
    }

    /*
        Initialise render system etc. here
    */

    if ( !eventLoop( window ) )
    {
        close( window, context );

        /*
            Destroy rendering pipeline
        */

        return EXIT_SUCCESS;
    }
}
