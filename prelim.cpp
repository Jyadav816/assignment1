#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    char name;
    gethostname(&name, 1024);
    cout << name;
    cout << "helloworld";
    return 0;
}
