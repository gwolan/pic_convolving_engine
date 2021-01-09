#include <algorithm>
#include <ImageProcessing/Filter.hpp>
#include <ImageProcessing/FilterConfig.hpp>


Filter::Filter(FilterConfig::FilterEffect effectType)
    : _coefficientsWidth(NULL)
    , _coefficientsHeight(NULL)
    , _bias(NULL)
    , _factor(NULL)
    , _coefficients(NULL)
{
    FilterConfig::getFilterConfig(effectType, _coefficientsWidth, _coefficientsHeight, _bias, _factor, _coefficients);
}

void Filter::convolve(Image& inputImage)
{
    uint8_t* resultPixels = new uint8_t[inputImage.getSize()];
    std::copy(inputImage.getPixels(), inputImage.getPixels() + inputImage.getSize(), resultPixels);

    int32_t height = inputImage.getHeight();
    int32_t width = inputImage.getWidth();
    int32_t channels = inputImage.getChannels();

    for(int32_t pixelY = 0; pixelY < height; ++pixelY)
    {
        for(int32_t pixelX = 0; pixelX < width * channels; pixelX += channels)
        {
            double r = 0.0;
            double g = 0.0;
            double b = 0.0;
            double a = 0.0;

            for(int32_t coeffY = 0; coeffY < *_coefficientsHeight; ++coeffY)
            {
                for(int32_t coeffX = 0; coeffX < *_coefficientsWidth; ++coeffX)
                {
                    int32_t xOffset = (pixelX - (*_coefficientsWidth / 2) * channels + coeffX * channels + width * channels) % (width * channels);
                    int32_t yOffset = ((pixelY - *_coefficientsHeight / 2 + coeffY + height) * width * channels) % (width * height * channels);

                    for(int32_t channel = 0; channel < channels; ++channel)
                    {
                        if(channel == 0)
                            r += inputImage.getPixels()[yOffset + xOffset + channel] * (*_coefficients)[coeffY][coeffX];
                        else if(channel == 1)
                            g += inputImage.getPixels()[yOffset + xOffset + channel] * (*_coefficients)[coeffY][coeffX];
                        else if(channel == 2)
                            b += inputImage.getPixels()[yOffset + xOffset + channel] * (*_coefficients)[coeffY][coeffX];
                        else if(channel == 3)
                            a += inputImage.getPixels()[yOffset + xOffset + channel] * (*_coefficients)[coeffY][coeffX];
                    }
                }
            }

            for(int32_t channel = 0; channel < channels; ++channel)
            {
                if(channel == 0)
                    resultPixels[pixelY * width * channels + pixelX + channel] = std::min(std::max(static_cast<int32_t>(*_factor * r + *_bias), static_cast<int32_t>(0)), static_cast<int32_t>(255));
                else if(channel == 1)
                    resultPixels[pixelY * width * channels + pixelX + channel] = std::min(std::max(static_cast<int32_t>(*_factor * g + *_bias), static_cast<int32_t>(0)), static_cast<int32_t>(255));
                else if(channel == 2)
                    resultPixels[pixelY * width * channels + pixelX + channel] = std::min(std::max(static_cast<int32_t>(*_factor * b + *_bias), static_cast<int32_t>(0)), static_cast<int32_t>(255));
                else if(channel == 3)
                    resultPixels[pixelY * width * channels + pixelX + channel] = std::min(std::max(static_cast<int32_t>(*_factor * a + *_bias), static_cast<int32_t>(0)), static_cast<int32_t>(255));
            }
        }
    }

    inputImage.setPixels(resultPixels);
}
