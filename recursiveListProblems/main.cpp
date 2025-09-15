//Grant Tatge

#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

// Get a list from the user for a specific purpose,
// and output that list
list get_list(std::string purpose) {
    std::cout << "Enter a list for " << purpose << ": ";
    list p = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p);
    return p;
}

void testNumNodesAtTheTopLevel() {
    // Test this numNodesAtTheTopLevel 3 times.

    auto p = get_list("testing numNodesAtTheTopLevel");
    std::cout << "The number of nodes at the top-level is " << numNodesAtTheTopLevel(p) << std::endl;

    p = get_list("testing numNodesAtTheTopLevel");
    std::cout << "The number of nodes at the top-level is " << numNodesAtTheTopLevel(p) << std::endl;

    p = get_list("testing numNodesAtTheTopLevel");
    std::cout << "The number of nodes at the top-level is " << numNodesAtTheTopLevel(p) << std::endl;
}

void testNumAtomsAtTheTopLevel() {
    auto p = get_list("testing numAtomsAtTheTopLevel");
    std::cout << "The number of atoms at the top-level is " << numAtomsAtTheTopLevel(p) << std::endl;

    p = get_list("testing numAtomsAtTheTopLevel");
    std::cout << "The number of atoms at the top-level is " << numAtomsAtTheTopLevel(p) << std::endl;

    p = get_list("testing numAtomsAtTheTopLevel");
    std::cout << "The number of atoms at the top-level is " << numAtomsAtTheTopLevel(p) << std::endl;

}

void testFind() {
    auto p = get_list("testing find");
    auto q = get_list("input an atom, q");
    if (find(p, q) == true) {
        std::cout << "Found atom" << std::endl;
    }
    else {
        std::cout << "Atom not found" << std::endl;
    }
}

void testAreEqual() {
    auto p = get_list("testing areEqual \nInput a list of atoms p");
    auto q = get_list("Input a list of atoms q");
    if (areEqual(p, q) == true) {
        std::cout << "Lists are equal" << std::endl;
    }
    else {
        std::cout << "Lists are not equal" << std::endl;
    }
}

void testEvenNumberOfAtoms() {
    auto p = get_list("testing evenNumberOfAtoms \nInput a list of atoms p");
    if (evenNumberOfAtoms(p) == true) {
            std::cout << "even number of atoms" << std::endl;
    }
    else {
        std::cout << "not an even number of atoms" << std::endl;
    }
}

void testEveryOtherAtom() {
    auto p = get_list("testing everyOtherAtom \nInput a list of atoms p");
    auto q = get_list("Input a list of atoms q");
    if (everyOtherAtom(p, q) == true) {
        std::cout << "p has every other atom of q" << std::endl;
    }
    else {
        std::cout << "p does not have every other atom of s" << std::endl;
    }
}

int main()
{

    testNumNodesAtTheTopLevel();
    testNumAtomsAtTheTopLevel();
    testFind();
    testAreEqual();
    testEvenNumberOfAtoms();
    testEveryOtherAtom();

    return 0;
}
