//
// Created by yue on 18-7-21.
//
#include <iostream>
#include <fstream>
#include <string>
#include "single_sint32.pb.h"


void writeExample1(int val);
void writeExample2(int val, int more = 0);

int main() {
    writeExample1(-1);
    writeExample1(-2);


    writeExample2(-1);
    writeExample2(-1, -2);
    return 0;
}

void writeExample1(int val) {
    Example1 example1;
    example1.set_sint32val(val);
    std::string filename = "single_sint32_example1_val" + std::to_string(val) + "_result";
    std::fstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!example1.SerializeToOstream(&output)) {
        std::cerr << "Failed to write example1." << std::endl;
        exit(-1);
    }
}

void writeExample2(int val, int more) {
    Example2 example2;
    std::string filename = "";

    if (more == 0) {
        example2.add_sint32val(val);
        filename = "single_sint32_example2_val" + std::to_string(val) + "_result";
    } else {
        example2.add_sint32val(val);
        example2.add_sint32val(more);
        filename = "single_sint32_example2_val" + std::to_string(val) + "+" + std::to_string(more) + "_result";
    }

    std::fstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!example2.SerializeToOstream(&output)) {
        std::cerr << "Failed to write example2." << std::endl;
        exit(-1);
    }
}