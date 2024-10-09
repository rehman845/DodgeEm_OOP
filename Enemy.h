#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Block.h"

using namespace sf;
using namespace std;

class Enemy {
public:
    Texture tex;
    Sprite spr;
    float speed;
    string direction;
    bool directionchanged;
    Enemy() {
        tex.loadFromFile("img/PNG/CARS/PolsCar2.png");
        spr.setTexture(tex);
        spr.setPosition(300, 715);
        spr.setScale(0.1,0.1);
        direction = "LEFT";
        speed = 0.1;
        directionchanged = false;
    }
    void draw(RenderWindow& window){
        window.draw(spr);
    }
    void CollisionWalls(Block& b) {
        for (int i = 0; i < b.size; i++) {
            if (spr.getGlobalBounds().intersects(b.walls[i].getGlobalBounds())) {
                if (i % 2 == 0 && direction == "LEFT") {
                    // cout << spr.getPosition().y << endl;

                    spr.rotate(90);
                    spr.setPosition(b.walls[i].getGlobalBounds().left + b.walls[i].getGlobalBounds().width + spr.getGlobalBounds().width + 10, b.walls[i + 1].getGlobalBounds().top - spr.getGlobalBounds().height - 10);
                    direction = "UP";
                }
                else if (i % 2 == 1 && direction == "DOWN") {
                    spr.rotate(90);
                    spr.setPosition(b.walls[i - 1].getGlobalBounds().left - spr.getGlobalBounds().width - 10, b.walls[i].getGlobalBounds().top - spr.getGlobalBounds().height - 10);
                    direction = "LEFT";
                }
                else if (i % 2 == 0 && direction == "RIGHT") {

                    spr.rotate(90);
                    spr.setPosition(b.walls[i].getGlobalBounds().left - spr.getGlobalBounds().width - 10, b.walls[i + 1].getGlobalBounds().top + spr.getGlobalBounds().height + 10);
                    direction = "DOWN";
                }
                else if (i % 2 == 1 && direction == "UP") {
                    spr.rotate(90);
                    spr.setPosition(b.walls[i - 1].getGlobalBounds().left + b.walls[i - 1].getGlobalBounds().width + spr.getGlobalBounds().width + 10, b.walls[i].getGlobalBounds().top + b.walls[i].getGlobalBounds().height + spr.getGlobalBounds().height+10);
                    direction = "RIGHT";
                }
            }
        }
    }
    virtual bool destroyEnemy()
    {
        return 0;
    }
    virtual void move() = 0;
};

class Level1Enemy: public Enemy {
public:
    Level1Enemy(): Enemy() {
        speed = 0.1;
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
        if(direction == "RIGHT"){
            if (310 < spr.getPosition().x && spr.getPosition().x < 500){
                if (!directionchanged){
                    int d = rand() % 2;
                    if(d == 1) {//up movement
                        cout << "enemy y = " << spr.getPosition().y << endl;
                        if (spr.getPosition().y - 60 >= 80 ) {
                            cout << "moved up\n";
                            spr.move(0, -60);
                            directionchanged = true;
                        }
                    }
                    if( d== 0 || !directionchanged) {
                        cout << "enemy y = " << spr.getPosition().y << endl;
                        if (spr.getPosition().y + 60 <260){
                            
                            cout << "moved down\n";

                            spr.move(0, 60);
                            directionchanged = true;
                        }
                    }
                }
            }
            else
                directionchanged = false;
        }
        else if(direction == "LEFT"){
            if (310 < spr.getPosition().x && spr.getPosition().x < 500){
                if (!directionchanged) {
                    int d = rand() % 2;
                    if(d == 1) {//up movement
                        cout << "enemy y = " << spr.getPosition().y << endl;
                        if ( spr.getPosition().y - 60 > 560) {
                            cout << "moved upleft\n";
                            spr.move(0, -60);
                            directionchanged = true;
                        }
                    }
                    if(d == 0 || !directionchanged) {
                        cout << "enemy y = " << spr.getPosition().y << endl;
                        if (spr.getPosition().y + 60 < 740){
                            cout << "moved downright\n";

                            spr.move(0, 60);
                            directionchanged = true;
                        }
                    }
                }
            }
            else
                directionchanged = false;
        }
    }


};