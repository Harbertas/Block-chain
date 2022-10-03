#include <iostream>
#include "sha256.h"

using std::string;
using std::cout;
using std::endl;

bool is_empty(std::ifstream& df)
{
    return df.peek() == std::ifstream::traits_type::eof();
}

string hexToBin(string hexdec)
{
    long int i = 0;
    string binary;
    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            binary += "0000";
            break;
        case '1':
            binary += "0001";
            break;
        case '2':
            binary += "0010";
            break;
        case '3':
            binary += "0011";
            break;
        case '4':
            binary += "0100";
            break;
        case '5':
            binary += "0101";
            break;
        case '6':
            binary += "0110";
            break;
        case '7':
            binary += "0111";
            break;
        case '8':
            binary += "1000";
            break;
        case '9':
            binary += "1001";
            break;
        case 'A':
        case 'a':
            binary += "1010";
            break;
        case 'B':
        case 'b':
            binary += "1011";
            break;
        case 'C':
        case 'c':
            binary += "1100";
            break;
        case 'D':
        case 'd':
            binary += "1101";
            break;
        case 'E':
        case 'e':
            binary += "1110";
            break;
        case 'F':
        case 'f':
            binary += "1111";
            break;

            //cout << "\nInvalid hexadecimal digit " << hexdec[i];
        }
        i++;
    }
    return binary;
}

double compare(string first, string second)
{
    double percent;
    int same = 0;
    for (int i = 0; i < first.size(); i++)
    {
        if (first.at(i) == second.at(i))
            same++;
    }
    percent = ((double)same / first.size()) * 100;
    return percent;
}

std::ifstream read(std::vector<string>& rows, double& timeTaken)
{
    string singleRow;

    string inp;
    cout << "Write file name (without .txt extension):" << endl;
    std::getline(std::cin, inp);
    inp = inp + ".txt";
    std::ifstream df(inp);

    try
    {
        if (!df)
            throw 1;
        if (is_empty(df))
            throw 2;

    }
    catch (int x) {
        if (x == 1) {
            cout << "File '" << inp << "' does not exist!" << endl; exit(0);
        }
        else if (x == 2) {
            cout << "File is empty!" << endl; exit(0);
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
    while (df)
    {
        if (!df.eof())
        {
            std::getline(df, singleRow);
            rows.push_back(singleRow);
        }
        else break;
    }
    df.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)

    timeTaken = diff.count();

    return df;
}

int main(int argc, char* argv[])
{
    std::vector<std::string> row;
    std::vector<std::string> hashedRow;
    double timeTaken;
    read(row, timeTaken);
    std::string output;
    timeTaken = 0;
    int count = 1;
    int i = 1;
    for (auto hashed : row) {
        output = sha256(hashed, timeTaken);
        hashedRow.push_back((string)output);
        /*if (count == (i * 2) || count == 789) {
            cout << count << " row :" << timeTaken << "s." << endl;
            i = count;
        }*/
        count++;
    }
    cout << "Time taken to hash: " << timeTaken << "s." << endl;

   

    std::vector<double> percent;
    for (int i = 0; i < hashedRow.size(); i++) {
        percent.push_back(compare(hashedRow.at(i), hashedRow.at(i + 1)));
        i++;
    }
    std::sort(percent.begin(), percent.end());
    double sum = 0;
    for (auto& el : percent) {
        sum += el;
    }
    cout << "HEXADECIMAL" << endl;
    cout << "minimum similarity: " << percent.at(0) << "%" << endl;
    cout << "average similarity: " << sum / percent.size() << "%" << endl;
    cout << "maximum similarity: " << percent.at(percent.size() - 1) << "%" << endl;


    //similarity BINARY
    percent.clear();
    for (int i = 0; i < hashedRow.size(); i++) {
        percent.push_back(compare(hexToBin(hashedRow.at(i)), hexToBin(hashedRow.at(i + 1))));
        i++;
    }
    std::sort(percent.begin(), percent.end());
    sum = 0;
    for (auto& el : percent) {
        sum += el;
    }
    cout << "BINARY" << endl;
    cout << "minimum similarity: " << percent.at(0) << "%" << endl;
    cout << "average similarity: " << sum / percent.size() << "%" << endl;
    cout << "maximum similarity: " << percent.at(percent.size() - 1) << "%" << endl;
    return 0;
}