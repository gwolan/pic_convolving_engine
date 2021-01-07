#include <iostream>
#include <IO/ArgParser.hpp>
#include <ImageProcessing/Image.hpp>


// ERROR RETURN CODES:
// 1 = invalid arguments
// 2 = unable to load image
// 3 - unable to save image


int main(int argc, char* argv[])
{
    ArgParser argParser(static_cast<uint32_t>(argc), argv);

    if(argParser.validateArgs())
    {
        std::cout << "Success!" << std::endl;
        std::cout << "Path: " << argParser.getImagePath() << std::endl;
        std::cout << "Format: " << argParser.getImageFormat() << std::endl;
        std::cout << "Effect: " << argParser.getRequestedEffect() << std::endl;

        Image image(argParser.getImagePath(), argParser.getImageFormat());

        if(image.isImageLoaded())
        {
            // convolve

            if(not image.saveImage())
            {
                std::cout << "ERROR: Unable to save image." << std::endl;
                return 3;
            }
        }
        else
        {
            std::cout << "ERROR: Unable to load image." << std::endl;
            return 2;
        }
    }
    else
    {
        return 1;
    }
    

    return 0;
}