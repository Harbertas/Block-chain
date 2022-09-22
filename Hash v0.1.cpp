// Hash v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "input.h"

int main()
{
    double timeTakenToRead = 0;
    double timeTakenToConvert = 0;
    vector<Input> duomenys;
    duomenys[0].read(duomenys, timeTakenToRead);
    cout << "Time taken to read: " << timeTakenToRead << " s" << endl;
    //cout << duomenys.size() << endl;
    int i = 0;
    for (auto& inst : duomenys)
    {
        inst.hashRow(timeTakenToConvert);
        //cout << inst.getHashedRow() << endl;
        //cout << i << " " << inst.getHashedRow() << endl;
        i++;
    }
    cout << "Time taken to convert: " << timeTakenToConvert << " s" << endl;

    for (int j = 0; j < duomenys.size(); j++) 
    {
        for (int i = j+1; i < duomenys.size(); i++)
        {
            if (duomenys[j].getHashedRow() == duomenys[i].getHashedRow() && duomenys[j].getRow() != duomenys[i].getRow())
            {
                cout << j << " " << duomenys[j].getHashedRow() << "\n" << i << " " << duomenys[i].getHashedRow() << endl;
                cout << j << " " << duomenys[j].getRow() << "\n" << i << " " << duomenys[i].getRow() << endl;
            }
        }
    }
    //cout << duomenys[0].getHashedRow() << endl;
    //for (auto& data : duomenys)
    //{
    //    cout << data.getRow() << endl;
    //    cout << data.getHashedRow() << endl;
    //    for(int i = 0; i < data.getWordCount(); i++)
    //    cout << data.getWord(i) << " ";
    //    cout << endl;
    //}

    //for (auto& inst : duomenys) {
    //    for (int i = 0; i < inst.getWordCount(); i++) {
    //        cout << inst.getHashedWord(i) << endl;
    //    }
    //}
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
