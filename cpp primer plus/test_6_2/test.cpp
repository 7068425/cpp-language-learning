#include <iostream>
int main()
{
    char ch;
 
    std::cout << "Type, and I shall repeat.\n";
    std::cin.get(ch);
    while (ch != '.')
    {
        if (ch == '\n')
            std::cout << ch;     // done if newline
        else
            //std::cout << ++ch;   // done otherwise   输出加1后的字符  
            std::cout << ch+1;   // done otherwise   输出加1后的ASCII码
        std::cin.get(ch);
    }
    // try ch + 1 instead of ++ch for interesting effect
    std::cout << "\nPlease excuse the slight confusion.\n";
    // std::cin.get();
    // std::cin.get();
    return 0;
}