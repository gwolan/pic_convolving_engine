#pragma once

#include <string>


namespace FilterConfig
{
    enum FileFormat
    {
        UNKNOWN_FORMAT = 0,
        JPEG,
        PNG,
        BMP,
        TGA
    };

    enum FilterEffect
    {
        UNKNOWN_EFFECT = 0,
        BLUR,
        MOTION_BLUR,
        EDGE_DETECTION,
        SHARPEN
    };

    FileFormat convertFileFormatToEnum(const std::string& fileFormatStr);
    FilterEffect convertFilterEffectToEnum(const std::string& filterEffectStr);
}
