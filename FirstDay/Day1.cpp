#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int nums[2001];

int main() {
    /*string line;
    ifstream myfile("ws.txt");
    if (myfile.is_open())
    {
        int i = 0;
        while (getline(myfile, line))
        {
            nums[i] = stoi(line);
            i++;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    int increased = 0;
    for (int i = 1; i <= 2000; i++)
    {
        if (nums[i] > nums[i - 1]) {
            increased++;
        }
    }
    cout << increased;*/
    
    string line;
    ifstream myfile("ws1.txt");
    if (myfile.is_open())
    {
        int i = 0;
        while (getline(myfile, line))
        {
            nums[i] = stoi(line);
            i++;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    int increased = 0;
    for (int i = 2000; i > 2; i--)
    {
        int first = nums[i] + nums[i - 1] + nums[i - 2];
        int second = nums[i-1] + nums[i - 2] + nums[i - 3];
        if (first > second) {
            increased++;
        }
    }
    cout << increased;
}