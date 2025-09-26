#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

int main()
{

    std::cout << "Enter a list: ";
    list p = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p);
    std::cout << "The number of nodes at the top level of the input list is: "
        << numNodesAtTheTopLevel(p) << std::endl;
    return 0;
}
