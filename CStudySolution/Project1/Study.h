#pragma once

#include <iostream>
#include <cstring>

using namespace std;

enum E_Risk
{
    Risk_A,
    Risk_B,
    Risk_C
};

class Employee
{
private:
    char name[100];
public:
    Employee(const char*name)
    {
        strcpy_s(this->name, strlen(name)+1, name);
    }
    void ShowYourName() const
    {
        cout<<"name : "<<name<<endl;
    }

    virtual int GetPay() const = 0;
    virtual void ShowSalaryInfo() const = 0;
};

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(const char * name, int pay):Employee(name), workTime(0), payPerHour(pay){}
    void AddWorkTime(int time)
    {
        workTime+=time;
    }
    virtual int GetPay() const
    {
        return workTime*payPerHour;
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"Salary : "<<GetPay()<<endl;
    }
};

class PermanentWorker : public Employee
{
private:
    int salary;
public:
    PermanentWorker(const char* name, int money):Employee(name), salary(money){}
    virtual int GetPay() const
    {
        return salary;
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"Salary : "<<salary<<endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(const char * name, int money, double ratio)
    : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio){}

    void AddSalesResult(int value)
    {
        salesResult+=value;
    }
    virtual int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
    }

    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"Salary : "<<GetPay()<<endl;
    }
};

class ForeignSalesWorker : public SalesWorker
{
private:
    const E_Risk Risk = E_Risk::Risk_A;
    float Risk_Bonus_Ratio = 0;
    
    
public:
    ForeignSalesWorker(const char * name, int money, double ratio, E_Risk risk):SalesWorker(name, money, ratio), Risk(risk)
    {
        switch (Risk)
        {
        case Risk_A :
            Risk_Bonus_Ratio = 0.3f;
            break;
        case Risk_B :
            Risk_Bonus_Ratio = 0.2f;
            break;
        case Risk_C:
            Risk_Bonus_Ratio = 0.1f;
            break;
        default:
            cout<<"input Wrong Risk ratio"<<endl;
        }
    }

    virtual int GetPay() const
    {
        float OriginalPay = (float)SalesWorker::GetPay();
        return (int)(OriginalPay + OriginalPay*Risk_Bonus_Ratio);
    }

    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary : "<< SalesWorker::GetPay()<<endl;
        cout<<"Risk pay : "<< (float)SalesWorker::GetPay()*Risk_Bonus_Ratio<<endl;
        cout<<"sum : "<<GetPay()<<endl;
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0){}
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for(int i = 0; i<empNum; i++)
        {
            empList[i]->ShowSalaryInfo();
        }
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i <empNum; i++)
        {
            sum += empList[i]->GetPay();
        }
        cout <<"Total Salary : "<<sum<<endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i<empNum; i++)
        {
            delete empList[i];
        }
    }
};

int main()
{
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));
    
    TemporaryWorker * alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);
    
    SalesWorker * seller=new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    ForeignSalesWorker * fSeller1 = new ForeignSalesWorker("AAA", 1000, 0.1, Risk_A);
    ForeignSalesWorker * fSeller2 = new ForeignSalesWorker("BBB", 1000, 0.1, Risk_B);
    ForeignSalesWorker * fSeller3 = new ForeignSalesWorker("CCC", 1000, 0.1, Risk_C);

    fSeller1->AddSalesResult(7000);
    fSeller2->AddSalesResult(7000);
    fSeller3->AddSalesResult(7000);

    handler.AddEmployee(fSeller1);
    handler.AddEmployee(fSeller2);
    handler.AddEmployee(fSeller3);
    
    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}