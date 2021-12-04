#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <math.h>

using namespace std;

int most_common[12];

/*void findFrequency(string line) {
    for (int i = 0; i < line.length(); i++)
    {
        if (line.at(i) == '1')
        {
            most_common[i]++;
        }
    }
}*/

// works for oxygen
char findMostCommon(list<string> example, int index) {
    unsigned int j = 0;
    for (auto it = begin(example); it != end(example); ++it)
    {
        if ((*it).at(index) == '1')
        {
            j++;
        }
    }
    if (j >= (example.size() + 1) / 2)
    {
        return '1';
    }
    return '0';
}

int main() {
    /*string line;
    ifstream myfile("ws.txt");
    if (myfile.is_open())
    {
    while (getline(myfile, line))
    {
    for (int j = 0; j < line.length(); j++)
    {
    if (line.at(j) == '1')
    {
    frequency_of_ones[j]++;
    }
    };
    }
    myfile.close();
    }
    else cout << "Unable to open file";

    int gamma[12];
    int epsilon[12];
    for (int i = 0; i < 12; i++)
    {
    if (frequency_of_ones[i] > 500) {
    gamma[i] = 1;
    epsilon[i] = 0;
    }
    else {
    gamma[i] = 0;
    epsilon[i] = 1;
    }
    }

    for (int i = 0; i < 12; i++)
    {
    cout << gamma[i];
    }

    cout << endl;

    for (int i = 0; i < 12; i++)
    {
    cout << epsilon[i];
    }

    cout << endl;

    int gamma_int = 0;
    int epsilon_int = 0;
    for (int i = 0; i < 12; i++)
    {
    int holder = 1;
    if (gamma[i] == 1) {
    for (int j = 0; j < 12-i-1; j++)
    {
    holder = holder * 2;
    }
    gamma_int += holder;
    }
    else {
    for (int j = 0; j < 12 - i-1; j++)
    {
    holder = holder * 2;
    }
    epsilon_int += holder;
    }

    }
    cout << gamma_int * epsilon_int;*/

    list<string> oxygen;
    list<string> carbon;
    string words[1001];

    string line;
    ifstream myfile("ws1.txt");
    if (myfile.is_open())
    {
        int i = 0;
        while (getline(myfile, line))
        {
            words[i] = line;
            //findFrequency(line);
            oxygen.push_back(line);
            carbon.push_back(line);
            i++;
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";

    /*for (int i = 0; i < 5; i++)
    {
        std::cout << most_common[i] << " ";
    }

    std::cout << endl;*/

    cout << "most common" << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << findMostCommon(oxygen, i) << " ";
    }
    cout << endl;

    // find oxygen level
    int i = 0;
    while (oxygen.size() != 1)
    {
        vector<string> to_remove;
        char common = findMostCommon(oxygen, i);
        //cout << common << endl;
        for (auto it = begin(oxygen); it != end(oxygen); ++it) {
            //cout << *it << " " << (*it).at(i) << endl;
            if ((*it).at(i) != common)
            {
                to_remove.push_back(*it);
            }
        }
        //cout << "---removal---" << endl;
        for (int j = 0; j < to_remove.size(); j++)
        {
            //cout << to_remove[j] << endl;
            if (oxygen.size() == 1) {
                break;
            }
            oxygen.remove(to_remove[j]);
        }
        //cout << "---removal_end---" << endl;
        i++;
    }
    for (auto it = begin(oxygen); it != end(oxygen); ++it)
    {
        cout << *it << endl;
    }

    // find carbon level
    i = 0;
    while (carbon.size() != 1)
    {
        vector<string> to_remove;
        char common = findMostCommon(carbon, i);
        //cout << common << endl;
        for (auto it = begin(carbon); it != end(carbon); ++it) {
            //cout << *it << " " << (*it).at(i) << endl;
            if ((*it).at(i) == common)
            {
                to_remove.push_back(*it);
            }
        }
        //cout << "---removal---" << endl;
        for (int j = 0; j < to_remove.size(); j++)
        {
            //cout << to_remove[j] << endl;
            if (carbon.size() == 1) {
                break;
            }
            carbon.remove(to_remove[j]);
        }
        //cout << "---removal_end---" << endl;
        i++;
    }
    for (auto it = begin(carbon); it != end(carbon); ++it)
    {
        cout << *it << endl;
    }
    // find carbon level
    /*i = 1;
    while (carbon.size() != 1)
    {

        vector<string> to_remove;
        for (auto it = begin(carbon); it != end(carbon); ++it) {
            //cout << *it << " " << (*it).at(i) << endl;
            if ((*it).at(i) - '0' == most_common[i])
            {
                to_remove.push_back(*it);
            }
        }
        for (int j = 0; j < to_remove.size(); j++)
        {
            //cout << to_remove[j] << endl;
            if (carbon.size() == 1) {
                break;
            }
            carbon.remove(to_remove[j]);
        }
        i++;
    }
    for (auto it = begin(carbon); it != end(carbon); ++it)
    {
        //cout << *it << endl;
    }*/


    // not a solution to the actual problem
    /*int longest_oxygen = 0;
    int longest_carbon = 0;
    int max_oxygen = 0;
    int max_carbon = 0;
    int holder = 0;
    for (int i = 0; i < 1000; i++)
    {
        bool isLegit_oxygen = false;
        bool isLegit_carbon = false;
        for (int j = 0; j < 12; j++)
        {
            cout << words[i].at(j) - '0' << " ";
            if ((words[i].at(j)-'0') != most_common[j]) {
                if (longest_carbon == j) { longest_carbon++; }
            }
            else {
                if (longest_oxygen == j) { longest_oxygen++; }
            }
        }
        std::cout << longest_oxygen << " " << longest_carbon << endl;
        if (longest_oxygen > max_oxygen) {
            isLegit_oxygen = true;
            max_oxygen = longest_oxygen;
        }
        if (longest_carbon > max_carbon) {
            isLegit_carbon = true;
            max_carbon = longest_carbon;
        }
        if (isLegit_oxygen)
        {
            if (oxygen.size() > 0) { oxygen.pop_back(); }
            oxygen.push_back(words[i]);
        }
        if (isLegit_carbon)
        {
            if (carbon.size() > 0) { carbon.pop_back(); }
            carbon.push_back(words[i]);
        }
        longest_oxygen = 0;
        longest_carbon = 0;
    }
    std::cout << endl;
    std::cout << longest_oxygen << endl;
    std::cout << longest_carbon << endl;
    std::cout << oxygen.size() << endl;
    std::cout << carbon.size() << endl;
    for (auto it = begin(oxygen); it != end(oxygen); ++it) {
        std::cout << *it << "\n";
    }
    for (auto it = begin(carbon); it != end(carbon); ++it) {
        std::cout << *it << "\n";
    }*/
}
