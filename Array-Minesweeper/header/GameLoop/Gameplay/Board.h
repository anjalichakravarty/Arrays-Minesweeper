#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "../../header/GameLoop/Gameplay/Cell.h"
#include "../../header/Event/EventPollingManager.h"

namespace Gameplay
{

    class Board
    {
    private:
        // Board Constants
        static const int numberOfRows = 9;
        static const int numberOfColumns = 9;
        static const int minesCount = 9;

        // State and View Members
        Cell* cell;

        const float horizontalCellPadding = 115.f;
        const float verticalCellPadding = 329.f;

        // Board Rendering
        const float boardWidth = 866.f;
        const float boardHeight = 1080.f;
        const float boardPosition = 530.f;
        const std::string boardTexturePath = "assets/textures/board.png";
        sf::Texture boardTexture;
        sf::Sprite boardSprite;

        // Randomization
        std::default_random_engine randomEngine;
        std::random_device randomDevice;

        // Private helper methods
        void initialize();
        void initializeBoardImage();

        void createBoard();
        float getCellWidthInBoard() const;
        float getCellHeightInBoard() const;
        void deleteBoard();

    public:
        Board();
        ~Board();

        // Game flow methods
        void render(sf::RenderWindow& window);

    };
}