cmake_minimum_required(VERSION 3.29)
project(DictionaryBenchmarkAvgOnly)

set(CMAKE_CXX_STANDARD 20)

add_executable(DictionaryBenchmarkAvgOnly
        main.cpp
        Dictionary.hpp
        UnsortedVectorDict.cpp
        UnsortedVectorDict.hpp
        SortedVectorDict.cpp
        SortedVectorDict.hpp
        UnsortedLinkedListDict.cpp
        UnsortedLinkedListDict.hpp
        SortedLinkedListDict.cpp
        SortedLinkedListDict.hpp
)


add_test(NAME AllTests COMMAND tests)
