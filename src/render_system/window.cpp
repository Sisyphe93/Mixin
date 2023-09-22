#include "../../includes/render_system/window.hpp"

void cleanup(int status, void *data)
{
    Window *app = (Window *)data;

    if (app->window != NULL)
    {
        SDL_DestroyWindow(app->window);
    }

    if (app->renderer != NULL)
    {
        SDL_DestroyRenderer(app->renderer);
    }
    SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO);
    SDL_Quit();
}

void prepareScene(Window *app)
{
    SDL_SetRenderDrawColor(app->renderer, 90, 128, 255, 255);
    SDL_RenderClear(app->renderer);
}

void presentScene(Window *app)
{
    SDL_RenderPresent(app->renderer);
}

void initSDL(Window *app)
{
    int renderFlags, windowFlags;

    renderFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) < 0)
    {
        cout << "Couldn't initialize SDL" << SDL_GetError() << endl;
        exit(1);
    }

    app->window = SDL_CreateWindow("First Window", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
    if (!app->window)
    {
        cout << "Failed to Open Window" << SDL_GetError() << endl;
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app->renderer = SDL_CreateRenderer(app->window, -1, renderFlags);
    if (!app->renderer)
    {
        cout << "Failed to Create a renderer" << SDL_GetError() << endl;
        exit(1);
    }
}

int window()
{
    Window window;
    Entity player("player", Vector2(100.0f, 100.0f), 45.0f, Vector2(1.0f, 1.0f));
    Vector2 pos;

    pos = player.GetPosition();
    memset(&window, 0, sizeof(Window));
    initSDL(&window);
    on_exit(cleanup, &window);
    cout << pos.x << ' ' << pos.y << endl;
    while (1)
    {
        prepareScene(&window);
        inputs();
        presentScene(&window);
    }
    return 0;
}