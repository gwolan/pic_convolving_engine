#include <iostream>
#include <IO/ArgParser.hpp>


int main(int argc, char* argv[])
{
    ArgParser argParser(static_cast<uint32_t>(argc), argv);

    if(argParser.validateArgs())
    {
        std::cout << "Success!" << std::endl;
        std::cout << "Path: " << argParser.getImagePath() << std::endl;
        std::cout << "Format: " << argParser.getImageFormat() << std::endl;
        std::cout << "Effect: " << argParser.getRequestedEffect() << std::endl;
    }

    return 0;
}