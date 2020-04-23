
#include <SDL.h>
#include <string>
using namespace std;


// hàm điều hướng game

// hàm xử lý đối tượng trong game
void Jumping( SDL_Renderer* &renderer, SDL_Rect& pet,int &foot,bool& StartJump);
void RunningBarrier( SDL_Renderer* &renderer, SDL_Rect& pos,int &state, string Barri[] ,long&score );
void Animachar (bool& StartJump, int& time1);
bool accident(SDL_Rect& pet, SDL_Rect& barrier );

void PlaygameEvent(SDL_Event e, bool& StartJump, bool& quit);
void KeyPressedplayagain( SDL_Event e,long &score , bool& gamerunning, bool&quit);
void KeyPresstostart( SDL_Event e, bool& starting, bool&quit);
