#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <SDL_mixer.h>

using namespace std;
void logSDLError(ostream& os, const string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
// Chứa các hàm khởi tạo w, renderer, audio, text
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
	int screenWidth, int screenHeight, const char* windowTitle)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);
    window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, screenWidth, screenHeight);
        if (TTF_Init() < 0)
	{
		cout << "ERROR: "<< TTF_GetError();
	}
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
	    cout << "ERROR: "<<  Mix_GetError();
	}
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
    Mix_CloseAudio();
    TTF_Quit();
	SDL_Quit();

}

/// SHOW FUNTION
void Showimage(const char* imgfile, SDL_Renderer* renderer , SDL_Rect& posit) {
    // nhận vào file ảnh và in ra tại vị trí rect
    SDL_Texture * img = NULL;
    int w, h;
    img = IMG_LoadTexture( renderer, imgfile);
    SDL_QueryTexture(img, NULL, NULL, &w, &h);
    SDL_Rect tex;
    tex.x = posit.x;
    tex.y = posit.y -h;
    tex.w = w;
    tex.h = h;
    posit =tex;
    posit.y+=h;
    SDL_RenderCopy(renderer, img , NULL, &tex);
    SDL_DestroyTexture(img);
}
void ShowText( const char* text,SDL_Color fg, SDL_Renderer *renderer, int c_size,SDL_Rect& posit){
    //show tương tự file ảnh
    TTF_Font* font = NULL;
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;

    font = TTF_OpenFont("font/arial.ttf", c_size);
	surface = TTF_RenderText_Solid(font, text, fg);
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
	TTF_SizeText(font, text, &posit.w, &posit.h);
    SDL_RenderCopy(renderer, texture, NULL, &posit);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

}
void PlayMusic(const char* song){
    Mix_Music* music= NULL;                     //background music
    music = Mix_LoadMUS(song);
    if (music == NULL)
	{
		cout << "Error :" <<Mix_GetError() << endl;
	}
	Mix_PlayMusic(music, -1);
}
void Playchunk(const char* filechunk){
    Mix_Chunk* chunk = NULL;

    chunk = Mix_LoadWAV(filechunk);
    if (chunk == NULL)
	{
		cout << "Error :" <<Mix_GetError() << endl;
	}
    //if (!Mix_Playing(-1))
        Mix_PlayChannel(-1, chunk, 0);
}




