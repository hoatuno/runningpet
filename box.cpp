#include <SDL.h>
#include <string>
#include <time.h>
#include "box.h"
#include "utils.h"

const int GROUND = 500;
void Jumping( SDL_Renderer* &renderer, SDL_Rect& pet,int &foot,bool &StartJump){ // Hàm giúp nhảy lên 100px rồi rơi xuống
    int boxstep ;
    foot+=1;                                                            // foot để giúp nhảy lên 1px sau mỗi frame
    boxstep=0.16*foot*foot - 9*foot;// 0 <= boxstep <= 50

    pet.y=GROUND + boxstep ;
    if(foot>=56) { foot =0; StartJump =0; } // 9*foot and >=56 || 8*foot and >=50

}
void Animachar (bool& StartJump, int& time1){  // tạo chuyển động của nhân vật
    if(!StartJump)time1++;
    else time1=6;
    if(time1>11)time1=0;

}
void RunningBarrier( SDL_Renderer* &renderer, SDL_Rect& pos,int &state, string Barri[],long& score ){
{
    // Hàm nhận vào một cửa sổ, một render, một chướng ngại vật và vị trí của nó,
    // chướng ngại vật sẽ đi từ phải qua trái và giải phòng
        srand(time(NULL));        int rapid= (score >800) ? (score-300)/500 : 0;
        int step= -5 -rapid;
        pos.x += step;
        Showimage( Barri[state].c_str() , renderer, pos );

        if (pos.x <= -60)  {
            state = rand()%5 + 0;                   // biến state để random barrier trong khoảng nhỏ
            pos.x= 1000;
            cout << step <<endl;
        }
    }
}
void PlaygameEvent(SDL_Event e,  bool& StartJump, bool&quit){ //Thông báo sự kiện phím
                                                                     //xử lý các thao tác ban đầu với phím
                                                                     //khi game đang chạy
        if (e.type == SDL_QUIT) { quit=0; cout << "QUIT GAME!" << endl; }
        if (e.type == SDL_KEYDOWN)  {
            switch (e.key.keysym.sym){
                case SDLK_SPACE :{
                        cout << "space" << endl;
                        StartJump =1;
                        Playchunk("music/jump.ogg");
                }break;

                default: break;
        }
        if (e.type == SDL_KEYUP) { }
        }
}
void KeyPressedplayagain( SDL_Event e, long& score, bool& gamerunning, bool&quit)
{
    if (e.type == SDL_QUIT) {quit =0; gamerunning=0; cout << "QUIT GAME!" << endl; }
    if (e.type == SDL_KEYDOWN)
        if (e.key.keysym.sym == SDLK_KP_ENTER) {
            score=0;
            gamerunning=1;
            cout << "PLAY AGAIN!" << endl;
    }
}
void KeyPresstostart( SDL_Event e,bool &starting, bool &quit)
{
    if (e.type == SDL_QUIT) { quit=0;cout << "QUIT GAME!" << endl; }
    if (e.type == SDL_KEYDOWN) if (e.key.keysym.sym == SDLK_SPACE) {
    starting =0;
    cout << "START GAME!" << endl; }

}
bool accident(SDL_Rect& pet, SDL_Rect& ba )  // kiem tra va cham giữa 2 rect
                                             // x, y là điểm ở góc phần tư thứ III
{
    int Ax= pet.x+pet.w;
    int Ay= pet.y-5;

    int Bx= pet.x;
    int By= pet.y-5;
    if( Ax>=ba.x+5 && Ax <= ba.x+ba.w-5  &&
            Ay>=ba.y-ba.h+10 && Ay <= ba.y) return 1;
    if( Bx>=ba.x+5 && Bx <= ba.x+ba.w-5  &&
            By>=ba.y-ba.h+10 && By <= ba.y) return 1;
    return 0;
}
