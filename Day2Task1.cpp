//https://wandbox.org/permlink/thGeSMRCGQvlIvul
#include <iostream>
#include <string> 
#include <algorithm> 
#include <sstream> 
#include <vector> 

using namespace std;

vector<int> getNumbers(const string& p_line)
{
    long l_number(0);
    vector<int> l_row;

    stringstream iss(p_line); 
    while (iss >> l_number)
    {
        l_row.push_back(l_number);
    }
    return l_row;
}

int main() 
{ 
    string l_line; 
    long l_checksum = 0; 
    while (getline(cin, l_line))
    { 
        const auto l_row = getNumbers(l_line); 
        const auto l_minMax = minmax_element(l_row.begin(), l_row.end());
        l_checksum += *l_minMax.second - *l_minMax.first;
    } 

    cout << " Checksum = " << l_checksum << endl; 
} 