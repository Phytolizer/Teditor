#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "font.h"

void scc(int code, const char* call) {
    const char* lparen = strchr(call, '(');
    char* buffer = NULL;
    const char* view = call;

    if (lparen != NULL) {
        buffer = calloc(1, lparen - call + 1);
        memcpy(buffer, call, lparen - call);
        buffer[lparen - call] = '\0';
        view = buffer;
    }

    if (code < 0) {
        fprintf(stderr, "%s: %s\n", view, SDL_GetError());
        free(buffer);
        exit(1);
    }

    free(buffer);
}

#define SCC(Call) scc((Call), #Call)

void* scp(void* ptr, const char* call) {
    const char* lparen = strchr(call, '(');
    char* buffer = NULL;
    const char* view = call;

    if (lparen != NULL) {
        buffer = calloc(1, lparen - call + 1);
        memcpy(buffer, call, lparen - call);
        buffer[lparen - call] = '\0';
        view = buffer;
    }

    if (ptr == NULL) {
        fprintf(stderr, "%s: %s\n", view, SDL_GetError());
        free(buffer);
        exit(1);
    }

    free(buffer);
    return ptr;
}

#define SCP(Call) scp((Call), #Call)

int main(void) {
    SCC(SDL_Init(SDL_INIT_VIDEO));
    SDL_Window* win = SCP(SDL_CreateWindow(
                "Teditor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));
    SDL_Renderer* ren = SCP(SDL_CreateRenderer(
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

        SCC(SDL_SetRenderDrawColor(ren, 0, 0, 0, 255));
        SCC(SDL_RenderClear(ren));
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
