#include "../../includes/shared/classes.hpp"

SDL_Texture *loadTexture(const char *filename, Window *app)
{
    SDL_Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    texture = IMG_LoadTexture(app->renderer, filename);

    return texture;
}

void blit(Window *app, SDL_Texture *texture, Entity player)
{
    SDL_Rect dest;
    Vector2 position = player.GetPosition();

    dest.x = position.x;
    dest.y = position.y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(app->renderer, texture, NULL, &dest);
}
