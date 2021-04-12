#include "bg.h"
#include "input.h"

int main()
{
    int done = 1, run = 0;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_Surface *screen, *staticBg;

    screen = SDL_SetVideoMode(1000, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Lunatics", NULL); //window title

    //----------------------------------------------------------------------------------------------------------------------

    Input I;
    init_input(&I);

    GameplayBg b;
    GameplayBg b2;

    //----------------------------------------------------------------------------------------------------------------------

    initBg(&b);
    initBg(&b2);

    b2.BgPos.x = 500;
    b2.camera.w = 500;

    SDL_Event event;

    SDL_EnableKeyRepeat(1, 0);
    while (done)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                done = 0;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done = 0;
                    break;

                case SDLK_RIGHT:
                    I.right = 1;
                    //scrolling_right(&b, 10, screen, I);

                    break;

                case SDLK_LEFT:
                    I.left = 1;
                    //scrolling_left(&b, 10, screen, I);
                    break;

                    break;
                case SDLK_d:
                    I.right2 = 1;
                    //scrolling_right(&b, 10, screen, I);
                    break;
                case SDLK_q:
                    I.left2 = 1;
                    //scrolling_left(&b, 10, screen, I);
                    break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                    I.jump = 0;

                    break;

                case SDLK_RIGHT:
                    I.right = 0;

                    break;

                case SDLK_LEFT:
                    I.left = 0;

                    break;

                case SDLK_d:
                    I.right2 = 0;
                    //scrolling_right(&b, 10, screen, I);
                    break;
                case SDLK_q:
                    I.left2 = 0;
                    //scrolling_left(&b, 10, screen, I);
                    break;
                }
                break;
            }




                scrolling_right(&b, 10, screen, I);
                scrolling_left(&b, 10, screen, I);



        }
        //afficher_background(screen, &b);
        afficher_background(screen, &b);
        SDL_Flip(screen);

        //SDL_Delay(20);
    }

    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;
}