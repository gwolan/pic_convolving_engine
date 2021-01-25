#include <algorithm>
#include <fstream>
#include <iostream>
#include <ImageProcessing/Filter.hpp>
#include <ImageProcessing/FilterConfig.hpp>
#include <Miscellanous/Timer.hpp>


Filter::Filter(FilterConfig::FilterEffect effectType)
    : _grayScaleRequired(NULL)
    , _coefficientsWidth(NULL)
    , _coefficientsHeight(NULL)
    , _bias(NULL)
    , _factor(NULL)
    , _coefficients(NULL)
    , _effect(effectType)
{
    FilterConfig::getFilterConfig(effectType, _coefficientsWidth, _coefficientsHeight, _bias, _factor, _grayScaleRequired, _coefficients);
}

void Filter::convolve(Image& inputImage)
{
    uint8_t* resultPixels = new uint8_t[inputImage.getSize()];
    int32_t height = inputImage.getHeight();
    int32_t width = inputImage.getWidth();
    int32_t channels = inputImage.getChannels();
    int32_t rgbDelimiter = (channels < 4 ? channels : 3);

    // TESTING
    Timer timer;
    std::ofstream file;
    uint32_t iterations = 100;
    double result = 0.0;

    file.open("wyniki.txt", std::ofstream::app);
    file << width << "x" << height << std::endl;
    file << FilterConfig::convertFilterEffectEnumToStr(_effect) << std::endl;

    for(uint32_t it = 0; it < iterations; ++it)
    {
        std::cout << "Pomiar dla " << width << "x" << height << " " << FilterConfig::convertFilterEffectEnumToStr(_effect) << " (" << it + 1 << " z " << iterations << ")..." << std::endl;
        timer.start();
        std::copy(inputImage.getPixels(), inputImage.getPixels() + inputImage.getSize(), resultPixels);

        for(int32_t pixelY = 0; pixelY < height; ++pixelY)
        {
            for(int32_t pixelX = 0; pixelX < width * channels; pixelX += channels)
            {
                double r = 0.0;
                double g = 0.0;
                double b = 0.0;

                for(int32_t coeffY = 0; coeffY < *_coefficientsHeight; ++coeffY)
                {
                    for(int32_t coeffX = 0; coeffX < *_coefficientsWidth; ++coeffX)
                    {
                        int32_t xOffset = (pixelX - (*_coefficientsWidth / 2) * channels + coeffX * channels + width * channels) % (width * channels);
                        int32_t yOffset = ((pixelY - *_coefficientsHeight / 2 + coeffY + height) * width * channels) % (width * height * channels);

                        for(int32_t channel = 0; channel < rgbDelimiter; ++channel)
                        {
                            if(channel == 0)
                                r += inputImage.getPixels()[yOffset + xOffset + channel] * (*_coefficients)[coeffY][coeffX];
                            else if(channel == 1)
                                g += inputImage.getPixels()[yOffset + xOffset + channel] * (*_coefficients)[coeffY][coeffX];
                            else if(channel == 2)
                                b += inputImage.getPixels()[yOffset + xOffset + channel] * (*_coefficients)[coeffY][coeffX];
                        }
                    }
                }

                for(int32_t channel = 0; channel < rgbDelimiter; ++channel)
                {
                    if(channel == 0)
                        resultPixels[pixelY * width * channels + pixelX + channel] = std::min(std::max(static_cast<int32_t>(*_factor * r + *_bias), static_cast<int32_t>(0)), static_cast<int32_t>(255));
                    else if(channel == 1)
                        resultPixels[pixelY * width * channels + pixelX + channel] = std::min(std::max(static_cast<int32_t>(*_factor * g + *_bias), static_cast<int32_t>(0)), static_cast<int32_t>(255));
                    else if(channel == 2)
                        resultPixels[pixelY * width * channels + pixelX + channel] = std::min(std::max(static_cast<int32_t>(*_factor * b + *_bias), static_cast<int32_t>(0)), static_cast<int32_t>(255));
                }
            }
        }

        if(*_grayScaleRequired)
            addGrayScale(inputImage, resultPixels, channels, inputImage.getSize());

        timer.stop();
        result += timer.getTime();
    }

    result = result / static_cast<double>(iterations);
    file << result << std::endl << std::endl;
    file.close();
    std::cout << "Koniec pomiarów dla " << width << "x" << height << " " << FilterConfig::convertFilterEffectEnumToStr(_effect) << "." << std::endl << std::endl;

    inputImage.setPixels(resultPixels);
}

void Filter::addGrayScale(Image& image, uint8_t*& resultPixels, int32_t channels, int32_t size)
{
    uint8_t* grayPixels = new uint8_t[size];
    int32_t rgbDelimiter = (channels < 4 ? channels : 3);

    for(int32_t it = 0; it < size; it += channels)
    {
        int32_t accumulator = 0;
        for(int32_t channel = 0; channel < rgbDelimiter; ++channel)
        {
            accumulator += resultPixels[it + channel];
        }

        accumulator /= channels;
        for(int32_t channel = 0; channel < rgbDelimiter; ++channel)
        {
            grayPixels[it + channel] = accumulator;
        }
    }

    std::swap(grayPixels, resultPixels);
    delete[] grayPixels;
}
