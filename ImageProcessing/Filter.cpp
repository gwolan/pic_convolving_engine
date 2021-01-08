#include <iostream>
#include <ImageProcessing/Filter.hpp>


Filter::Filter(FilterConfig::FilterEffect effectType)
    : _effectType(effectType)
{
    if(_effectType == FilterConfig::BLUR)
    {
        _coefficientsWidth = &FilterConfig::BlurCoefficients::coefficientsWidth;
        _coefficientsHeight = &FilterConfig::BlurCoefficients::coefficientsHeight;
        _coefficients = &FilterConfig::BlurCoefficients::coefficients;
        _factor = &FilterConfig::BlurCoefficients::factor;
        _bias = &FilterConfig::BlurCoefficients::bias;
    }
    else if(_effectType == FilterConfig::MOTION_BLUR)
    {
        _coefficientsWidth = &FilterConfig::MotionBlurCoefficients::coefficientsWidth;
        _coefficientsHeight = &FilterConfig::MotionBlurCoefficients::coefficientsHeight;
        _coefficients = &FilterConfig::MotionBlurCoefficients::coefficients;
        _factor = &FilterConfig::MotionBlurCoefficients::factor;
        _bias = &FilterConfig::MotionBlurCoefficients::bias;
    }
    else if(_effectType == FilterConfig::EDGE_DETECTION)
    {
        _coefficientsWidth = &FilterConfig::EdgeDetectionCoefficients::coefficientsWidth;
        _coefficientsHeight = &FilterConfig::EdgeDetectionCoefficients::coefficientsHeight;
        _coefficients = &FilterConfig::EdgeDetectionCoefficients::coefficients;
        _factor = &FilterConfig::EdgeDetectionCoefficients::factor;
        _bias = &FilterConfig::EdgeDetectionCoefficients::bias;
    }
    else if(_effectType == FilterConfig::SHARPEN)
    {
        _coefficientsWidth = &FilterConfig::SharpenCoefficients::coefficientsWidth;
        _coefficientsHeight = &FilterConfig::SharpenCoefficients::coefficientsHeight;
        _coefficients = &FilterConfig::SharpenCoefficients::coefficients;
        _factor = &FilterConfig::SharpenCoefficients::factor;
        _bias = &FilterConfig::SharpenCoefficients::bias;
    }
}

void Filter::convolve(Image& inputImage)
{

}
