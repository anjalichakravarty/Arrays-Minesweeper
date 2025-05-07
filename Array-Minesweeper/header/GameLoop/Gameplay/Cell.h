#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElements/Button/Button.h"
#include "../../header/Event/EventPollingManager.h"

using namespace UIElements;
using namespace sf;

namespace Gameplay
{
	enum class CellState
	{
		HIDDEN,
		OPEN,
		FLAGGED
	};

	enum class CellType
	{
		EMPTY,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		MINE	
	};

	class Cell
	{
	private:
		//Cell data members
		CellState current_cell_state;
		CellType cell_type;

		Vector2i position;

		const int tile_size = 128;
		const int slice_count = 12;
		const string cell_texture_path = "assets/textures/cells.jpeg";

		const float cell_top_offset = 274.0f;
		const float cell_left_offset = 583.0f;

		Vector2f getCellScreenPosition() const;

		Button* cell_button;

		void initialize(float width, float height, Vector2i position);

	public:

		Cell(float width, float height, Vector2i position);
		~Cell() = default;

		void setCellTexture();

		void render(RenderWindow& window);

		//Getters, setters
		CellState getCellState() const;
		void setCellState(CellState state);
		CellType getCellType() const;
		void setCellType(CellType type);
	};
}
