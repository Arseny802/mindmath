#pragma once
#include "common/setup.h"
#include <memory>
#include <string>

namespace mindmath::config {
class config_parser
{
public:
    virtual ~config_parser() = 0;

    virtual bool read(const std::string& filename) = 0;
    virtual std::unique_ptr<common::setup> get_setup() = 0;
};
using config_parser_ptr = std::shared_ptr<config_parser>;
} // namespace mindmath::config
