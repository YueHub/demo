//
// Created by yue on 18-7-21.
//
#include <iostream>
#include <fstream>
#include <string>
#include "single_enum.pb.h"


void writeExample1(Example1_COLOR val);

int main() {
    writeExample1(Example1_COLOR_BLUE);
    return 0;
}

void writeExample1(Example1_COLOR val) {
    Example1 example1;
    example1.set_colorval(val);
    std::string filename = "single_enum_example1_val" + std::to_string(val) + "_result";
    std::fstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!example1.SerializeToOstream(&output)) {
        std::cerr << "Failed to write example1." << std::endl;
        exit(-1);
    }
}
