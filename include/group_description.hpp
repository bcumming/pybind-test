#pragma once

#include <vector>

enum class cell_kind {cable, lif};

struct group_description {
    const cell_kind kind;
    const std::vector<int> gids;

    group_description(cell_kind k, std::vector<int> g):
        kind(k),
        gids(std::move(g))
    {}
};
