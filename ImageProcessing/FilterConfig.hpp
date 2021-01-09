#pragma once

#include <string>
#include <vector>


namespace FilterConfig
{
    namespace BlurCoefficients
    {
        constexpr int32_t coefficientsWidth = 3;
        constexpr int32_t coefficientsHeight = 3;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0 / 4.5;
        const std::vector<std::vector<double>> coefficients = { { 0.1, 0.2, 0.3 },
                                                                { 0.4, 0.5, 0.6 },
                                                                { 0.7, 0.8, 0.9 } };
    }

    namespace MotionBlurCoefficients
    {
        constexpr int32_t coefficientsWidth = 3;
        constexpr int32_t coefficientsHeight = 3;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0 / 3.0;
        const std::vector<std::vector<double>> coefficients = { { 1.0, 0.0, 0.0 },
                                                                { 0.0, 1.0, 0.0 },
                                                                { 0.0, 0.0, 1.0 } };
    }

    namespace EdgeDetectionCoefficients
    {
        constexpr int32_t coefficientsWidth = 3;
        constexpr int32_t coefficientsHeight = 3;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0;
        const std::vector<std::vector<double>> coefficients = { { -1.0, -1.0, -1.0 },
                                                                { -1.0,  8.0, -1.0 },
                                                                { -1.0, -1.0, -1.0 } };
    }

    namespace SharpenCoefficients
    {
        constexpr int32_t coefficientsWidth = 3;
        constexpr int32_t coefficientsHeight = 3;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0;
        const std::vector<std::vector<double>> coefficients = { { -1.0, -1.0, -1.0 },
                                                                { -1.0,  9.0, -1.0 },
                                                                { -1.0, -1.0, -1.0 } };
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
        SHARPEN
    };

    FileFormat convertFileFormatToEnum(const std::string& fileFormatStr);
    FilterEffect convertFilterEffectToEnum(const std::string& filterEffectStr);
    void getFilterConfig(FilterEffect effect, const int32_t*& width,
                                              const int32_t*& height, const double*& filterBias,
                                                                      const double*& filterFactor, const std::vector<std::vector<double>>*& filterCoeffs);
}
