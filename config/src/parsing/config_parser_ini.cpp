#include "config_parser_ini.h"
#include "./"
#include "INIReader.h"

namespace mindmath::config::parsing {
config_parser_ini::config_parser_ini() = default;
config_parser_ini::~config_parser_ini() = default;

bool config_parser_ini::read(const std::string& filename)
{
    common::setup new_setup;
    new_setup.allowed_operations = 0;


    INIReader reader("../examples/test.ini");

    if (reader.ParseError() < 0) {
        //std::cout << "Can't load 'test.ini'\n";
        return 1;
    }


    return false;
}

std::unique_ptr<common::setup> config_parser_ini::get_setup()
{
    return std::make_unique<common::setup>(setup_);
}
} // namespace mindmath::config::parsing
