#pragma once

#include <SFML/Graphics.hpp>
#include "../../header/UI/UI Elements/Button/Buttons.h"
#include "../../header/Event/EventPollingManager.h"

using namespace UIElements;

namespace Gameplay
{
    enum class CellState
    {
        HIDDEN,
        OPEN,
        FLAGGED,
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
        MINE,
    };

    class Cell
    {
    private:
        CellState current_cell_state;
        CellType cell_type;
        sf::Vector2i position;
        int mines_around;

        const float cell_top_offset = 274.f;
        const float cell_left_offset = 583.f;
        const int tile_size = 32;
        const int slice_count = 12;
        const std::string cell_texture_path = "assets/textures/cells.jpeg";
        Button* cell_button;

        void initialize(float width, float height, sf::Vector2i position);
        sf::Vector2f getCellScreenPosition() const;
        void setCellTexture();

    public:
        Cell(float width, float height, sf::Vector2i position);
        ~Cell() = default;

        void render(sf::RenderWindow& window);

        //Getters, Setters
        CellState getCellState() const;
        void setCellState(CellState state);
        CellType getCellType() const;
        void setCellType(CellType type);
        sf::Vector2i getCellPosition();
    };
}