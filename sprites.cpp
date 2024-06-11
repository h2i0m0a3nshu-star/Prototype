#include "sprites.h"

Texture2D* sprites::loadTexture(const char* path)
{
    Texture2D img = LoadTexture(path);
    return &img;
}

void sprites::unloadTexture(Texture2D curr)
{
    UnloadTexture(curr);
}

bool sprites::animate(Texture2D curr, Rectangle DestRect,int rotation, int num_of_images)
{
    ctr++;
        float width = curr.width / num_of_images;
        float height = curr.height;
        if (ctr > num_of_images && delay >= 5) {
            ctr = 1;    
            return true;
        }
        DrawTexturePro(curr, { float(ctr * width),0, width,height }, DestRect, { 0,0 }, rotation, RAYWHITE);
        return false;
}

bool sprites::flipanimate(Texture2D curr, Rectangle DestRect, int num_of_images)
{
    ctr++;
        float width = curr.width / num_of_images;
        float height = curr.height;
        if (ctr > num_of_images && delay >= 5) {
            ctr = 1;
            return true;
        }
        DrawTexturePro(curr, { float(ctr * width),0, width * -1,height }, DestRect, { 0,0 }, 0, RAYWHITE);
        return false;
}

void sprites::setctr(int newctr)
{
    ctr = newctr;
}

void sprites::delay_handler()
{
    if (delay >= 0 && delay < 5) {
        delay++;
    }
}

