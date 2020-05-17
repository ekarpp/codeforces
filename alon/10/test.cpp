#include <string>
#include <iostream>
int main(void)
{
    std::string s = "abcdeab";
    std::string ss = "abc";
    std::string sss = "cdef";

    std::cout << s.compare(1, 3, ss);

}
