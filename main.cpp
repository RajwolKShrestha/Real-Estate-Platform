#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

//Class defination
class house
{
private:
    string owner_name;
    string location;
    float area;

public:
    void getdata1()
    {
        cin.ignore(); // flush newline
        cout << "Enter owner name: ";
        getline(cin, owner_name);
        cout << "Enter house location: ";
        getline(cin, location);
        cout << "Enter house area: ";
        cin >> area;
    }
        void write_data1(const string &filename)const
    {
        ofstream file(filename,ios::app);
        if(file.is_open())
        {
            file<<owner_name<<endl;
            file<<location<<endl;
            file<<area<<endl;
        }
        else
        {
            cerr<<"Error in opening file"<<endl;
        }
        file.close();
    }
};

class facility:public house
{
private:
    string model;
    string drainage;
    string sewage;
    string parking;
    string garden;
public:
     void getdata2()
    {
        cin.ignore(); // flush newline
        cout << "Enter house model: ";
        getline(cin, model);
        cout << "Is there drainage system? : ";
        getline(cin, drainage);
        cout << "Is there sewage system? : ";
        getline(cin, sewage);
        cout << "Is there parking facility? : ";
        getline(cin, parking);
        cout << "Is there garden? : ";
        getline(cin, garden);
    }
        void write_data2(const string &filename)const
    {
        ofstream file(filename,ios::app);
        if(file.is_open())
        {
            file<<model<<endl;
            file<<drainage<<endl;
            file<<sewage<<endl;
            file<<parking<<endl;
            file<<garden<<endl;
        }
        else
        {
            cerr<<"Error in opening file"<<endl;
        }
        file.close();
    }
};

class house_model:public facility
{
private:
    int bedroom;
    int kitchen;
    int bathroom;
    string flooring;

public:
     void getdata3()
    {
        cout << "Enter no. of bedrooms: ";
        cin >> bedroom;
        cout << "Enter no. of kitchens: ";
        cin >> kitchen;
        cout << "Enter no. of bathrooms: ";
        cin >> bathroom;
        cin.ignore(); // flush newline
        cout << "What kind of flooring is done? ";
        getline(cin, flooring);
    }
    void write_data3(const string &filename)const
    {
        ofstream file(filename,ios::app);
        if(file.is_open())
        {
            file<<bedroom<<endl;
            file<<kitchen<<endl;
            file<<bathroom<<endl;
            file<<flooring<<endl;
        }
        else
        {
            cerr<<"Error in opening file"<<endl;
        }
        file.close();
    }
    void write_data(const string &file_name)
    {
        write_data1(file_name);
        write_data2(file_name);
        write_data3(file_name);
    }
};

//Global Functions Declaration
void main_choice();
void choice_house();
void choice_land();
void house_purchase();
void house_selling();
/*
void land_purchase();
void land_selling();
*/


//Global Functions Defination
void main_menu() {
    while (true) {
        system("cls");
        int n;
        cout << "\t\t\tWelcome to Real Estate Business Platform!!";
        cout << "\n\n\t\t\t 1. House Real Estate business ";
        cout << "\n\t\t\t 2. Land Real Estate business";
        cout << "\n\t\t\t 3. Exit";
        cout << "\n\n\t\t\t Enter a choice: ";
        cin >> n;

        switch (n) {
            case 1:
                choice_house();
                break;
            case 2:
                choice_land();
                break;
            case 3:
                exit(0);
            default:
                cout << "\n\n\t\t\tInvalid Entry!!\n";
                system("pause");
        }
    }
}

void choice_house() {
    while (true) {
        system("cls");
        int n;
        cout << "\t\t\tHouse Real Estate Menu";
        cout << "\n\n\t\t\t 1. House Purchase (Not Implemented)";
        cout << "\n\t\t\t 2. House Selling";
        cout << "\n\t\t\t 3. <- Back";
        cout << "\n\n\t\t\t Enter a choice: ";
        cin >> n;

        switch (n) {
            case 1:
                // house_purchase();
                break;
            case 2:
                house_selling();
                break;
            case 3:
                return; // back to main menu
            default:
                cout << "\n\n\t\t\tInvalid Entry!!\n";
                system("pause");
        }
    }
}


void choice_land()
{
    system("cls");
    int n;
    cout<<"\t\t\tWelcome to Real Estate Business Platform!!";
    cout<<"\n\n\t\t\t 1.Land Purchase";
    cout<<"\n\t\t\t 2.Land Selling";
    cout<<"\n\t\t\t 3.<-Back";
    cout<<"\n\n\t\t\t Enter a choice: ";
    cin>>n;
    switch (n)
    {
    case 1:
        //land_purchase();
        break;
    case 2:
        //land_selling();
        break;
    case 3:
        main_menu();
        break;
    default:
        cout<<"\n\n\t\t\tInvalid Entry!!";
    }
    choice_land();
}

void house_selling() {
    char choice;
    do {
        system("cls");
        house_model h1;
        h1.getdata1();
        h1.getdata2();
        h1.getdata3();
        h1.write_data("house_record.txt");
        cout << "Enter another record? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

//Main Body
int main()
{
    system("cls");
    main_menu();

    return 0;
}
