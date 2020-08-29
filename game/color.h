#ifndef __COLOR_H__
#define __COLOR_H__

#include <string>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");
const char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
#endif // __COLOR_H__