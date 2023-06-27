#pragma once
#include <vector>

static std::vector<std::vector<float>> or_gate = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
};
static std::vector<std::vector<float>> and_gate = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1}
};