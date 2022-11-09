// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
//#include <unistd.h>
#include "options_parser/options_parser.h"

int main(int argc, char* argv[]) {
    command_line_options_t command_line_options{argc, argv};
    std::cout << "A flag value: " << command_line_options.get_A_flag() << std::endl;

    for(std::basic_string<char> i: command_line_options.get_filenames()){
        std::cout << i << std::endl;
    }

    return 0;
}
