#include "Input.h"

bool is_empty(std::ifstream& df)
{
    return df.peek() == std::ifstream::traits_type::eof();
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

void checkCollision(vector<Input>& d)
{
    //CHECK COLLISION
    for (int j = 0; j < d.size(); j++)
    {
        for (int i = j + 1; i < d.size(); i++)
        {
            if (d[j].getHashedRow() == d[i].getHashedRow() && d[j].getRow() != d[i].getRow())
            {
                cout << j << " " << d[j].getHashedRow() << "\n" << i << " " << d[i].getHashedRow() << endl;
                cout << j << " " << d[j].getRow() << "\n" << i << " " << d[i].getRow() << endl;
            }
        }
    }
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

string generateSalt()
{
    stringstream saltBuff;
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> rnd(32, 126);
    
    for (int i = 0; i < 14; i++)
        saltBuff << rnd(mt);
    return saltBuff.str();
}

void generate(int size, int length) {
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> numb(48, 126);

    stringstream buffer;

    string fileName = to_string(size);
    fileName += "_" + to_string(length) + ".txt";
    std::ofstream rf(fileName);

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < length; j++)
        {
            buffer << (char)numb(mt);
        }
        if (i < size - 1)
            buffer << "\n";
    }

    rf << buffer.str();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << size << " row size generation time " << diff.count() << " s\n";

    buffer.str("");
    buffer.clear();
    rf.close();
}

void generate(int size) {
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> numb(48, 126);
    std::uniform_int_distribution<int> rnd(2, 1000);

    stringstream buffer;

    string fileName = to_string(size);
    fileName += ".txt";
    std::ofstream rf(fileName);

    auto start = std::chrono::high_resolution_clock::now();
    int length;
    string smth;
    for (int i = 0; i < size; i++)
    {
        length = rnd(mt);
        smth.clear();
        for (int j = 0; j < length; j++)
        {
            smth += (char)numb(mt);
        }
        buffer << smth;
        if (i < size - 1)
            buffer << "\n";
        std::uniform_int_distribution<int> change(0, length-1);
        smth.at(change(mt)) = '/';
        buffer << smth;
        i++;
        if (i < size - 1)
            buffer << "\n";
    }

    rf << buffer.str();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << size << " row size generation time " << diff.count() << " s\n";

    buffer.str("");
    buffer.clear();
    rf.close();
}

Input::Input(const Input& old_obj) 
{
    this->row = old_obj.row;
    this->hashedRow = old_obj.hashedRow;
    this->words = old_obj.words;
    this->hashedWords = old_obj.hashedWords;
}

Input& Input::operator=(const Input& other)
{
    words.clear();
    hashedRow.clear();
    if (this != &other) //protect against invalid self-assignment
    {
        this->row = other.row;
        this->hashedRow = other.hashedRow;
        this->words = other.words;
        this->hashedWords = other.hashedWords;
    }
    return *this;
}

std::ifstream Input::read(vector<Input>& data, double& timeTaken)
{
    vector<string> rows;
    string singleRow;

    string inp;
    cout << "Write file name (without .txt extension):" << endl;
    cin.ignore();
    getline(cin, inp);
    inp = inp + ".txt";
    std::ifstream df(inp);

    try
    {
        if (!df)
            throw 1;
        if(is_empty(df))
            throw 2;

    }
    catch(int x) {
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

string Input::decToHex(string row)
{
    int dec_num, r;
    string hexdec_num = "";
    /*cout << "pradzia " << *word.begin() << endl;
    cout << "galas " << *(word.end()-1) << endl;*/
    //cout << word << endl;
    int sum = 0;
    for (auto it = row.end() - 1; it >= row.begin(); it--)
    {
        sum += (int)*it;
    }
    ////////
    for (auto it = row.end() - 1; it >= row.begin(); it--)
    {
        if (hexdec_num.length() > 63) break;
        //cout << "pradzia " << *word.begin() << endl;
        //cout << "galas " << *(word.end()-1) << endl;
        //cout << "itterator " << *it << endl;
        dec_num = ((int)*it) * sum^2 * words.size()^4;
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
        //cout << w << endl;
        //cout << decToHex(w) << endl;
        hashedRow = decToHex(getRow());
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

void Input::hashRow(string row) {
    hashedRow = decToHex(row);
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
}

void Input::hashRowSalt(string row) {
    hashedRowSalt = decToHex(generateSalt() + getRow());
    while (true) {
        if (hashedRow.length() < 64) {
            setHashedRowSalt(decToHex(getHashedRowSalt()));
        }
        else
        {
            hashedRowSalt.resize(64);
            setHashedRowSalt(getHashedRowSalt());
            break;
        }
    }
}

void Input::hashRowSalt() {
    hashedRowSalt = decToHex(row + generateSalt());
    while (true) {
        if (hashedRow.length() < 64) {
            setHashedRowSalt(decToHex(getHashedRowSalt()));
        }
        else
        {
            hashedRowSalt.resize(64);
            setHashedRowSalt(getHashedRowSalt());
            break;
        }
    }
}