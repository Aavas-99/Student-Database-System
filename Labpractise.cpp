#include<bits/stdc++.h>
using namespace std;

class Database
{
protected:
    string name;
public:
    Database()
    {

    }
    static int count;
    virtual void setdata()=0;
    ~Database(){}
} ;

class Student: public Database
{
private:
    int roll;
    string dept;
public:
    friend ostream& operator << (ostream& out,Student& s);
    Student()
    {
        count++;
    }
    void setdata()
    {
        cout<< "Nick Name: ";
        cin>>name;
        cout<< "Roll: ";
        cin>>roll;
        cout<< "Department: ";
        cin>>dept;
        cin.ignore();
        cout<<endl;
    }
    ~Student()
    {

    }
};

int Database::count=0;

ostream& operator << (ostream& out,Student& s)
{
    out<< s.name << " " << s.roll << " " << s.dept << "\n";
    return out;
}

int main()
{
    int num;
    string line;
    cin >> num;
    Student* st = new Student[num];
    for(int i=0;i<num;i++)
    {
        st[i].setdata();
    }

    cout<< "New Registered Student number: " << Student::count << "\n\n";
    cout<< "\Newly Registered Students(Name_Roll_Department):\n\n";

    for(int i=0;i<num;i++)
    {
        cout<<st[i];
    }

    try
    {
        ofstream write("Data.txt", ios::app);

        if(write)
        {
            for(int i=0;i<num;i++)
            {
                write<<st[i];
            }
        }
        else
        {
            throw "ERROR";
        }

        write.close();
    }
    catch(...)
    {
        cout<< "Error writing in File\n" ;
    }

    ifstream read("Data.txt");

    cout<< "\nFull Database(Name_Roll_Department):\n\n";

    while(getline(read,line))
    {
        cout<<line<<endl;
    }
    read.close();

    delete[] st;
}
