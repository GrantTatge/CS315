#pragma once
#include <vector>
#include "Dictionary.hpp"

class SortedVectorDict : public Dictionary
{ public:
    void insert(int) override;
    bool lookup(int) const override;
    void remove(int) override;
    std::vector<int> returnData() {
        return data;
    }

private:
    std::vector<int> data;
    void sortElements(int key, int idx);

    [[nodiscard]] int lookup_idx(int) const;
};