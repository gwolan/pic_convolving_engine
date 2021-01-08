#include <cstdint>
#include <ImageProcessing/FilterConfig.hpp>


namespace FilterConfig
{
    namespace BlurCoefficients
    {
        constexpr uint32_t coefficientsWidth = 3;
        constexpr uint32_t coefficientsHeight = 3;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0;
        constexpr double coefficients[coefficientsWidth][coefficientsHeight] =
        {
            0.0, 0.2, 0.0,
            0.2, 0.2, 0.2,
            0.0, 0.2, 0.0
        };
    }

    namespace MotionBlurCoefficients
    {
        constexpr uint32_t coefficientsWidth = 3;
        constexpr uint32_t coefficientsHeight = 3;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0 / 3.0;
        constexpr double coefficients[coefficientsWidth][coefficientsHeight] =
        {
            1.0, 0.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 0.0, 1.0
        };
    }

    namespace EdgeDetectionCoefficients
    {
        constexpr uint32_t coefficientsWidth = 3;
        constexpr uint32_t coefficientsHeight = 3;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0;
        constexpr double coefficients[coefficientsWidth][coefficientsHeight] =
        {
            -1.0, -1.0, -1.0,
            -1.0,  8.0, -1.0,
            -1.0, -1.0, -1.0
        };
    }

    namespace SharpenCoefficients
    {
        constexpr uint32_t coefficientsWidth = 3;
        constexpr uint32_t coefficientsHeight = 3;

        constexpr double bias = 0.0;
        constexpr double factor = 1.0;
        constexpr double coefficients[coefficientsWidth][coefficientsHeight] =
        {
            -1.0, -1.0, -1.0,
            -1.0,  9.0, -1.0,
            -1.0, -1.0, -1.0
        };
    }

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
