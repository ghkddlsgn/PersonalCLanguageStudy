#include "Project1/multithreading/section01/part3.h"
#include <string>
#include <thread>

int main()
{
    std::thread thr(hello);
    thr.join();

    std::thread thr2(hello2, "asdfa");
    thr2.join();

    // thread with movable
    std::string str = "movable";
    std::cout<<"starting thread"<<std::endl;
    std::thread thr3(func, str);
    thr3.join();

    std::cout<<"Do i still have any data?" << " ";
    std::cout<<(str.empty() ? "No":"Yes") << ".\n";

    // thread with call reference
    std::thread str4(changestr, std::ref(str));
    str4.join();
    std::cout<<"value changes as "<<str<<"\n";

    // class memberfunction
    Greeter greeter;
    std::thread str5(&Greeter::hello, &greeter);
    str5.join();
    
    std::thread str6(&Greeter::hello_with_print, &greeter, "hello");
    str6.join();

    // lambda
    int i = 3;
    std::thread str7([&i]{i = i*2;});
    str7.join();
    std::cout<<i<<"\n";

    return 0;
}