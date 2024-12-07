#include <stdexcept>
#include <string>
#include <cmath>
#include <iostream>

#include "../inc/life.hpp"

// reads the game state from a string
GameBoard::GameBoard(std::string game_state){
    // determine if the game size is a perfect square
    int game_size = game_state.size();
    float root = sqrt(game_size);
    if (ceil(root) != floor(root))
        throw std::invalid_argument("invalid game size");
    this->size = root;
    // parse the game state
    for (int i = 0; i < game_size; i++){
        switch (game_state[i]){
        case '*':
            this->board.push_back(false);
            break;
        case '0':
            this->board.push_back(true);
            break;
        default:
            throw std::invalid_argument("invalid character");
        }
    }
    this->next_state = this->board;
}

// returns if the cell is alive or dead, returns dead if the cell is out of bound
bool GameBoard::get_cell(int row, int col) const{
    if (row < 0 || row > this->size || col < 0 || col > this->size)
        return false;
    else
        return this->board[(row * size) + col];
}

// return the number of neighbors a given cell has
int GameBoard::GameBoard::get_neighbors(int row, int col) const{
    int neighbors {0};
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            if (i != 0 || j != 0)
                neighbors += this->get_cell(row+i, col+j);
        }
    }
    return neighbors;
}

// writes updates the given row in the next state
void GameBoard::update_row(int row_num){
    int row_offset = row_num * size;
    for (int i = 0; i < size; i++){
        bool live = get_cell(row_num, i);
        int neighbors = get_neighbors(row_num, i);
        if (live && (neighbors < 2 || neighbors > 3)){
            this->next_state[row_offset + i] = false;
        }
        else if (!live && neighbors == 3)
            this->next_state[row_offset + i] = true;
    }
}

// updates the game's state
void GameBoard::update(){
    for (int i = 0; i < this->size; i++)
        this->update_row(i);
    this->board = this->next_state;
}

// writes the game's current state to the an output stream
std::ostream& operator<<(std::ostream& out, const GameBoard& game){
    int row {0}, col {0};
    while (row < game.size){
        out << ((game.get_cell(row, col)) ? 'O' : ' ');
        col++;
        if (col == game.size){
            col = 0;
            row++;
            out << "\n";
        }
    }
    return out;
}


