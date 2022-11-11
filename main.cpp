// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "options_parser/options_parser.h"

#define BUF_SIZE 16384

int main(int argc, char* argv[]) {
    command_line_options_t command_line_options{argc, argv};
    std::string main_output;

    for (std::basic_string<char> file_name: command_line_options.get_filenames()) {
        assert_file_exist(file_name);
        int myfile;
        ssize_t bytes_read=-1;
        char line[BUF_SIZE];
        myfile = open(file_name.c_str(), O_RDONLY);

        while ((bytes_read=read(myfile,line,BUF_SIZE))>0) {

            if (command_line_options.get_A_flag()){
                std::string new_line;

                for (int i=0; i< bytes_read; i++){
                    char c = line[i];
                    if (!std::isprint(c) && !std::isspace(c)){
                        std::ostringstream os;
                        os << std::hex << std::uppercase << (int) (c & 0xff);
                        new_line += "\\x" + os.str();
                    }else {
                        new_line += c;

                    }
                }
                main_output.append(new_line);
            } else {
                main_output.append(line);
            }
        }
        //main_output.append("\r");
        close(myfile);
    }

    write(1, main_output.c_str(), main_output.length());

    return 0;
}
