//Grant Tatge

#include "reclists.hpp"
#include "solutions.hpp"
#include <cassert>

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp. The function-prototypes
// for append and reverse are already in solutions.hpp.


int numNodesAtTheTopLevel(list p) {
    // p is one of
    //    a null list
    //    an atom
    //    a recursive list

    // The function returns the number of nodes at the top-level
    // of p.

    if( is_null(p) )
        return 0;
    if( is_atom(p) )
        return 1;
    return 1 + numNodesAtTheTopLevel(cdr(p));
}


int numAtomsAtTheTopLevel(list p) {
// pre-condition: p is not an atom

// This function receives a recursive list that
// is either null or a list of lists and counts
// the number of atoms at its top level.

// Here is a sample input/output
// input: (((a b) c) d (a b))  output: 1
// input: (a b c d e) output: 5
// input: () output 0

    assert(!is_atom(p));
    if (is_null(p))
        return 0;
    if (is_atom(car(p))) {
        return 1 + numAtomsAtTheTopLevel(cdr(p));
    }
    return numAtomsAtTheTopLevel(cdr(p));
}

bool find(list p, list q) {
    // p is a list that contains atoms; q is an atom
    // Does p have an atom whose value is the same as that of q?
    if (is_null(p) || is_atom(p)) {
        return false;
    }
    if (!is_atom(q)) {
        std::cerr << "Data invalid" << std::endl;
        exit(0);
    }
    if (eq(car(p), q)) {
        return true;
    }
    return find(cdr(p), q) || find(car(p), q);
}

bool areEqual(list p, list q) {
    // p is a list of atoms
    // q is a list of atoms
    // p & q have the same number of atoms
    // the function returns true if the atoms
    // in p are the same as those in q and in the same order

    // p is (a b c d) q is (a b c d). the function returns true
    // p is (a b c d) q is (b a c d). the function false
    if (is_atom(q) || is_atom(p)) {
        std::cerr << "Data invalid" << std::endl;
        exit(0);
    }
    if (is_null(p) && is_null(q)) {
        return true;
    }
    if (is_null(p) || is_null(q)) {
        return false;
    }
    if (eq(car(p), car(q))) {
        return areEqual(cdr(p), cdr(q));
    }
    return false;
}

bool evenNumberOfAtoms(list p) {
// p is a list of atoms. It might be empty -- a null list.
// This function returns true if p contains an even number of
// atoms. Otherwise, it returns false.
// For example, given the following list
// (a b c d e f g h i j)
// the function returns true as there are 10 atoms on this list.
// On the other hand given this list
// (a b c d e)
// the function should return false as the list contains 5 atoms.
    if (is_null(p)) {
        return true;
    }
    if (is_atom(p)) {
        std::cerr << "Data invalid" << std::endl;
        exit(0);
    }
    if (evenNumberOfAtoms(cdr(p))) {
        return false;
    }
    return true;
}

bool everyOtherAtom(list p, list q) {
    // each of p and q is a list of atoms or an empty list.
    // The functions return true if the i-th atom of p appears
    // in the 2*i-th position of q or not.
    if (is_null(p)) {
        return true;
    }
    if (is_null(q)) {
        return false;
    }
    //if (is_null(cdr(p))) {
    //    return false;
    //}
    if (eq(car(p), car(cdr(q)))) {
        return everyOtherAtom(cdr(p), cdr(cdr(q)));
    }
    return false;
}