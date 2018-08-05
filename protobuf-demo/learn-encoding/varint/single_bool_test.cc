//
// Created by yue on 18-7-21.
//
#include <iostream>
#include <fstream>
#include <string>
#include "single_bool.pb.h"


void writeExample1(bool val);

int main() {
    writeExample1(true);
    writeExample1(false);
    return 0;
}

void writeExample1(bool val) {
    Example1 example1;
    example1.set_boolval(val);

    std::string filename = "single_bool_example1_val" + std::to_string(val) + "_result";
    std::fstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!example1.SerializeToOstream(&output)) {
        std::cerr << "Failed to write example1." << std::endl;
        exit(-1);
    }
}
