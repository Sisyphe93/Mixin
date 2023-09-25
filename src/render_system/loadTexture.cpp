#include "../../includes/shared/classes.hpp"

SDL_Texture *loadTexture(const char *filename, Window *app)
{
    SDL_Texture *texture;

    texture = IMG_LoadTexture(app->renderer, filename);

    return texture;
}

void blit(Window *app, SDL_Texture *texture, Entity player)
{
    SDL_Rect dest;
    Vector2 position = player.GetPosition();
    Vector2 scale = player.GetScale();

    dest.x = position.x;
    dest.y = position.y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    dest.w = dest.w * scale.x;
    dest.h = dest.h * scale.y;
    SDL_RenderCopy(app->renderer, texture, NULL, &dest);
}
