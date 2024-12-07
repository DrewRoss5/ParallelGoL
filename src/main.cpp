#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

#include "../inc/life.hpp"

int main(int argc, char** argv){
    // validate user arguments
    if (argc != 2){
        std::cout << "This game takes exactly one argument" << std::endl;
        return 1;
    }
    // read the provided game file
    std::ifstream file(argv[1]);
    if (!file.good()){
        std::cout << "error: unable to read the game file" << std::endl;
        return 1;
    }
    std::string line, game_state;
    while (std::getline(file, line))
        game_state += line;
    file.close();
    GameBoard game(game_state);
    while (true){
        std::cout << game << std::endl;
        game.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("clear");
    }
}