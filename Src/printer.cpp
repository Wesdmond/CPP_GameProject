#include "printer.h"

std::string printColored(const std::string& text, Color color)
{
    std::string ans;
    switch (color)
    {
    case Color::RED:   ans += "\033[31m"; break;
    case Color::GREEN: ans += "\033[32m"; break;
    case Color::BLUE:  ans += "\033[34m"; break;
    case Color::YELLOW:  ans += "\033[33m"; break;
    }
    ans += text + "\033[0m";
    return ans;
}

std::string printColored(int num, Color color)
{
    std::string ans;
    switch (color)
    {
    case Color::RED:   ans += "\033[31m"; break;
    case Color::GREEN: ans += "\033[32m"; break;
    case Color::BLUE:  ans += "\033[34m"; break;
    case Color::YELLOW:  ans += "\033[33m"; break;
    }
    ans += std::to_string(num) + "\033[0m";
    return ans;
}