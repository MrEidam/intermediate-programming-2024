#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>

// set v cells
struct Board{
    std::vector<bool> cells;
    std::size_t width;
    std::size_t height;
};

bool isAlive(const Board& board, std::size_t x, std::size_t y){
    if(x < 0 || y < 0 || x >= board.width || y >= board.height)
        return false;

    return board.cells[board.width*y + x];
}

// ⬛⬜

void print_board(const Board& board){
    for(size_t y = 0; y < board.height; y++){
        for(size_t x = 0; x < board.width; x++){
            if(isAlive(board, x, y))
                std::cout << "⬜";
            else
                std::cout << "⬛";
        }
        std::cout << std::endl;
    }
}

int neighbour_count(const Board& board, std::size_t x, std::size_t y){
    int out = 0;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2;j++){
            if(i==0 && j==0) continue;
            if(isAlive(board, x + j, y + i))
                out++;
        }
    }
    return out;
}

Board game_step(const Board& board){
    Board newBoard = board;
    for(size_t y = 0; y < board.height; y++){
        for(size_t x = 0; x < board.width; x++){
            if((!isAlive(board, x, y) && neighbour_count(board, x, y) == 3) ||
                (isAlive(board, x, y) && ((neighbour_count(board, x, y) == 2) || (neighbour_count(board, x, y) == 3)))){
                newBoard.cells[board.width*y + x] = true;
            }else{
                newBoard.cells[board.width*y + x] = false;
            }
        }
    }
    return newBoard;
}

void clear_screen(){
    std::cout << "\033[2J\033[1;1H";
}

Board parse_board(const std::string& path);
Board default_board();

int main(int argc, const char** argv){
    using namespace std::chrono_literals;
    Board board;
    if(argc > 1){
        board = parse_board(argv[1]);
    } else {
        board = default_board();
    }

    while(true){
        board = game_step(board);
        clear_screen();
        print_board(board);
        std::this_thread::sleep_for(10ms);
    }
    
    return 0;
}

Board parse_board(const std::string& path){
    Board board;
    // If a filename is provided, load board from file.
    std::ifstream infile(path);
    if(!infile){
        std::cerr << "Error: Cannot open file " << path << std::endl;
        abort();
    }
    
    // Read board dimensions from the first two lines.
    infile >> board.width >> board.height;
    // Discard the rest of the line after reading numbers.
    std::string line;
    std::getline(infile, line);
    
    // Skip potential empty lines before board pattern.
    while(std::getline(infile, line) && line.empty()){
        // continue skipping
    }
    
    // Allocate board cells (initialize to dead).
    board.cells.assign(board.width * board.height, false);
    
    // Process the first non-empty board line that was already read.
    std::size_t row = 0;
    if(!line.empty() && row < board.height){
        for(std::size_t col = 0; col < line.size() && col < board.width; ++col){
            if(line[col] == '#')
                board.cells[row * board.width + col] = true;
        }
        ++row;
    }
    
    // Continue reading remaining lines.
    while(row < board.height && std::getline(infile, line)){
        if(line.empty())
            continue;
        for(std::size_t col = 0; col < line.size() && col < board.width; ++col){
            if(line[col] == '#')
                board.cells[row * board.width + col] = true;
        }
        ++row;
    }
    return board;
}

Board default_board(){
    Board board;
    board.width = 200;
    board.height = 54;
    board.cells.assign(board.width * board.height, false);
    
    // Default board pattern as provided.
    std::vector<std::string> defaultPattern = {
        "                                      #",
        "                                    # #",
        "                          ##      ##            ##",
        "                         #   #    ##            ##",
        "              ##        #     #   ##",
        "              ##        #   # ##    # #",
        "                        #     #       #",
        "                         #   #    ",
        "                          ##      "
    };
    
    // Place the default pattern into the top rows of the board.
    for(std::size_t row = 0; row < defaultPattern.size() && row < board.height; ++row){
        const std::string &line = defaultPattern[row];
        for(std::size_t col = 0; col < line.size() && col < board.width; ++col){
            if(line[col] == '#')
                board.cells[row * board.width + col] = true;
        }
    }

    return board;
}
