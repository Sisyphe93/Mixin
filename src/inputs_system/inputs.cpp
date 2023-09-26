#include "../../includes/inputs_system/inputs.hpp"

void keyDownInputs(Entity *player, SDL_KeyboardEvent *event)
{
    Vector2 position = player->GetPosition();
    switch (event->keysym.scancode)
    {
    case SDL_SCANCODE_UP:
        position.y -= 4;
        break;
    case SDL_SCANCODE_DOWN:
        position.y += 4;
        break;
    case SDL_SCANCODE_LEFT:
        position.x -= 4;
        break;
    case SDL_SCANCODE_RIGHT:
        position.x += 4;
        break;
    default:
        break;
    }
    player->setPosition(position);
}

void keyUpInputs(Entity *player, SDL_KeyboardEvent *event)
{
}

void inputs(Entity *player)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            keyDownInputs(player, &event.key);
        default:
            break;
        }
    }
}