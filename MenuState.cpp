#include "MenuState.h"
#include "Game.h"
#include "PlayingState.h"
#include <iostream>
#include <cmath> // For std::sin

MenuState::MenuState()
    : selectedOption_(0)
    , font_(nullptr)
    , useCustomCursor_(false) {

    auto& rm = ResourceManager::getInstance();

    if (rm.hasFont("default")) {
        font_ = &rm.getFont("default");
    }

    // Create background
    background_.setSize(sf::Vector2f(1280.0f, 720.0f));
    background_.setFillColor(sf::Color(210, 180, 140)); // Light brown

    // --- 1. TITLE (TOP) ---
    if (font_) {
        titleText_.setFont(*font_);
        titleText_.setString("CARROT CHASE");
        titleText_.setCharacterSize(100);     
        titleText_.setFillColor(sf::Color(101, 67, 33)); // Dark Brown
        titleText_.setOutlineColor(sf::Color(255, 255, 255)); // White Outline
        titleText_.setOutlineThickness(5.0f);
        titleText_.setStyle(sf::Text::Bold);

        sf::FloatRect textBounds = titleText_.getLocalBounds();
        titleText_.setOrigin(textBounds.left + textBounds.width / 2.0f,
                             textBounds.top + textBounds.height / 2.0f);
        
        // Position: Top
        titleText_.setPosition(640.0f, 120.0f);
    }

    // --- 2. START TEXT (BOTTOM) ---
    if (font_) {
        startText_.setFont(*font_);
        startText_.setString("Let's Start");
        startText_.setCharacterSize(60);
        startText_.setFillColor(sf::Color(101, 67, 33));
        startText_.setOutlineColor(sf::Color(255, 255, 255));
        startText_.setOutlineThickness(5.0f);
        startText_.setStyle(sf::Text::Bold);
        
        sf::FloatRect bounds = startText_.getLocalBounds();
        startText_.setOrigin(bounds.left + bounds.width / 2.0f, 
                             bounds.top + bounds.height / 2.0f);
        
        // Position: Bottom
        startText_.setPosition(640.0f, 580.0f);
    }

    // --- 3. BUNNY (EXACT MIDDLE) ---
    if (rm.hasTexture("player_jump")) {
        bunnySprite_.setTexture(rm.getTexture("player_jump"));
        sf::FloatRect bounds = bunnySprite_.getGlobalBounds();
        bunnySprite_.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
        
        // Position: Center of the gap (350.0f)
        bunnySprite_.setPosition(640.0f, 350.0f); 
        
        // Scale: 3/4th of the big size (1.875)
        bunnySprite_.setScale(1.875f, 1.875f);
    }

    // Custom cursor setup...
    if (rm.hasTexture("cursor_hand")) {
        cursorSprite_.setTexture(rm.getTexture("cursor_hand"));
        cursorSprite_.setScale(0.8f, 0.8f);
        useCustomCursor_ = true;
    }
}

void MenuState::handleInput(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space ||
            event.key.code == sf::Keyboard::Enter) {
            if (game_) {
                auto state = std::make_unique<PlayingState>();
                state->setGame(game_);
                game_->changeState(std::move(state));
            }
        }
        else if (event.key.code == sf::Keyboard::Escape) {
            if (game_) {
                game_->quit();
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
        if (game_) {
            auto state = std::make_unique<PlayingState>();
            state->setGame(game_);
            game_->changeState(std::move(state));
        }
    }
}

void MenuState::update(float deltaTime) {
    // Breathing animation
    static float time = 0.0f;
    time += deltaTime;
    float scale = 1.0f + std::sin(time * 2.0f) * 0.05f; 
    titleText_.setScale(scale, scale);
    startText_.setScale(scale, scale);
}

void MenuState::render(sf::RenderWindow& window) {
    window.draw(background_);

    if (bunnySprite_.getTexture()) {
        window.draw(bunnySprite_);
    }

    if (font_) {
        window.draw(titleText_);
        window.draw(startText_);
    }

    if (useCustomCursor_) {
        window.setMouseCursorVisible(false);
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        cursorSprite_.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        window.draw(cursorSprite_);
    }
    else {
        window.setMouseCursorVisible(true);
    }
}