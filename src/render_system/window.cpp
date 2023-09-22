#include "../../includes/render_system/window.hpp"

void prepareScene(Window app)
{
    SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(Window app)
{
    SDL_RenderPresent(app.renderer);
}

void initSDL(Window app)
{
    int renderFlags, windowFlags;

    renderFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Couldn't initialize SDL" << SDL_GetError() << endl;
        exit(1);
    }

    app.window = SDL_CreateWindow("First Window", SDL_WINDOW_RESIZABLE,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
    if (!app.window)
    {
        cout << "Failed to Open Window" << SDL_GetError() << endl;
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app.renderer = SDL_CreateRenderer(app.window, -1, renderFlags);
    if (!app.renderer)
    {
        cout << "Failed to Create a renderer" << SDL_GetError() << endl;
        exit(1);
    }
}

int window()
{
    Window window;
    memset(&window, 0, sizeof(Window));
    initSDL(window);
    while (1)
    {
        prepareScene(window);
        inputs();
        presentScene(window);
    }
    return 0;
}