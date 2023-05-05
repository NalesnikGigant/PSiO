
#include "klasy.h"

int main()
{
    srand(time_t(NULL));
    sf::Clock clock;
    sf::Time czas;
    sf::RenderWindow window(sf::VideoMode(1000, 600), "My window", sf::Style::Titlebar | sf::Style::Close);
    //Tworzenie obiektów
    std::vector<std::unique_ptr<sf::Drawable>> smoki;
    for (int i = 0; i < 5; i++) {
        smoki.emplace_back(std::make_unique<smok>(i));
    }
    std::vector<std::unique_ptr<sf::Drawable>> blaty;
    for (int i = 0; i < 8; i++) {
        blaty.emplace_back(std::make_unique<platforma>(150*i,70*i));
    }
    bohater Kosc;
    bohater* b;
    while (window.isOpen()) {
        window.setFramerateLimit(60);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color::Black);
        window.draw(Kosc);
        czas = clock.getElapsedTime();
        for (auto& rec : smoki) {
            window.draw(*rec);
            smok& obw = dynamic_cast<smok&>(*rec);
            obw.telepotracja();
            obw.ruszaj(czas);
            for (auto& rec : blaty) {
                platforma& kox = dynamic_cast<platforma&>(*rec);
                obw.spotkanie( kox);                
            }
            obw.spłonięcie(Kosc);
        }   
        for (auto& hok : blaty) {
            window.draw(*hok);
            platforma& kox = dynamic_cast<platforma&>(*hok);
        }

        for (auto& rec : blaty) {
            platforma& kox = dynamic_cast<platforma&>(*rec);
            Kosc.skok(kox);
            Kosc.ruszaj(czas, kox);
            Kosc.zatrzymaj(kox);
        }
        czas = clock.restart();
        Kosc.granice();
        object f;
        f.gra() == true;
        if (f.gra() == false) {
            window.clear(sf::Color::Black);
            lose cos;
            window.draw(cos);
        }
        window.display();
        Kosc.wygrana(f);
        

    }
    return 0;
}