#ifndef __MY_SOLUTION_HPP__
#define __MY_SOLUTION_HPP__

#include<iostream>
#include"reclists.hpp"

int numNodesAtTheTopLevel(list p);
list append(list p, list q);
list reverse(list p);

// Implemented
bool is_lat(list p);
bool member(list p, list q);
list last(list p);
list list_pair(list p, list q);
list firsts(list p);
list flat(list p);
bool two_the_same(list p, list q);
bool equal(list p, list q);
list total_reverse(list p);
list shape(list p);

list intersection(list p, list q);
// list list_union(list p, list q);
list substitute(list oldList, list newList, list p);
list remove(list p, list a);
// bool subset(list p, list q);



#endif
