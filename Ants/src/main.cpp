#define SDL_MAIN_HANDLED

#include <iostream>
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "Environment.h"
#include "Renderer.h"
#include <time.h>
#include "Timer.h"
#include "Agent.h"
#include "Food.h"
#include "Anthill.h"
#include "SillyAnt.h"
#include "Ant.h"
#include "AntWithRules.h"

static unsigned int windowWidth() { return 1024; }

static unsigned int windowHeight() { return 700; }

/// <summary>
/// called each time a key is pressed.
/// </summary>
/// <param name="key">The key.</param>
/// <param name="environment">The environment.</param>
void onKeyPressed(char key, Environment *environment) {
    std::cout << "Key pressed: " << key << std::endl;
    switch (key) {
        case 'f': {
            new Food(environment, environment->randomPosition(), MathUtils::random(200, 2000));
            break;
        }
        case 'd': {
            if (!environment->getAllInstancesOf<Agent>().empty()) {
                environment->getAllInstancesOf<Agent>().front()->setStatus(destroy);
            }
            break;
        }
        case 'a': {
            auto anthill = new Anthill(environment, environment->randomPosition());
            for (int i = 0; i < 50; ++i) {
                new AntWithRules(environment, anthill);
            }
            break;
        }
        default: {
            break;
        }
    }
}

/// <summary>
/// Called at each time step.
/// </summary>
void onSimulate() {
    Agent::simulate();
}

/// <summary>
/// The main program.
/// </summary>
/// <param name="argc">The number of arguments.</param>
/// <param name="argv">The arguments.</param>
/// <returns></returns>
int main(int /*argc*/, char ** /*argv*/) {
    // 1 - Initialization of SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS/* | SDL_INIT_AUDIO*/) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }
    // 2 - Initialization of the renderer
    Renderer::initialize(windowWidth(), windowHeight());

    // 3 - Creation of an environment
    Environment environment(windowWidth(), windowHeight());

    // 4 - We change the seed of the random number generator
    srand((unsigned int) time(NULL));

    // The main event loop...
    SDL_Event event;
    bool exit = false;
    while (!exit) {
        // 1 - We handle events
        while (SDL_PollEvent(&event)) {
            if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == 'q')) {
                ::std::cout << "Exit signal detected" << ::std::endl;
                exit = true;
                break;
            }
            if (event.type == SDL_KEYDOWN) {
                onKeyPressed((char) event.key.keysym.sym, &environment);
            }
        }
        // 2 - We update the simulation
        Timer::update(0.5);
        onSimulate();
        // 3 - We render the scene
        Renderer::getInstance()->flush();
    }

    std::cout << "Shutting down renderer..." << std::endl;
    Renderer::finalize();

    std::cout << "Shutting down SDL" << std::endl;
    SDL_Quit();

    Agent::finalize();

    return 0;
}
