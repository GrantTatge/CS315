#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

// Helper functions for testing

list enterList(bool defaultMessage = true) {
    if (defaultMessage == true) {
        std::cout << "Enter a list: ";
    }
    list p = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p);
    return p;
}

list enterAtom(bool defaultMessage = true, std::string msg = "") {
    list p = null();
    while (!is_atom(p)) {
        if (defaultMessage == true) {
            std::cout << "Enter an atom: ";
        }
        else {
            std::cout << msg;
        }
        p = read_list();
        if (!is_atom(p)) {
            std::cout << "p should be an atom, i.e. 'q', not '(q)'" << std::endl;
        }
    }
    std::cout << "Echoing the atom that you entered below." << std::endl;
    write_list(p);
    return p;
}

bool isEmptyList(list p) {
    if (is_null(p)) {
        std::cout << "The list provided is empty." << std::endl;
        return true;
    }
    return false;
}

// Test functions

void test_numNodesAtTop(list p) {
    std::cout << "The number of nodes at the top level of the input list is: "
            << numNodesAtTheTopLevel(p) << std::endl;
}

void test_is_lat(list p) {
    if (isEmptyList(p) == false) {
        if (is_lat(p) == true) {
            std::cout << "The list consists entirely of atoms, so it is lateral. \n" << std::endl;
        }
        else std::cout << "The list has a recursive structure and does not consist entirely of atoms. \n" << std::endl;
    }
    else std::cout << "The list provided is empty; an empty list is lateral as it has no recursive structure." << std::endl;
}

void test_member(list q) {
    if (isEmptyList(q) == false) {
        list p = enterAtom();
        if (member(p, q) == true) {
            std::cout << "Atom p was found in list q \n" << std::endl;
        }
        else std::cout << "Atom p was not found in list q \n" << std::endl;}
}

void test_last(list p) {
    list lastMember = last(p);
    std::cout << "The last element in list p is ";
    write_list(lastMember);
    std::cout << "\n" << std::endl;
}

void test_list_pair() {
    std::cout << "Enter two lists of atoms of the same length: ";
    list p = enterList(false);
    list q = enterList(false);

    list listPairs = list_pair(p, q);
    std::cout << "The list of pairs between the two lists is ";
    write_list(listPairs);
    std::cout << std::endl;
}

void test_firsts() {
    std::cout << "Enter a list of lists of atoms: ";
    list p = enterList(false);

    list listFirsts = firsts(p);
    std::cout << "The firsts atoms in each list are ";
    write_list(listFirsts);
    std::cout << std::endl;
}

void test_flat() {
    list p = enterList();
    list listFlat = flat(p);
    std::cout << "The flattened list is ";
    write_list(listFlat);
}

void test_two_the_same() {
    std::cout << "Enter two lists: ";
    list p = enterList(false);
    list q = enterList(false);

    if (two_the_same(p, q) == true) {
        std::cout << "The two lists share at least one atom." << std::endl;
    }
    else std::cout << "The two lists do not share any atoms." << std::endl;
}

void test_equal() {
    std::cout << "Enter two lists: ";
    list p = enterList(false);
    list q = enterList(false);

    if (equal(p, q) == true) {
        std::cout << "The two lists are identical." << std::endl;
    }
    else std::cout << "The two lists are not identical." << std::endl;
}

void test_total_reverse() {
    list p = enterList();
    list listReversed = total_reverse(p);
    std::cout << "The reversed list is " << std::endl;
    write_list(listReversed);
}

void test_shape() {
    list p = enterList();
    list listShape = shape(p);
    std::cout << "The shape of the list is " << std::endl;
    write_list(listShape);
}

void test_intersection() {
    list p = enterList();
    list q = enterList();
    list listIntersection = intersection(p, q);
    std::cout << "The intersection list is " << std::endl;
    write_list(listIntersection);
}

void test_substitute() {
    auto oldAtom = enterAtom(false, "Enter an atom that will be in the list: ");
    std::cout << "Enter an atom or list to substitute the previous atom: ";
    auto newAtom = enterList(false);
    list p = enterList();
    list listSubstitute = substitute(oldAtom, newAtom, p);

    std::cout << "The list with the substituted atom / list is: " << std::endl;
    write_list(listSubstitute);
}

void test_remove() {
    list p = enterList();
    list a = enterAtom();
    list listRemove = remove(p, a);
    std::cout << "The list without the given atom is " << std::endl;
    write_list(listRemove);
}

int main()
{
     list p = enterList();
     test_is_lat(p);
     test_member(p);
     test_last(p);
     test_list_pair();
     test_firsts();
     test_flat();
     test_two_the_same();
     test_equal();
     test_total_reverse();
     test_shape();
     test_intersection();
     // test_union()
     test_intersection();
     test_substitute();
     test_remove();
    // test_subset()


    return 0;
}
