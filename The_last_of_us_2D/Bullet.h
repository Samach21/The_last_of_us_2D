#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
#include<cmath>

class Bullet
{
private:
    int slot;

    sf::Texture texture;

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    sf::Vector2f startPoint;
    sf::Vector2f targetPoint;

    sf::Clock clock;
    sf::Clock allT;

    float v, s, t;
    float sx, sy;
    float vx, vy;
    float allS;
    float lastSx, lastSy;
    sf::Vector2f lastMap;

    void initVariables();
    void initSprites();
public:
    Bullet(float x, float y,float targetx, float targety, int* slot, float mapx, float mapy);
    virtual ~Bullet();

    sf::Sprite sprite;
    bool isDelete;

    void updatePosition(float x, float y);
    void update(sf::RenderTarget* target, float x, float y);
    void render(sf::RenderTarget* target);
};

