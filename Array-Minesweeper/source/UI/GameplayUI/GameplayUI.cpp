#include <iostream>
#include "../../header/UI/GameplayUI/GameplayUI.h"
#include "../../../header/GameLoop/Gameplay/GameplayManager.h"

namespace UI {

    GameplayUI::GameplayUI(GameplayManager* gameplay_manager) { initialize(gameplay_manager); }

    void GameplayUI::initialize(GameplayManager* gameplay_manager)
    {
        this->gameplay_manager = gameplay_manager;
        loadFonts();
        initializeTexts();
        initializeButton();
        registerButtonCallback();
    }

    void GameplayUI::loadFonts()
    {
        if (!bubbleBobbleFont.loadFromFile("assets/fonts/bubbleBobble.ttf"))
            std::cerr << "Error loading bubbleBobble font!" << std::endl;
        
        if (!dsDigibFont.loadFromFile("assets/fonts/DS_DIGIB.ttf"))
            std::cerr << "Error loading DS_DIGIB font!" << std::endl;
    }

    void GameplayUI::registerButtonCallback()
    {
        restartButton->registerCallbackFunction([this](UIElements::MouseButtonType buttonType)
            {
                RestartButtonCallback(buttonType);
            }
        );
    }

    void GameplayUI::initializeTexts()
    {
        // Mine Text
        mineText.setFont(dsDigibFont);
        mineText.setCharacterSize(fontSize);
        mineText.setFillColor(textColor);
        mineText.setPosition(mineTextLeftOffset, minetextTopOffset);
        mineText.setString("000");


        // Time Text
        timeText.setFont(dsDigibFont);
        timeText.setCharacterSize(fontSize);
        timeText.setFillColor(textColor);
        timeText.setPosition(timeTextLeftOffset, timeTextTopOffset);
        timeText.setString("000");
    }

    std::string GameplayUI::formatScore(int text)
    {
        if (text < 10)
            return "00" + std::to_string(text);
        else if (text < 100)
            return "0" + std::to_string(text);
        return std::to_string(text);
    }

    void GameplayUI::initializeButton()
    {
        restartButton = new Button(restartButtonTexturePath, sf::Vector2f(restartButtonLeftOffset, restartButtonTopOffset), buttonWidth, buttonHeight);
    }

    void GameplayUI::RestartButtonCallback(MouseButtonType mouse_button_type)
    {
        if (mouse_button_type == MouseButtonType::LEFT_MOUSE_BUTTON)
        {
            Sound::SoundManager::PlaySound(Sound::SoundType::BUTTON_CLICK);
            gameplay_manager->restartGame();
        }
    }

    void GameplayUI::update(int remaining_mines, int remaining_time, EventPollingManager& eventManager, sf::RenderWindow& window)
    {
        mineText.setString(formatScore(remaining_mines));
        timeText.setString(formatScore(remaining_time));
        restartButton->handleButtonInteractions(eventManager, window);
    }

    void GameplayUI::render(sf::RenderWindow& window)
    {
        window.draw(mineText);
        window.draw(timeText);
        restartButton->render(window);
    }
}

