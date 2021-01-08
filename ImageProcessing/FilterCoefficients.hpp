#pragma once

#include <cstdint>
#include <vector>


struct FilterCoefficients
{
    FilterCoefficients(double bias,
                       double factor, uint32_t coefficientsWidth,
                                      uint32_t coefficientsHeight, const std::vector<std::vector<double>>& coefficients);


    const double _bias;
    const double _factor;

    const uint32_t _coefficientsWidth;
    const uint32_t _coefficientsHeight;
    const std::vector<std::vector<double>> _coefficients;
};
