#include <SFML/Graphics.hpp>
#pragma once
#include "game.h"

class Menu {
public:

   // Fonts and Text
    int selected;
    Font font;
    Text option_text[5];
    Texture back;
    Sprite background;
    Texture op[5];
    Sprite options[5];

    HighScores high;
     //Music music;
    Menu();
    void show_instructions(RenderWindow& window);
    char* get_name();
    string score_to_string(int score);
    void show_highscore(RenderWindow& window);
    void game_over();
    int display_menu();
    virtual ~Menu() {}
};


Menu::Menu()
{
    //constructors body
    back.loadFromFile("./img/backgroundnew.jpg");
   // background.setTexture(back.Texture);
    op[0].loadFromFile("img/PNG/UI/buttonBlue.png");
    op[1].loadFromFile("img/PNG/UI/buttonGreen.png");
    op[2].loadFromFile("img/PNG/UI/buttonRed.png");
    op[3].loadFromFile("img/PNG/UI/buttonYellow.png");
    op[4].loadFromFile("img/PNG/UI/buttonRed.png");
    for (int i = 0, j = 120, k = 20; i < 5; i++, j += 100)
    {
       // options[i].setTexture(op[i].Texture);
        options[i].setPosition(200, j + i * k);
        options[i].setScale(1.2, 1.2);
    }
    font.loadFromFile("Fonts/Oswald-Regular.ttf");
    // font.loadFromFile("Fonts/SEASRN__.ttf");
    for (int i = 0; i < 5; i++)
    {
        option_text[i].setFont(font);
        option_text[i].setCharacterSize(30);
        option_text[i].setScale(1.3, 1);
        option_text[i].setFillColor(Color::Black);
        option_text[i].setStyle(Text::Bold);
        option_text[i].setPosition(options[i].getPosition());
        option_text[i].move(0, 5);
    }
    selected = 1;
    option_text[1].setFillColor(Color::Red);
    option_text[0].setString("       RESUME");
    option_text[1].setString("     NEW GAME");
    option_text[2].setString("  INSTRUCTIONS");
    option_text[3].setString("    HIGH SCORE");
    option_text[4].setString("          EXIT");
  //  if (!music.openFromFile("Sound/newmusic.ogg"))
    //    std::cout << "NOT OPENED\n";
}

void Menu::show_instructions(RenderWindow& window)
{
    Texture local_back;
    Sprite backg;
    local_back.loadFromFile("img/instructions.png");
    backg.setTexture(local_back);
    Texture arr[2];
    Sprite arrows[2];
    arr[0].loadFromFile("img/PNG/UI/arrow keys.png");
    arrows[0].setTexture(arr[0]);
    arrows[0].move(50, 0);
    arrows[0].setScale(0.5, 0.5);
    arr[1].loadFromFile("img/PNG/CARS/Instruc_car.png");
    arrows[1].setTexture(arr[1]);
    arrows[1].move(250, 200);
    arrows[1].setScale(1.25, 1);
    
    Text instruct[5];
    for (int i = 0; i < 5; i++)
    {
        instruct[i].setFont(font);
        instruct[i].setCharacterSize(35);
        instruct[i].setFillColor(Color::Yellow);
        instruct[i].setStyle(Text::Bold);
    }
    instruct[0].move(5, 15);
    instruct[0].setString("Use Arrow Keys to Navigate");
    instruct[1].move(40, 600);
    instruct[1].setString("Pick up all the gift boxes in the arena to");
    instruct[2].move(130, 650);
    instruct[2].setString("proceed to the next level");
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
            {
                // window.close();
                return;
                // display_menu();
            }
            else if (e.type == Event::KeyPressed)
            {
                if (e.key.code == Keyboard::Escape)
                {
                    // window.close();
                    return;
                    // display_menu();
                }
            }
        }

        // instruct.setString(instructions);
        window.clear(Color::Black); //clears the screen
        window.setMouseCursorVisible(0);
        window.draw(backg);  // setting background
        for (int i = 0; i < 2; i++)
            window.draw(arrows[i]);
        for (int i = 0; i < 5; i++)
            window.draw(instruct[i]);
        window.display();
    }
}

char* Menu::get_name()
{
    Texture backgrd, tex;
    Text enter;
    enter.setFont(font);
    enter.setCharacterSize(30);
    enter.setFillColor(Color::Red);
    enter.setStyle(Text::Bold);
    enter.setString("Enter Name:");
    enter.setPosition(150, 150);
    backgrd.loadFromFile("img/background2.jpg");
    Sprite spr;
    spr.setTexture(backgrd);
    tex.loadFromFile("img/PNG/UI/buttonBlue.png");
    Sprite input;
    input.setTexture(tex);
    input.setPosition(150, 200);
    input.setScale(1.25, 1.5);
    spr.setScale(1.75, 2);
    Text name_input;
    name_input.setFont(font);
    name_input.setCharacterSize(30);
    name_input.setFillColor(Color::Black);
    name_input.setStyle(Text::Bold);
    name_input.setPosition(input.getPosition());
    name_input.move(10, 7);
    srand(time(0));
    Clock clock;
    float timer = 0.0;
    RenderWindow window(VideoMode(600, 500), title);
    char* the_name = new char[13];
    for (int i = 0; i < 13; i++)
        the_name[i] = '\0';
    int i = 0;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        //std::cout << timer << std::endl;
        clock.restart();
        timer += time;
        name_input.setString(the_name);
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::KeyPressed)
            {
                if (i < 12)
                {
                    if (e.key.code == Keyboard::A) the_name[i++] = 'A';
                    else if (e.key.code == Keyboard::B) the_name[i++] = 'B';
                    else if (e.key.code == Keyboard::C) the_name[i++] = 'C';
                    else if (e.key.code == Keyboard::D) the_name[i++] = 'D';
                    else if (e.key.code == Keyboard::E) the_name[i++] = 'E';
                    else if (e.key.code == Keyboard::F) the_name[i++] = 'F';
                    else if (e.key.code == Keyboard::G) the_name[i++] = 'G';
                    else if (e.key.code == Keyboard::H) the_name[i++] = 'H';
                    else if (e.key.code == Keyboard::I) the_name[i++] = 'I';
                    else if (e.key.code == Keyboard::J) the_name[i++] = 'J';
                    else if (e.key.code == Keyboard::K) the_name[i++] = 'K';
                    else if (e.key.code == Keyboard::L) the_name[i++] = 'L';
                    else if (e.key.code == Keyboard::M) the_name[i++] = 'M';
                    else if (e.key.code == Keyboard::N) the_name[i++] = 'N';
                    else if (e.key.code == Keyboard::O) the_name[i++] = 'O';
                    else if (e.key.code == Keyboard::P) the_name[i++] = 'P';
                    else if (e.key.code == Keyboard::Q) the_name[i++] = 'Q';
                    else if (e.key.code == Keyboard::R) the_name[i++] = 'R';
                    else if (e.key.code == Keyboard::S) the_name[i++] = 'S';
                    else if (e.key.code == Keyboard::T) the_name[i++] = 'T';
                    else if (e.key.code == Keyboard::U) the_name[i++] = 'U';
                    else if (e.key.code == Keyboard::V) the_name[i++] = 'V';
                    else if (e.key.code == Keyboard::W) the_name[i++] = 'W';
                    else if (e.key.code == Keyboard::X) the_name[i++] = 'X';
                    else if (e.key.code == Keyboard::Y) the_name[i++] = 'Y';
                    else if (e.key.code == Keyboard::Z) the_name[i++] = 'Z';
                    else if (e.key.code == Keyboard::Space) the_name[i++] = ' ';
                }
                if (e.key.code == Keyboard::BackSpace && i > 0) the_name[--i] = '\0';
                if (e.key.code == Keyboard::Enter)
                {
                    window.close();
                    return the_name;
                }
            }
        }
        window.clear(Color::Black); //clears the screen
        window.setMouseCursorVisible(0);
        window.draw(spr);  // setting background
        window.draw(input);
        window.draw(enter);
        window.draw(name_input);
        window.display();
    }
    return NULL;
}

string Menu::score_to_string(int score)
{
    int size = 0;
    int temp = score;
    while (temp != 0)
    {
        temp /= 10;
        size++;
    }
    char* answer = new char[size + 1];
    answer[size] = '\0';
    for (int i = size - 1; i >= 0; i--)
    {
        answer[i] = (score % 10) + '0';
        score /= 10;
    }
    return answer;
}

void Menu::show_highscore(RenderWindow& window)
{
    Texture boxx;
    Sprite box;
    boxx.loadFromFile("img/PNG/UI/white.png");
    box.setTexture(boxx);
    box.setPosition(140, 60);
    box.setScale(1, 1.7);
    // font.loadFromFile("Fonts/Oswald-Regular.ttf");
    Texture medal_tex[3];
    Sprite medals[3];
    for (int i = 0; i < 3; i++)
    {
        medal_tex[i].loadFromFile("img/PNG/UI/medals.png");
        medals[i].setTexture(medal_tex[i]);
        medals[i].setTextureRect(IntRect(34 * i, 0, 34.33, 43));
    }
    medals[0].setPosition(180, 175);
    medals[1].setPosition(180, 220);
    medals[2].setPosition(180, 270);
    // RenderWindow window(VideoMode(350, 655), title);
    Text highnames[high.size], highscores[high.size];
    Text heading;
    Font f;
    f.loadFromFile("Fonts/Pacifico.ttf");
    heading.setFont(f);
    heading.setCharacterSize(35);
    heading.move(5, 15);
    heading.setFillColor(Color::Blue);
    heading.setStyle(Text::Bold);
    heading.setString("HIGHSCORES");
    heading.setPosition(200, 100);
    for (int i = 0; i < high.size; i++)
    {
        highnames[i].setFont(font);
        highnames[i].setCharacterSize(25);
        highnames[i].move(5, 15);
        highnames[i].setFillColor(Color::Black);
        highnames[i].setStyle(Text::Bold);
        highnames[i].setString(high.names[i]);
        highnames[i].setPosition(230, 25 * (i + 1) + i * 25 + 150);
        highscores[i].setFont(font);
        highscores[i].setCharacterSize(25);
        highscores[i].move(5, 15);
        highscores[i].setFillColor(Color::Black);
        highscores[i].setStyle(Text::Bold);
        highscores[i].setString(score_to_string(high.scores[i]));
        highscores[i].setPosition(430, 25 * (i + 1) + i * 25 + 150);
    }
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
            {
                // window.close();
                // display_menu();
                return;
            }
            else if (e.type == Event::KeyPressed)
            {
                if (e.key.code == Keyboard::Escape)
                {
                    // window.close();
                    // display_menu();
                    return;
                }
            }
        }
        window.clear(Color::Black); //clears the screen
        window.setMouseCursorVisible(0);
        window.draw(background);  // setting background
        window.draw(box);
        window.draw(heading);
        for (int i = 0; i < high.size; i++)
        {
            window.draw(highnames[i]);
            window.draw(highscores[i]);
        }
        for (int i = 0; i < 3; i++)
            window.draw(medals[i]);
        window.display();
    }
}

void Menu::game_over() {
    Texture t;
    t.loadFromFile("img/PNG/UI/game_over.png");
    Sprite spr;
    spr.setTexture(t);
    spr.setPosition(20, 200);
    spr.setScale(2, 2);
    RenderWindow window(VideoMode(350, 655), title);
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
        window.clear(Color::Black); //clears the screen
        window.setMouseCursorVisible(0);
        window.draw(background);  // setting background
        window.draw(spr);
        window.display();
    }
}

int Menu::display_menu() {
    // add functionality of all the menu options here
    RenderWindow window(VideoMode(650, 800), title);
    Texture boxx;
    Sprite box;
    boxx.loadFromFile("img/PNG/UI/box.png");
    box.setTexture(boxx);
    box.setPosition(140, 60);
    box.setScale(1, 1.7);
   // music.play();
   // music.setLoop(1);
    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game  
            if (e.type == Event::KeyPressed)
            {
                if (e.key.code == Keyboard::Down)
                {
                    option_text[selected].setFillColor(Color::Black);
                    selected++;
                    if (selected > 4)
                        selected = 0;
                    option_text[selected].setFillColor(Color::Red);
                }
                else if (e.key.code == Keyboard::Up)
                {
                    option_text[selected].setFillColor(Color::Black);
                    selected--;
                    if (selected < 0)
                        selected = 4;
                    option_text[selected].setFillColor(Color::Red);
                }
                else if (e.key.code == Keyboard::Enter)
                {
                    if ( selected == 4)
                    {
                        window.close();
                        return selected;
                    }
                    else if (selected == 1 || selected == 0) {
                        window.close();
                        Game g;
                        g.start_game();
                    }
                    else if (selected == 2)
                    {
                        show_instructions(window);
                    }
                    else if (selected == 3)
                    {
                        show_highscore(window);
                    }
                }
            }
        }

        window.clear(Color::Black); //clears the screen
        window.setMouseCursorVisible(0);
        window.draw(background);  // setting background
        window.draw(box);
        for (int i = 0; i < 5; i++)
        {
            window.draw(options[i]);
            window.draw(option_text[i]);
        }
        window.display();
    }
    return 4;
    //if Start game option is chosen 
         //g.start_game();
}