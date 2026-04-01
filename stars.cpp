#include <iostream>

int main()
{
    std::cout << "What is your name? ";
    std::string x;
    std::cin >> x;
    std::cout << "Hello, " + x + "!\n\n";
    
    std::string cont = "y";
    while(cont == "y") {
        std::cout << "How many stars do you want? ";
        int count;
        std::cin >> count;
        std::cout << "\n";
        for(int i = 0; i < count; i++) {
            std::cout << "*";
        }
        std::cout << "\n\n";
        std::cout << "Do you want more stars? [y/n] ";
        std::cin >> cont;
    }
    std::cout << "\nGoodbye, " + x + "!\n";
    
    return 0;
}
