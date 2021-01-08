#include <ImageProcessing/FilterConfig.hpp>


namespace FilterConfig
{
    FilterCoefficients blurCoefficients(0.0, 1.0, 3, 3, { { 0.0, 0.2, 0.0 },
                                                          { 0.2, 0.2, 0.2 },
                                                          { 0.0, 0.2, 0.0 } });

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
        else
        {
            return UNKNOWN_EFFECT;
        }
    }
}
