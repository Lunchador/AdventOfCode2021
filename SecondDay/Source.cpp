#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int hor = 0;
int depth = 0;
int aim = 0;

int main() {
    /*string line;
    ifstream myfile("ws.txt");
    if (myfile.is_open())
    {
        string delimeter = " ";
        while (getline(myfile, line))
        {
            string direction = line.substr(0, line.find(delimeter));
            int value_to_add = stoi(line.substr(line.find(delimeter), line.at(line.length() - 1)));
            if (line.at(0) == 'f') {
                hor += value_to_add;
            }
            else if (line.at(0) == 'u') {
                depth -= value_to_add;
            }
            else {
                depth += value_to_add;
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    cout << hor * depth;*/

    string line;
    ifstream myfile("ws1.txt");
    if (myfile.is_open())
    {
        string delimeter = " ";
        while (getline(myfile, line))
        {
            string direction = line.substr(0, line.find(delimeter));
            int value_to_add = stoi(line.substr(line.find(delimeter), line.at(line.length() - 1)));
            if (line.at(0) == 'f') {
                hor += value_to_add;
                depth += aim * value_to_add;
            }
            else if (line.at(0) == 'u') {
                aim -= value_to_add;
            }
            else {
                aim += value_to_add;
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    cout << hor * depth;

}