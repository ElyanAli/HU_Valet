#pragma once
#include <iostream>
#include "welcomeScreen.hpp"
#include <SDL.h>


// #include "levelButton.hpp"

// #include "changeColourButton.hpp"
using namespace std;

welcomeScreen::welcomeScreen(){}
welcomeScreen::welcomeScreen(levelButton levelButt, changeColourButton B1, changeColourButton B2)
    : level_buttons(levelButt), button_1(B1), button_2(B2), window(nullptr), renderer(nullptr)
    {
        //creating window
        window = SDL_CreateWindow("HU Valet", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
        // Creating renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    }

    void welcomeScreen::displayOptions()
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set background color to white
        SDL_RenderClear(renderer);
        
        // Render welcome screen elements (simple text)
        SDL_Color textColor = {0, 0, 0, 255}; // Black color
        // Set the font size and style
        int fontSize = 24;
        SDL_Surface* surfaceMessage = nullptr;


         // Create a font using SDL's built-in font
        // SDL_Rect welcomeRect;
        // welcomeRect.x = 100;
        // welcomeRect.y = 200;

        const char* welcomeMessage = "Welcome to HU Valet";
        surfaceMessage = SDL_CreateRGBSurface(0, 200, 50, 32, 0, 0, 0, 0);
        SDL_FillRect(surfaceMessage, NULL, SDL_MapRGB(surfaceMessage->format, 255, 255, 255));
        // SDL_Color textColor = {0, 0, 0, 255}; // Black color

        /// Create a surface for rendering text
        SDL_Surface* textSurface = SDL_CreateRGBSurface(0, 200, 50, 32, 0, 0, 0, 0);
        SDL_FillRect(textSurface, nullptr, SDL_MapRGB(textSurface->format, 255, 255, 255));
        SDL_Texture* welcomeTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        // Get the width and height of the rendered text
        SDL_Rect welcomeRect;
        welcomeRect.x = 100;
        welcomeRect.y = 200;
        welcomeRect.w = textSurface->w;
        welcomeRect.h = textSurface->h;

        // Render text texture
        SDL_RenderCopy(renderer, welcomeTexture, nullptr, &welcomeRect);

        // Cleanup
        SDL_DestroyTexture(welcomeTexture);
        SDL_FreeSurface(textSurface);

        // Present the renderer
        SDL_RenderPresent(renderer);


    }

    //destructor
    welcomeScreen::~welcomeScreen() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    
