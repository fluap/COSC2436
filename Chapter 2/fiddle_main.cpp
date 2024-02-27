#include <iostream>
using namespace std;

void message(int);
int facto(int);
void backward1(string);
void backward2(string);


int main()
{
    string word;
    
    cout << "Enter a word: ";
    cin >> word;
    cout << "Backwards V1:  " << word << "\n";
    backward1(word);
    backward2(word);
    message(4);
    cout << facto(4);

    return 0;
}

void backward2(string w)
{
    if (w.size())
    {
        backward2(w.substr(1, w.size() - 1));
        cout << w.substr(0, 1);
    }
}
void backward1(string w)
{
    if (w.size())
    {
        cout << w.substr(w.size() - 1, 1);
        backward1(w.substr(0, w.size() - 1));
    }
    cout << "\n";
}


int facto(int number){
    if (number > 1) {
        return number * facto(number - 1);
    }
    else {
        return 1;
    }
}

void message(int times) { 
    if (times > 0) { 
        std::cout << "Hi\n"; 
        message(times - 1); 
    }
}
