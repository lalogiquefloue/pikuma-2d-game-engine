#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

const int FPS = 30;
const int MILLISECS_PER_FRAME = 1000 / FPS;

class Game {
	private:
		bool isRunning;
		SDL_Window* window;
		SDL_Renderer* renderer;
		int millisecsPreviousFrame;

	public:
		Game();		// constructor
		~Game();	// destructor

		void Initialize();
		void Run();
		void ProcessInput();
		void Setup();
		void Update();
		void Render();
		void Destroy();

		int windowWidth;
		int windowHeight;
};

#endif