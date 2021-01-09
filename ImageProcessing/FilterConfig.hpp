#pragma once

#include <string>
#include <vector>


namespace FilterConfig
{
    namespace BlurCoefficients
    {
        constexpr int32_t coefficientsWidth = 7;
        constexpr int32_t coefficientsHeight = 7;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0 / 75.0;
        const std::vector<std::vector<double>> coefficients = { { 0.0, 0.0, 0.0, 3.0, 0.0, 0.0, 0.0 },
                                                                { 0.0, 0.0, 3.0, 3.0, 3.0, 0.0, 0.0 },
                                                                { 0.0, 3.0, 3.0, 3.0, 3.0, 3.0, 0.0 },
                                                                { 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0 },
                                                                { 0.0, 3.0, 3.0, 3.0, 3.0, 3.0, 0.0 },
                                                                { 0.0, 0.0, 3.0, 3.0, 3.0, 0.0, 0.0 },
                                                                { 0.0, 0.0, 0.0, 3.0, 0.0, 0.0, 0.0 } };
    }

    namespace MotionBlurCoefficients
    {
        constexpr int32_t coefficientsWidth = 7;
        constexpr int32_t coefficientsHeight = 7;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0 / 16.0;
        const std::vector<std::vector<double>> coefficients = { { 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
                                                                { 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
                                                                { 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0 },
                                                                { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },
                                                                { 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0 },
                                                                { 0.0, 0.0, 0.0, 0.0, 0.0, 3.0, 0.0 },
                                                                { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.0 } };
    }

    namespace EdgeDetectionCoefficients
    {
        constexpr int32_t coefficientsWidth = 5;
        constexpr int32_t coefficientsHeight = 5;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0;
        const std::vector<std::vector<double>> coefficients = { { 1.0, 1.0,   1.0, 1.0, 1.0 },
                                                                { 1.0, 2.0,   2.0, 2.0, 1.0 },
                                                                { 1.0, 2.0, -32.0, 2.0, 1.0 },
                                                                { 1.0, 2.0,   2.0, 2.0, 1.0 },
                                                                { 1.0, 1.0,   1.0, 1.0, 1.0 } };
    }

    namespace SharpenCoefficients
    {
        constexpr int32_t coefficientsWidth = 3;
        constexpr int32_t coefficientsHeight = 3;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0;
        const std::vector<std::vector<double>> coefficients = { { -1.0, -1.0, -1.0 },
                                                                {  0.0,  7.0,  0.0 },
                                                                { -1.0, -1.0, -1.0 } };
    }

    namespace EmbossCoefficients
    {
        constexpr int32_t coefficientsWidth = 5;
        constexpr int32_t coefficientsHeight = 5;

        constexpr double bias = 128.0;
        constexpr double factor = 1.0;
        const std::vector<std::vector<double>> coefficients = { { -1.0, -1.0, -1.0, -1.0, 0.0 },
                                                                { -1.0, -1.0, -1.0,  0.0, 1.0 },
                                                                { -1.0, -1.0,  0.0,  1.0, 1.0 },
                                                                { -1.0,  0.0,  1.0,  1.0, 1.0 },
                                                                {  0.0,  1.0,  1.0,  1.0, 1.0 } };
    }

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
        SHARPEN,
        EMBOSS
    };

    FileFormat convertFileFormatStrToEnum(const std::string& fileFormatStr);
    FilterEffect convertFilterEffectStrToEnum(const std::string& filterEffectStr);

    std::string convertFileFormatEnumToStr(const FileFormat fileFormatEnum);
    std::string convertFilterEffectEnumToStr(const FilterEffect filterEffectEnum);

    void getFilterConfig(FilterEffect effect, const int32_t*& width,
                                              const int32_t*& height, const double*& filterBias,
                                                                      const double*& filterFactor, const std::vector<std::vector<double>>*& filterCoeffs);
}
