#define SDL_MAIN_HANDLED
#include <string>
#include <iostream>
#include <stdlib.h>     /* srand, rand */

#include "utils.h"
#include "box.h"
#include "play.h"

using namespace std;

    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;
    bool quitgame =1;
    SDL_Window* window;
    SDL_Renderer* renderer;
    //SDL_Event e;

int main() {
    initSDL(window,renderer, SCREEN_WIDTH, SCREEN_HEIGHT, "GAME OF HOATU");
    long Highscore=0;
    long score=0;
    bool quit =1;
    bool gamerunning=1;
    bool startgame =1;

    while(quit){
    if(startgame){Preplay(window,renderer, quit);   startgame=0;}                // MENU GAME

    if(quit) Playgame(window,renderer, gamerunning,score, Highscore, quit) ;
    if(quit) Highscore = score >Highscore ? score : Highscore;
    if(quit) Playagain(window,renderer, score,gamerunning, quit);            //PLAY GAME AGAIN
    }
    quitSDL(window, renderer);
    return 0;
}
