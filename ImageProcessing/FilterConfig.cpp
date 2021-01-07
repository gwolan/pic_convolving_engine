#include <ImageProcessing/FilterConfig.hpp>


FilterConfig::FilterConfig()
    : _supportedFileFormats( { JPEG, PNG } )
    , _supportedFilterEffects( { BLUR } )
{ }

const std::vector<FilterConfig::FileFormat>& FilterConfig::getSupportedFileFormats() const
{
    return _supportedFileFormats;
}

const std::vector<FilterConfig::FilterEffect>& FilterConfig::getSupportedFilterEffects() const
{
    return _supportedFilterEffects;
}

FilterConfig::FileFormat FilterConfig::convertFileFormatToEnum(const std::string& fileFormatStr)
{
    if(fileFormatStr == "jpeg")
    {
        return JPEG;
    }
    else if(fileFormatStr == "png")
    {
        return PNG;
    }
    else
    {
        return UNKNOWN_FORMAT;
    }
}

FilterConfig::FilterEffect FilterConfig::convertFilterEffectToEnum(const std::string& filterEffectStr)
{
    if(filterEffectStr == "BLUR")
    {
        return BLUR;
    }
    else
    {
        return UNKNOWN_EFFECT;
    }
}
