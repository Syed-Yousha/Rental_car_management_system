#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>

using namespace std;

// Base class to store user information
class User
{
private:
    string name;
    string address;
    string email;
    string phone;
    double balance;

public:
    User(string n = "", string a = "", string e = "", string p = "", double bal = 0.0) : name(n), address(a), email(e), phone(p), balance(bal) {}

    void setName(string n)
    {
        name = n;
    }

    void setAddress(string a)
    {
        address = a;
    }

    void setEmail(string e)
    {
        email = e;
    }

    void setPhone(string p)
    {
        phone = p;
    }

    void setBalance(double b)
    {
        balance = b;
    }

    string getName()
    {
        return name;
    }

    string getAddress()
    {
        return address;
    }

    string getEmail()
    {
        return email;
    }

    string getPhone()
    {
        return phone;
    }

    double getBalance()
    {
        return balance;
    }

    virtual void displayDetails() = 0;
};

// Derived class to store user information
class Customer : public User
{
private:
    int id;
    string password;

    friend class Car;

public:
    Customer(string n = "", string a = "", string e = "", string p = "", int i = 0, string pass = "", double bal = 0.0) : User(n, a, e, p, bal), id(i), password(pass) {}

    void setId(int i)
    {
        id = i;
    }

    void setPassword(string pass)
    {
        password = pass;
    }

    int getId()
    {
        return id;
    }

    string getPassword()
    {
        return password;
    }

    void displayDetails()
    {
        cout << setw(15) << left << getName() << setw(25) << left << getAddress() << setw(25) << left << getEmail() << setw(15) << left << getPhone() << setw(10) << left << getId() << setw(15) << left << getBalance() << endl;
    }

    void CustomerRegistration()
    {
        // Write customer details to file
        ofstream fout("customers.txt", ios::app);
        fout << getName() << "," << getAddress() << "," << getEmail() << "," << getPhone() << "," << id << "," << password << "," << getBalance() << endl;
        fout.close();

        cout << "\nRegistration successful. Your customer id is " << id << ". Please remember this for future use." << endl;
    }

    bool loginUser()
    {

        ifstream infile;
        infile.open("customers.txt");
        int userId;
        double b;
        string username, useradd, useremail, userph, userid, userpass, userbal;
        while (infile >> username >> useradd >> useremail >> userph >> userid >> userpass >> userbal)
        {
            userid.erase(userid.size() - 1);
            stringstream ss(userid);
            ss >> userId;

            userpass.erase(userpass.size() - 1);
            // userId = stoi(userid);
            // b = stof(userbal);
            cout << userId << endl;
            cout << userpass << endl;

            if (userId == id && userpass == password)
            {
                cout << "Login successful!" << endl;
                setName(username);
                setAddress(useradd);
                setEmail(useremail);
                setPhone(userph), setBalance(b);
                infile.close();
                return true;
            }
        }
        infile.close();
        cout << "Incorrect user ID or password. Please try again." << endl;
        return false;
    }
};

// base class to store car information
class Car
{
private:
    string make;
    string model;
    int year;
    string fuelType;
    int seatingCapacity;
    double rentalRate;
    bool available;

public:
    Car(string m = "", string md = "", int y = 0, string ft = "", int sc = 0, double rr = 0.0, bool avail = false) : make(m), model(md), year(y), fuelType(ft), seatingCapacity(sc), rentalRate(rr), available(avail) {}

    void setMake(string m)
    {
        make = m;
    }

    void setModel(string md)
    {
        model = md;
    }

    void setYear(int y)
    {
        year = y;
    }

    void setFuelType(string ft)
    {
        fuelType = ft;
    }

    void setSeatingCapacity(int sc)
    {
        seatingCapacity = sc;
    }

    void setRentalRate(double rr)
    {
        rentalRate = rr;
    }

    void setAvailable(bool avail)
    {
        available = avail;
    }

    string getMake()
    {
        return make;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    string getFuelType()
    {
        return fuelType;
    }

    int getSeatingCapacity()
    {
        return seatingCapacity;
    }

    double getRentalRate()
    {
        return rentalRate;
    }
    bool isAvailable()
    {
        return available;
    }

    void DisplayCarDetails()
    {
        string myText;
        ifstream MyCars("cars.txt");

        if (!MyCars)
        {
            cout << "\nFile not found!";
            exit(0);
        }

        while (getline(MyCars, myText))
        {
            cout << myText << endl;
        }

        MyCars.close();
    }

    void searchCar()
    {
        string CarName;

        cout << "\nEnter the car name: ";
        cin >> CarName;

        string line;
        ifstream file("Cars.txt");

        if (!file)
        {
            cout << "\nFile not found!!";
            exit(0);
        }

        // Read each line of the file
        while (getline(file, line))
        {

            // Find the position of the commas
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            size_t pos4 = line.find(',', pos3 + 1);
            size_t pos5 = line.find(',', pos4 + 1);
            size_t pos6 = line.find(',', pos5 + 1);

            // Extract the fields using substr
            string name = line.substr(0, pos1);
            string year1 = line.substr(pos1 + 2, pos2 - pos1 - 2);
            string year2 = line.substr(pos2 + 2, pos3 - pos2 - 2);
            string fuel = line.substr(pos3 + 2, pos4 - pos3 - 2);
            string cylinders = line.substr(pos4 + 2, pos5 - pos4 - 2);
            string engine_size = line.substr(pos5 + 2, pos6 - pos5 - 2);
            string sold = line.substr(pos6 + 2);

            // Print the details of Tesla
            if (name == CarName)
            {
                cout << "Name: " << name << endl;
                cout << "Year range: " << year1 << "-" << year2 << endl;
                cout << "Fuel type: " << fuel << endl;
                cout << "Number of cylinders: " << cylinders << endl;
                cout << "Engine size: " << engine_size << endl;
                cout << "Sold: " << sold << endl;
            }
        }
    }

    void BookCar(Customer* C)
    {
        string CarName;

        cout << "\nEnter the car name: ";
        cin >> CarName;

        string line;
        ifstream infile("Cars.txt");
        ofstream outfile("rental history.txt");

        // Read each line of the input file
        while (getline(infile, line))
        {
            // Find the position of the commas
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            size_t pos4 = line.find(',', pos3 + 1);
            size_t pos5 = line.find(',', pos4 + 1);
            size_t pos6 = line.find(',', pos5 + 1);

            // Extract the fields using substr
            string name = line.substr(0, pos1);
            string year1 = line.substr(pos1 + 2, pos2 - pos1 - 2);
            string year2 = line.substr(pos2 + 2, pos3 - pos2 - 2);
            string fuel = line.substr(pos3 + 2, pos4 - pos3 - 2);
            string cylinders = line.substr(pos4 + 2, pos5 - pos4 - 2);
            string engine_size = line.substr(pos5 + 2, pos6 - pos5 - 2);
            string avail = line.substr(pos6 + 2);

            // Check if the car is a Tesla and update the availability
            if (name == CarName && avail == "y")
            {
                cout << "Car is booked. Enjoy Your ride." << endl;
                avail = "n";
            }
            else if(name == CarName && avail == "n")
            {
                cout << "\nCar is not availble";
                exit(0);
            }
            else{
            	cout << "Car is not available" << endl;
			}

            // Write the updated line to the output file
            outfile << name << ", " << year1 << ", " << year2 << ", " << fuel << ", "
                    << cylinders << ", " << engine_size << ", " << avail << C->getName() << C->getId() << endl;
        }

        // Close the input and output files
        infile.close();
        outfile.close();



        // Rename the temporary file to the original file
        remove("Cars.txt");
        rename("temp.txt", "Cars.txt");
    }

    void showRentalHistory(Customer *obj)
    {
        int userId;
        cout << "\n Cutomer " << obj->getName() << " rented the following cars,\n";

        ifstream infile("rental history.txt");

        string line;

         while (getline(infile, line))
        {
            // Find the position of the commas
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            size_t pos4 = line.find(',', pos3 + 1);
            size_t pos5 = line.find(',', pos4 + 1);
            size_t pos6 = line.find(',', pos5 + 1);
            size_t pos7 = line.find(',', pos6 + 1);
            size_t pos8 = line.find(',', pos7 + 1);

            // Extract the fields using substr
            string name = line.substr(0, pos1);
            string year1 = line.substr(pos1 + 2, pos2 - pos1 - 2);
            string year2 = line.substr(pos2 + 2, pos3 - pos2 - 2);
            string fuel = line.substr(pos3 + 2, pos4 - pos3 - 2);
            string cylinders = line.substr(pos4 + 2, pos5 - pos4 - 2);
            string engine_size = line.substr(pos5 + 2, pos6 - pos5 - 2);
            string avail = line.substr(pos6 + 2, pos7 - pos6 - 2);
            string customername = line.substr(pos7 + 2, pos8 - pos7 - 2);
            string id = line.substr(pos8 + 2);
            stringstream ss(id);
            ss >> userId;

            // Check if the car is a Tesla and update the availability
            if (customername == obj->getName() && userId == obj->getId())
            {
                cout << name << endl << year1 << endl << year2 << endl << fuel << endl << cylinders << endl << engine_size << endl << avail << endl << customername << endl << id;
            }
            else
            {
                cout << "\nCar is not availble";
                exit(0);
            }
        }
        
//      string make, model, fuel_type, availability;
//      int year, engine_size;
//
//        if (!infile.is_open())
//        {
//            cerr << "Error opening file!" << endl;
//            exit(1);
//        }
//
//        // read and display the cars with availability 'n'
//        while (infile >> make >> year >> model >> fuel_type >> engine_size >> availability)
//        {
//            if (availability == "n")
//            {
//                cout << make << " " << year << " " << model << " " << fuel_type << " " << engine_size << " " << availability << endl;
//            }
//        }
//
//        infile.close();
    }
};

// Function prototypes
// void adminLogin();
// void addCar();
// void displayAvailableCars();
// void searchCars();
// void bookCar();
// void viewRentalHistory();
// void leaveFeedback();
// void emailNotification();
// void encryptDecryptFile();

int main()
{
    string name, address, email, phone, password, pass;
    int id;
    double balance;
    int choice, choice_two;
    Customer C;
    Car cars;

    cout << "\n\nWelcome to Car Rental System" << endl;
    cout << "=============================" << endl;
    cout << "1. Customer Registration" << endl;
    cout << "2. Admin Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\nCustomer Registration" << endl;
        cout << "=====================" << endl;

        cout << "Enter your name: ";
        cin >> name;

        cout << "Enter your address: ";
        cin >> address;

        cout << "Enter your email: ";
        cin >> email;

        cout << "Enter your phone number: ";
        cin >> phone;

        cout << "Enter a password: ";
        cin >> password;

        cout << "Enter your initial balance: ";
        cin >> balance;

        // Generate unique customer id
        id = rand() % 10000 + 1;
        C = Customer(name, address, email, phone, id, password, balance);
        C.CustomerRegistration();

        main();
        break;
    case 2:

    jump:
        cout << "Enter your id: ";
        cin >> id;
        cout << "Enter your password:";
        cin >> pass;

        C.setId(id);
        C.setPassword(pass);

        if (C.loginUser() != true)
        {
            goto jump;
        }

        system("cls");
    jump2:
        cout << "Welcome to your account...." << endl
             << "What would you like?" << endl
             << "1. Display Available Cars" << endl
             << "2. Search Cars" << endl
             << "3. book cars" << endl
             << "4. View Rental Histoy" << endl
             << "5. leave feedback" << endl
             << "6. Log out" << endl;

        cin >> choice_two;

        switch (choice_two)
        {
        case 1:
            cars.DisplayCarDetails();
            goto jump2;

        case 2:
            cars.searchCar();
            goto jump2;

        case 3:
            cars.BookCar(&C);
            cout << "\nThankyou for renting!, Drive Safely....\n";
            goto jump2;

        case 4:
            cars.showRentalHistory(&C);
            goto jump2;

//        default:
//            cout << "\nYou entered an in valid choice";
//            goto jump2;       
		}


    case 3:
        cout << "\nThank you for using Car Rental System. Have a nice day!" << endl;
        exit(0);
    default:
        cout << "\nInvalid choice. Please try again." << endl;
        main();
    }

    return 0;
}

