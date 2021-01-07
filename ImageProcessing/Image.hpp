#pragma once

#include <string>
#include <cstdint>
#include <ImageProcessing/FilterConfig.hpp>


class Image
{
    public:
    Image(const std::string& path, FilterConfig::FileFormat format);
    ~Image();

    bool isImageLoaded() const;
    bool loadImage();
    bool saveImage();
    void setPixels(uint8_t* newPixels);
    uint8_t* getPixels();
    uint32_t getSize();
    int32_t getChannels();
    int32_t getWidth();
    int32_t getHeight();


    private:
    const std::string _path;
    const FilterConfig::FileFormat _format;
    int32_t _width;
    int32_t _height;
    int32_t _channels;
    const int32_t _jpgQuality;
    uint8_t* _pixels;
    bool _isImageLoaded;
};
