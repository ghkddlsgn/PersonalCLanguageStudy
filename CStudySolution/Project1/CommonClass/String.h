#pragma once
#include <iostream>
#include <cstring>

class String
{
private:
    char * str;
    int length = 0;
public:
    String()
    {
        str = nullptr;
        length = 0;
    }
    String(const char* Input_str)
    {
        length = (int)strlen(Input_str) + 1;
        str = new char[length];
        strcpy_s(str, length, Input_str);
    }
    String(const String& Ref)
    {
        length = Ref.length;
        str = new char[length];
        strcpy_s(str, length, Ref.str);
    }

    String& operator=(const String& Ref)
    {
        delete []str;
        
        length = Ref.length;
        str = new char[length];
        strcpy_s(str, length, Ref.str);
        return *this;
    }
    
    String operator+(const String& ref) const
    {
        //if ref is valid
        int NewLength = (int)strlen(str) + (int)strlen(ref.str) +1;
        char *ConcatStr = new char[NewLength];
        
        strcpy_s(ConcatStr, strlen(str)+1, str);
        strcat_s(ConcatStr, NewLength, ref.str);
        
        String ReturnValue(ConcatStr);

        delete []ConcatStr;
        return ReturnValue;
    }
    
    String& operator+=(const String&ref)
    {
        int NewLength = length + (int)strlen(ref.str); //it containts null memory size
        char * temp = new char[NewLength];
        strcpy_s(temp, length, str);
        strcat_s(temp, NewLength, ref.str); //contain return value to temp
        
        delete []str;
        str = new char[NewLength]; //expand memory for str to contain both string
        strcpy_s(str, NewLength, temp);
        
        delete []temp;
        length = NewLength;
        
        return *this;
    }
    
    bool operator==(const String&ref) const
    {
        return strcmp(str, ref.str)==0;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& ref);
    friend std::istream& operator>>(std::istream& is, String& ref);
    

    ~String()
    {
        delete []str;
    }

    void Info()
    {
        std::cout<<str<< std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const String& ref)
{
    os<<ref.str;
    return os;
}

inline std::istream& operator>>(std::istream& is, String& ref)
{
    char InputString[100]; //input
    std::cin>>InputString;

    delete []ref.str; //replace str from previous string to new string
    ref.length = strlen(InputString)+1;
    ref.str = new char[ref.length];
    strcpy_s(ref.str, ref.length, InputString);

    return is;
}

void Compare(const String&A, const String&B)
{
    if (A==B)
    {
        std::cout<<"Both Strings are same"<< std::endl;
    }
    else
    {
        std::cout<<"Strings are not equal"<< std::endl;
    }
}
