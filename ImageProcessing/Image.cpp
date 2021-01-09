#include <STBlib/STB.hpp>
#include <ImageProcessing/Image.hpp>


Image::Image(const std::string& path, FilterConfig::FileFormat format)
    : _path(path)
    , _format(format)
    , _width(0)
    , _height(0)
    , _channels(0)
    , _jpgQuality(100)
    , _pixels(NULL)
    , _isImageLoaded(false)
{
    _isImageLoaded = loadImage();
}

Image::~Image()
{
    stbi_image_free(_pixels);
}

bool Image::isImageLoaded() const
{
    return _isImageLoaded;
}

bool Image::loadImage()
{
    stbi_image_free(_pixels);
    _pixels = stbi_load(_path.c_str(), &_width, &_height, &_channels, 0);

    return _pixels != NULL;
}

bool Image::saveImage()
{
    uint32_t result = 0;

    switch (_format)
    {
        case FilterConfig::JPEG:
            result = stbi_write_jpg(_path.c_str(), _width,
                                                   _height,
                                                   _channels,
                                                   _pixels,
                                                   _jpgQuality);
            break;
        
        case FilterConfig::PNG:
            result = stbi_write_png(_path.c_str(), _width,
                                                   _height,
                                                   _channels,
                                                   _pixels,
                                                   _width * _channels);
            break;
        
        case FilterConfig::BMP:
            result = stbi_write_bmp(_path.c_str(), _width,
                                                   _height,
                                                   _channels,
                                                   _pixels);
            break;
        
        case FilterConfig::TGA:
            result = stbi_write_tga(_path.c_str(), _width,
                                                   _height,
                                                   _channels,
                                                   _pixels);
            break;

        default:
            break;
    }

    return result != 0;
}

void Image::setPixels(uint8_t* newPixels)
{
    stbi_image_free(_pixels);
    _pixels = NULL;

    std::swap(_pixels, newPixels);
}

uint8_t* Image::getPixels()
{
    return _pixels;
}

int32_t Image::getSize()
{
    return _height * _width * _channels;
}

int32_t Image::getChannels()
{
    return _channels;
}

int32_t Image::getWidth()
{
    return _width;
}

int32_t Image::getHeight()
{
    return _height;
}
