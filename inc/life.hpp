#pragma once

#include <vector>
#include <iostream>

class GameBoard{
    public:
        GameBoard(std::string board);
        void update();
        friend std::ostream& operator<<(std::ostream&, const GameBoard&);

    private:
        int size;
        std::vector<bool> board;
        std::vector<bool> next_state;
        bool get_cell(int row, int col) const;
        int get_neighbors(int row, int col) const;
        void update_row(int row_no);
};