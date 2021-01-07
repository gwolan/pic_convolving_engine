#include <iostream>
#include <IO/ArgParser.hpp>


ArgParser::ArgParser(uint32_t argc, char* argv[], FilterConfig& filterConfig)
    : _help("Program transforms input image apllying chosen effect.\n\nAvailable options")
    , _inputMap()
    , _filterConfig(filterConfig)
    , _errorMsg()
    , _filePath()
    , _fileFormat(FilterConfig::UNKNOWN_FORMAT)
    , _filterEffect(FilterConfig::BLUR)
    , _argCount(argc)
{
    _help.add_options()
        ("help,h", "print this help message and terminates")
        ("path,p", boost::program_options::value<std::string>(), "path to the image (either relative or absolute)")
        ("format,f", boost::program_options::value<std::string>(), "image format")
        ("effect,e", boost::program_options::value<std::string>()->default_value("BLUR"), "requested effect (optional)\n\nSupported effects:\n- BLUR");

    parseArgs(argc, argv);
}

void ArgParser::parseArgs(uint32_t argc, char* argv[])
{
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, _help), _inputMap);
    boost::program_options::notify(_inputMap);

    if(_inputMap.count("path"))
    {
        _filePath = _inputMap["path"].as<std::string>();
    }

    if(_inputMap.count("format"))
    {
        _fileFormat = _filterConfig.convertFileFormatToEnum(_inputMap["format"].as<std::string>());
    }

    if(_inputMap.count("effect"))
    {
        _filterEffect = _filterConfig.convertFilterEffectToEnum(_inputMap["effect"].as<std::string>());
    }
}

void ArgParser::printHelp()
{
    std::cout << _help << std::endl;
}

void ArgParser::printMsg(const std::string& msg)
{
    std::cout << msg << std::endl << std::endl;
}

bool ArgParser::validateArgs()
{
    if(_inputMap.count("help") or _argCount == 1)
    {
        printHelp();
        return false;
    }
    else if(not _inputMap.count("path"))
    {
        printMsg("ERROR: Path to image was not specified.");
        printHelp();
        return false;
    }
    else if(not _inputMap.count("format"))
    {
        printMsg("ERROR: Image format was not specified.");
        printHelp();
        return false;
    }
    else if(_inputMap.count("effect") and _filterEffect == FilterConfig::UNKNOWN_EFFECT)
    {
        printMsg("ERROR: Chosen effect is not supported.");
        printHelp();
        return false;
    }

    return true;
}

std::string ArgParser::getImagePath() const
{
    return _filePath;
}

FilterConfig::FileFormat ArgParser::getImageFormat() const
{
    return _fileFormat;
}

FilterConfig::FilterEffect ArgParser::getRequestedEffect() const
{
    return _filterEffect;
}
