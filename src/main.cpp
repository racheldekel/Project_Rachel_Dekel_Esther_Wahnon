#include "ManagerScreen.h"
#include <fstream>

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
    file << "Unknown Excpetion\n";
    return EXIT_FAILURE;
}