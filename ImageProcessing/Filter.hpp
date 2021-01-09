#pragma once

#include <ImageProcessing/FilterConfig.hpp>
#include <ImageProcessing/Image.hpp>


class Filter
{
    public:
    Filter(FilterConfig::FilterEffect effectType);

    void convolve(Image& inputImage);


    private:
    const FilterConfig::FilterEffect _effectType;
    const int32_t* _coefficientsWidth;
    const int32_t* _coefficientsHeight;
    const double* _bias;
    const double* _factor;
    const std::vector<std::vector<double>>* _coefficients;
};
