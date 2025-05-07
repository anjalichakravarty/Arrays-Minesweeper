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

		//Board Constants
		static const int numberOfRows = 9;
		static const int numberOfColumns = 9;

		const float horizontalCellPadding = 115.f;
		const float verticalCellPadding = 329.f;

		const string boardTexturePath = "assets/textures/board.png";
		Texture boardTexture;
		Sprite boardSprite;

		float getCellWidthInBoard() const;
		float getCellHeightInBoard() const;

		void initializeBoardImage();
		void initialize();
		void createBoard();

	public:

		Board();

		void render(RenderWindow& window);
	};
}