// Grant Tatge & Danny Meza

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>

bool iterativeMember(const std::vector<int> &numbers, size_t n, int key) {
      // Write an iterative solution to the Member Problem.
      // Determine if "key" is one of the values in numbers[0..n-1].
    for (auto i : numbers) {
        if (i == key) {
            return true;
        }
    }
    return false;
}

bool recursiveMember(const std::vector<int> &numbers, size_t n, int key) {
    // Write a recursive solution to the member problem.
    // Determine if "key" is one of the values in numbers[0..n-1].
    if (n == 0) {
        return false;
    }
    if (numbers.at(n - 1) == key) {
        return true;
    }
    return recursiveMember(numbers, n - 1, key);
}

bool iterativeAreIdentical(const std::vector<int> &numbers1, const std::vector<int> &numbers2, size_t n) {
    // Write an iterative solution to the are identical problem.
    // Given two vectors each of which has n elements, do they contain the same elements in
    // the same positions?

    // Example 1:
    // numbers1 contains 34, 21, 80, 56, 100
    // numbers2 contains 34, 21, 80, 56, 100
    // iterativeAreIdentical(numbers1, number2, 5) should return true.

    // Example 2:
    // numbers1 contains 32, 21, 80, 56, 100
    // numbers2 contains 34, 100, 30, 56, 21
    // iterativeAreIdentical(numbers1, number2, 5) should return false.
    assert(numbers1.size() == numbers2.size());

    for (int i = 0; i < numbers1.size() - 1; i++) {
        if (numbers1.at(i) != numbers2.at(i)) {
            return false;
        }
    }
    return true;
}

bool recursiveAreIdentical(const std::vector<int> &numbers1, const std::vector<int> &numbers2, size_t n) {
    // Write a recursive solution to the are-identical problem.
    // Given two vectors each of which has n elements, do they contain the same elements in
    // the same positions?

    // Example 1:
    // numbers1 contains 34, 21, 80, 56, 100
    // numbers2 contains 34, 21, 80, 56, 100
    // iterativeAreIdentical(numbers1, number2, 5) should return true.

    // Example 2:
    // numbers1 contains 32, 21, 80, 56, 100
    // numbers2 contains 34, 100, 30, 56, 21
    // iterativeAreIdentical(numbers1, number2, 5) should return false.
    if (n == 0)
        return true;
    if (numbers1.at(n - 1) != numbers2.at(n - 1)) {
        return false;
    }
    return recursiveAreIdentical(numbers1, numbers2, n - 1);

}

bool iterativePalindrome(const std::string &s) {
     // Write an function that determines whether a string is a palindrome.
     // A string is a palindrome if it reads the same forward and backward.
     // For example, "dad" and "kayak" are palindromes.
     //
     // Hint: You can use the array subscript operator to access characters.
     // For example, if s is a string, then s[0], s[1], and s[s.length()-1]
     // refer to the first, second, and last characters, respectively.
    int i = 0; int j = s.length() - 1;
    while (i <= j) {
        if (s.at(i) != s.at(j)) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


bool recursivePalindrome(const std::string &s, size_t leftIdx, size_t rightIdx) {
   // Given a string, write a recursive function to determine whether the characters
   // in the range s[leftIdx] ... s[rightIdx] form a palindrome.

    if (s.at(leftIdx) != s.at(rightIdx)) {
        return false;
    }
    if (leftIdx >= rightIdx) {
        return true;
    }

    return recursivePalindrome(s, leftIdx + 1, rightIdx - 1);
}

int countInversionsIteratively(const std::vector<int> &v, size_t n) {
    // Write a function that counts the number of inversions in a vector.
    // Two consecutive values form an inversion at index i if v.at(i) > v.at(i+1).
    // Assume that i+1 < n.
    //
    // A sorted vector of n elements has no inversions,
    // because v.at(i) <= v.at(i+1) for 0 <= i < n - 1.
    //
    // For example, if v contains {5, 8, 10, 6, 7},
    // the function should return 1, since 10 > 6 is the only inversion.
    int count = 0;
    for (size_t i = 0; i < n - 1; i++) {
        if (v.at(i) > v.at(i + 1)) {
            count++;
        }
    }
    return count;
}

int countInversionsRecursively(const std::vector<int> &v, size_t n) {
     // Count and return the number of inversion in the first n
     // elements of v, recursively.
    if (n <= 1) {
        return 0;
    }
    if (v.at(n - 1) < v.at(n - 2)) {
        return countInversionsIteratively(v, n - 1) + 1;
    }
    return countInversionsRecursively(v, n - 1);
}

bool iterativePalindrome2(const std::string &s) {
      // Write a function that determines whether a string is a palindrome.
      // In this version, the string may contain non-letter characters.
      // Ignore all non-letter characters and only compare letters
      // to decide if the string is a palindrome.
      //
      // For example, the string "a man, a plan, a canal, panama"
      // is a palindrome when non-letter characters are ignored.
      //
      // Important: Do NOT preprocess the string by collecting only letters
      // into a new string. You should implement your solution in a single loop
      // that skips non-letter characters as needed.

      // Note: function isalpha(c) returns true if c is an alphabetic character.
    auto i = 0;
    auto j = s.length() - 1;
    while (i < s.length() - 1) {
        if (!isalpha(s.at(i))) {
            i++;
            continue;
        }
        if (!isalpha(s.at(j))) {
            j--;
            continue;
        }
        if (tolower(s.at(i)) != tolower(s.at(j))) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


bool recursivePalindrome2(const std::string &s, int leftIdx, int rightIdx) {
    // Given a string, determine if the characters in the range
    // s[leftIdx] ... s[rightIdx] form a palindrome or not.
    // Write this one recursively.

    // You should NOT preprocess the string.

    // You should NOT preprocess the string. That is,
    // you can not write a loop to collect the letters
    // into a string and then process this new string.

    if(leftIdx >= rightIdx) {
        return true;
    }

    if (!isalpha(s.at(leftIdx))) {
        return recursivePalindrome2(s, leftIdx + 1, rightIdx);
    }

    if (!isalpha(s.at(rightIdx))) {
        return recursivePalindrome2(s, leftIdx, rightIdx - 1);
    }

    if(tolower(s.at(leftIdx)) != tolower(s.at(rightIdx))) {
        return false;
    }

    return recursivePalindrome2(s, leftIdx + 1, rightIdx - 1);
}

bool iterCheckForIntersection(int key, const std::vector<int> &checkedVec) {
    for (auto value : checkedVec) {
        if (key == value) {
            return true;
        }
    }
    return false;
}

void iterativeIntersection(const std::vector<int> &values1,
                           const std::vector<int> &values2,
			   std::vector<int> &result,
			   std::size_t values1NumElements,
			   std::size_t values2NumElements) {
    // "values1" and "values2", two independent vectors, have "values1NumElements" and
    // "values2NumElements" values. This function finds the elements that are on both lists and
    // adds them to "result".


    // Example:
    // values1 contains: 1, 2, 13, 4, 15, 6, 7
    // values1NumElements is 7

    // values2 contains: 5, 2, 10, 4, 21, 6
    // values2NumElements is 6

    // std::vector<int> result = {}  -- an empty vector
    // After having called iterativeIntersection(values1, values2, result, 7, 6)
    // result should contain: 2, 4, 6. These are elements that are on both lists.

    // You will have to write a helper function to solve this problem. This function
    // performs a lookup and based on the outcome, the calling function decide whether
    // to add an element to the "result" or not.
    for (auto value : values1) {
        if (iterCheckForIntersection(value, values2) == true) {
            result.push_back(value); // value is in values2 and not in results add to result
        }
    }
}

void recursiveIntersection(const std::vector<int> &values1,
                           const std::vector<int> &values2,
                           std::vector<int> &result, 
                           std::size_t values1NumElements,
			   std::size_t values2NumElements) {
    // "values1" and "values2", two independent vectors, have "values1NumElements" and
    // "values2NumElements" values. This function finds the elements that are on both lists and
    // adds them to "result".


    // Example:
    // values1 contains: 1, 2, 13, 4, 15, 6, 7
    // values1NumElements is 7

    // values2 contains: 5, 2, 10, 4, 21, 6
    // values2NumElements is 6

    // std::vector<int> result = {}  -- an empty vector
    // After having called iterativeIntersection(values1, values2, result, 7, 6)
    // result should contain: 2, 4, 6. These are elements that are on both lists.


    // You will have to write a recursive helper function to solve this problem. This function
    // performs a lookup and based on the outcome, the calling function decide whether
    // to add an element to the "result" or not.
    for (auto value : values1) {
        if (iterCheckForIntersection(value, values2) == true) {
            result.push_back(value); // value is in values2 and not in results add to result
        }
    }


}

void testMember( bool (*member)(const std::vector<int> &, size_t, int)) {

    std::vector<int> numbers = {10, 20, 65, 23, 66, 42, 12, 55};
    std::cout << "Testing iterative member begins. \n";
    std::cout << "Do not expect any output if the function works properly.\n";

    // Yes cases:
    for(auto v: numbers) {
        if (!member(numbers, numbers.size(), v)) {
            std::cout << "Iterative member fails. " << v
                      << " is a member, but the function returned false.\n";
            exit(1);
        }
    }

    // No cases
    std::vector<int> numbers2 = {9, 22, 68, 28, 60, 38, 120, 50};
    for(auto v: numbers2) {
        if (member(numbers, numbers.size(), v)) {
            std::cout << "Iterative member fails. " << v
                      << " is not a member, but the function returned true.\n";
            exit(1);
        }
    }

    std::cout << "Testing iterative member ends...\n";
}

void testAreIdentical(bool (*areIdentical)(const std::vector<int> &, const std::vector<int> &, size_t n), int id) {


    std::vector<int> numbers1 = {10, 28, 65, 23, 66, 42, 12, 55};
    std::vector<int> numbers2 = {10, 28, 65, 23, 70, 42, 12, 55};

    std::cout << "Testing are identical begins...\n";
    if( areIdentical(numbers1, numbers1, numbers1.size()) )
        std::cout << "Are Identical works! (" << id << ")" << std::endl;
    else
        std::cout << "iterativeAreIdentical doesn't work! (" << id << ")" << std::endl;

    if( areIdentical(numbers1, numbers2, numbers1.size()) )
        std::cout << "iterativeAreIdentical doesn't work! (" << id + 1 << ")" << std::endl;
    else
        std::cout << "Are Identical works! (" << id + 1 << ")" << std::endl;
    std::cout << "Testing are identical begins...\n";

}

void testInterativePlaindrome() {
    std::string s1 = "madam", s2 = "madman";

    if(iterativePalindrome(s1))
        std::cout << "iterativePalindrome works! (1)" << std::endl;
    else
        std::cout << "iterativePalindrome doesn't work! (1)" << std::endl;


    if(! iterativePalindrome(s2))
        std::cout << "iterativePalindrome works! (3)" << std::endl;
    else
        std::cout << "iterativePalindrome doesn't work! (3)" << std::endl;

}

void testRecursivePalindrome() {
    std::string s1 = "madam", s2 = "madman";

    if(recursivePalindrome(s1, 0, s1.length() - 1))
        std::cout << "recursivePalindrome works! (2)" << std::endl;
    else
        std::cout << "recursivePalindrome doesn't work! (2)" << std::endl;

    if(! recursivePalindrome(s2, 0, s2.length() - 1))
        std::cout << "recursivePalindrome works! (4)" << std::endl;
    else
        std::cout << "recursivePalindrome doesn't work! (4)" << std::endl;

}

void testInterativePlaindrome2() {
    std::string s3 = "a man, a plan, a canal, panama", s4 = "a man, no plan, a canal, panama";

    if(iterativePalindrome2(s3))
        std::cout << "iterativePalindrome2 works! (5)" << std::endl;
    else
        std::cout << "iterativePalindrome2 doesn't work! (5)" << std::endl;

    if(! iterativePalindrome2(s4))
        std::cout << "iterativePalindrome2 works! (5)" << std::endl;
    else
        std::cout << "iterativePalindrome2 doesn't work! (5)" << std::endl;

}

void testRecursivePlaindrome2() {
    std::string s3 = "a man, a plan, a canal, panama", s4 = "a man, no plan, a canal, panama";

    if(recursivePalindrome2(s3, 0, s3.length() - 1))
        std::cout << "recursivePalindrome2 works! (6)" << std::endl;
    else
        std::cout << "recursivePalindrome2 doesn't work! (6)" << std::endl;

    if(! recursivePalindrome2(s4, 0, s4.length() - 1))
        std::cout << "recursivePalindrome2 works! (6)" << std::endl;
    else
        std::cout << "recursivePalindrome2 doesn't work! (6)" << std::endl;

}

void testCountInversions(int (*countInversions)(const std::vector<int> &, size_t), int id) {
    std::vector<int> increasing = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        decreasing = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        mixed = {1, 10, 2, 9, 3, 8, 4, 7, 5, 5};
    int mixedInversions = 4;

    if(countInversions(increasing, increasing.size()) == 0)
        std::cout << "Count Inversions works! (" << id << ")\n";
    else
        std::cout << "Count Inversions doesn't work! (" << id << ")\n";

    if(countInversions(decreasing, increasing.size()) == decreasing.size() - 1)
        std::cout << "Count Inversions works! (" << id + 1 << ")\n";
    else
        std::cout << "Count Inversions doesn't work! (" << id + 1 << ")\n";

    if(countInversions(mixed, increasing.size()) == mixedInversions)
        std::cout << "Count Inversions works! (" << id + 2 << ")\n";
    else
        std::cout << "Count Inversions doesn't work! (" << id + 2 << ")\n";

}

void testIntersection(void (*intersection)(const std::vector<int> &values1,
                                   const std::vector<int> &values2,
                                   std::vector<int> &result,
                                   size_t values1NumElements, size_t values2NumElements),
                      int id) {

    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
            v2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
            v3 = {10, 11, 12, 13, 14},
            result;


    // a full intersection

    std::cout << "Testing intersection begins...\n";
    std::cout << "No output will be printed if all tests pass.\n";
    intersection(v1, v2, result, v1.size(), v2.size());
    if(result.size() != v1.size()) {
        std::cout << "Intersection fails (" << id << ")\n";
        return;
    }

    for(auto v: result)
        if(!iterativeMember(v1, v1.size(), v)) {
            std::cout << "Intersection fails (" << id + 1 << ")\n";
            return;
        }


    // v1 and v3 have only one value in common

    std::vector<int> result2;
    intersection(v1, v3, result2, v1.size(), v3.size());

    if(result2.size() != 1) {
        std::cout << "Intersection fails (" << id + 2 << ")\n";
        return;
    }

    if(result2.at(0) != 10)
        std::cout << "Intersection fails (" << id + 3 << ")\n";

    std::cout << "Testing intersection ends...\n";
}

int main() {

     testMember(iterativeMember);
     testMember(recursiveMember);
//
     testAreIdentical(iterativeAreIdentical, 1);
     testAreIdentical(recursiveAreIdentical, 3);

     testInterativePlaindrome();
     testRecursivePalindrome();
// // //
       testInterativePlaindrome2();
       testRecursivePlaindrome2();
// //
     testCountInversions(countInversionsIteratively, 1);
     testCountInversions(countInversionsRecursively, 4);
//
     // testIntersection(iterativeIntersection, 1);
     // testIntersection(recursiveIntersection, 5);
//
    return 0;
}
