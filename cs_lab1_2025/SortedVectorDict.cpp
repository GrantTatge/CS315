#include "SortedVectorDict.hpp"

void SortedVectorDict::insert(int key) {

    data.emplace(data.begin(), key);
    sortElements(key, 0);

    /* alternatively: this method of sorting can be done from the end
    * bubbling the key upwards instead of downwards */
    // data.push_back(key);
    // int i = data.size() - 1;
    // while (i > 0 && data.at(i) < data.at(i - 1)) {
    //     data.at(i) = data.at(i - 1);
    //     data.at(i - 1) = key;
    //     i--;
    // }

    /* you can also just use emplace... */
    // if (data.size() != 0) {
    //     while (i <= data.size() - 1 && data.at(i) < key) {
    //         i++;
    //     }
    //     data.emplace(data.begin() + i, key);
    // }
    // else {
    //     data.emplace(data.begin(), key);
    // }
}

int SortedVectorDict::lookup_idx(int key) const {

    // Performs a linear search on a sorted container.
    // A linear search algorithm is used since incrementing i
    // is fundamental to finding the index.

    for (auto i = 0; i < data.size(); i++) {
        if (data[i] == key)
            return i;
    }
    return data.size();

}

bool SortedVectorDict::lookup(int key) const {
    int low_end = 0;
    int high_end = data.size()-1;
    while (low_end <= high_end) {
        auto midpoint = low_end + (high_end - low_end) / 2;
        if (key == data.at(midpoint)) {
            return true;
        }
        if (key < data.at(midpoint)) {
            high_end = midpoint - 1;
        }
        else {
            low_end = midpoint + 1;
        }
    }
    return false;
}

void SortedVectorDict::remove(int key) {
    // If key is a member, replaces it with the last item on the list.

    int idx = lookup_idx(key);
    if(idx != data.size()) {
        data[idx] = data.back();
        data.pop_back();
        sortElements(data[idx], idx);
    }
}

void SortedVectorDict::sortElements(int key, int idx) {
    while (idx < data.size()-1 && data.at(idx) > data.at(idx + 1)) {
        data.at(idx) = data.at(idx + 1);
        data.at(idx + 1) = key;
        idx++;
    }
}
