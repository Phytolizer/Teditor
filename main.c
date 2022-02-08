#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void scc(int code) {
    if (code < 0) {
        fprintf(stderr, "SDL error: %s\n", SDL_GetError());
        exit(1);
    }
}

void* scp(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "SDL error: %s\n", SDL_GetError());
        exit(1);
    }

    return ptr;
}

int main(void) {
    scc(SDL_Init(SDL_INIT_VIDEO));
    SDL_Window* win = scp(SDL_CreateWindow(
                "Teditor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));
    SDL_Renderer* ren = scp(SDL_CreateRenderer(
                win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

    bool quit = false;

    while (!quit) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }

        scc(SDL_SetRenderDrawColor(ren, 0, 0, 0, 255));
        scc(SDL_RenderClear(ren));
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
