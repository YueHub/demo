//
// Created by yue on 18-7-21.
//
#include <iostream>
#include <fstream>
#include <string>
#include "single_length_delimited_all.pb.h"


int main() {
    Example1 example1;
    example1.set_stringval("hello,world");
    example1.set_bytesval("are you ok?");

    Example1_EmbeddedMessage *embeddedExample2 = new Example1_EmbeddedMessage();

    embeddedExample2->set_int32val(1);
    embeddedExample2->set_stringval("embeddedInfo");
    example1.set_allocated_embeddedexample1(embeddedExample2);

    example1.add_repeatedint32val(2);
    example1.add_repeatedint32val(3);
    example1.add_repeatedstringval("repeated1");
    example1.add_repeatedstringval("repeated2");

    std::string filename = "single_length_delimited_all_example1_val_result";
    std::fstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!example1.SerializeToOstream(&output)) {
        std::cerr << "Failed to write example1." << std::endl;
        exit(-1);
    }


    return 0;
}