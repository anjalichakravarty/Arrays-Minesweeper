#include "../../header/GameLoop/Gameplay/Board.h"
#include "../../header/GameLoop/Gameplay/GameplayManager.h"
#include <iostream>

namespace Gameplay
{
    Board::Board()
    {
        initialize();
    }

    Board::~Board()
    {
        deleteBoard();
    }

    void Board::initialize()
    {
        initializeBoardImage();
        createBoard();
    }

    void Board::initializeBoardImage()
    {
        if (!boardTexture.loadFromFile(boardTexturePath))
        {
            std::cerr << "Failed to load board texture!" << std::endl;
            return;
        }
        boardSprite.setTexture(boardTexture);
        boardSprite.setPosition(boardPosition, 0);
        boardSprite.setScale(boardWidth / boardTexture.getSize().x, boardHeight / boardTexture.getSize().y);
    }


    void Board::createBoard()
    {
        float cell_width = getCellWidthInBoard();
        float cell_height = getCellHeightInBoard();
        cell = new Cell(cell_width, cell_height, sf::Vector2i(0, 0));
    }

    void Board::deleteBoard()
    {
        delete cell;
    }

    void Board::render(sf::RenderWindow& window)
    {
        window.draw(boardSprite);
        cell->render(window);

    }

    float Board::getCellWidthInBoard() const
    {
        return (boardWidth - horizontalCellPadding) / numberOfColumns;
    }

    float Board::getCellHeightInBoard() const
    {
        return (boardHeight - verticalCellPadding) / numberOfRows;
    }
}
