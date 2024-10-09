#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Food.h"
#include "HighScores.h"

using namespace std;

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

const int NumSmallBoxes = 2; // Set the number of small boxes


class Box
{
public:
    RectangleShape shape;
    int direction; // Direction of movement for the box

    // Default constructor
    Box()
        : direction(0) // Set a default direction (you can adjust as needed)
    {
        // Set default properties or leave them uninitialized as needed
    }

    // Parameterized constructor
    Box(float x, float y, float width, float height, int initialDirection)
        : direction(initialDirection)
    {
        shape.setSize(Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(Color::Red); // Adjust the color as needed
    }

    void move(float speed, float offsetY)
    {
        shape.move(speed * direction, offsetY);
    }
};


class Game
{
public:
    Sprite background; // Game background sprite
    Texture bg_texture;
    Sprite background_2;
    Texture bg_texture_2;
    Texture lives_tex;
    Sprite* lives_sprite;
    HighScores high;
    Box smallBoxes[NumSmallBoxes]; // Declare the array here
    int direction = 1; // Variable to store the direction of movement
    Block b;
    Player* P;
    Enemy** E;
    Text scores_text;
    Text level_text;
    int numOfEnemy;
    int no_offoods=44;
    food** foods;

    Game()
    {
        bg_texture_2.loadFromFile("img/background_1.png");
        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2, 1.5);
        background_2.setTexture(bg_texture_2);
        background_2.setPosition(800,0);
        initializeSmallBoxes();
        numOfEnemy = 1;
        E = new Enemy*;
        *E = new Level1Enemy;
        string nm;
        cout << "Enter Name: ";
        cin >> nm;
        P = new Player(nm);

        foods = new food * [no_offoods];
        for (int i = 0; i < no_offoods; i++) {
            foods[i] = new Red_Rectangle;
        }
        foods[0]->spr.setPosition(52, 90);
        foods[1]->spr.setPosition(742, 90);
        foods[2]->spr.setPosition(54, 710);
        foods[3]->spr.setPosition(742, 708);
        foods[28]->spr.setPosition(114, 150);
        foods[29]->spr.setPosition(742, 708);
        foods[30]->spr.setPosition(742, 708);

        int temp1 = 56;
        int temp2 = 90;
        for (int i = 4; i < 10; i++) {
            if (i >=7) {
                foods[i]->spr.setPosition(52, temp2);
                // window.draw(foods[i]->spr);
                temp2 += 80;
            }
            else {
                foods[i]->spr.setPosition(temp1, 90);
                // window.draw(foods[i]->spr);
                temp1 += 80;
            }
        }
        temp1 = 742;
        temp2 = 90;
        for (int i = 10; i < 16; i++) {
            if (i >= 13) {
                foods[i]->spr.setPosition(742, temp2);
                // window.draw(foods[i]->spr);
                temp2 += 80;
            }
            else {
                foods[i]->spr.setPosition(temp1, 90);
                // window.draw(foods[i]->spr);
                temp1 -= 80;
            }
        }
        temp1 = 54;
        temp2 = 710;
        for (int i = 16; i < 22; i++) {
            if (i >= 19) {
                foods[i]->spr.setPosition(54, temp2);
                // window.draw(foods[i]->spr);
                temp2 -= 80;
            }
            else {
                foods[i]->spr.setPosition(temp1, 710);
                // window.draw(foods[i]->spr);
                temp1 += 80;
            }
        }
        temp1 = 742;
        temp2 = 708;
        for (int i = 22; i < 28; i++) {
            if (i >= 25) {
                foods[i]->spr.setPosition(742, temp2);
                // window.draw(foods[i]->spr);
                temp2 -= 80;
            }
            else {
                foods[i]->spr.setPosition(temp1, 708);
                // window.draw(foods[i]->spr);
                temp1 -= 80;
            }
        }


    }

    void initializeSmallBoxes()
    {
        // Add code here to initialize small boxes as needed
        smallBoxes[0] = Box(200.f, 300.f, 30.f, 30.f, 1); // Initial direction is 1 (right)
        smallBoxes[0].shape.setPosition(500, 340);
        smallBoxes[1] = Box(400.f, 500.f, 30.f, 30.f, -1); // Initial direction is -1 (left)
    }

    void start_game()
    {
        //Block b;
        unsigned seed = time(0);
        srand(seed);
        RenderWindow window(VideoMode(1200, 800), title);
        Clock clock;
        float timer = 0;
        Font font;
        font.loadFromFile("Fonts/SEASRN__.ttf");
        std::string scores = "SCORE: ";
        std::string LEVEL =  "LEVEL: ";
        string namestr = "Name:\n" + P->name;
        Text names;
        names.setFont(font);
        names.setString(namestr);
        names.setPosition(900,300);
        names.setCharacterSize(40);
        LEVEL += to_string(P->level);
        level_text.setFont(font);
        level_text.setString(LEVEL);
        level_text.setPosition(900,200);
        level_text.setCharacterSize(40);
        lives_tex.loadFromFile("img/PNG/Power-ups/pill_yellow.png");
        lives_sprite = new Sprite[P->lives];
        for(int i=0 ; i<P->lives ; i++)
        {
            lives_sprite[i].setTexture(lives_tex);
            lives_sprite[i].setPosition(750 - i*25,755);
        }
        scores += to_string(P->score);
        scores_text.setFont(font);
        scores_text.setString(scores);
        scores_text.setPosition(900,100);
        scores_text.setCharacterSize(40);

        

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            delete[] lives_sprite;
            lives_sprite = new Sprite[P->lives];
            for(int i=0 ; i<P->lives ; i++)
            {
                lives_sprite[i].setTexture(lives_tex);
                lives_sprite[i].setPosition(850 - i*25,755);
            }
            scores = "SCORE: ";
            scores += to_string(P->score);
            scores_text.setString(scores);
            LEVEL = "LEVEL:  ";
            LEVEL += to_string(P->level);
            level_text.setString(LEVEL);
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();
                if (e.type == Event::KeyPressed) {
                    if (e.key.code == Keyboard::Right) {
                        if (P->direction == "UP" || P->direction == "DOWN") {
                            if(340 < P->spr.getPosition().y && P->spr.getPosition().y < 470)
                                if ((P->spr.getPosition().x + 60 <= 260 && P->direction == "DOWN") || (P->spr.getPosition().x + 60 <= 740 && P->direction == "UP"))
                                    P->spr.move(60, 0);
                        }
                    }
                    else if (e.key.code == Keyboard::Left) {
                        if (P->direction == "UP" || P->direction == "DOWN") {
                            if (340 < P->spr.getPosition().y && P->spr.getPosition().y < 470) {
                                if ((P->spr.getPosition().x - 60 > 80 && P->direction == "DOWN") || (P->spr.getPosition().x - 60 >= 560 && P->direction == "UP"))
                                    P->spr.move(-60, 0);
                            }
                        }
                    }
                    else if (e.key.code == Keyboard::Up) {
                        if (P->direction == "RIGHT" || P->direction == "LEFT") {
                            if (310 < P->spr.getPosition().x && P->spr.getPosition().x < 500)
                                if ((P->spr.getPosition().y - 60 >= 80 && P->direction == "LEFT") || (P->spr.getPosition().y - 60 >= 560 && P->direction == "RIGHT"))
                                    P->spr.move(0, -60);
                        }
                    }
                    else if (e.key.code == Keyboard::Down) {
                        if (P->direction == "RIGHT" || P->direction == "LEFT") {
                            if (310 < P->spr.getPosition().x && P->spr.getPosition().x < 500)
                                if ((P->spr.getPosition().y + 60 <=260 && P->direction == "LEFT") || (P->spr.getPosition().y + 60 <= 740 && P->direction == "RIGHT"))

                            P->spr.move(0, 60);
                        }
                    }
                    else if (e.key.code == Keyboard::P) {
                        PauseGame(window);
                    }
                }
            }
            CollisionWithWall();
            FoodAccept();
            for(int i=0 ; i<numOfEnemy ; i++){
                E[i]->CollisionWalls(b);
                E[i]->move();
            }
            P->move();
            if(EnemyCollision()){
                gameOver(window);
                return;
            }
            window.clear(Color::Black);
            window.draw(background);
            window.draw(background_2);
            window.draw(scores_text);
            window.draw(level_text);
            window.draw(names);
            for(int i=0 ; i<P->lives ; i++)
                window.draw(lives_sprite[i]);
            for(int i=0 ; i<28 ; i++)
                if(foods[i]->show)
                    window.draw(foods[i]->spr);
            b.draw(window);
            // Move and draw small boxes
            //for (int i = 0; i < NumSmallBoxes; ++i)
            //{
            //    float speed = 2.0f;
            //    smallBoxes[i].move(speed, 0.0f);

            //    if (smallBoxes[i].shape.getPosition().x + smallBoxes[i].shape.getSize().x > window.getSize().x ||
            //        smallBoxes[i].shape.getPosition().x < 0)
            //    {
            //        smallBoxes[i].direction = -smallBoxes[i].direction;
            //    }

            //    window.draw(smallBoxes[i].shape);
            //}
            window.draw(smallBoxes[0].shape);
            P->draw(window);
            for(int i=0 ; i<numOfEnemy ; i++)
                E[i]->draw(window);
            window.display();
        }
    }
    bool EnemyCollision(){
        for(int i=0 ; i<numOfEnemy ; i++)
            if(P->spr.getGlobalBounds().intersects(E[i]->spr.getGlobalBounds())){
                P->lives--;
                if(P->lives == 0)
                    return true;
                else{
                    int liv = P->lives;
                    int scr = P->score;
                    string nm = P->name;
                    delete P;
                    P = new Player(nm);
                    P->lives = liv;
                    P->score = scr;
                    delete E[i];
                    E[i] = new Level1Enemy;
                }
                return false;
            }
        return false;
    }
    void FoodAccept(){
        for(int i=0 ; i<28 ; i++){
            if(!foods[i]->show)
                continue;
            if(P->spr.getGlobalBounds().intersects(foods[i]->spr.getGlobalBounds())) {
                P->score += foods[i]->score();
            }
        }
    }

    void gameOver(RenderWindow& window){
        high.add(P->name,P->score);
        Texture gm;
        Sprite over;
        gm.loadFromFile("img/PNG/UI/game_over.png");
        over.setTexture(gm);
        over.setPosition(450,300);
        over.setScale(2,2);
        while (window.isOpen()){
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();
            }
            window.clear(Color::Black);
            window.draw(over);
            window.display();
        }
        
        
    }
    void CollisionWithWall() {
        for (int i = 0; i < b.size; i++) {
            if (P->spr.getGlobalBounds().intersects(b.walls[i].getGlobalBounds())) {
                // cout << "is true\n";
                if (i % 2 == 0 && P->direction == "LEFT") {
                    cout << P->spr.getPosition().y << endl;

                    P->spr.rotate(90);
                    P->spr.setPosition(b.walls[i].getGlobalBounds().left + b.walls[i].getGlobalBounds().width + P->spr.getGlobalBounds().width, b.walls[i + 1].getGlobalBounds().top + b.walls[i + 1].getGlobalBounds().height + P->spr.getGlobalBounds().height);
                    P->direction = "DOWN";
                }
                else if (i % 2 == 1 && P->direction == "DOWN") {
                    P->spr.rotate(90);
                    P->spr.setPosition(b.walls[i-1].getGlobalBounds().left + b.walls[i-1].getGlobalBounds().width, b.walls[i].getGlobalBounds().top - 10);
                    P->direction = "RIGHT";
                }
                else if (i % 2 == 0 && P->direction == "RIGHT") {
                    // cout << P->spr.getPosition().y << endl;
            
                    P->spr.rotate(90);
                    P->spr.setPosition(b.walls[i].getGlobalBounds().left - P->spr.getGlobalBounds().width, b.walls[i + 1].getGlobalBounds().top - P->spr.getGlobalBounds().height - 10);
                    P->direction = "UP";
                }
                else if (i % 2 == 1 && P->direction == "UP") {

                    P->spr.rotate(90);
                    P->spr.setPosition(b.walls[i - 1].getGlobalBounds().left , b.walls[i].getGlobalBounds().top + b.walls[i].getGlobalBounds().height + 10);
                    P->direction = "LEFT";
                }
            }
        }
    }
    void PauseGame(RenderWindow& window)
    {
        Clock clock;
        float timer=0;
        int selected=0;
        Font font;
        font.loadFromFile("Fonts/arial.ttf");
        Text option_text[5];
        std::string instructions;
        Texture op[5];
        Sprite options[5];
        Sprite background_2;
        Texture bg_texture_2;
        background_2.setTexture(bg_texture_2);
        background_2.setPosition(780,0);
        bg_texture_2.loadFromFile("img/background_1.png");
        op[0].loadFromFile("img/PNG/UI/buttonBlue.png");
        op[1].loadFromFile("img/PNG/UI/buttonGreen.png");
        op[2].loadFromFile("img/PNG/UI/buttonRed.png");
        op[3].loadFromFile("img/PNG/UI/buttonYellow.png");
        op[4].loadFromFile("img/PNG/UI/buttonRed.png");
        for(int i=0,j=180 ; i<5 ; i++,j+=100)
        {
            options[i].setTexture(op[i]);
            options[i].setPosition(300,j);
        }
        // font.loadFromFile("Fonts/arial.ttf");
        for(int i=0 ; i<5 ; i++)
        {
            option_text[i].setFont(font);
            option_text[i].setCharacterSize(25);
            option_text[i].setFillColor(Color::Black);
            option_text[i].setStyle(Text::Bold);
            option_text[i].setPosition(options[i].getPosition());
            option_text[i].move(0,5);
        }
        instructions = "Ye Instructions hain bc\nParho ja kar Final Qareeb hain\n";
        option_text[0].setString("       RESUME");
        option_text[1].setString("     NEW GAME");
        option_text[2].setString("  INSTRUCTIONS");
        option_text[3].setString("    HIGH SCORE");
        option_text[4].setString("          EXIT");
        while(window.isOpen())
        {
            // std::cout << "in loop\n";
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            Event e;
                while (window.pollEvent(e))
                {
                    // if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    // {    window.close(); //close the game  
                    if(e.type == Event::KeyPressed)
                    {
                        if(e.key.code == Keyboard::P)
                        {   
                            return;
                        }
                        else if(e.key.code == Keyboard::Down)
                        {
                            option_text[selected].setFillColor(Color::Black);
                            selected++;
                            if(selected>4)
                                selected = 0;
                            option_text[selected].setFillColor(Color::Red);
                        }
                        else if(e.key.code == Keyboard::Up)
                        {
                            option_text[selected].setFillColor(Color::Black);
                            selected--;
                            if(selected<0)
                                selected = 4;
                            option_text[selected].setFillColor(Color::Red);
                        }
                        else if(e.key.code == Keyboard::Enter)
                        {
                            if(selected==0)
                            {
                                return;
                            }
                            else if(selected==1)
                            {
                                // window.close();
                                // char* name;
                                // name =  M.get_name();
                                // Game g(name);
                                // bool gameover = g.start_game();
                                // if(gameover)
                                //     M.game_over();
                                // else return;
                            }
                            else if(selected == 2)
                            {
                                // window.close();
                                // Menu M;
                                // M.show_instructions(window);
                            }
                            else if(selected==3)
                            {
                                // // window.close();
                                // Menu M;
                                // M.show_highscore(window);
                            }
                            else if(selected==4)
                                window.close();
                        }
                    }                      	    
                }
            window.clear(Color::Black); //clears the screen
    	    // window.setMouseCursorVisible(0);
            window.draw(background);  // setting background
            window.draw(background_2);
            for(int i=0 ; i<5 ; i++)
            {
                window.draw(options[i]);
                window.draw(option_text[i]);
            }
            window.display();
        }
    }
};



