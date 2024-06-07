

#include <stdio.h>
#include "core.h"

#include <SDL.h>

void message(){
  printf("Hello World! dll\n");
  //GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message");
}

SDL_Window* window;
SDL_Event event;
int quit = 1;

void core_create_window(){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("error initializing SDL: %s\n", SDL_GetError());
  }
  // SDL_Window* win = SDL_CreateWindow("GAME",
  //                                      SDL_WINDOWPOS_CENTERED,
  //                                      SDL_WINDOWPOS_CENTERED,
  //                                      1000, 1000, 0);

  window = SDL_CreateWindow("GAME",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    800, 600, 0);
}

void core_loop(){
  while(quit){
    while(SDL_PollEvent(&event) > 0)
    {
      switch(event.type)
      {
        case SDL_QUIT:
          quit = 0;
          break;
      }
    }
    SDL_UpdateWindowSurface(window);
  }
}

void core_close_window(){
  //Destroy window
  SDL_DestroyWindow( window );
  //Quit SDL subsystems
  SDL_Quit();
}