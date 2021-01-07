#include <string>

namespace FilterConfig
{
    enum FileFormat
    {
        UNKNOWN_FORMAT = 0,
        JPEG,
        PNG
    };

    enum FilterEffect
    {
        UNKNOWN_EFFECT = 0,
        BLUR
    };

    inline FileFormat convertFileFormatToEnum(const std::string& fileFormatStr)
    {
        if(fileFormatStr == "jpeg")
        {
            return JPEG;
        }
        else if(fileFormatStr == "png")
        {
            return PNG;
        }
        else
        {
            return UNKNOWN_FORMAT;
        }
    }

    inline FilterEffect convertFilterEffectToEnum(const std::string& filterEffectStr)
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
