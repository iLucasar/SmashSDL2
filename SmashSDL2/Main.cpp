/*



 ad88888ba   88b           d88         db         ad88888ba   88        88      ad88888ba   88888888ba,    88            ad888888b,
d8"     "8b  888b         d888        d88b       d8"     "8b  88        88     d8"     "8b  88      `"8b   88           d8"     "88
Y8,          88`8b       d8'88       d8'`8b      Y8,          88        88     Y8,          88        `8b  88                   a8P
`Y8aaaaa,    88 `8b     d8' 88      d8'  `8b     `Y8aaaaa,    88aaaaaaaa88     `Y8aaaaa,    88         88  88                ,d8P"
  `"""""8b,  88  `8b   d8'  88     d8YaaaaY8b      `"""""8b,  88""""""""88       `"""""8b,  88         88  88              a8P"
        `8b  88   `8b d8'   88    d8""""""""8b           `8b  88        88             `8b  88         8P  88            a8P'
Y8a     a8P  88    `888'    88   d8'        `8b  Y8a     a8P  88        88     Y8a     a8P  88      .a8P   88           d8"
 "Y88888P"   88     `8'     88  d8'          `8b  "Y88888P"   88        88      "Y88888P"   88888888Y"'    88888888888  88888888888


    Un progetto dei programmatori Luca Bonaldo e Chiara Mancarella, con la collaborazione del tecnico grafico Jacopo Pianon

    Studenti del liceo Giuseppe Veronese di Borgo San Giovanni, Chioggia, rispettivamente delle classi IV s.a., III s.a. e IV s.a.

*/


// LISTA LIBRERIE

/*
*
*   iostream    : per il prompt sulla console di dati di debug
*   Windows.h   : gestione colori
*   Console.h   : Libreria gestione console di debug
*   Engine.h    : Engine di gestione
*   Tile.h      : Sistema tile
*   Character.h : Sistemma personaggi
*   Sprite.h    : Sistema sprite
*   SDL.h       : libreria base sdl motore grafico
*
*/

#define SDL_MAIN_HANDLED
#include <SDL.h>


#include <iostream>
#include <Windows.h>
#include "Console.h"

#include "Tile.h"
#include "Entity.h"

#include "Character.h"

#include "Engine.h"

// FILE INCLUSI

/*
* 
*   Errors.h    : File contenente la definizione degli errori
* 
*/

#include "Errors.h"

int main(int argc, char* argv[])
{

    // Inizializzazione SDL2

    Engine::start();

    // Creazione della finestra e del renderer

    Engine* GameEngine = new Engine("Gioco", Vector2f(1280, 720));

    // Tile di prova

    GameEngine->addEntity("Character", &(Entity(GameEngine->getRenderer(), "character.png")));

    SDL_Event event;

    while (GameEngine->isRunning())
    {

        // Update fisica

        if (GameEngine->shouldUpdate())
        {

            // Rudimenti di controllo

            SDL_PollEvent(&event);

            switch (event.type) {
            case SDL_QUIT:
                GameEngine->stop();
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    GameEngine->getEntity("Character")->getPos()->x++;
                    break;
                case SDLK_LEFT:
                    GameEngine->getEntity("Character")->getPos()->x--;
                    break;
                }
                }

        }

        // Update rendering

        GameEngine->GFXUpdate();
        
    }

    // Pulizia

    delete(GameEngine);

    return EXIT_SUCCESS;

}