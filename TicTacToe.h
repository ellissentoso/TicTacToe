//
// Created by Ellis Sentoso on 2019-11-19.
//
#ifndef SFML_PROJECT_TICTACTOE_H
#define SFML_PROJECT_TICTACTOE_H
#include "../Game/Game.h"
#include "asset.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

// Global Variables
const int HEIGHT = 1080;
const int WIDTH = 1920;
const int SIZE = 200;
const int COL = 3;
const int ROW = 3;
const int X_PIECE = 1;
const int O_PIECE = 2;
const int EMPTY = 0;
const int AI_PIECE = 2;

struct GameData {
    sf::RenderWindow window;
    asset assets;


};

class TicTacToe : public Game {
private:
    sf::RectangleShape shapeArray[3][3]; // SFML array
    sf::RenderWindow window;
    sf::Font font;

    sf::SoundBuffer buffer; // SFML soundbuffer
    sf::SoundBuffer buffer2;
    sf::SoundBuffer bufferwin;
    sf::SoundBuffer bufferstart;

    sf::Sound soundO; // SFML sound
    sf::Sound soundwin;
    sf::Sound soundstart;
    sf::Sound soundX;

    int row_cords[3] = {51, 259, 460}; // coordinates of the grid
    int col_cords[3] = {10, 220, 410};

    int row = 0;
    int col = 0;

    char player1 = 'X';
    char player2 = 'O';
    bool xturn = true;
    bool oturn = false;
    bool gameOver = true;
    bool turnNotYetDone = true;
    bool aiGame = false;

    sf::Text Title; // SFML variables for putting text
    sf::Text Start;
    sf::Text new_;
    sf::Text infos;
    sf::Text ai;

                    // determinds whether someone wins/or not

public:
    char arr[3][3];
    TicTacToe();
    TicTacToe(int width, int height, string title);

    ~TicTacToe() ;
    bool place(char player, int& row, int& col);  // Place marks
    bool checker(char arr[][COL], int row, int col); // check for wins



    void FillShapes(); // Shape display
    void ShowShapes(sf::RenderTarget &window) const; // show shapes
    void clear();


    virtual void start(sf::RenderWindow& window); // start
    virtual void addEvents(sf::RenderWindow &window); // adding events
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void exit();


    void ProcessEvents(sf::RenderWindow &window, TicTacToe& g, int& row, int& col);

//    bool pair(int row, int col, char ai);
};


#endif //SFML_PROJECT_TICTACTOE_H
