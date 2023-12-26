#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
    std::vector<int> linenums;
    std::string line;
    int total = 0;
    int linetotal = 0;
    std::ifstream foobar("input.txt");

    for (;std::getline(foobar, line);) // does it until eof
    {
        for (int i = 0; i < line.size(); ++i) //search through line for num
        {
            if (isdigit(line[i]))
            {
                linenums.push_back(line[i] - '0'); // typecasts value
            }
        }
        if (linenums.size() == 1) {
            linetotal = (linenums.front() * 10) + linenums.front();
        }
        else {
            linetotal = (linenums.front() * 10) + linenums.back();
        }
        total += linetotal;
        linenums.clear();
        linetotal = 0;
    }
    foobar.close();
    std::cout << total;
    return 0;
}
