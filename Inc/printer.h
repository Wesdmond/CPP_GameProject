#pragma once
#include <string>

enum class Color { RED, GREEN, BLUE, YELLOW };

std::string printColored(const std::string& text, Color color);
std::string printColored(int num, Color color);
