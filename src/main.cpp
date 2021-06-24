#include <SFML/Graphics.hpp>
#include "ManagerScreen.h"
#include "fstream"
#include <iostream>
const auto LOG = "log.txt";

int main() try 
{
    ManagerScreen s;

    s.main_run();

    return EXIT_SUCCESS;
   
}
catch (std::exception& e)
{
    auto file = std::ofstream(LOG);
    file << e.what() << '\n';
    return EXIT_FAILURE;
}
catch (...)
{
    auto file = std::ofstream(LOG);
    file << "Unknown Exception" << '\n';
    return EXIT_FAILURE;
}