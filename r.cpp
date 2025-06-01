// We use inheritance to extend the type of some things
//  while we use composition to add a feature or part of something


#include <iostream>
#include <windows.h>
#include <fstream> // file handling
#include <sstream> //string stream for dividing the string into smaller //units
using namespace std;
void land_measurement();
void main_choice();
void choice_land();
void land_selling();
void land_purchase();

class seller;

class buyer{
    private:
    string name;
    string address;
    string contact_num;
     long int budget;

    public:
    void get_info(){
        cout<<"\n\t\t\t\tPlease fill the following details:\n";
         Sleep(2000); // Wait for 2 seconds
        system("cls");
        cin.ignore();
        cout<<"Name:";
        getline(cin,name);
        cout<<"Address:";
        getline(cin,address);
        cout << "Contact number: ";
        getline(cin, contact_num);
        cout<<"Budget:";
        cin>>budget;
    }
     void show_info() {
        cout << "\n--- Info ---";
        cout << "\nName: " << name;
        cout << "\nContact Number: " << contact_num;
        cout << "\nBudget: " << budget <<endl;
        cout<<"Address: "<<address<<endl;
    }

    void  correct(){
        cout<<"\nPlease fill the following details:\n";
         Sleep(2000); // Wait for 2 seconds
        system("cls");
        cin.ignore();
        cout<<"Name:";
        getline(cin,name);
        cout<<"\nContact_number:";
        cin>>contact_num;
        cout<<"\nBudget:";
        cin>>budget;
    }
    void write(){
        ofstream fout("buyer.txt",ios::app);
        fout<<"--- Info ---"<<endl;
        fout<<"Name: "<<name<<endl;
        fout<<"Contact_number:"<<contact_num<<endl;
        fout<<"Budget:"<<budget<<endl;
        fout<<"Address:"<<address<<endl;
        fout<<"----------------------------------------"<<endl;
        fout.close();
}  
    friend seller;
};

class seller {
    private:
    string owner;
    string address;
    float area;
    string location;
    int selling_price;
public:
    void get_data() {
        cout << "\nFetching land details from registered sellers...\n";
        // Simulate loading
        Sleep(2000);
        system("cls");
         ifstream fin("land's entry detail.txt");  // Open the file
    if (!fin) {
        cout << "Error opening file!" << endl;
        return ;
    }
    string line;
    while (getline(fin, line)) {   // Read line by line
        cout << line << endl;
    }
    }
};

class location
{
private:
    string road_access, landmark;
    char grade;


public:
    void location_detail()
    {
        system("cls");
        cout << "\t\t\tEnter road access(Highway/Urban road/ proposed / no road access ? ): ";
        // cin.ignore();
        getline(cin, road_access);
        cout << "\n\t\t\tEnter nearby landmarks: ";
        getline(cin, landmark);
        cout << "\n\t\t\tland category? (A=Prime, B=Residential, C=Semi-Urban, D=Rural): ";
        cin >> grade;
        grade = toupper(grade);
            while(1){
             if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D') {
                 break;  
                } else cout << "\t\t\tInvalid choice! Please enter A, B, C, or D only.\n";
            }
    }
    string getR(){return road_access;}
    string getL() { return landmark; }
    char getG() { return grade; }
};
class facilities
{
private:
    string electricity;
    string water;
    string sewage;


public:
    void facilities_detail()
    {
        system("cls");
        cout << "\t\t\t(1/3) Do the land have access to an electricity line? (y/n) : ";
        getline(cin, electricity);
        cout << "\n\t\t\t(2/3) Does the land have access to a water pipeline? (y/n) : ";
        getline(cin, water);
        cout << "\n\t\t\t(3/3) Does the land have access to a sewage pipeline? (y/n) : ";
        getline(cin, sewage);
    }
    string getE() { return electricity; }
    string getW() { return water; }
    string getS() { return sewage; }
};
class land
{
private:
    string owner;
    string address;
    float area;
    string kitta_no;
    facilities fac;
    location loc;
    int selling_price;


public:
    land()
    {
        cout << "\n\t\t\tPlease enter the required information as per your land ownership documents..." << endl;
        Sleep(2000); // Wait for 2 seconds
        system("cls");
        cin.ignore();
        cout << "\t\t\tKindly enter the name of the Land owner: ";
        getline(cin, owner);
        cout << "\n\t\t\tKindly enter the address of the property: ";
        getline(cin, address);
        cout << "\n\t\t\tEnter the Kitta number associated with the property: ";
        getline(cin, kitta_no);
        land_measurement();
        // the newline left by cin confuses getline and thinks of the  end of input immediately
        // cin.ignore ignore removes the new line left by cin//
        cin.ignore();
        system("cls");
        fac.facilities_detail();
        loc.location_detail();
        system("cls");
        cout << "\t\t\twhat is selling price of property(land)? : Rs ";
        cin >> selling_price;
        system("cls");
        cout << "\t\t\tMr/Mrs " << owner << ", Thanks for entering the land's detail." << endl;
        Sleep(2000);
    }
    void land_measurement()
    {
        int choice;
        system("cls");
        cout << "\t\t\tMr/Mrs " << owner << ", which unit of land measure do you prefer? " << endl;
        cout << "\n\t\t\t1. Traditional Nepali Land Measurement (ROPANI, AANA, PAISA)" << endl;
        cout << "\n\t\t\t2. Square meters" << endl;
        cout << "\n\t\t\tEnter your choice : ";
        cin >> choice;
        cin.ignore();
        cout << "\n\t\t\tThanks for entering your choice" << endl;
        Sleep(1500);
        if (choice == 1)
        {
            system("cls");
            float ropani, aana, paisa, dam;
            cout << "\t\t\tEnter Ropani: ";
            cin >> ropani;
            cout << "\t\t\tEnter Aana: ";
            cin >> aana;
            cout << "\t\t\tEnter Paisa: ";
            cin >> paisa;
            cout << "\t\t\tEnter Dam: ";
            cin >> dam;
            display_land_detail(ropani, aana, paisa, dam);
        }
        else if (choice == 2)
        {
            system("cls");
            float sqmeter;
            cout << "\t\t\tEnter area in square meters: ";
            cin >> sqmeter;
            display_land_detail(sqmeter);
        }
        else
        {
            cout << "\t\t\tPlease enter the correct options(1 or 2)" << endl;
        }
    }
    void display_land_detail(float s)
    {
        cout << "\n\n\t\t\tArea entered: " << s << " sq.m" << endl;
        this->area = s;
        Sleep(2000);
    }


    void display_land_detail(float a, float b, float c, float d)
    {
        cout << "\n\n\t\t\tLand Area: " << a << " Ropani, " << b << " Aana, " << c << " Paisa, " << d << " Daam." << endl;
        float totalSqMeters = convertToSquareMeters(a, b, c, d);
        cout << "\n\n\t\t\tEquivalent area in square meters: " << totalSqMeters << " sq.m" << endl;
        this->area = totalSqMeters;
        Sleep(2000);
    }


    float convertToSquareMeters(float ropani, float aana, float paisa, float dam)
    {
        float area = ropani * 508.74;
        area += aana * 31.80;
        area += paisa * 7.95;
        area += dam * 1.99;
        return area;
    }
    void display_Details()
    {
        system("cls");
        cout << "-------------------------Land Details-------------------------------" << endl;
        cout << "Owner's Name                                       : " << owner << endl;
        cout << "Property Address                                   : " << address << endl;
        cout << "Area of the Property                               : " << area << " sq.m " << endl;
        cout << "Kitta Number                                       : " << kitta_no << endl;
        cout << "Does the land have access to an electricity line?  : " << fac.getE() << endl;
        cout << "Does the land have access to a water pipeline?     : " << fac.getW() << endl;
        cout << "Does the land have access to a sewage pipeline?    : " << fac.getS() << endl;
        cout << "land category                                      : " << loc.getG() << endl;
        cout << "landmark                                           : " << loc.getL() << endl;
        cout << "Road access                                        : " << loc.getR() << endl;
        cout << "selling price                                      : " << selling_price << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }
    void save_file()
    {
        ofstream fout("land's entry detail.txt", ios::app);
        fout << "-------------------------Land Details-------------------------------" << endl;
        fout << "Owner's Name                                       : " << owner << endl;
        fout << "Property Address                                   : " << address << endl;
        fout << "Area of the Property                               : " << area << " sq.m " << endl;
        fout << "Kitta Number                                       : " << kitta_no << endl;
        fout << "Does the land have access to an electricity line?  : " << fac.getE() << endl;
        fout << "Does the land have access to a water pipeline?     : " << fac.getW() << endl;
        fout << "Does the land have access to a sewage pipeline?    : " << fac.getS() << endl;
        fout << "land category                                      : " << loc.getG() << endl;
        fout << "landmark                                           : " << loc.getL() << endl;
        fout << "Road access                                        : " << loc.getR() << endl;
        fout << "selling price                                      : " << selling_price << endl;
        fout << "--------------------------------------------------------------------" << endl;
        fout.close();
    }
    void save_file_temp()
    {
        ofstream fout("temp.txt", ios::app);
        fout << owner;
        fout << "%" << address;
        fout << "%" << area;
        fout << "%" << kitta_no;
        fout << "%" << fac.getE();
        fout << "%" << fac.getW();
        fout << "%" << fac.getS();
        fout << "%" << loc.getG();
        fout << "%" << loc.getL();
        fout << "%" << loc.getR();
        fout << "%" << selling_price << "\n";
        fout.close();
    }
};
void main_choice()
{
    int n;
    while (true)
    {
        system("cls");
        cout << "\t\t\tWelcome to Real Estate Business Platform!!";
        cout << "\n\n\t\t\t 1.House Real Estate business ";
        cout << "\n\t\t\t 2.Land Real Estate business";
        cout << "\n\t\t\t 3.Exit";
        cout << "\n\n\t\t\t Enter a choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            // choice_house();
            break;
        case 2:
            choice_land();
            break;
        case 3:
            exit(0);
        default:
            cout << "\n\n\t\t\tInvalid Entry!!";
            Sleep(1000);
        }
    }
}
void choice_land()
{
    system("cls");
    int n;
    while (true)
    {
        cout << "\t\t\tWelcome to Real Estate Business Platform!!";
        cout << "\n\n\t\t\t 1.Land Purchase";
        cout << "\n\t\t\t 2.Land Selling";
        cout << "\n\t\t\t 3.<-Back";
        cout << "\n\t\t\t 4.Exit";
        cout << "\n\n\t\t\t Enter a choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            land_purchase();
            break;
        case 2:
            land_selling();
            break;
        case 3:
            main_choice();
        case 4:
            system("cls");
            cout << "\n\t\t\tThanks for using our service" << endl;
            exit(0);
            break;
        default:
            cout << "\n\n\t\t\tInvalid Entry!!";
        }
    }
}
void land_selling()
{
    land a;
    a.display_Details();
    a.save_file();
    a.save_file_temp();
}
void filter()
{
    cout << "\n\n\t\t\the order in file : owner,address,area,kitta no,status of(eletricity,water,sewage),landmark,road and selling price" << endl;
    string line;
    string gradeb;
    float areab, budget;
    float area, selling_price;
    bool found;
    string address, owner, road, landmark, eletricity, water, sewage, grade, kitta_no;
    cout << "\n\t\t\twhat is budget for property purchase?: ";
    cin >> budget;
    cout << "\n\t\t\twhat is area required?: ";
    cin >> areab;
    cout << "\n\t\t\twhat is grade of property?: " ;
    cin >> gradeb;
    int a=0;
    int b=0;
    ifstream fin("temp.txt");
    while (getline(fin, line))
    {  
        a++;
        stringstream read(line);
        getline(read, owner, '%');
        getline(read, address, '%');
        read >> area;
        read.ignore();
        getline(read, kitta_no, '%');
        getline(read, eletricity, '%');
        getline(read, water, '%');
        getline(read, sewage, '%');
        getline(read, grade, '%');
        getline(read, landmark, '%');
        getline(read, road, '%');
        read >> selling_price;
        read.ignore();
    }
    if ((gradeb == grade) &&
        (selling_price >= 0.8 * budget && selling_price <= 1.2 * budget) &&
        (area >= 0.8 * areab && area <= 1.2 * areab))
    {  
        b++;
        found = true;
        system("cls");
        cout<<"\t\t\t"<<b<<" out of "<<a<<" matched"<<endl;
        cout << "--------------------------- Matching Property ----------------------------" << endl;
        cout << "Owner's Name                                       : " << owner << endl;
        cout << "Property Address                                   : " << address << endl;
        cout << "Area of the Property                               : " << area << " sq.m " << endl;
        cout << "Kitta Number                                       : " << kitta_no << endl;
        cout << "Does the land have access to an electricity line?  : " << eletricity << endl;
        cout << "Does the land have access to a water pipeline?     : " << water << endl;
        cout << "Does the land have access to a sewage pipeline?    : " << sewage << endl;
        cout << "Land category                                      : " << grade << endl;
        cout << "Landmark                                           : " << landmark << endl;
        cout << "Road access                                        : " << road << endl;
        cout << "Selling price                                      : " << selling_price << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }
    if (!found)
    {
        cout << "\n\n\t\t\tNo match sorry\n";
    }
}

void purchase(){
    string kitta_no;
    float price;
        cout<<"\t\t\tEnter the kitta number of the land you want to purchase:";
        cin>>kitta_no;
        cout<<"\n\t\tEnter the price yout want to set for purchasing land:";
        cin>>price;
        cout<<"\t\t\tWe will get you informed soon regarding your purchase keep visiting our service line...";
        Sleep(2000);
        system("cls");
        cout << "\n\t\t\tThanks for using our service" << endl;
        Sleep(2000);
        exit(0);
}

void Buy(){
    entry:
    char c;
    buyer b1;
    b1.get_info();
    system("cls");
    b1.show_info();
    cout<<"\n\n\n";
    cout<<"DO you want to edit your entered information [Press(y/Y) if yes else press any key to continue!...]:";
    cin>>c;
    if(c=='y'|| c=='Y'){
    Sleep(3000); // Wait for 3 seconds
    system("cls");
    goto entry;
    }
    else{
        b1.write();
        cout<<"\t\t\t\tThankyou for your response....";
        Sleep(2000);
        system("cls");
    }
    cout<<"\nDo you want to purchase any of the above registered land [y/Y if yes else press any key to continue! ]): ";
    char cget;
    cin>>cget;
    if(cget=='y'|| cget=='Y'){
          purchase();
    }
    else{
        exit;
    }
}

void land_purchase()
{
    int choice;
    system("cls");
    cout << "\n\t\t\t 1. View all lands";
    cout << "\n\t\t\t 2. Filter land by preferences";
    cout<<"  \n\t\t\t 3.Buy Land";
    cout << "\n\t\t\t Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        system("cls");
        ifstream fin("land's entry detail.txt");
        string read;
        if (fin.is_open())
        {
            while (getline(fin, read))
            {
                cout << read << endl;
            }
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            system("cls");
            fin.close();
        }
        else
        {
            cout << "\t\t\tFile doesn't exist" << endl;
        }
        break;
    }
    case 2:
    {
        system("cls");
        filter();
        break;
    }
    case 3:
    {
        system("cls");
        Buy();
        break;
    }
    default:
    {
        cout << "\n\t\t\tInvalid choice. Try again.\n";
        break;
    }
    }
}
int main()
{
    main_choice();
    return 0;
}




