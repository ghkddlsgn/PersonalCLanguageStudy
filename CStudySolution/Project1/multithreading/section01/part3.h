#pragma once
#include <iostream>
#include <string>

void hello();

void hello2(std::string str){
    std::cout<<str<<std::endl;
}

void func(std::string&& str){
    std::cout<<"ownership of \""<<str<<"\" transferred to thread<< '\n";
}

void changestr(std::string& str){
    str = "xxxxxx";
}

class Greeter{
    public:
    void hello(){
        std::cout<<"Hello\n";
    }
    void hello_with_print(std::string str){
        std::cout<<str<<"\n";
    }
};