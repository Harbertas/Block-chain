#include "Input.h"


std::ifstream Input::read(vector<Input>& data, double& timeTaken)
{
    vector<string> rows;
    string singleRow;

    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream df("input.txt");
    while (df)
    {
        if (!df.eof())
        {
            std::getline(df, singleRow);
            rows.push_back(singleRow);
        }
        else break;
    }
    //for (auto& str : rows) 
    //{
    //  cout << str << endl;
    //}
    df.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)

    timeTaken = diff.count();

    Input temp;
    stringstream ss;
    string word;
    //int i = 0;
    for (auto& singleRow : rows)
    {
        //cout << "i " << i << endl;
        //i = 0;
        ss << singleRow;
        temp.setRow(singleRow);
        while (!ss.eof()) {
            ss >> word;
            //cout << word << endl;
            temp.setWords(word);
        }
        data.push_back(temp);
        ss.clear();
        temp.words.clear();
        //i++;
    }
    rows.clear();
    return df;
}

Input::~Input()
{
    words.clear();
    hashedWords.clear();
}

string Input::decToHex(string word)
{
    int dec_num, r;
    string hexdec_num = "";
    /*cout << "pradzia " << *word.begin() << endl;
    cout << "galas " << *(word.end()-1) << endl;*/
    //cout << word << endl;
    int sum = 0;
    for (auto it = word.end() - 1; it >= word.begin(); it--)
    {
        sum += (int)*it;
    }
    for (auto it = word.end() - 1; it >= word.begin(); it--)
    {
        //cout << "pradzia " << *word.begin() << endl;
        //cout << "galas " << *(word.end()-1) << endl;
        //cout << "itterator " << *it << endl;
        dec_num = ((int)*it) * sum * words.size();
        char hex[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
        while (dec_num > 0)
        {
            r = dec_num % 16;
            hexdec_num = hex[r] + hexdec_num;
            dec_num = dec_num / 16;
        }
    }
    //cout << endl;
    //cout << "row size: " << row.size() << endl;
    //cout << "word count: " << words.size() << endl;
    return hexdec_num;
}


void Input::hashRow(double& timeTakenToConvert) {
    auto start = std::chrono::high_resolution_clock::now();
    for (auto& w : words)
    {
        //cout << w << endl;
        //cout << decToHex(w) << endl;
        setHashedWords(decToHex(w));
        hashedRow += decToHex(w);
    }
    while (true) {
        if (hashedRow.length() < 64) {
            setHashedRow(decToHex(getHashedRow()));
        }
        else
        {
            hashedRow.resize(64);
            setHashedRow(getHashedRow());
            break;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)

    timeTakenToConvert += diff.count();
}