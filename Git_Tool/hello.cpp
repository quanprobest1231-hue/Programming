#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!, QUAN"};
    cout << "Message: Hello Xi" << endl;
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
