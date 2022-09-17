// Hash v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Input.h"

void decToHex(int num) {
    int dec_num, r;
    string hexdec_num = "";
    char hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	cout << "\n\n Convert a decimal number to hexadecimal number:\n";
	cout << "---------------------------------------------------\n";
	cout << " Input a decimal number: ";
	cin >> dec_num;
		
        while(dec_num > 0)
        {
            r = dec_num % 16;
            hexdec_num = hex[r] + hexdec_num;
            dec_num = dec_num / 16;
        }
        cout << " The hexadecimal number is : " << hexdec_num << "\n"; 
}

int main()
{
    //cout << "Hello World!\n";
    Input duomenys;
    duomenys.read();
    duomenys.showRows();
    cout << duomenys.getTimeTaken() << " s\n";

    char raide = 'a';
    char raide1 = 'A';
    cout << (int)raide;
    cout << (int)raide1;

    decToHex(100);
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
