#pragma once
#include <SFML/Graphics.hpp>
enum screens { START_SCREEN, MENU_SCREEN, INTRODUCTION_SCREEN, GOAL_SCREEN, GAME_SCREEN, GAME_OVER_SCREEN , STORE_SCREEN};
class Screen
{
    public:
        
        Screen() {};
        ~Screen() {};
        virtual int run(sf::RenderWindow& gold_miner, int& level, int& totalMoney) = 0 ;

    protected:
              int m_i = 0;
  

     
       
};