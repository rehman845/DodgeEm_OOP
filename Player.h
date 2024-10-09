#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;
using namespace std;
class Player {
public:
    Texture tex;
    Sprite spr;
    string name;
    int lives;
    int level;
    float speed;
    int score;
    string direction;
    Player(string nm = "") {
        tex.loadFromFile("img/PNG/CARS/Player_car.png");
        spr.setTexture(tex);
        spr.rotate(270);
        lives = 3;
        spr.setPosition(500, 740);
        direction = "RIGHT";
        speed = 0.2;
        level = 1;
        name = nm;
    }
    void move() {
        if (direction == "RIGHT") {
            spr.move(speed, 0);
        }
        else if (direction == "LEFT") {
            spr.move(-speed, 0);
        }
        else if (direction == "UP") {
            spr.move(0, -speed);

        }
        else if (direction == "DOWN") {
            spr.move(0, speed);
        }

    }
    void draw(RenderWindow& window) {
        window.draw(spr);
    }

};
