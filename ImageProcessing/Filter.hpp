#pragma once

#include <ImageProcessing/Image.hpp>


class Filter
{
    public:
    Filter(FilterConfig::FilterEffect effectType);

    void convolve(Image& inputImage);


    private:
    void addGrayScale(Image& image, uint8_t*& resultPixels, int32_t channels, int32_t size);

    const bool* _grayScaleRequired;
    const int32_t* _coefficientsWidth;
    const int32_t* _coefficientsHeight;
    const double* _bias;
    const double* _factor;
    const std::vector<std::vector<double>>* _coefficients;
    const FilterConfig::FilterEffect _effect;
};
