#pragma once
#include "config/config_parser.h"

namespace mindmath::config::parsing {

class config_parser_ini final : public config_parser
{
public:
    config_parser_ini();
    ~config_parser_ini() override;

    bool read(const std::string& filename) override;

    std::unique_ptr<common::setup> get_setup() override;

private:
    common::setup setup_;
};

} // namespace mindmath::config::parsing
