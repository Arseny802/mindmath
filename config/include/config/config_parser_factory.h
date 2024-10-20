#pragma once
#include "config/config_parser.h"
#include "config/parsing_types.h"

namespace mindmath::config {

class config_parser_factory
{
public:
    static config_parser_ptr generate_parser(parsing_types type);
};

} // namespace mindmath::config
