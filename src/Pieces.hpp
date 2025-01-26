/**
 * @file Menu.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Defines, for each piece, a class to handle a matrix to generate the pieces in the grid. It defines all the possible positions of each piece for roation purposes
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

// https://gamedev.stackexchange.com/questions/208367/how-is-rotation-defined-in-a-tetris-game

class LinePiece : public Piece {
private:
    std::vector<std::vector<bool>> masks = {
        {
            0, 0, 0, 0,
            0, 0, 0, 0,
            1, 1, 1, 1,
            0, 0, 0, 0
        },
        {
            0, 0, 1, 0,
            0, 0, 1, 0,
            0, 0, 1, 0,
            0, 0, 1, 0
        }
    };
    int currentMask = 0;
public:
    LinePiece() : LinePiece({0, 0}) {}

    LinePiece(sf::Vector2u position) : Piece(position, PieceKind::LINE) {
        setMasks(masks);
        mask = masks[0];
    }
};

class SquarePiece : public Piece {
private:
    std::vector<std::vector<bool>> masks = {
        {
            0, 0, 0, 0,
            0, 1, 1, 0,
            0, 1, 1, 0,
            0, 0, 0, 0
        }
    };
    int currentMask = 0;
public:
    SquarePiece() : SquarePiece({0, 0}) {}

    SquarePiece(sf::Vector2u position) : Piece(position, PieceKind::SQUARE) {
        setMasks(masks);
        mask = masks[0];
    }
};

class JPiece : public Piece {
private:
    std::vector<std::vector<bool>> masks = {
        {
            0, 0, 0, 0,
            1, 1, 1, 0,
            0, 0, 1, 0,
            0, 0, 0, 0
        },
        {
            0, 1, 0, 0,
            0, 1, 0, 0,
            1, 1, 0, 0,
            0, 0, 0, 0
        },
        {
            1, 0, 0, 0,
            1, 1, 1, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        },
        {
            0, 1, 1, 0,
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 0, 0, 0
        }
    };
    int currentMask = 0;
public:
    JPiece() : JPiece({0, 0}) {}

    JPiece(sf::Vector2u position) : Piece(position, PieceKind::J) {
        setMasks(masks);
        mask = masks[0];
    }
};

class LPiece : public Piece {
private:
    std::vector<std::vector<bool>> masks = {
        {
            0, 0, 0, 0,
            1, 1, 1, 0,
            1, 0, 0, 0,
            0, 0, 0, 0
        },
        {
            1, 1, 0, 0,
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 0, 0, 0
        },
        {
            0, 0, 1, 0,
            1, 1, 1, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        },
        {
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 1, 1, 0,
            0, 0, 0, 0
        }
    };
    int currentMask = 0;
public:
    LPiece() : LPiece({0, 0}) {}

    LPiece(sf::Vector2u position) : Piece(position, PieceKind::L) {
        setMasks(masks);
        mask = masks[0];
    }
};

class SPiece : public Piece {
private:
    std::vector<std::vector<bool>> masks = {
        {
            0, 0, 0, 0,
            0, 1, 1, 0,
            1, 1, 0, 0,
            0, 0, 0, 0
        },
        {
            0, 1, 0, 0,
            0, 1, 1, 0,
            0, 0, 1, 0,
            0, 0, 0, 0
        }
    };
    int currentMask = 0;
public:
    SPiece() : SPiece({0, 0}) {}

    SPiece(sf::Vector2u position) : Piece(position, PieceKind::S) {
        setMasks(masks);
        mask = masks[0];
    }
};

class ZPiece : public Piece {
private:
    std::vector<std::vector<bool>> masks = {
        {
            0, 0, 0, 0,
            1, 1, 0, 0,
            0, 1, 1, 0,
            0, 0, 0, 0
        },
        {
            0, 0, 1, 0,
            0, 1, 1, 0,
            0, 1, 0, 0,
            0, 0, 0, 0
        }
    };
    int currentMask = 0;
public:
    ZPiece() : ZPiece({0, 0}) {}

    ZPiece(sf::Vector2u position) : Piece(position, PieceKind::Z) {
        setMasks(masks);
        mask = masks[0];
    }
};

class TPiece : public Piece {
private:
    std::vector<std::vector<bool>> masks = {
        {
            0, 0, 0, 0,
            1, 1, 1, 0,
            0, 1, 0, 0,
            0, 0, 0, 0
        },
        {
            0, 1, 0, 0,
            1, 1, 0, 0,
            0, 1, 0, 0,
            0, 0, 0, 0
        },
        {
            0, 1, 0, 0,
            1, 1, 1, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        },
        {
            0, 1, 0, 0,
            0, 1, 1, 0,
            0, 1, 0, 0,
            0, 0, 0, 0
        }
    };
    int currentMask = 0;
public:
    TPiece() : TPiece({0, 0}) {}

    TPiece(sf::Vector2u position) : Piece(position, PieceKind::T) {
        setMasks(masks);
        mask = masks[0];
    }
};