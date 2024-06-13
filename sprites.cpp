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
        float width = curr.width / num_of_images;
        float height = curr.height;

        if (ctr >= num_of_images - 1) {
            ctr = 0;    
            return true;
        }
        DrawTexturePro(curr, { float(ctr * width),0, width,height }, DestRect, { 0,0 }, rotation, main_color);
        ctr++;
        return false;
}

bool sprites::flipanimate(Texture2D curr, Rectangle DestRect, int num_of_images)
{
        float width = curr.width / num_of_images;
        float height = curr.height;

        if (ctr >= num_of_images-1) {
            ctr = 0;
            return true;
        }
        DrawTexturePro(curr, { float(ctr * width),0, width * -1,height }, DestRect, { 0,0 }, 0, main_color);
        ctr++;
        return false;
}

void sprites::setColor(Color new_color)
{
    main_color = new_color;
}

void sprites::setctr(int newctr)
{
    ctr = newctr;
}
