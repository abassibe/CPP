//
// Created by Daniel HADLEY on 2019-04-06.
//

#include "../includes/GraphicalView.hpp"
#include "../includes/ConsoleView.hpp"
#include "../includes/HostModule.hpp"
#include "../includes/OSModule.hpp"
#include "../includes/DateModule.hpp"
#include "../includes/CPUModule.hpp"
#include "../includes/RAMModule.hpp"
#include "../includes/NetworkModule.hpp"
#include "../includes/ConsoleView.hpp"
#include "../includes/CPUActivityModule.hpp"
#include "../includes/RAMActivityModule.hpp"
#include <SFML/Graphics.hpp>

GraphicalView::GraphicalView() : _module(), _moduleShapes() {
}

GraphicalView::GraphicalView(GraphicalView const &copy) {
    (void) copy;
}

GraphicalView::~GraphicalView() {
}

GraphicalView &GraphicalView::operator=(GraphicalView const &copy) {
    (void) copy;
    return (*this);
}

void GraphicalView::updateModule() {
    for (std::vector<IMonitorModule *>::iterator it = _module.begin(); it != _module.end(); it++)
        (*it)->updateData();
}

void GraphicalView::render() {

    enum Direction {Down, Left, Right, Up};

    sf::Vector2i source(1, Down);

    sf::Font font;
    if (!font.loadFromFile("american_captain/American_Captain.otf")) {
        std::cout << "Can't find the font file" << std::endl;
    }

    sf::RectangleShape moduleRectangle(sf::Vector2f(800, 150));
    moduleRectangle.setOutlineThickness(10.f);
    moduleRectangle.setFillColor(sf::Color(9, 49, 69));
    moduleRectangle.setOutlineColor(sf::Color(239, 212, 105));

    sf::RectangleShape progressBar;
    progressBar.setFillColor(sf::Color(235, 201, 68));

    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);

    sf::Text text2;
    text2.setFont(font);
    text2.setFillColor(sf::Color(239, 212, 105));

    sf::Texture owlTexture;
    sf::Sprite owlImage;

    if (!owlTexture.loadFromFile("owlsprite.png")) {
        std::cout << "Could not load owl image" << std::endl;
    }
    owlImage.setTexture(owlTexture);

    while (_window->isOpen()) {
        sf::Event myEvent;
        while (_window->pollEvent(myEvent)) {
            switch (myEvent.type) {
                case sf::Event::Closed:_window->close();
                    break;
                case sf::Event::Resized:
                    std::cout << "New window width " << myEvent.size.width << " new window height "
                              << myEvent.size.height << std::endl;
                    break;
                case sf::Event::KeyPressed:
                    if (myEvent.key.code == sf::Keyboard::Up)
                        source.y = Up;
                    else if (myEvent.key.code == sf::Keyboard::Down)
                        source.y = Down;
                    else if (myEvent.key.code == sf::Keyboard::Right)
                        source.y = Right;
                    else if (myEvent.key.code == sf::Keyboard::Left)
                        source.y = Left;
                    break;
                default:break;
            }
        }

        source.x++;
        if (source.x * (276 / 2) >= (int) owlTexture.getSize().x) {
            source.x = 0;
        }

        owlImage.setTextureRect(sf::IntRect(source.x * (276 / 3), source.y * (100 / 3), 276 / 3, 100 / 3));
        owlImage.setPosition(2000, 375);


        for (std::vector<IMonitorModule *>::iterator it = _module.begin(); it != _module.end(); it++) {

            if (HostModule *host = dynamic_cast<HostModule *>(*it)) {

                moduleRectangle.setPosition(host->getX(), host->getY());


                _window->draw(moduleRectangle);

                std::string value("Host name: ");
                value += host->getHostName();
                value += "\nLogin name: ";
                value += host->getLoginName();
                value += "\nDomaine name: ";
                value += host->getDomaineName();


                text.setString(value);
                text.setPosition(host->getX() + 10, host->getY());
                _window->draw(text);


            } else if (OSModule *os = dynamic_cast<OSModule *>(*it)) {
                moduleRectangle.setPosition(os->getX(), os->getY());
                _window->draw(moduleRectangle);

                std::string value;
                value += os->getProductName();
                value += os->getProductVersion();
                value += os->getBuildVersion();

                std::string systemValue;
                systemValue = "System Name: " + os->getSysName();
                systemValue += "\nRelease Version: " + os->getReleaseVersion();
                systemValue += "\nMachine architecture: " + os->getMachineArchitecture();


                text.setString(value);
                text.setPosition(os->getX() + 10, os->getY());
                _window->draw(text);

                text2.setString(systemValue);
                text2.setPosition(150, (_window->getSize().y / 4) * 3);
                _window->draw(text2);

            } else if (DateModule *date = dynamic_cast<DateModule *>(*it)) {
                moduleRectangle.setPosition(date->getX(), date->getY());
                _window->draw(moduleRectangle);

                std::string value("Date: ");
                value += date->getDate();
                value += "Time: ";
                value += date->getTime();

                text.setString(value);
                text.setPosition(date->getX() + 10, date->getY());
                _window->draw(text);

            } else if (CPUModule *cpu = dynamic_cast<CPUModule *>(*it)) {
                moduleRectangle.setPosition(cpu->getX(), cpu->getY());
                _window->draw(moduleRectangle);


                std::string value("Model: ");
                value += cpu->getModel();
                value += "\nClock speed: ";
                value += cpu->getClockSpeed();
                value += "\nCore: ";
                value += std::to_string(cpu->getCore());
                value += "\nCPU Activity: ";
                value += std::to_string(cpu->getActivity());
                value += "%";


                text.setString(value);
                text.setPosition(cpu->getX() + 10, cpu->getY());
                _window->draw(text);
            } else if (RAMModule *ram = dynamic_cast<RAMModule *>(*it)) {
                moduleRectangle.setPosition(ram->getX(), ram->getY());
                _window->draw(moduleRectangle);


                std::string value("RAM Capacity: ");
                value += std::to_string(ram->getRAMCapacity());
                value += "Go";
                value += "\nRAM Activity: ";
                value += std::to_string(ram->getRAMActivity());
                value += "%";


                text.setString(value);
                text.setPosition(ram->getX() + 10, ram->getY());
                _window->draw(text);

            } else if (NetworkModule *net = dynamic_cast<NetworkModule *>(*it)) {
                moduleRectangle.setPosition(net->getX(), net->getY());
                _window->draw(moduleRectangle);


                std::string value("Input: ");
                value += net->getInputActivity();
                value += "\nOutput: ";
                value += net->getOutputActivity();


                text.setString(value);
                text.setPosition(net->getX() + 10, net->getY());
                _window->draw(text);


            } else if (CPUActivityModule *cpu = dynamic_cast<CPUActivityModule *>(*it)) {
                moduleRectangle.setPosition(cpu->getX(), cpu->getY());
                _window->draw(moduleRectangle);


                std::list<float> list = cpu->getPreviousActivity();

                int size = 78;
                for (std::list<float>::reverse_iterator it2 = list.rbegin(); it2 != list.rend() && size > 0; it2++) {
                    float percent = *it2 / 100;
                    if (percent > 1.f)
                        percent = 1.f;

                    progressBar.setSize(sf::Vector2f(moduleRectangle.getSize().x / 78,
                                                     moduleRectangle.getSize().y * percent));
                    progressBar.setPosition(cpu->getX() + ((size - 1) * (moduleRectangle.getSize().x / 78)),
                                            cpu->getY());

                    _window->draw(progressBar);
                    size--;
                }
            } else if (RAMActivityModule *ram = dynamic_cast<RAMActivityModule *>(*it)) {
                moduleRectangle.setPosition(ram->getX(), ram->getY());
                _window->draw(moduleRectangle);

                std::list<float> list = ram->getPreviousActivity();
                int size = 78;
                for (std::list<float>::reverse_iterator it2 = list.rbegin(); it2 != list.rend() && size > 0; it2++) {
                    float percent = *it2 / 100;
                    if (percent > 1.f)
                        percent = 1.f;

                    progressBar.setSize(sf::Vector2f(moduleRectangle.getSize().x / 78,
                                                     moduleRectangle.getSize().y * percent));
                    progressBar.setPosition(ram->getX() + ((size - 1) * (moduleRectangle.getSize().x / 78)),
                                            ram->getY());

                    _window->draw(progressBar);
                    size--;
                }

            }

        }

        moduleRectangle.setPosition(1600, 300);
        _window->draw(moduleRectangle);
        _window->draw(owlImage);
        _window->display();
        updateModule();
        _window->clear();

    }
}


void GraphicalView::addModule(IMonitorModule *toAdd) {
    _module.push_back(toAdd);

}

void GraphicalView::removeModule(IMonitorModule const *target) {
    (void) target;
}