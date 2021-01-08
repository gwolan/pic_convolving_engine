#pragma once

#include <string>
#include <ImageProcessing/FilterCoefficients.hpp>


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
        BLUR
    };

    FileFormat convertFileFormatToEnum(const std::string& fileFormatStr);
    FilterEffect convertFilterEffectToEnum(const std::string& filterEffectStr);
}
