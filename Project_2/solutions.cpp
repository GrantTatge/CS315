#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp.
//


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

list append(list p, list q) {
    if (is_null(p)) {
        return q;
    }
    return cons(car(p), append(cdr(p), q));
}

list reverse(list p) {
    if (is_null(p)) {
        return p;
    }

    return append(reverse(cdr(p)), cons(car(p), null()));
}

bool is_lat(list p) {
    // p is a list
    // returns true if the list is lateral, false if not
    if (is_null(p)) {
        return true;
    }
    if (!is_atom(car(p))) {
        return false;
    }

    return is_lat(cdr(p));
}

bool member(list p, list q) {
    // p is an atom, q is a list
    // returns true if p is in q
    if (is_atom(q) && eq(p, q)) {
        return true;
    }
    if (is_null(q) || is_atom(q)) {
        // if q is an atom and this is reached, we know q != p
        return false;
    }

    return member(p, cdr(q)) || member(p, car(q));
}

list last(list p) {
    // returns the last atom or list in list p
    if (is_null(cdr(p))) {
        return p;
    }

    return last(cdr(p));
}

list list_pair(list p, list q) {
    // p and q are lists of atoms of the same length
    // returns a list in which every "pair" is added as a list to the return list
    if (is_null(p)) {
        return null();
    }

    list currPair = append(car(p), car(q));
    return append(currPair, list_pair(cdr(p), cdr(q)));
}

list firsts(list p) {
    // p is a list
    // returns a list of the atoms at the first spot in each "level" of the list
    if (is_null(cdr(p))) {
        return cons(car(car(p)), null());
    }

    auto currAtom = cons(car(car(p)), null());
    return append(currAtom, firsts(cdr(p)));
}

list flat(list p) {
    // p is a list
    // returns a lateral (i.e. flattened) version of p
    if (is_null(p) || is_atom(p)) {
        return null();
    }
    if (is_atom(car(p))) {
        return append(cons(car(p), null()), flat(cdr(p)));
    }

    return append(flat(car(p)), flat(cdr(p)));
}

bool two_the_same(list p, list q) {
    // p and q are lists
    // returns true if p and q share at least one atom
    if (is_null(p)) {
        return false;
    }
    if (!is_atom(car(p))) {
        return two_the_same(car(p), q) ||
            two_the_same(cdr(p), q);
    }

    return member(car(p), q) || two_the_same(cdr(p), q);
}

bool equal(list p, list q) {
    // p and q are lists
    // returns true if p and q are identical, i.e. same structure and atoms
    if (is_null(p) && is_null(q)) {
        return true;
    }
    if (!is_null(p) && !is_null(q)
        && !is_atom(car(p)) && !is_atom(car(q))) {
        return equal(car(p), car(q)) && equal(cdr(p), cdr(q));
    }
    if ((is_null(p) && !is_null(q))
    || (!is_null(p) && is_null(q))
    || (is_atom(car(p)) && !is_atom(car(q)))
    || (!is_atom(car(p)) && is_atom(car(q)))
    || !eq(car(p), car(q))) {
        return false;
    }
    return equal(cdr(p), cdr(q));
}

list total_reverse(list p) {
    // p is a list
    // reverses each part of the given list, so that it reads entirely backwards
    if (is_null(p)) {
        return p;
    }
    if (!is_atom(car(p))) {
        return append( total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
    }
    return append(total_reverse(cdr(p)), cons(car(p), null()));
}

list shape(list p) {
    // p is a list
    // returns a list showing the structure of p without any atoms
    if (is_null(p)) {
        return null();
    }
    if (!is_atom(car(p))) {
        return cons(shape(car(p)), shape(cdr(p)));
    }
    return append(null(), shape(cdr(p)));
}

list intersection(list p, list q) {
    // p and q are lists of atoms
    // returns the intersection of p and q
    if (is_null(p)) {
        return null();
    }
    if (member(car(p), q)) {
        return cons(car(p), intersection(cdr(p), q));
    }
    return intersection(cdr(p), q);
}

list substitute(list oldList, list newList, list p) {
    // oldList is an atom, newList is an atom or list, p is a list
    // replaces each instance of oldList in list p with newList
    if (is_null(p)) {
        return null();
    }
    if (!is_atom(car(p))) {
        return cons(substitute(oldList, newList, car(p)), substitute(oldList, newList, cdr(p)));
    }
    if (eq(car(p), oldList)) {
        return cons(newList, substitute(oldList, newList, cdr(p)));
    }
    return cons(car(p), substitute(oldList, newList, cdr(p)));
}

list remove(list p, list a) {
    // p is a list, a is an atom
    // removes each instance of a from p, returning a list with no instances of a
    if (is_null(p)) {
        return null();
    }
    if (eq(car(p), a)) {
        return remove(cdr(p), a);
    }
    return cons(car(p), remove(cdr(p), a));
}