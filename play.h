
#include <string>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <SDL_mixer.h>

#include "utils.h"
#include "box.h"


void Preplay(SDL_Window* &window, SDL_Renderer* &renderer,bool&quit);
void Playgame(SDL_Window* &window, SDL_Renderer* &renderer,bool& gamerunning, long& score, long& Highscore,bool&quit);
void Playagain(SDL_Window* &window, SDL_Renderer* &renderer, long& score,bool&gamerunning,bool&quit);
