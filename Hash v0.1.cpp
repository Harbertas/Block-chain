// Hash v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "input.h"

int main()
{
    double timeTakenToRead = 0;
    double timeTakenToConvert = 0;

    int how;
    cout << "Write input by hand? (0 - no, 1 - yes)" << endl;
    cin >> how;
    while ((how != 0 && how != 1) || cin.fail())
    {
        cout << "Wrong input data, try again!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> how;
    }
    if (how == 1) 
    {
        Input row;
        string data;
        cout << "Input row data" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        getline(cin, data);
        row.setRow(data);
        row.hashRow(timeTakenToConvert);
        cout << row.getHashedRow() << endl;
    }
    else 
    {
        vector<Input> duomenys;
        duomenys[0].read(duomenys, timeTakenToRead);
        cout << "Time taken to read: " << timeTakenToRead << " s" << endl;
        //int i = 0;
        int count = 1;
        int i = 1;
        for (auto& inst : duomenys)
        {
            inst.hashRow(timeTakenToConvert);
            if (count == (i * 2) || count == 789) {
                cout << count << " row :" << timeTakenToConvert << "s." << endl;
                i = count;
            }
            count++;
            //cout << i << " " << inst.getHashedRow() << endl;
            //i++;
        }
        cout << "Time taken to convert: " << timeTakenToConvert << " s" << endl;

        //checkCollision(duomenys);

        ////similarity HEX
        //vector<double> percent;
        //for (int i = 0; i < duomenys.size(); i++) {
        //    percent.push_back(compare(duomenys.at(i).getHashedRow(), duomenys.at(i+1).getHashedRow()));
        //    i++;
        //}
        //sort(percent.begin(), percent.end());
        //double sum = 0;
        //for (auto& el : percent) {
        //    sum += el;
        //}
        //cout << "HEXADECIMAL" << endl;
        //cout << "minimum similarity: " << percent.at(0) << "%" << endl;
        //cout << "average similarity: " << sum / percent.size() << "%" << endl;
        //cout << "maximum similarity: " << percent.at(percent.size() - 1) << "%" << endl;


        ////similarity BINARY
        //percent.clear();
        //for (int i = 0; i < duomenys.size(); i++) {
        //    percent.push_back(compare(hexToBin(duomenys.at(i).getHashedRow()), hexToBin(duomenys.at(i+1).getHashedRow())));
        //    i++;
        //}
        //sort(percent.begin(), percent.end());
        //sum = 0;
        //for (auto& el : percent) {
        //    sum += el;
        //}
        //cout << "BINARY" << endl;
        //cout << "minimum similarity: " << percent.at(0) << "%" << endl;
        //cout << "average similarity: " << sum / percent.size() << "%" << endl;
        //cout << "maximum similarity: " << percent.at(percent.size() - 1) << "%" << endl;
        //hexToBin(duomenys.at(0).getHashedRow());
    }
    //generate(50000, 10);
    //generate(100000);
    return 0;
}




















// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
