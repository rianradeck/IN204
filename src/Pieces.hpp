class LinePiece : public Piece {
public:
    LinePiece() : LinePiece({0, 0}) {}

    LinePiece(sf::Vector2u position) : Piece(position, PieceKind::LINE) {
        mask = {
            1, 0, 0, 0,
            1, 0, 0, 0,
            1, 0, 0, 0,
            1, 0, 0, 0
        };
    }
};

class JPiece : public Piece {
public:
    JPiece() : JPiece({0, 0}) {}

    JPiece(sf::Vector2u position) : Piece(position, PieceKind::J) {
        mask = {
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 1, 0, 0,
            1, 1, 0, 0
        };
    }
};

class LPiece : public Piece {
public:
    LPiece() : LPiece({0, 0}) {}

    LPiece(sf::Vector2u position) : Piece(position, PieceKind::L) {
        mask = {
            1, 0, 0, 0,
            1, 0, 0, 0,
            1, 0, 0, 0,
            1, 1, 0, 0
        };
    }
};

class SquarePiece : public Piece {
public:
    SquarePiece() : SquarePiece({0, 0}) {}

    SquarePiece(sf::Vector2u position) : Piece(position, PieceKind::SQUARE) {
        mask = {
            1, 1, 0, 0,
            1, 1, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };
    }
};

class TPiece : public Piece {
public:
    TPiece() : TPiece({0, 0}) {}

    TPiece(sf::Vector2u position) : Piece(position, PieceKind::T) {
        mask = {
            1, 1, 1, 0,
            0, 1, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };
    }
};

class SPiece : public Piece {
public:
    SPiece() : SPiece({0, 0}) {}

    SPiece(sf::Vector2u position) : Piece(position, PieceKind::S) {
        mask = {
            0, 1, 1, 0,
            1, 1, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };
    }
};

class ZPiece : public Piece {
public:
    ZPiece() : ZPiece({0, 0}) {}

    ZPiece(sf::Vector2u position) : Piece(position, PieceKind::Z) {
        mask = {
            1, 1, 0, 0,
            0, 1, 1, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };
    }
};