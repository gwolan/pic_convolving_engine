#include <cstdint>
#include <ImageProcessing/FilterConfig.hpp>


namespace FilterConfig
{
    FileFormat convertFileFormatToEnum(const std::string& fileFormatStr)
    {
        if(fileFormatStr == "jpeg")
        {
            return JPEG;
        }
        else if(fileFormatStr == "png")
        {
            return PNG;
        }
        else if(fileFormatStr == "bmp")
        {
            return BMP;
        }
        else if(fileFormatStr == "tga")
        {
            return TGA;
        }
        else
        {
            return UNKNOWN_FORMAT;
        }
    }

    FilterEffect convertFilterEffectToEnum(const std::string& filterEffectStr)
    {
        if(filterEffectStr == "BLUR")
        {
            return BLUR;
        }
        else if(filterEffectStr == "MOTION_BLUR")
        {
            return MOTION_BLUR;
        }
        else if(filterEffectStr == "EDGE_DETECTION")
        {
            return EDGE_DETECTION;
        }
        else if(filterEffectStr == "SHARPEN")
        {
            return SHARPEN;
        }
        else
        {
            return UNKNOWN_EFFECT;
        }
    }
}
