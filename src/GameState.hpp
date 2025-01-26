/**
 * @file GameState.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Definition of the possible states of the game
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

enum class GameState {
    NO_CHANGE,
    START_SCREEN,
    PLAYING,
    GAME_OVER,
    WAITING_FOR_CONNECTION,
    SEARCHING_FOR_SERVER,
    YOU_WON,
    EXIT
};

