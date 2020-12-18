#pragma once
#include <cstdlib>
#include <algorithm>
#include <fstream>

#include "State.h"
#include "Button.h"
#include "Player.h"
#include "Map.h"
#include "Collision.h"
#include "Enemy.h"
#include "Bullet.h"

class GameState :
    public State
{
private:
    enum class Status {
        PLAY,
        PAUSE,
        END
    };
    std::vector<Enemy*> enemies;
    std::vector<Bullet*> bullets;
    sf::Clock spawnCooldown;
    bool firstSpawn;
    std::map<std::string, Button*> buttons;
    std::map<std::string, Button*> pausedButtons;
    std::map<std::string, Button*> endButtons;
    sf::RectangleShape pausedPlane;
    sf::RectangleShape endPlane;
    sf::Text endText;
    sf::Text scoreEndText;
    sf::Text timeText;
    sf::Text ammoText;
    sf::Font font;
    sf::Clock pauseDebounce;
    GameState::Status status;
    bool isGamePause;
    sf::Clock keyPressedClock;
    std::string playerName;

    sf::Clock Time;
    String TimeString;
    int sec, min, hour;
    unsigned long allTime;

    bool showEnemy;

    sf::SoundBuffer clickBuffer;
    SoundBuffer bgMapSoundBuff;
    SoundBuffer deathScenceBuff;
    SoundBuffer akBuff;
    SoundBuffer minigunBuff;
    SoundBuffer bowBuff;
    SoundBuffer shotgunBuff;
    
    sf::Sound click;
    Sound bgMapSound;
    Sound deathScence;
    Sound ak;
    Sound minigun;
    Sound bow;
    Sound shotgun;

    sf::Sound* backgroundSound;

    Player player;
    Map map;

    Texture shaderTexture;
    Sprite shader;

    Texture deathTexture;
    Sprite death;

    sf::Clock bulletClock;
    float bulletTime;

    sf::Clock deathClock;
    bool resetDeathClock;

    bool firstbgsound;

    // Functions
    void initKeybinds();
    void initFont();
    void initPlayer();
    void initPausedButtons();
    void initPausedMenu();
    void initEndButtons();
    void initEndMenu();
    void initSounds();
public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, std::string player_name, sf::Sound* bgsound);
    virtual ~GameState();

    // Functions
    void checkEndGame();
    void waitForEnd();
    void endGame();
    void toggleStatePaused();

    void spawnEnemies();
    void updateEnemiesKilled();
    void updateTime();
    void updateInput();
    void updateEnemiesCollide();
    void updateEnemies();
    void updateBullets();
    void updateBulletsCollide();
    void updateDeleteBullet();
    void updatePausedMenu();
    void updateEndMenu();
    void updateAndSaveScore();
    void update(const float& dt);

    void renderTime(sf::RenderTarget* target);
    void renderEnemies(sf::RenderTarget* target);
    void renderBullets(sf::RenderTarget* target);
    void renderPausedMenu(sf::RenderTarget* target);
    void renderEndMenu(sf::RenderTarget* target);
    void render(sf::RenderTarget* target = NULL);
};

