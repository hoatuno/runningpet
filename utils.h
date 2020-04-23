#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>


void logSDLError(std::ostream& os,  const std::string &msg, bool fatal);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, int screenWidth, int screenHeight, const char* windowTitle) ;
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();

void Showimage(const char* imgfile, SDL_Renderer* renderer , SDL_Rect& posit);
void ShowText(const char* text,SDL_Color fg, SDL_Renderer *renderer, int c_size,SDL_Rect& posit);
void PlayMusic(const char* song);
void Playchunk(const char* chunk);
