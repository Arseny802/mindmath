#include "config/config_parser_factory.h"
#include "parsing/config_parser_ini.h"

namespace mindmath::config {

config_parser_ptr config_parser_factory::generate_parser(parsing_types type)
{
    switch (type) {
        case parsing_types::ini:
            return std::make_shared<parsing::config_parser_ini>();
        default:
            return nullptr;
    }
}

} // namespace mindmath::config
