#include <iostream>
#include <cstring>

using namespace std;

enum Position
{
    CLERK,
    SENIOR,
    ASSIST,
    MANAGER
};

class NameCard
{
    char* name;
    char* OfficeName;
    char* PhoneNumber;
    int Position;

    void PrintEnumAsString()
    {
        switch (Position)
        {
        case 0 :
                cout<<"CLERK"<<endl;
                break;
        case 1:
            cout<<"SENIOR"<<endl;
            break;
        case 2:
            cout<<"ASSIST"<<endl;
            break;
        case 3:
            cout<<"MANAGER"<<endl;
            break;
        default:
            cout<<"WRONG index in position"<<endl;
        }
    }
    
public:
    NameCard(const char* Input_name,const char* Input_OfficeName,const char* Input_PhoneNumber, enum Position Input_position)
    {
        name = new char[sizeof(char)*(strlen(Input_name)+1)];
        OfficeName = new char[sizeof(char)*(strlen(Input_OfficeName)+1)];
        PhoneNumber = new char[sizeof(char)*(strlen(Input_PhoneNumber)+1)];

        strcpy_s(name,sizeof(char)*(strlen(Input_name)+1) ,Input_name);
        strcpy_s(OfficeName,sizeof(char)*(strlen(Input_OfficeName)+1), Input_OfficeName);
        strcpy_s(PhoneNumber,sizeof(char)*(strlen(Input_PhoneNumber)+1), Input_PhoneNumber);
        Position = (int)Input_position;
    }

    ~NameCard()
    {
        delete []name;
        delete []OfficeName;
        delete []PhoneNumber;
    }
    void ShowNameCardInfo()
    {
        cout<<name<<endl;
        cout<<OfficeName<<endl;
        cout<<PhoneNumber<<endl;
        PrintEnumAsString();
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", Position::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", Position::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", Position::ASSIST);

    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}