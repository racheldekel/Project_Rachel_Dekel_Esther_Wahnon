#pragma once


class Screen
{
    public:

        Screen() {};
        ~Screen() {};
        virtual int run(sf::RenderWindow& gold_miner) = 0;


    private :
};