#include "Context.hpp"

bool handleKeyUp( SDL_KeyboardEvent *key )
{
    bool quit = false;

    switch ( key->keysym.scancode )
    {
    case SDL_SCANCODE_ESCAPE:
        quit = true;
        break;
    default:
        break;
    }

    return quit;
}

void checkGLErrors( )
{
    if ( SDL_GL_GetCurrentContext( ) != NULL )
    {
        GLenum err;
        while ( ( err = glGetError( ) ) != GL_NO_ERROR )
        {
            std::cout << "GL Error: " << err << std::endl;
        }
    }
    else
    {
        std::cout << "No GL Context Found!" << std::endl;
    }
}

bool createContext( SDL_Window *&window, SDL_GLContext &context )
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError( )
                  << std::endl;

        return false;
    }

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK,
                         SDL_GL_CONTEXT_PROFILE_CORE );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 8 );

    window = SDL_CreateWindow( "Open GL",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               800,
                               600,
                               SDL_WINDOW_OPENGL );

    if ( NULL == window )
    {
        std::cout << "Window not created: " << SDL_GetError( ) << std::endl;

        return false;
    }

    context = SDL_GL_CreateContext( window );

    glewExperimental = GL_TRUE;
    glewInit( );

    return true;
}

void close( SDL_Window *&window, SDL_GLContext &context )
{
    SDL_GL_DeleteContext( context );
    context = NULL;
    SDL_DestroyWindow( window );
    window = NULL;
    SDL_Quit( );
}

bool eventLoop( SDL_Window *&window )
{
    SDL_Event event;

    bool quit    = false;
    bool visible = true;

    auto t_start = std::chrono::high_resolution_clock::now( );

    while ( !quit )
    {
        if ( SDL_PollEvent( &event ) )
        {
            switch ( event.type )
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_WINDOWEVENT:
                switch ( event.window.event )
                {
                case SDL_WINDOWEVENT_HIDDEN:
                    visible = false;
                    break;
                case SDL_WINDOWEVENT_SHOWN:
                    visible = true;
                    break;
                case SDL_WINDOWEVENT_FOCUS_LOST:
                    visible = false;
                    break;
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    visible = true;
                    break;
                case SDL_WINDOWEVENT_CLOSE:
                    quit = true;
                    break;
                }
                break;
            case SDL_KEYUP:
                quit = handleKeyUp( &event.key );
                break;
            default:
                break;
            }
        }

        if ( !visible )
        {
            SDL_WaitEvent( NULL );
        }
        else
        {
            auto t_now = std::chrono::high_resolution_clock::now( );
            float time =
                std::chrono::duration_cast<std::chrono::duration<float>>(
                    t_now - t_start )
                    .count( );

            /*
                Call draw functions here
            */

            SDL_GL_SwapWindow( window );

            checkGLErrors( );
        }
    }

    std::cout << "App will now exit." << std::endl;

    return false;
}