/**
 * @file enums.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Simple document to store enumerated constants
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

enum PieceKind {
    NONE = 0,
    LINE = 1,
    J = 2,
    L = 3,
    SQUARE = 4,
    T = 5,
    S = 6,
    Z = 7,
    BLOCKED = 8
};

enum Direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};
