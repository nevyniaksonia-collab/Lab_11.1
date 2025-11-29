#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

// Якщо файл не вдалося відкрити, повертає -1
int CountInFile(const char* filename)
{
    ifstream fin(filename); 
    if (!fin.is_open())
    {
        return -1; 
    }

    int count = 0;
    char prev, curr;

    // Спробуємо зчитати перший символ
    if (!fin.get(prev))
    {
        fin.close();
        return 0; // Файл порожній
    }

    // Зчитуємо файл посимвольно
    while (fin.get(curr))
    {
        if ((prev == 'n' && curr == 'o') || (prev == 'o' && curr == 'n'))
        {
            count++;
        }

        // Запам'ятовуємо поточний символ як попередній для наступної ітерації
        prev = curr;
    }

    fin.close(); // Закриваємо файл
    return count;
}

int main()
{
    char filename[100];

    cout << "Enter filename (e.g., t.txt): ";
    cin >> filename;

    // Викликаємо функцію, передаючи їй назву файлу
    int result = CountInFile(filename);

    if (result == -1)
    {
        cout << "Error: Cannot open file '" << filename << "'." << endl;
        cout << "Make sure the file exists in the project folder." << endl;
    }
    else
    {
        cout << "Result: " << endl;
        if (result > 0)
            cout << "Yes, the file contains " << result << " pairs of 'no' or 'on'." << endl;
        else
            cout << "No, pairs 'no' or 'on' were not found." << endl;
    }

    return 0;
}