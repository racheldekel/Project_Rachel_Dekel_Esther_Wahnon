#include <SFML/Graphics.hpp>
#include "ManagerScreen.h"
#include "fstream"
#include <iostream>//swear to remove this too
const auto LOG = "log.txt";

int main() try 
{
    ManagerScreen s;

    s.main_run();

    return EXIT_SUCCESS;
   
}
catch (std::exception& e)
{
    std::cout << "Unknown Exception" << '\n';//temporary i swear to remove this line before submit
    auto file = std::ofstream(LOG);
    file << e.what() << '\n';
    return EXIT_FAILURE;
}
catch (...)
{
    auto file = std::ofstream(LOG);
    file << "Unknown Exception" << '\n';
    std::cout << "Unknown Exception" << '\n';//temporary i swear to remove this line before submit
    return EXIT_FAILURE;
}