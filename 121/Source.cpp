#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    char* str;
    int length;
    static int objectCount;

public:

    char& operator[](int index) 
    {
        if (index >= 0 && index < length) 
        {
            return str[index];
        }
        else {
            throw out_of_range("Index out of range");
        }
    }

    void operator()() 
    {
        cout << "Enter a string: ";
        cin.getline(str, length + 1);
    }

    MyString operator+(char c) const 
    {
        MyString temp;
        temp.length = length + 1;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        temp.str[length] = c;
        temp.str[temp.length] = '\0';
        return temp;
    }

    friend MyString operator+(char c, const MyString& obj) 
    {
        MyString temp;
        temp.length = obj.length + 1;
        temp.str = new char[temp.length + 1];
        temp.str[0] = c;
        strcpy(temp.str + 1, obj.str);
        return temp;
    }

    friend MyString operator+(int n, const MyString& obj) 
    {
        if (n == 10) 
        {
            MyString temp;
            temp.length = obj.length + 10;
            temp.str = new char[temp.length + 1];
            strcpy(temp.str, obj.str);
            for (int i = obj.length; i < temp.length; i++) 
            {
                temp.str[i] = ' ';
            }
            temp.str[temp.length] = '\0';
            return temp;
        }
        else 
        {
            throw invalid_argument("This function only supports adding 10 elements.");
        }

    }

    MyString operator+(int n) const 
    {
        if (n == 10) 
        {
            MyString temp;
            temp.length = length + 10;
            temp.str = new char[temp.length + 1];
            strcpy(temp.str, str);
            for (int i = length; i < temp.length; i++) 
            {
                temp.str[i] = ' ';
            }
            temp.str[temp.length] = '\0';
            return temp;
        }
        else 
        {
            throw invalid_argument("This function only supports adding 10 elements.");
        }
    }

    MyString operator++(int) 
    {
        MyString temp = *this;
        length++;
        char* newStr = new char[length + 1];
        strcpy(newStr, str);
        newStr[length - 1] = ' ';
        newStr[length] = '\0';
        delete[] str;
        str = newStr;
        return temp;
    }

    MyString& operator++() 
    {
        length++;
        char* newStr = new char[length + 1];
        newStr[0] = ' ';
        strcpy(newStr + 1, str);
        delete[] str;
        str = newStr;
        return *this;
    }

    static int getObjectCount() 
    {
        return objectCount;
    }

    MyString()
    {
        length = 80;
        str = new char[length + 1];
        strcpy(str, "");
        objectCount++;
    }

    MyString(int size)
    {
        length = size;
        str = new char[length + 1];
        strcpy(str, "");
        objectCount++;
    }

    MyString(const char* inputStr)
    {
        length = strlen(inputStr);
        str = new char[length + 1];
        strcpy(str, inputStr);
        objectCount++;
    }

    ~MyString()
    {
        delete[] str;
        objectCount--;
    }

    void input()
    {
        cout << "Enter a string: ";
        cin.getline(str, length);
    }

    void output() const
    {
        cout << "String: " << str << endl;
    }

    void MyStrcpy(MyString& obj)
    {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }

    bool MyStrStr(const char* substr) const
    {
        return strstr(str, substr) != nullptr;
    }

    int MyChr(char c) const
    {
        for (int i = 0; i < length; i++)
        {
            if (str[i] == c)
            {
                return i;
            }
        }
        return -1;
    }

    int MyStrLen() const
    {
        return length;
    }

    void MyStrCat(MyString& b)
    {
        char* newStr = new char[length + b.length + 1];
        strcpy(newStr, str);
        strcat(newStr, b.str);
        delete[] str;
        str = newStr;
        length += b.length;
    }

    void MyDelChr(char c)
    {
        char* newStr = new char[length + 1];
        int newLen = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] != c)
            {
                newStr[newLen++] = str[i];
            }
        }
        newStr[newLen] = '\0';
        delete[] str;
        str = newStr;
        length = newLen;
    }

    int MyStrCmp(MyString& b) const
    {
        int result = strcmp(str, b.str);
        if (result < 0) return -1;
        if (result > 0) return 1;
        return 0;
    }

    MyString operator+(const MyString& b) const
    {
        MyString temp;
        temp.length = length + b.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, b.str);
        return temp;
    }

    MyString& operator++()
    {
        char* newStr = new char[length + 2];
        std::strcpy(newStr, str);
        newStr[length] = ' ';
        newStr[length + 1] = '\0';
        delete[] str;
        str = newStr;
        length += 1;
        return *this;
    }

    MyString& operator--()
    {
        if (length > 0)
        {
            str[length - 1] = '\0';
            length -= 1;
        }
        return *this;
    }

    static int getObjectCount()
    {
        return objectCount;
    }
};

int MyString::objectCount = 0;
