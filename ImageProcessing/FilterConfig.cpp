#include <cstdint>
#include <ImageProcessing/FilterConfig.hpp>


namespace FilterConfig
{
    FileFormat convertFileFormatStrToEnum(const std::string& fileFormatStr)
    {
        if     (fileFormatStr == "jpeg") return JPEG;
        else if(fileFormatStr == "png")  return PNG;
        else if(fileFormatStr == "bmp")  return BMP;
        else if(fileFormatStr == "tga")  return TGA;
        else                             return UNKNOWN_FORMAT;
    }

    FilterEffect convertFilterEffectStrToEnum(const std::string& filterEffectStr)
    {
        if     (filterEffectStr == "BLUR")           return BLUR;
        else if(filterEffectStr == "MOTION_BLUR")    return MOTION_BLUR;
        else if(filterEffectStr == "EDGE_DETECTION") return EDGE_DETECTION;
        else if(filterEffectStr == "SHARPEN")        return SHARPEN;
        else if(filterEffectStr == "EMBOSS")         return EMBOSS;
        else                                         return UNKNOWN_EFFECT;
    }

    std::string convertFileFormatEnumToStr(const FileFormat fileFormatEnum)
    {
        switch (fileFormatEnum)
        {
            case JPEG: return "jpeg";

            case PNG: return "png";

            case BMP: return "bmp";

            case TGA: return "tga";

            default: return "UNKNOWN_FORMAT";
        }
    }

    std::string convertFilterEffectEnumToStr(const FilterEffect filterEffectEnum)
    {
        switch (filterEffectEnum)
        {
            case BLUR: return "BLUR";

            case MOTION_BLUR: return "MOTION_BLUR";

            case EDGE_DETECTION: return "EDGE_DETECTION";

            case SHARPEN: return "SHARPEN";

            case EMBOSS: return "EMBOSS";

            default: return "UNKNOWN_EFFECT";
        }
    }

    void getFilterConfig(FilterEffect effect, const int32_t*& width,
                                              const int32_t*& height, const double*& filterBias,
                                                                      const double*& filterFactor, const bool *& grayScale, const std::vector<std::vector<double>>*& filterCoeffs)
    {
        if(effect == BLUR)
        {
            grayScale = &FilterConfig::BlurCoefficients::grayScaleRequired;
            width = &FilterConfig::BlurCoefficients::coefficientsWidth;
            height = &FilterConfig::BlurCoefficients::coefficientsHeight;
            filterCoeffs = &FilterConfig::BlurCoefficients::coefficients;
            filterFactor = &FilterConfig::BlurCoefficients::factor;
            filterBias = &FilterConfig::BlurCoefficients::bias;
        }
        else if(effect == MOTION_BLUR)
        {
            grayScale = &FilterConfig::MotionBlurCoefficients::grayScaleRequired;
            width = &FilterConfig::MotionBlurCoefficients::coefficientsWidth;
            height = &FilterConfig::MotionBlurCoefficients::coefficientsHeight;
            filterCoeffs = &FilterConfig::MotionBlurCoefficients::coefficients;
            filterFactor = &FilterConfig::MotionBlurCoefficients::factor;
            filterBias = &FilterConfig::MotionBlurCoefficients::bias;
        }
        else if(effect == EDGE_DETECTION)
        {
            grayScale = &FilterConfig::EdgeDetectionCoefficients::grayScaleRequired;
            width = &FilterConfig::EdgeDetectionCoefficients::coefficientsWidth;
            height = &FilterConfig::EdgeDetectionCoefficients::coefficientsHeight;
            filterCoeffs = &FilterConfig::EdgeDetectionCoefficients::coefficients;
            filterFactor = &FilterConfig::EdgeDetectionCoefficients::factor;
            filterBias = &FilterConfig::EdgeDetectionCoefficients::bias;
        }
        else if(effect == SHARPEN)
        {
            grayScale = &FilterConfig::SharpenCoefficients::grayScaleRequired;
            width = &FilterConfig::SharpenCoefficients::coefficientsWidth;
            height = &FilterConfig::SharpenCoefficients::coefficientsHeight;
            filterCoeffs = &FilterConfig::SharpenCoefficients::coefficients;
            filterFactor = &FilterConfig::SharpenCoefficients::factor;
            filterBias = &FilterConfig::SharpenCoefficients::bias;
        }
        else if(effect == EMBOSS)
        {
            grayScale = &FilterConfig::EmbossCoefficients::grayScaleRequired;
            width = &FilterConfig::EmbossCoefficients::coefficientsWidth;
            height = &FilterConfig::EmbossCoefficients::coefficientsHeight;
            filterCoeffs = &FilterConfig::EmbossCoefficients::coefficients;
            filterFactor = &FilterConfig::EmbossCoefficients::factor;
            filterBias = &FilterConfig::EmbossCoefficients::bias;
        }
    }
}
