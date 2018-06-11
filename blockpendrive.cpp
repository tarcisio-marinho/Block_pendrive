#include<iostream>
#include <unistd.h>
#include <cstring>

void error(const char *s){
    std::cout << s << std::endl;
    exit(-1);
}


void help(const char * s){
    std::cout << " Usage: " << s << " [allow/block]" << std::endl;
    exit(0);
}


bool is_root(){
    if(getuid()!= 0){
        return false;
    }
    return true;
}


void allow(){
    char * allow = "sudo chmod 000 /media/";

    if(is_root()){
        system(allow);
        std::cout << "Done!" << std::endl;
    }else{
        error("You're not root");
    }
}


void block(){
    char * block = "sudo chmod 777 /media/";
    if(is_root()){
        system(block);
        std::cout << "Done!" << std::endl;
    }else{
        error("You're not root");
    }
}



int main(int argc, char *argv[]){

    if(argc == 1){
        help(argv[0]);
    }
    if(argc > 1 && argc < 3){
        if(strcmp(argv[1], "allow")){
            allow();
        }else if(strcmp(argv[1], "block")){
            block();
        }else{
            help(argv[0]);
        }
    }else{
        help(argv[0]);
    }
}