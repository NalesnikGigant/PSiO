#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <vector>
#include <chrono>
#include <thread>
class object : public sf::Sprite {
public:
    void ruszaj() {}
    bool gra();
    int punkt = 5;
};
class platforma : public object {
public:
    sf::Texture blat;
    platforma(int x, int y);

};
class bohater : public object {
public:
    sf::Texture boh;
    bohater();
    void ruszaj(sf::Time czas, platforma makaron);
    void skok(platforma makaron);
    void zatrzymaj(platforma makaron);
    void granice();
    void wygrana(object f);
private:
    int v_x = 25;
};
class smok : public object {
public:
    sf::Texture drake;
    smok(int x);
    void spotkanie(platforma makaron);
    void telepotracja();
    void ruszaj(sf::Time czas);
    void sp³oniêcie(bohater& Kosc);
    friend class lose;
protected:
    int v_x = 50;
};
class win : public object {
public:
    sf::Texture ween;
    win();
};
class lose : public object {
public:
    sf::Texture los;
    lose();
};

