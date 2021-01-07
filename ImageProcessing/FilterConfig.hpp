#include <vector>
#include <string>


class FilterConfig
{
    public:
    FilterConfig();

    enum FileFormat
    {
        UNKNOWN_FORMAT = 0,
        JPEG,
        PNG
    };

    enum FilterEffect
    {
        UNKNOWN_EFFECT = 0,
        BLUR
    };

    const std::vector<FileFormat>& getSupportedFileFormats() const;
    const std::vector<FilterEffect>& getSupportedFilterEffects() const;
    FileFormat convertFileFormatToEnum(const std::string& fileFormatStr);
    FilterEffect convertFilterEffectToEnum(const std::string& filterEffectStr);


    private:
    std::vector<FileFormat> _supportedFileFormats;
    std::vector<FilterEffect> _supportedFilterEffects;
};
