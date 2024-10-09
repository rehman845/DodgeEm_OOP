#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;


class Block {
public:

    int size = 8;
    RectangleShape walls[32];



    Block() {


        //sf::RenderWindow window(sf::VideoMode(900, 800), "SFML Blocks Example");

        int px = 30, py = 60;

        int size1 = 250;//240    ,    580 
        for (int i = 1; i <= size; i += 2) {
            walls[i - 1].setSize(Vector2f(10, size1));
            walls[i - 1].setPosition(Vector2f(px, py));
            walls[i - 1].setFillColor(Color(200, 0, 0));


            walls[i].setSize(Vector2f(size1, 10));
            walls[i].setPosition(Vector2f(px, py));
            walls[i].setFillColor(Color(200, 0, 0));


            px += 60;
            py += 60;
            size1 -= 50;

        }
        cout << walls[7].getGlobalBounds().left + walls[7].getGlobalBounds().width << endl;

        size = 16;
        size1 = 250;
        px = 30 + 500;
        py = 60;

        for (int i = 9; i <= size; i += 2, px -= 10) {
            px += size1;
            walls[i - 1].setSize(Vector2f(10, size1));
            walls[i - 1].setPosition(Vector2f(px, py));
            walls[i - 1].setFillColor(Color(200, 0, 0));


            px -= size1;
            walls[i].setSize(Vector2f(size1, 10));
            walls[i].setPosition(Vector2f(px, py));
            walls[i].setFillColor(Color(200, 0, 0));


            py += 60;
            size1 -= 50;

        }
        size = 24;
        px = 30;
        py = 500;
        size1 = 250;

        for (int i = 17; i <= size; i += 2, py -= 10) {

            walls[i - 1].setFillColor(Color(200, 0, 0));
            walls[i - 1].setSize(Vector2f(10, size1));
            walls[i - 1].setPosition(Vector2f(px, py));

            walls[i].setFillColor(Color(200, 0, 0));
            walls[i].setSize(Vector2f(size1, 10));
            walls[i].setPosition(Vector2f(px, py + size1));

            px += 60;

            size1 -= 50;
        }

        size = 32;
        px = 30 + 500;
        py = 500;
        size1 = 250;

        for (int i = 25; i <= size; i += 2, size1 -= 50) {

            walls[i - 1].setSize(Vector2f(10, size1));
            walls[i - 1].setPosition(Vector2f(px + size1, py));
            walls[i - 1].setFillColor(Color(200, 0, 0));

            walls[i].setSize(Vector2f(size1, 10));
            walls[i].setPosition(Vector2f(px + 10, py + size1));
            walls[i].setFillColor(Color(200, 0, 0));

            px -= 10;
            py -= 10;
        }


    }
public:
    void draw(RenderWindow& window) {
        // Draw all blocks
        for (int i = 0; i < size; i++)
            window.draw(walls[i]);
    }
};