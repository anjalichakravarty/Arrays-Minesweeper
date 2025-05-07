#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "../../header/GameLoop/Gameplay/Cell.h"
#include "../../header/Event/EventPollingManager.h"

namespace Gameplay {
	using namespace sf;
	using namespace std;

	class Board {
	private:

		Cell* cell;

		const float boardWidth = 866.0f;
		const float boardHeight = 1080.0f;
		const float boardPosition = 530.0f;

		const string boardTexturePath = "assets/textures/board.png";
		Texture boardTexture;
		Sprite boardSprite;

		void initializeBoardImage();
		void initialize();
		void createBoard();

	public:

		Board();

		void render(RenderWindow& window);
	};
}