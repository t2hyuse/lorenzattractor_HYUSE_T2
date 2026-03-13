/**
 * @file test_lorenzattractor.cxx
 * @brief Unit tests for lorenzattractor
 * @author Hyuse & T2
 */

#include "lorenzattractor.hxx"
#include <iostream>
#include <cassert>

void test_hello() {
    Lorenzattractor obj;
    obj.hello();
    std::cout << "[PASS] test_hello" << std::endl;
}

int main() {
    std::cout << "Running tests for lorenzattractor..." << std::endl;
    test_hello();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
