#include <ImageProcessing/FilterCoefficients.hpp>


FilterCoefficients::FilterCoefficients(double bias,
                                       double factor, uint32_t coefficientsWidth,
                                                      uint32_t coefficientsHeight, const std::vector<std::vector<double>>& coefficients)
    : _bias(bias)
    , _factor(factor)
    , _coefficientsWidth(coefficientsWidth)
    , _coefficientsHeight(coefficientsHeight)
    , _coefficients(coefficients)
{ }
