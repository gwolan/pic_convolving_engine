#pragma once

#include <cstdint>
#include <string>
#include <boost/program_options.hpp>
#include <ImageProcessing/FilterConfig.hpp>


class ArgParser
{
    public:
    ArgParser(uint32_t argc, char* argv[]);

    void printHelp();
    void printMsg(const std::string& msg);
    bool validateArgs();
    std::string getImagePath() const;
    FilterConfig::FileFormat getImageFormat() const;
    FilterConfig::FilterEffect getRequestedEffect() const;


    private:
    void parseArgs(uint32_t argc, char* argv[]);

    boost::program_options::options_description _help;
    boost::program_options::variables_map _inputMap;

    std::string _filePath;
    FilterConfig::FileFormat _fileFormat;
    FilterConfig::FilterEffect _filterEffect;
    uint32_t _argCount;
};
