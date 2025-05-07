#include "../../header/GameLoop/Gameplay/Board.h"
#include <iostream>

namespace Gameplay {
	using namespace std;

	Board::Board()
	{
		initialize();
	}

	void Board::initialize()
	{
		initializeBoardImage();
		createBoard();
	}

	void Board::createBoard()
	{
		float cell_width = getCellWidthInBoard();
		float cell_height = getCellHeightInBoard();
		cell = new Cell(cell_width, cell_height, Vector2i(0, 0));
	}

	void Board::initializeBoardImage()
	{
		if (!boardTexture.loadFromFile(boardTexturePath))
		{
			cerr << "Failed to load board texture!" << endl;
			return;
		}

		boardSprite.setTexture(boardTexture);
		boardSprite.setPosition(boardPosition, 0);
		boardSprite.setScale(boardWidth / boardTexture.getSize().x,
			boardHeight / boardTexture.getSize().y);
	}

	float Board::getCellWidthInBoard() const
	{
		return (boardWidth - horizontalCellPadding) / numberOfColumns;
	}

	float Board::getCellHeightInBoard() const
	{
		return (boardHeight - verticalCellPadding) / numberOfRows;
	}

	void Board::render(RenderWindow& window)
	{
		window.draw(boardSprite);
		cell->render(window);
	}
}