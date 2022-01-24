//By S.Moienadin Makkiyan
//By Asal Rodbari

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <SDL2/SDL_mixer.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DECLERE TAVABE

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void background();
void ball();
void skate();
void RestLose();
void khat_partab();
void setsign();
void barkhord();
void limit(double t, double x);
void ajor(double x,double y,int k);
void draw_ajor();
void calculate();
void taskbar();
void tasktext();
void check();
void gameover();
void nextlevel();
void TextBox();
void first_menu();
void startgame();
void enter_name();
void staart();
void setting();
void high_scores();
void cheat_codes();
void about_us();
void exit();
void loadgame();
void newgame();
void historytable();
void Lcalculate();
void save_game();
void chap(int x, int y, int digit);
void print_number(int x, int y, int number);
void secondmenu();
void unmute_music();
void mute_music();
void start_music();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DECLERE GLOBALS

SDL_Window *m_window;
SDL_Renderer *m_renderer;
SDL_Texture *background1;
SDL_Texture *semenu;
SDL_Texture *ball1;
SDL_Texture *skate1;
SDL_Texture *ajor1;
SDL_Texture *ajor2;
SDL_Texture *ajor3;
SDL_Texture *ajor4;
SDL_Texture *ajor5;
SDL_Texture *task1;
SDL_Texture *pause1;
SDL_Texture *level1;
SDL_Texture *score1;
SDL_Texture *lives1;
SDL_Texture *damage1;
SDL_Texture *gameover1;
SDL_Texture *START;
SDL_Texture *LSTART;
SDL_Texture *entername;
SDL_Texture *firstmenu;
SDL_Texture *newgame1;
SDL_Texture *loadgame1;
SDL_Texture *historytable1;
SDL_Texture *digit0;
SDL_Texture *digit1;
SDL_Texture *digit2;
SDL_Texture *digit3;
SDL_Texture *digit4;
SDL_Texture *digit5;
SDL_Texture *digit6;
SDL_Texture *digit7;
SDL_Texture *digit8;
SDL_Texture *digit9;
SDL_Texture *cheat;
SDL_Texture *about;
SDL_Texture *ball2;
SDL_Texture *background2;
SDL_Texture *skate2;
SDL_Texture *ball3;
SDL_Texture *background3;
SDL_Texture *skate3;
SDL_Texture *ball4;
SDL_Texture *background4;
SDL_Texture *skate4;
SDL_Texture *types;
SDL_Texture *lock;

Mix_Music *backgroundSound;
Mix_Chunk *beeb;
Mix_Chunk *beeb2;

bool fmenu=true;
bool smenu=true;
bool start=false;
bool sstart=false;
bool namefound=false;

double x_b=580+100;
double y_b=560;
double signx_b=0;
double signy_b=5;

double x_s=450+100;
double y_s=600;
double signx_s=20;

double x_f;
double y_f;
double teta=M_PI_2;
double dt=0.2;

double lim_l=1;
double lim_s=1;

double Li=100;

int level=1;
int score=0;
int lives=3;
int damage=3;

int oldlevel=-5;
int oldscore=-5;
int oldlives=-5;
int olddamage=-5;

int x_m=0;
int y_m=0;

int aa=40;
int bb=40;
bool aaa=true;
bool bbb=true;
bool music=true;

int type=1;

using namespace std;

string name="";
int history=0;
int name_data[5][5];
int ajor_info_name [5][100][8][3];
int info_ajor[100][8][3];
int stu=0;

int main( int argc, char * argv[] )
{
    bool qqqq=true;
    cout<<"     WELCOME TO BREAK BRICK!"<< endl;
    while(qqqq)
    {
        cout<<endl;
        cout<<"PLEASE ENTER THE PASSWORD : ";
        string a; cin>>a;
        if(a=="SUT") qqqq=false;
    }


    int W = 700;
    int L = 1300;
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    window_color(m_renderer,255,255,255);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //LOAD MUSIC

    backgroundSound = Mix_LoadMUS("backmusic.mp3");
    beeb = Mix_LoadWAV("beep.wav");
    beeb2 = Mix_LoadWAV("beep2.wav");

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //LOAD AX
    START = IMG_LoadTexture( m_renderer, "START.png");
    startgame();

    background1 = IMG_LoadTexture( m_renderer, "background1.jpg");
    ball1 = IMG_LoadTexture( m_renderer, "ball1.png");
    skate1 = IMG_LoadTexture( m_renderer, "skate1.png");
    ajor1 = IMG_LoadTexture( m_renderer, "ajor1.png");
    ajor2 = IMG_LoadTexture( m_renderer, "ajor2.png");
    ajor3 = IMG_LoadTexture( m_renderer, "ajor3.png");
    ajor4 = IMG_LoadTexture( m_renderer, "ajor4.png");
    ajor5 = IMG_LoadTexture( m_renderer, "ajor5.png");
    task1 = IMG_LoadTexture( m_renderer, "task1.png");
    pause1 = IMG_LoadTexture( m_renderer, "pause1.png");
    level1 = IMG_LoadTexture( m_renderer, "level1.png");
    score1 = IMG_LoadTexture( m_renderer, "score1.png");
    lives1 = IMG_LoadTexture( m_renderer, "lives1.png");
    damage1 = IMG_LoadTexture( m_renderer, "damage1.png");
    gameover1 = IMG_LoadTexture( m_renderer, "gameover1.png");
    entername = IMG_LoadTexture( m_renderer, "entername.png");
    firstmenu = IMG_LoadTexture( m_renderer, "firstmenu.png");
    newgame1 = IMG_LoadTexture( m_renderer, "newgame.png");
    loadgame1 = IMG_LoadTexture( m_renderer, "loadgame.png");
    historytable1 = IMG_LoadTexture( m_renderer, "scoretable.png");
    semenu = IMG_LoadTexture( m_renderer, "semenu.png");
    digit0 = IMG_LoadTexture( m_renderer, "digit0.png");
    digit1 = IMG_LoadTexture( m_renderer, "digit1.png");
    digit2 = IMG_LoadTexture( m_renderer, "digit2.png");
    digit3 = IMG_LoadTexture( m_renderer, "digit3.png");
    digit4 = IMG_LoadTexture( m_renderer, "digit4.png");
    digit5 = IMG_LoadTexture( m_renderer, "digit5.png");
    digit6 = IMG_LoadTexture( m_renderer, "digit6.png");
    digit7 = IMG_LoadTexture( m_renderer, "digit7.png");
    digit8 = IMG_LoadTexture( m_renderer, "digit8.png");
    digit9 = IMG_LoadTexture( m_renderer, "digit9.png");
    cheat = IMG_LoadTexture( m_renderer, "chaetcodes.png");
    about = IMG_LoadTexture( m_renderer, "aboutus.png");
    ball2 = IMG_LoadTexture( m_renderer, "ball2.png");
    background2 = IMG_LoadTexture( m_renderer, "background2.jpg");
    skate2 = IMG_LoadTexture( m_renderer, "skate2.png");
    ball3 = IMG_LoadTexture( m_renderer, "ball3.png");
    background3 = IMG_LoadTexture( m_renderer, "background3.png");
    skate3 = IMG_LoadTexture( m_renderer, "skate3.png");
    ball4 = IMG_LoadTexture( m_renderer, "ball4.png");
    background4 = IMG_LoadTexture( m_renderer, "background4.png");
    skate4 = IMG_LoadTexture( m_renderer, "skate4.png");
    types = IMG_LoadTexture( m_renderer, "types.png");
    LSTART = IMG_LoadTexture( m_renderer, "LSTART.png");
    lock = IMG_LoadTexture( m_renderer, "lock.png");

    SDL_Event *event = new SDL_Event();
    while (1)
            {
                first_menu();
                while(sstart)
                    {
                        if(y_b>700) RestLose();
                        if( SDL_PollEvent( event ) )
                        {
                            if( event->type == SDL_KEYDOWN )
                            {
                                switch( event->key.keysym.sym )
                                {
                                    case SDLK_LEFT:
                                        {
                                        limit(teta,x_s-signx_s);
                                        x_s-=signx_s*lim_s;
                                        break;
                                        }
                                    case SDLK_RIGHT:
                                        {
                                        limit(teta,x_s+signx_s);
                                        x_s+=signx_s*lim_s;
                                        break;
                                        }
                                    case SDLK_UP:
                                        {
                                        limit(teta+dt,x_s);
                                        teta+=dt*lim_l;
                                        break;
                                        }
                                    case SDLK_DOWN:
                                        {
                                        limit(teta-dt,x_s);
                                        teta-=dt*lim_l;
                                        break;
                                        }
                                    case SDLK_SPACE:
                                        {
                                        if(!start)
                                        {
                                            start=true;
                                            setsign();
                                        }
                                        break;
                                        }
                                    case SDLK_F1:
                                        {
                                            Li=500;
                                            break;
                                        }
                                    case SDLK_F2:
                                        {
                                            signx_s*=2;
                                            break;
                                        }
                                    case SDLK_F3:
                                        {
                                            for(int j=0;j<level;j++)
                                                for(int i=0;i<8;i++)
                                                    info_ajor[j][i][2]=0;
                                            break;
                                        }
                                    case SDLK_F4:
                                        {
                                            lives+=5;
                                            break;
                                        }
                                    case SDLK_F5:
                                        {
                                            score+=100;
                                            break;
                                        }
                                    case SDLK_F6:
                                        {
                                            damage*=2;
                                            break;
                                        }
                                    case SDLK_1:
                                    {
                                        for(int i=0;i<8;i++)
                                                info_ajor[level-1][i][2]=0;
                                            break;
                                    }
                                    case SDLK_2:
                                    {
                                        for(int i=0;i<8;i++)
                                                info_ajor[level-2][i][2]=0;
                                            break;
                                    }
                                    case SDLK_3:
                                    {
                                        for(int i=0;i<8;i++)
                                                info_ajor[level-3][i][2]=0;
                                            break;
                                    }
                                    case SDLK_4:
                                    {
                                        for(int i=0;i<8;i++)
                                                info_ajor[level-4][i][2]=0;
                                            break;
                                    }
                                    case SDLK_5:
                                    {
                                        for(int i=0;i<8;i++)
                                                info_ajor[level-5][i][2]=0;
                                            break;
                                    }
                                    case SDLK_6:
                                    {
                                        for(int i=0;i<8;i++)
                                                info_ajor[level-6][i][2]=0;
                                            break;
                                    }
                                    case SDLK_7:
                                    {
                                        for(int i=0;i<8;i++)
                                                info_ajor[level-7][i][2]=0;
                                            break;
                                    }
                                    case SDLK_8:
                                    {
                                        for(int i=0;i<8;i++)
                                                info_ajor[level-8][i][2]=0;
                                            break;
                                    }
                                    case SDLK_9:
                                    {
                                        for(int i=0;i<8;i++)
                                                info_ajor[level-9][i][2]=0;
                                            break;
                                    }
                                    case SDLK_ESCAPE:
                                    {
                                        exit();
                                        return 0;
                                    }
                                }

                            }
                            if(event->type != SDL_KEYDOWN)
                            {
                                x_m=event->button.x;
                                y_m=event->button.y;
                                if ((event->type==SDL_MOUSEBUTTONDOWN)&&x_m>10&&x_m<90&&y_m>25&&y_m<115)
                                {
                                    smenu=true;
                                    while(smenu)
                                    {
                                        secondmenu();
                                        smenu=false;
                                    }
                                }
                            }
                        }
                        if(start)
                        {
                            barkhord();
                            check();
                            x_b+=signx_b;
                            y_b+=signy_b;
                            background();
                            taskbar();
                            draw_ajor();
                            skate();
                            ball();
                            SDL_Delay(30);
                            SDL_RenderPresent(m_renderer);

                        }
                        else
                        {
                            check();
                            x_b=x_s+130;
                            background();
                            taskbar();
                            khat_partab();
                            draw_ajor();
                            skate();
                            ball();
                            SDL_RenderPresent(m_renderer);
                        }

                    }
            }
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor( Renderer, R, G, B, 255 );
    SDL_RenderClear( Renderer );
    SDL_RenderPresent( Renderer );
}


void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolian==1)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
}


void RestLose()
{
    x_b=580+100;
    y_b=560;

    x_s=450+100;
    y_s=600;

    teta=M_PI_2;

    start=false;

    lim_l=1;
    lim_s=1;

    Li=100;

    signx_s=20;

    lives--;
    Mix_PlayChannel(-1,beeb2,0);
    background();
    skate();
    ball();
    SDL_RenderPresent(m_renderer);
}


void background()
{
    if(type==1)
    {
        int w1, h1;
        SDL_QueryTexture(background1, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = 0;
        texr1.y = 0;
        texr1.w = 1300;
        texr1.h = 700;
        SDL_RenderCopy( m_renderer, background1, NULL, &texr1);
    }
    if(type==2)
    {
        int w11, h11;
        SDL_QueryTexture(background2, NULL, NULL, &w11, &h11);
        SDL_Rect texr11;
        texr11.x = 0;
        texr11.y = 0;
        texr11.w = 1300;
        texr11.h = 700;
        SDL_RenderCopy( m_renderer, background2, NULL, &texr11);
    }
    if(type==3)
    {
        rect(m_renderer,100,0,1200,700,255,255,255,1);
        int w111, h111;
        SDL_QueryTexture(background3, NULL, NULL, &w111, &h111);
        SDL_Rect texr111;
        texr111.x = 0;
        texr111.y = 0;
        texr111.w = 1300;
        texr111.h = 700;
        SDL_RenderCopy( m_renderer, background3, NULL, &texr111);
    }
    if(type==4)
    {
        int w1111, h1111;
        SDL_QueryTexture(background4, NULL, NULL, &w1111, &h1111);
        SDL_Rect texr1111;
        texr1111.x = 0;
        texr1111.y = 0;
        texr1111.w = 1300;
        texr1111.h = 700;
        SDL_RenderCopy( m_renderer, background4, NULL, &texr1111);
    }
}

void ball()
{
    if(type==1)
    {
        int w2, h2;
        SDL_QueryTexture(ball1, NULL, NULL, &w2, &h2);
        SDL_Rect texr2;
        texr2.x = x_b;
        texr2.y = y_b;
        texr2.w = 40;
        texr2.h = 40;
        SDL_RenderCopy( m_renderer, ball1, NULL, &texr2);
    }
    if(type==2)
    {
        int w22, h22;
        SDL_QueryTexture(ball2, NULL, NULL, &w22, &h22);
        SDL_Rect texr22;
        texr22.x = x_b;
        texr22.y = y_b;
        texr22.w = 40;
        texr22.h = 40;
        SDL_RenderCopy( m_renderer, ball2, NULL, &texr22);
    }
    if(type==3)
    {
        int w222, h222;
        SDL_QueryTexture(ball3, NULL, NULL, &w222, &h222);
        SDL_Rect texr222;
        texr222.x = x_b;
        texr222.y = y_b;
        texr222.w = 40;
        texr222.h = 40;
        SDL_RenderCopy( m_renderer, ball3, NULL, &texr222);
    }
    if(type==4)
    {
        int w2222, h2222;
        SDL_QueryTexture(ball4, NULL, NULL, &w2222, &h2222);
        SDL_Rect texr2222;
        texr2222.x = x_b;
        texr2222.y = y_b;
        texr2222.w = 40;
        texr2222.h = 40;
        SDL_RenderCopy( m_renderer, ball4, NULL, &texr2222);
    }
}

void skate()
{
    if(type==1)
    {
        int w3, h3;
        SDL_QueryTexture(skate1, NULL, NULL, &w3, &h3);
        SDL_Rect texr3;
        texr3.x = x_s;
        texr3.y = y_s;
        texr3.w = 300;
        texr3.h = 50;
        SDL_RenderCopy( m_renderer, skate1, NULL, &texr3);
    }
    if(type==2)
    {
        int w33, h33;
        SDL_QueryTexture(skate2, NULL, NULL, &w33, &h33);
        SDL_Rect texr33;
        texr33.x = x_s;
        texr33.y = y_s;
        texr33.w = 300;
        texr33.h = 50;
        SDL_RenderCopy( m_renderer, skate2, NULL, &texr33);
    }
    if(type==3)
    {
        int w333, h333;
        SDL_QueryTexture(skate3, NULL, NULL, &w333, &h333);
        SDL_Rect texr333;
        texr333.x = x_s;
        texr333.y = y_s;
        texr333.w = 300;
        texr333.h = 50;
        SDL_RenderCopy( m_renderer, skate3, NULL, &texr333);
    }
    if(type==4)
    {
        int w3333, h3333;
        SDL_QueryTexture(skate4, NULL, NULL, &w3333, &h3333);
        SDL_Rect texr3333;
        texr3333.x = x_s;
        texr3333.y = y_s;
        texr3333.w = 300;
        texr3333.h = 50;
        SDL_RenderCopy( m_renderer, skate4, NULL, &texr3333);
    }
}

void ajor(double x,double y,int k)
{
    if(k==1)
    {
        int w4, h4;
        SDL_QueryTexture(ajor1, NULL, NULL, &w4, &h4);
        SDL_Rect texr4;
        texr4.x = x;
        texr4.y = y;
        texr4.w = 100;
        texr4.h = 40;
        SDL_RenderCopy( m_renderer, ajor1, NULL, &texr4);
    }

    if(k==2)
    {
        int w11, h11;
        SDL_QueryTexture(ajor2, NULL, NULL, &w11, &h11);
        SDL_Rect texr11;
        texr11.x = x;
        texr11.y = y;
        texr11.w = 100;
        texr11.h = 40;
        SDL_RenderCopy( m_renderer, ajor2, NULL, &texr11);
    }

    if(k==3)
    {
        int w12, h12;
        SDL_QueryTexture(ajor3, NULL, NULL, &w12, &h12);
        SDL_Rect texr12;
        texr12.x = x;
        texr12.y = y;
        texr12.w = 100;
        texr12.h = 40;
        SDL_RenderCopy( m_renderer, ajor3, NULL, &texr12);
    }

    if(k==4)
    {
        int w13, h13;
        SDL_QueryTexture(ajor4, NULL, NULL, &w13, &h13);
        SDL_Rect texr13;
        texr13.x = x;
        texr13.y = y;
        texr13.w = 100;
        texr13.h = 40;
        SDL_RenderCopy( m_renderer, ajor4, NULL, &texr13);
    }

    if(k==4)
    {
        int w14, h14;
        SDL_QueryTexture(ajor5, NULL, NULL, &w14, &h14);
        SDL_Rect texr14;
        texr14.x = x;
        texr14.y = y;
        texr14.w = 100;
        texr14.h = 40;
        SDL_RenderCopy( m_renderer, ajor5, NULL, &texr14);
    }
}

void khat_partab()
{
    x_f=(x_b+20)+Li*cos(teta);
    y_f=(y_b+20)-Li*sin(teta);
    thickLineRGBA(m_renderer,x_b+20,y_b+20,x_f,y_f,2,220,0,0,255);
}

void setsign()
{
    signx_b=(x_f-x_b-20)/5.;
    signy_b=(y_f-y_b-20)/5.;
}

void barkhord()
{
    if(x_b>=1260||x_b<=120) {signx_b*=-1;}
    if(y_b<=0) {signy_b*=-1;}
    if(x_b+40>=x_s&&x_b<=x_s+300&&y_b>560&&y_b<600) {signy_b*=-1;}
    //if((x_b<=x_s&&y_b>=y_s&&y_b<=y_s+50)||(x_b>=x_s+300&&y_b>=y_s&&y_b<=y_s+50)) signx_b*=-1;

    for(int i=0;i<level;i++)
        for(int j=0;j<9;j++)
        {
            if(x_b>=info_ajor[i][j][0]-40&&x_b<=info_ajor[i][j][0]+100&&y_b<=info_ajor[i][j][1]+40&&y_b>=info_ajor[i][j][1]&&info_ajor[i][j][2]!=0)
                {signy_b*=-1;damage-=info_ajor[i][j][2];score+=info_ajor[i][j][2];info_ajor[i][j][2]=0;Mix_PlayChannel(-1,beeb,0);}
        }

}

void limit(double t, double x)
{
    if(t>M_PI_2+1.2||t<M_PI_2-1.2) lim_l=0;
    else lim_l=1;
    if(x<=100||x>=1000) lim_s=0;
    else lim_s=1;
}

void calculate()
{
    srand(time(NULL));
    for(int j=0;j<8;j++)
    {
        info_ajor[level-1][j][0]=125+150*j;
        info_ajor[level-1][j][1]=5;
        info_ajor[level-1][j][2]=(rand()%(level+3))%6;
    }
    for(int i=0;i<level-1;i++)
        for(int j=0;j<8;j++)
            info_ajor[i][j][1]+=50;
}

void draw_ajor()
{
    for(int i=0;i<level;i++)
        for(int j=0;j<8;j++)
            if(info_ajor[i][j][2]!=0)
                ajor(info_ajor[i][j][0],info_ajor[i][j][1],info_ajor[i][j][2]);
}

void taskbar()
{
    int w5, h5;
    SDL_QueryTexture(task1, NULL, NULL, &w5, &h5);
    SDL_Rect texr5;
    texr5.x = 0;
    texr5.y = 0;
    texr5.w = 100;
    texr5.h = 700;
    SDL_RenderCopy( m_renderer, task1, NULL, &texr5);

    int w7, h7;
    SDL_QueryTexture(pause1, NULL, NULL, &w7, &h7);
    SDL_Rect texr7;
    texr7.x = 10;
    texr7.y = 25;
    texr7.w = 80;
    texr7.h = 90;
    SDL_RenderCopy( m_renderer, pause1, NULL, &texr7);

    int w6, h6;
    SDL_QueryTexture(level1, NULL, NULL, &w6, &h6);
    SDL_Rect texr6;
    texr6.x = 10;
    texr6.y = 165;
    texr6.w = 80;
    texr6.h = 90;
    SDL_RenderCopy( m_renderer, level1, NULL, &texr6);

    int w9, h9;
    SDL_QueryTexture(score1, NULL, NULL, &w9, &h9);
    SDL_Rect texr9;
    texr9.x = 10;
    texr9.y = 305;
    texr9.w = 80;
    texr9.h = 90;
    SDL_RenderCopy( m_renderer, score1, NULL, &texr9);

    int w8, h8;
    SDL_QueryTexture(lives1, NULL, NULL, &w8, &h8);
    SDL_Rect texr8;
    texr8.x = 10;
    texr8.y = 445;
    texr8.w = 80;
    texr8.h = 90;
    SDL_RenderCopy( m_renderer, lives1, NULL, &texr8);

    int w10, h10;
    SDL_QueryTexture(damage1, NULL, NULL, &w10, &h10);
    SDL_Rect texr10;
    texr10.x = 10;
    texr10.y = 585;
    texr10.w = 80;
    texr10.h = 90;
    SDL_RenderCopy( m_renderer, damage1, NULL, &texr10);

    tasktext();
}

void check()
{
    if(lives==0) gameover();
    if(damage<=0)
    {
        nextlevel();
        level++;
        calculate();
        damage=level;
    }
    int P=0;
    for(int i=0;i<level;i++)
        for(int j=0;j<8;j++)
        {
            if(info_ajor[i][j][1]+40>=y_s&&info_ajor[i][j][2]!=0)
                gameover();
            if(info_ajor[i][j][2]!=0) P++;
        }
    if(P==0)
    {
        level++;
        calculate();
    }
}

void gameover()
{
    mute_music();
    stu=-1;
    RestLose();
    int w11, h11;
    SDL_QueryTexture(gameover1, NULL, NULL, &w11, &h11);
    SDL_Rect texr11;
    texr11.x = 200;
    texr11.y = 150;
    texr11.w = 1000;
    texr11.h = 400;
    SDL_RenderCopy( m_renderer, gameover1, NULL, &texr11);
    SDL_RenderPresent(m_renderer);
    type=1;
    save_game();
    SDL_Event *e3 = new SDL_Event();
    bool end=false;
    while(!end)
    {
        if( SDL_PollEvent( e3 ) )
        {
            if( e3 ->type != SDL_KEYDOWN )
                {
                    if (e3->type==SDL_MOUSEBUTTONDOWN)
                        end=true;
                }
        }
    }
    fmenu=true;
    sstart=false;
    stu=0;
    name="";
    aa=40;
    bb=40;
    aaa=true;
    bbb=true;
    music=true;
}

void nextlevel()
{

}

void TextBox()
{

    int font =1;
    bool caps_lock = false;
    int x_position=250;
    int y_position=265;
    int R=100;
    int G =100;
    int B=100;
    int A=0.5;
    int W = 370;
    int H = 200;
    bool quit = false ;
    char ch=0;
    SDL_Event *event = new SDL_Event();
    while (!quit)
    {
        SDL_RenderPresent(m_renderer);
        if(SDL_PollEvent(event))
        {
            if(event -> type == SDL_KEYUP)
            {
                switch(event->key.keysym.sym)
                {
                    case SDLK_SPACE:
                    quit = true;
                    break;
                    case SDLK_CAPSLOCK:
                    ch=0;
                    if(!caps_lock)
                    caps_lock = true;
                    else
                    caps_lock = false;
                    break;
                    case SDLK_BACKSPACE:
                    ch = 0;
                    if(name.length()!=0)
                    {
                    textRGBA(m_renderer,x_position +20 , y_position +H-105 , name.c_str(), font+1 , 75 , 255 ,255 ,255 , A);
                    name = name.substr(0,name.length()-1);
                    }

                    break;
                    default :
                    if(event->key.keysym.sym != SDLK_UP && event->key.keysym.sym != SDLK_DOWN && event->key.keysym.sym != SDLK_LEFT && event->key.keysym.sym != SDLK_RIGHT)
                    ch = event->key.keysym.sym;
                    break;
                }
                if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') && name.length()<25 && !quit)
                {
                    if(caps_lock )
                    name+=ch + 'A' - 'a';
                    else
                    name+=ch ;
                }
                if(name != "" && !quit)
                textRGBA(m_renderer,x_position +20 , y_position +H-105 , name.c_str(), font+1 , 75 , 0 ,0 , 0 , A);
            }
        }
    }

}


void tasktext()
{
    if(score>9&&aaa) {aa+=8;aaa=false;}
    if(damage>9&&bbb) {bb+=8;bbb=false;}
    print_number(40,210,level);
    print_number(40,490,lives);
    print_number(aa,355,score);
    print_number(bb,625,damage);
}

void first_menu()
{
        int w15, h15;
        SDL_QueryTexture(LSTART, NULL, NULL, &w15, &h15);
        SDL_Rect texr15;
        texr15.x = 0;
        texr15.y = 0;
        texr15.w = 1300;
        texr15.h = 700;
        SDL_RenderCopy( m_renderer, LSTART, NULL, &texr15);


        int w17, h17;
        SDL_QueryTexture(firstmenu, NULL, NULL, &w17, &h17);
        SDL_Rect texr17;
        texr17.x = 0;
        texr17.y = 0;
        texr17.w = 1300;
        texr17.h = 700;
        SDL_RenderCopy( m_renderer, firstmenu, NULL, &texr17);

        SDL_RenderPresent(m_renderer);

    SDL_Event *e = new SDL_Event();

    while(fmenu)
    {


        if( SDL_PollEvent( e ) )
        {
            if( e ->type != SDL_KEYDOWN )
                {
                    x_m=e->button.x;
                    y_m=e->button.y;
                    if (e->type==SDL_MOUSEBUTTONDOWN)
                    {
                        if(x_m>100&&x_m<530&&y_m>126&&y_m<276)//START
                            staart();
                        if(x_m>100+655&&x_m<530+655&&y_m>126&&y_m<276)//SETTING
                            setting();
                        if(x_m>100&&x_m<530&&y_m>126+205&&y_m<276+205)//HIGH-SCORES
                            high_scores();
                        if(x_m>100+655&&x_m<530+655&&y_m>126+205&&y_m<276+205)//CHEAT-CODES
                            cheat_codes();
                        if(x_m>100&&x_m<530&&y_m>126+205+205&&y_m<276+205+205)//ABOUT-US
                            about_us();
                        if(x_m>100+655&&x_m<530+655&&y_m>126+205+205&&y_m<276+205+205)//EXIT
                            exit();

                    }

                }
        }
    }
}


void enter_name()
{
    int w16, h16;
    SDL_QueryTexture(entername, NULL, NULL, &w16, &h16);
    SDL_Rect texr16;
    texr16.x = 0;
    texr16.y = 0;
    texr16.w = 1300;
    texr16.h = 700;
    SDL_RenderCopy( m_renderer, entername, NULL, &texr16);
    SDL_RenderPresent(m_renderer);
    TextBox();
}

void find_name()
{
    ifstream input;
    string filename=name+".txt";
    input.open(filename.c_str(),ios::in);
    if(input.good())
    {
        for(int i=0;i<5;i++)
        {
            input>>name_data[i][0];
            input>>name_data[i][1];
            input>>name_data[i][2];
            input>>name_data[i][3];
            input>>name_data[i][4];
            for(int j=0;j<100;j++)
                for(int k=0;k<8;k++)
                    for(int q=0;q<3;q++)
                        input>>ajor_info_name[i][j][k][q];
        }
        namefound=true;
    }
    else namefound=false;
    input.close();
}

void startgame()
{
    int w15, h15;
    SDL_QueryTexture(START, NULL, NULL, &w15, &h15);
    SDL_Rect texr15;
    texr15.x = 0;
    texr15.y = 0;
    texr15.w = 1300;
    texr15.h = 700;
    SDL_RenderCopy( m_renderer, START, NULL, &texr15);
    SDL_RenderPresent(m_renderer);
}

void staart()
{
    enter_name();
    find_name();
    if(namefound) loadgame();
    else newgame();
}

void setting()
{
    int w11, h11;
    SDL_QueryTexture(types, NULL, NULL, &w11, &h11);
    SDL_Rect texr11;
    texr11.x = 0;
    texr11.y = 0;
    texr11.w = 1300;
    texr11.h = 700;
    SDL_RenderCopy( m_renderer, types, NULL, &texr11);
    SDL_RenderPresent(m_renderer);
    SDL_Event *e13 = new SDL_Event();
    bool end=false;
    while(!end)
    {
        if( SDL_PollEvent( e13 ) )
        {
            if( e13 ->type != SDL_KEYDOWN )
                {
                    x_m=e13->button.x;
                    y_m=e13->button.y;
                    if (e13->type==SDL_MOUSEBUTTONDOWN)
                    {
                        if(x_m>25&&x_m<600&&y_m>115&&y_m<250)
                            type=1;
                        if(x_m>695&&x_m<695+575&&y_m>115&&y_m<250)
                            type=2;
                        if(x_m>25&&x_m<600&&y_m>115+292&&y_m<292+250)
                            type=3;
                        if(x_m>695&&x_m<695+575&&y_m>115+292&&y_m<250+292)
                            type=4;
                        end=true;
                    }
                }
        }
    }
        int w15, h15;
        SDL_QueryTexture(LSTART, NULL, NULL, &w15, &h15);
        SDL_Rect texr15;
        texr15.x = 0;
        texr15.y = 0;
        texr15.w = 1300;
        texr15.h = 700;
        SDL_RenderCopy( m_renderer, LSTART, NULL, &texr15);


        int w17, h17;
        SDL_QueryTexture(firstmenu, NULL, NULL, &w17, &h17);
        SDL_Rect texr17;
        texr17.x = 0;
        texr17.y = 0;
        texr17.w = 1300;
        texr17.h = 700;
        SDL_RenderCopy( m_renderer, firstmenu, NULL, &texr17);

        SDL_RenderPresent(m_renderer);
}

void high_scores()
{
    int w11, h11;
    SDL_QueryTexture(lock, NULL, NULL, &w11, &h11);
    SDL_Rect texr11;
    texr11.x = 400;
    texr11.y = 100;
    texr11.w = 500;
    texr11.h = 500;
    SDL_RenderCopy( m_renderer, lock, NULL, &texr11);
    SDL_RenderPresent(m_renderer);
    SDL_Event *e3 = new SDL_Event();
    bool end=false;
    while(!end)
    {
        if( SDL_PollEvent( e3 ) )
        {
            if( e3 ->type != SDL_KEYDOWN )
                {
                    if (e3->type==SDL_MOUSEBUTTONDOWN)
                        end=true;
                }
        }
    }
    int w15, h15;
        SDL_QueryTexture(LSTART, NULL, NULL, &w15, &h15);
        SDL_Rect texr15;
        texr15.x = 0;
        texr15.y = 0;
        texr15.w = 1300;
        texr15.h = 700;
        SDL_RenderCopy( m_renderer, LSTART, NULL, &texr15);


        int w17, h17;
        SDL_QueryTexture(firstmenu, NULL, NULL, &w17, &h17);
        SDL_Rect texr17;
        texr17.x = 0;
        texr17.y = 0;
        texr17.w = 1300;
        texr17.h = 700;
        SDL_RenderCopy( m_renderer, firstmenu, NULL, &texr17);

        SDL_RenderPresent(m_renderer);
}

void cheat_codes()
{
    int w22, h22;
    SDL_QueryTexture(cheat, NULL, NULL, &w22, &h22);
    SDL_Rect texr22;
    texr22.x = 0;
    texr22.y = 0;
    texr22.w = 1300;
    texr22.h = 700;
    SDL_RenderCopy( m_renderer, cheat, NULL, &texr22);
    SDL_RenderPresent(m_renderer);
    SDL_Event *e11 = new SDL_Event();
    bool ex=false;
    while(!ex)
    {
        if( SDL_PollEvent( e11 ) )
        {
            if( e11 ->type != SDL_KEYDOWN )
                {
                    if (e11->type==SDL_MOUSEBUTTONDOWN)
                        ex=true;
                }
        }
    }
    int w15, h15;
        SDL_QueryTexture(LSTART, NULL, NULL, &w15, &h15);
        SDL_Rect texr15;
        texr15.x = 0;
        texr15.y = 0;
        texr15.w = 1300;
        texr15.h = 700;
        SDL_RenderCopy( m_renderer, LSTART, NULL, &texr15);


        int w17, h17;
        SDL_QueryTexture(firstmenu, NULL, NULL, &w17, &h17);
        SDL_Rect texr17;
        texr17.x = 0;
        texr17.y = 0;
        texr17.w = 1300;
        texr17.h = 700;
        SDL_RenderCopy( m_renderer, firstmenu, NULL, &texr17);

        SDL_RenderPresent(m_renderer);
}

void about_us()
{
    int w21, h21;
    SDL_QueryTexture(about, NULL, NULL, &w21, &h21);
    SDL_Rect texr21;
    texr21.x = 0;
    texr21.y = 0;
    texr21.w = 1300;
    texr21.h = 700;
    SDL_RenderCopy( m_renderer, about, NULL, &texr21);
    SDL_RenderPresent(m_renderer);
    SDL_Event *e12 = new SDL_Event();
    bool ex=false;
    while(!ex)
    {
        if( SDL_PollEvent( e12 ) )
        {
            if( e12 ->type != SDL_KEYDOWN )
                {
                    if (e12->type==SDL_MOUSEBUTTONDOWN)
                        ex=true;
                }
        }
    }
    int w15, h15;
        SDL_QueryTexture(LSTART, NULL, NULL, &w15, &h15);
        SDL_Rect texr15;
        texr15.x = 0;
        texr15.y = 0;
        texr15.w = 1300;
        texr15.h = 700;
        SDL_RenderCopy( m_renderer, LSTART, NULL, &texr15);


        int w17, h17;
        SDL_QueryTexture(firstmenu, NULL, NULL, &w17, &h17);
        SDL_Rect texr17;
        texr17.x = 0;
        texr17.y = 0;
        texr17.w = 1300;
        texr17.h = 700;
        SDL_RenderCopy( m_renderer, firstmenu, NULL, &texr17);

        SDL_RenderPresent(m_renderer);
}

void exit()
{
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    IMG_Quit();
    SDL_Quit();
}

void loadgame()
{
    int w18, h18;
    SDL_QueryTexture(loadgame1, NULL, NULL, &w18, &h18);
    SDL_Rect texr18;
    texr18.x = 0;
    texr18.y = 0;
    texr18.w = 1300;
    texr18.h = 700;
    SDL_RenderCopy( m_renderer, loadgame1, NULL, &texr18);
    SDL_RenderPresent(m_renderer);
    SDL_Event *e4 = new SDL_Event();
    bool ex=false;
    while(!ex)
    {
        if( SDL_PollEvent( e4 ) )
        {
            if( e4 ->type != SDL_KEYDOWN )
                {
                    x_m=e4->button.x;
                    y_m=e4->button.y;
                    if(e4->type==SDL_MOUSEBUTTONDOWN&&x_m>290&&x_m<290+750&&y_m>130&&y_m<130+150)
                        {
                            level=1;
                            calculate();
                            lives=3;
                            damage=2;
                            score=0;
                            ex=true;
                            fmenu=false;
                            sstart=true;
                            start_music();
                        }
                    if(e4->type==SDL_MOUSEBUTTONDOWN&&x_m>290&&x_m<290+750&&y_m>430&&y_m<430+150)
                    {
                        historytable();
                        ex=true;
                    }
                }
        }
    }
}

void newgame()
{
    int w19, h19;
    SDL_QueryTexture(newgame1, NULL, NULL, &w19, &h19);
    SDL_Rect texr19;
    texr19.x = 0;
    texr19.y = 0;
    texr19.w = 1300;
    texr19.h = 700;
    SDL_RenderCopy( m_renderer, newgame1, NULL, &texr19);
    SDL_RenderPresent(m_renderer);
    SDL_Event *e2 = new SDL_Event();
    bool ex=false;
    while(!ex)
    {
        if( SDL_PollEvent( e2 ) )
        {
            if( e2 ->type != SDL_KEYDOWN )
                {
                    x_m=e2->button.x;
                    y_m=e2->button.y;
                    if (e2->type==SDL_MOUSEBUTTONDOWN&&x_m>290&&x_m<290+750&&y_m>130&&y_m<130+150)
                        {
                            level=1;
                            calculate();
                            lives=3;
                            damage=2;
                            score=0;
                            ex=true;
                            fmenu=false;
                            sstart=true;
                            start_music();
                        }
                }
        }
    }
}

void historytable()
{
    int w19, h19;
    SDL_QueryTexture(historytable1, NULL, NULL, &w19, &h19);
    SDL_Rect texr19;
    texr19.x = 0;
    texr19.y = 0;
    texr19.w = 1300;
    texr19.h = 700;
    SDL_RenderCopy( m_renderer, historytable1, NULL, &texr19);

    for(int i=0;i<5;i++)
    {

        int y_pos=250+80*i;
        if(name_data[i][0]!=0)
        {
            int font4 =2;

            stringstream ll;
            ll<<name_data[i][0];
            string lll;
            ll>>lll;
            textRGBA(m_renderer,180,y_pos,lll.c_str(),font4 ,50,0,0,0,255);

            stringstream ss;
            ss<<name_data[i][1];
            string sss;
            ss>>sss;
            textRGBA(m_renderer,370,y_pos,sss.c_str(),font4 ,50,0,0,0,255);

            stringstream lili;
            lili<<name_data[i][2];
            string lilili;
            lili>>lilili;
            textRGBA(m_renderer,600,y_pos,lilili.c_str(),font4 ,50,0,0,0,255);

            stringstream dd;
            dd<<name_data[i][3];
            string ddd;
            dd>>ddd;
            textRGBA(m_renderer,780,y_pos,ddd.c_str(),font4 ,50,0,0,0,255);

            if(name_data[i][4]<0)
            {
                string g="GAME OVER";
                textRGBA(m_renderer,950,y_pos,g.c_str(),font4 ,40,0,0,0,255);
            }
            if(name_data[i][4]>0)
            {
                string p="PAUSED";
                textRGBA(m_renderer,980,y_pos,p.c_str(),font4 ,40,0,0,0,255);
            }
        }
    }
    SDL_RenderPresent(m_renderer);
    SDL_Event *e5 = new SDL_Event();
    bool ex=false;
    while(!ex)
    {
        if( SDL_PollEvent( e5 ) )
        {
            if( e5 ->type != SDL_KEYDOWN )
                {
                    x_m=e5->button.x;
                    y_m=e5->button.y;
                    if(e5->type==SDL_MOUSEBUTTONDOWN&&x_m>500&&x_m<800&&y_m>100&&y_m<150)
                    {
                            level=1;
                            calculate();
                            lives=3;
                            damage=2;
                            score=0;
                            ex=true;
                            fmenu=false;
                            sstart=true;
                            start_music();
                    }
                    if(e5->type==SDL_MOUSEBUTTONDOWN&&x_m>90&&x_m<90+1110&&y_m>240&&y_m<240+75)
                        {
                            if(name_data[0][4]>0)
                            {
                                level=name_data[0][0];
                                score=name_data[0][1];
                                lives=name_data[0][2];
                                damage=name_data[0][3];
                                for(int j=0;j<100;j++)
                                    for(int k=0;k<8;k++)
                                        for(int q=0;q<3;q++)
                                            info_ajor[j][k][q]=ajor_info_name[0][j][k][q];
                                ex=true;
                                fmenu=false;
                                sstart=true;
                                start_music();
                            }
                            else
                            {

                            }
                        }
                        if(e5->type==SDL_MOUSEBUTTONDOWN&&x_m>90&&x_m<90+1110&&y_m>240+79&&y_m<240+75+79)
                        {
                            if(name_data[1][4]>0)
                            {
                                level=name_data[1][0];
                                score=name_data[1][1];
                                lives=name_data[1][2];
                                damage=name_data[1][3];
                                for(int j=0;j<100;j++)
                                    for(int k=0;k<8;k++)
                                        for(int q=0;q<3;q++)
                                            info_ajor[j][k][q]=ajor_info_name[1][j][k][q];
                                ex=true;
                                fmenu=false;
                                sstart=true;
                                start_music();
                            }
                            else
                            {

                            }
                        }
                        if(e5->type==SDL_MOUSEBUTTONDOWN&&x_m>90&&x_m<90+1110&&y_m>240+158&&y_m<158+240+75)
                        {
                            if(name_data[2][4]>0)
                            {
                                level=name_data[2][0];
                                score=name_data[2][1];
                                lives=name_data[2][2];
                                damage=name_data[2][3];
                                for(int j=0;j<100;j++)
                                    for(int k=0;k<8;k++)
                                        for(int q=0;q<3;q++)
                                            info_ajor[j][k][q]=ajor_info_name[2][j][k][q];
                                ex=true;
                                fmenu=false;
                                sstart=true;
                                start_music();
                            }
                            else
                            {

                            }
                        }
                        if(e5->type==SDL_MOUSEBUTTONDOWN&&x_m>90&&x_m<90+1110&&y_m>240+237&&y_m<237+240+75)
                        {
                            if(name_data[3][4]>0)
                            {
                                level=name_data[3][0];
                                score=name_data[3][1];
                                lives=name_data[3][2];
                                damage=name_data[3][3];
                                for(int j=0;j<100;j++)
                                    for(int k=0;k<8;k++)
                                        for(int q=0;q<3;q++)
                                            info_ajor[j][k][q]=ajor_info_name[3][j][k][q];
                                ex=true;
                                fmenu=false;
                                sstart=true;
                                start_music();
                            }
                            else
                            {

                            }
                        }
                        if(e5->type==SDL_MOUSEBUTTONDOWN&&x_m>90&&x_m<90+1110&&y_m>240+316&&y_m<316+240+75)
                        {
                            if(name_data[4][4]>0)
                            {
                                level=name_data[4][0];
                                score=name_data[4][1];
                                lives=name_data[4][2];
                                damage=name_data[4][3];
                                for(int j=0;j<100;j++)
                                    for(int k=0;k<8;k++)
                                        for(int q=0;q<3;q++)
                                            info_ajor[j][k][q]=ajor_info_name[4][j][k][q];
                                ex=true;
                                fmenu=false;
                                sstart=true;
                                start_music();
                            }
                            else
                            {

                            }
                        }

                }
        }
    }
}

void Lcalculate()
{
    int i=level;
    for(level=1;level<=i;level++)
        calculate();
}

void save_game()
{
    string filename=name+".txt";
    remove(filename.c_str());
    ofstream output;
    output.open(filename.c_str(),ios::out);
    if(output.good())
    {
        output<<level<<endl;
        output<<score<<endl;
        output<<lives<<endl;
        output<<damage<<endl;
        output<<stu<<endl;
        for(int jj=0;jj<100;jj++)
                for(int kk=0;kk<8;kk++)
                    for(int qq=0;qq<3;qq++)
                        output<<info_ajor[jj][kk][qq]<<endl;
        for(int i=0;i<4;i++)
        {
            output<<name_data[i][0]<<endl;
            output<<name_data[i][1]<<endl;
            output<<name_data[i][2]<<endl;
            output<<name_data[i][3]<<endl;
            output<<name_data[i][4]<<endl;
            for(int j=0;j<100;j++)
                for(int k=0;k<8;k++)
                    for(int q=0;q<3;q++)
                        output<<ajor_info_name[i][j][k][q]<<endl;
        }
    }
    output.close();
}

void print_number(int x, int y, int number)
{
    int n=number/10;
    while(number>9)
    {
        chap(x,y,number-n*10);
        n/=10;
        number/=10;
        x-=15;
    }
    chap(x,y,number);
}

void chap(int x, int y, int digit)
{
    if(digit==0)
    {
        int w0, h0;
        SDL_QueryTexture(digit0, NULL, NULL, &w0, &h0);
        SDL_Rect texr0;
        texr0.x = x;
        texr0.y = y;
        texr0.w = 20;
        texr0.h = 30;
        SDL_RenderCopy( m_renderer, digit0, NULL, &texr0);
    }
    if(digit==1)
    {
        int w1, h1;
        SDL_QueryTexture(digit1, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = x;
        texr1.y = y;
        texr1.w = 20;
        texr1.h = 30;
        SDL_RenderCopy( m_renderer, digit1, NULL, &texr1);
    }
    if(digit==2)
    {
        int w2, h2;
        SDL_QueryTexture(digit2, NULL, NULL, &w2, &h2);
        SDL_Rect texr2;
        texr2.x = x;
        texr2.y = y;
        texr2.w = 20;
        texr2.h = 30;
        SDL_RenderCopy( m_renderer, digit2, NULL, &texr2);
    }
    if(digit==3)
    {
        int w3, h3;
        SDL_QueryTexture(digit3, NULL, NULL, &w3, &h3);
        SDL_Rect texr3;
        texr3.x = x;
        texr3.y = y;
        texr3.w = 20;
        texr3.h = 30;
        SDL_RenderCopy( m_renderer, digit3, NULL, &texr3);
    }
    if(digit==4)
    {
        int w4, h4;
        SDL_QueryTexture(digit4, NULL, NULL, &w4, &h4);
        SDL_Rect texr4;
        texr4.x = x;
        texr4.y = y;
        texr4.w = 20;
        texr4.h = 30;
        SDL_RenderCopy( m_renderer, digit4, NULL, &texr4);
    }
    if(digit==5)
    {
        int w5, h5;
        SDL_QueryTexture(digit5, NULL, NULL, &w5, &h5);
        SDL_Rect texr5;
        texr5.x = x;
        texr5.y = y;
        texr5.w = 20;
        texr5.h = 30;
        SDL_RenderCopy( m_renderer, digit5, NULL, &texr5);
    }
    if(digit==6)
    {
        int w6, h6;
        SDL_QueryTexture(digit6, NULL, NULL, &w6, &h6);
        SDL_Rect texr6;
        texr6.x = x;
        texr6.y = y;
        texr6.w = 20;
        texr6.h = 30;
        SDL_RenderCopy( m_renderer, digit6, NULL, &texr6);
    }
    if(digit==7)
    {
        int w7, h7;
        SDL_QueryTexture(digit7, NULL, NULL, &w7, &h7);
        SDL_Rect texr7;
        texr7.x = x;
        texr7.y = y;
        texr7.w = 20;
        texr7.h = 30;
        SDL_RenderCopy( m_renderer, digit7, NULL, &texr7);
    }
    if(digit==8)
    {
        int w8, h8;
        SDL_QueryTexture(digit8, NULL, NULL, &w8, &h8);
        SDL_Rect texr8;
        texr8.x = x;
        texr8.y = y;
        texr8.w = 20;
        texr8.h = 30;
        SDL_RenderCopy( m_renderer, digit8, NULL, &texr8);
    }
    if(digit==9)
    {
        int w9, h9;
        SDL_QueryTexture(digit9, NULL, NULL, &w9, &h9);
        SDL_Rect texr9;
        texr9.x = x;
        texr9.y = y;
        texr9.w = 20;
        texr9.h = 30;
        SDL_RenderCopy( m_renderer, digit9, NULL, &texr9);
    }
}

void secondmenu()
{
    int w20, h20;
    SDL_QueryTexture(semenu, NULL, NULL, &w20, &h20);
    SDL_Rect texr20;
    texr20.x = 550;
    texr20.y = 150;
    texr20.w = 300;
    texr20.h = 400;
    SDL_RenderCopy( m_renderer, semenu, NULL, &texr20);
    SDL_RenderPresent(m_renderer);
    SDL_Event *e6 = new SDL_Event();
    bool ex=false;
    while(!ex)
    {
        if( SDL_PollEvent( e6 ) )
        {
            if( e6 ->type != SDL_KEYDOWN )
                {
                    x_m=e6->button.x;
                    y_m=e6->button.y;
                    if(e6->type==SDL_MOUSEBUTTONDOWN&&x_m>600&&x_m<600+180&&y_m>180&&y_m<180+60)
                        ex=true;
                    if(e6->type==SDL_MOUSEBUTTONDOWN&&x_m>600&&x_m<600+180&&y_m>180+130&&y_m<130+180+60)
                    {
                        if(music) mute_music();
                        else unmute_music();
                    }
                    if(e6->type==SDL_MOUSEBUTTONDOWN&&x_m>600&&x_m<600+200&&y_m>180+250&&y_m<180+60+250)
                    {
                        ex=true;
                        stu=1;
                        save_game();
                        fmenu=true;
                        sstart=false;
                        stu=0;
                        name="";
                        aa=40;
                        bb=40;
                        aaa=true;
                        bbb=true;
                        music=true;
                    }
                }
        }
    }
}

void mute_music()
{
    Mix_PauseMusic();
    //Mix_FreeMusic(backgroundSound);
    music=false;
}

void unmute_music()
{
    Mix_ResumeMusic();
    //Mix_PlayMusic(backgroundSound,-1);
    music=true;
}

void start_music()
{
    if(music)Mix_PlayMusic(backgroundSound,-1);
}
