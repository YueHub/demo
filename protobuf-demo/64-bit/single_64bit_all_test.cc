//
// Created by yue on 18-7-21.
//
#include <iostream>
#include <fstream>
#include <string>
#include "single_64bit_all.pb.h"


void writeExample1(int val1, int val2, double val3);

int main() {
    writeExample1(1, -1, 1.2);
    return 0;
}

void writeExample1(int val1, int val2, double val3) {
    Example1 example1;
    example1.set_fixed64val(val1);
    example1.set_sfixed64val(val2);
    example1.set_doubleval(val3);

    std::string filename = "single_64bit_all_example1_val" + std::to_string(val1) + "+" + std::to_string(val2) + "+" + std::to_string(val3) + "_result";
    std::fstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!example1.SerializeToOstream(&output)) {
        std::cerr << "Failed to write example1." << std::endl;
        exit(-1);
    }
}
