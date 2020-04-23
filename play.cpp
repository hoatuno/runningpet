#include <string>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <SDL_mixer.h>

#include "utils.h"
#include "box.h"
#include "play.h"

void Preplay(SDL_Window* &window, SDL_Renderer* &renderer,bool&quit){

    SDL_Event e;
    bool starting=1;;
    SDL_Texture * preback = NULL;
    preback = IMG_LoadTexture( renderer, "image/backpre.PNG");

    while(starting){
        while(SDL_PollEvent(&e)){
            KeyPresstostart( e,starting,quit);
        if(!quit) starting=0;
        }
        SDL_RenderCopy(renderer, preback, NULL, NULL);
        SDL_Delay(10);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
    SDL_DestroyTexture(preback);
}

void Playgame(SDL_Window* &window, SDL_Renderer* &renderer, bool& gamerunning, long&score, long& Highscore, bool&quit)
{
    string BARRI[5]={ "image/111.PNG","image/222.PNG","image/333.PNG","image/444.PNG","image/555.PNG" };
    string Guinea[12]= { "image/guinea/1.PNG", "image/guinea/2.PNG", "image/guinea/3.PNG","image/guinea/4.PNG", "image/guinea/5.PNG", "image/guinea/6.PNG", "image/guinea/7.PNG", "image/guinea/8.PNG", "image/guinea/9.PNG", "image/guinea/10.PNG", "image/guinea/11.PNG", "image/guinea/12.PNG"};

    SDL_Texture * background = NULL;
    background = IMG_LoadTexture( renderer, "image/backtwo.PNG");
    bool StartJump =0;
    int time1=0;
    int foot=0;
    int state= 4;
    int state2= 1;
    SDL_Rect pet;// Nhân vật
    pet.x= 50;
    pet.y= 500;
    SDL_Rect barr1; // chuong ngai vat
    barr1.x=1200;
    barr1.y=500;
    SDL_Rect barr2; // chuong ngai vat
    barr2.x=1800;
    barr2.y=500;

    SDL_Rect descore; // ghi diem
    descore.x=860;
    descore.y=520;
    SDL_Rect deshigh; // ghi diem cao
    deshigh.x=860;
    deshigh.y=548;

    SDL_Event e;
    if(gamerunning) PlayMusic("music/overworld.ogg");
    if(Mix_PausedMusic()) Mix_ResumeMusic();

    while(gamerunning){
        score++;
        while (SDL_PollEvent(&e)) {
            PlaygameEvent(e, StartJump, quit);
            if(!quit) gamerunning=0;
        }
        SDL_RenderCopy(renderer, background, NULL, NULL);
        RunningBarrier(renderer,barr1 , state, BARRI, score);
        RunningBarrier(renderer,barr2 , state2, BARRI, score);
        if ( accident(pet, barr1) || accident(pet, barr2)) { cout << "die"; Playchunk("music/crash.ogg");gamerunning =0;}

        if(StartJump) Jumping(renderer, pet, foot, StartJump );
        Animachar(StartJump,time1);

        Showimage( Guinea[time1].c_str() , renderer, pet);

        SDL_Color fg = { 5, 0, 4, 200 };
        ShowText(to_string(score).c_str(),fg,renderer, 27, descore);
        ShowText(to_string(Highscore).c_str(),fg,renderer, 27, deshigh);
        //cout << pet.x <<"; " << pet.y << "; " << pet.h <<"; " << pet.w << endl;

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        SDL_RenderClear(renderer);
    }

    if (!gamerunning && Mix_PlayingMusic()==1) { Mix_PauseMusic();}
    SDL_DestroyTexture(background);
    SDL_RenderClear(renderer);

}

void Playagain(SDL_Window* &window, SDL_Renderer* &renderer, long& score,bool&gamerunning, bool&quit){

    bool playagain=1;
    SDL_Event e;

    SDL_Rect Yscore;
    Yscore.x=330;
    Yscore.y=270;
    SDL_Texture * backout = NULL;
    backout = IMG_LoadTexture( renderer, "image/Backout.PNG");
    while(playagain){

        SDL_RenderCopy(renderer, backout, NULL, NULL);
        SDL_Color fg = { 255, 255, 255 };
        string typescore= "YOUR SCORE: ";
        typescore+= to_string(score);                         // handing score
        ShowText(typescore.c_str(),fg,renderer, 35, Yscore);

        while(SDL_PollEvent(&e)){
            KeyPressedplayagain(e,score,gamerunning,quit);
            if(gamerunning) playagain=0;
            if(!quit) playagain=0;

        }
        SDL_Delay(1);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    SDL_DestroyTexture(backout);
}
