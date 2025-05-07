#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElements/Button/Button.h"
#include "../../header/Event/EventPollingManager.h"

using namespace UIElements;
using namespace sf;

namespace Gameplay
{
	class Cell
	{
	private:
		Vector2i position;

		const int tile_size = 128;
		const int slice_count = 12;
		const string cell_texture_path = "assets/textures/cell.jpeg";

		Button* cell_button;

		void initialize(float width, float height, Vector2i position);

	public:

		Cell(float width, float height, Vector2i position);
		~Cell() = default;

		void render(RenderWindow& window);
	};
}
