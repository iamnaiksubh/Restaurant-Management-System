// *********** Restaurant Management System *************

#include <bits/stdc++.h>
#include <windows.h>
#include<conio.h>

using namespace std;

// MAIN PAGE 
class MainPage{
    private : 
    int selectedVal;
    public :

    // MAIN MENU
    void home_page(){
        cout <<"*** Garden Of Eat'n ***"<<endl;
        cout <<" 1.User Login           " <<endl;
        cout <<" 2.Admin Login          " <<endl;
        cout <<" 3.Register New User    " <<endl;
        cout <<" 4.Exit               " <<endl;
        cout <<" Enter Your choice: " <<endl;
        this -> choice();
    }


    //USER CHOICE 
    void choice(){
        int userChoice;
        cin >> userChoice;

        while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4){
            this -> home_page();
            cout << "Enter correct option: ";
            cin >> userChoice;
            cout << endl;
        }
        this -> selectedVal = userChoice;
    }


    int getChoice(){
        return this -> selectedVal;
    }
};

// USER LOGIN AND VERIFICATION
class User{
public:

    string userpassword;
    string username;

    bool getUser(){
        system("CLS");
        cout<<"Enter Username: ";
        cin>>username;
        cout<<endl<<"Enter User Password: "<<endl;
        cin>>userpassword;
        string user_pass;
        user_pass = username + ":" + userpassword;

        return this -> userfromlist(user_pass);
    }



    bool userfromlist(string user_pass){
        ifstream ip;
        ip.open("userinfo.txt");
        bool flag=false;
        string line;
        
        while(!ip.eof()){
            getline(ip,line);
            if(line==user_pass){
                cout<<"User Verified..."<<endl;
                Sleep(1000);
                flag = true;
                break;
            }
        }
            if(flag==false){

                cout<<"You entered incorrect username or password"<<endl;
                cout<<"Enter any key to continue"<<endl;
                getch();
                return false;
            }


        ip.close();
        if(flag){
            this -> Welcome();
            return true;
        }
    }



    void Welcome(){
    system("CLS");
    cout<<"Welcome "<<username<<endl;
    Sleep(1000);
    }
};

// ADMIN LOGIN AND VERIFICATION
class Admin {

    public :

    string userpassword;
    string username;

    bool getUser(){
        system("CLS");
        cout<<"Enter Username: ";
        cin>>username;
        cout<<endl<<"Enter User Password: "<<endl;
        cin>>userpassword;
        string user_pass;
        user_pass = username + ":" + userpassword;

        return this -> userfromlist(user_pass);
    }



    bool userfromlist(string user_pass){
        ifstream ip;
        ip.open("admininfo.txt");
        bool flag=false;
        string line;
        
        while(!ip.eof()){
            getline(ip,line);
            if(line==user_pass){
                cout<<"User Verified..."<<endl;
                Sleep(1000);
                flag = true;
                break;
            }
        }
            if(flag==false){

                cout<<"You entered incorrect username or password"<<endl;
                cout<<"Enter any key to continue"<<endl;
                getch();
                return false;
            }


        ip.close();
        if(flag){
            this -> Welcome();
            return true;
        }

    }



    void Welcome(){
    system("CLS");
    cout<<"Welcome Admin"<<endl;
    Sleep(1000);
    }
};


// COUNT TOTAL USER IN USERINFO
int countUser(){
        ifstream ip;
        int userCnt=0;
        ip.open("userinfo.txt");

        string line;

        while(!ip.eof()){
            userCnt++;
            getline(ip,line);
        }

        ip.close();
        return userCnt;
    }



// COUNT TOTAL ADMIN IN ADMININFO
int countAdmin(){
        ifstream ip;
        int adminCnt = 0;
        ip.open("admininfo.txt");

        string line;

        while(!ip.eof()){
            adminCnt++;
            getline(ip,line);
        }

        ip.close();
        return adminCnt;
    }




// ADMIN SUB MENU
class AdminMenu : public Admin{
    public : 

    void showMenu(){
        cout << "1.Count Admin" <<endl;
        cout << "2.Count User" <<endl;
        cout << "3.Exit" << endl;
    }


    void order(){
        repeat :
        system("CLS");
        this -> showMenu();

        cout << "Enter Your Order: ";
        int choice;
        cin >> choice;

        while(choice != 1 && choice != 2 && choice != 3){
            system("CLS");
            this -> showMenu();
            cout << "Enter Valid Option From Menu : ";
            cin >> choice;
        }

        if(choice == 3)
            return;

        if(choice == 1){
            cout << countAdmin() << endl;
            Sleep(1000);
        }

        if(choice == 2){
            cout << countUser() << endl;
            Sleep(1000);
        }
        
        system("CLS");
        cout << "1.Admin Menu" << endl;
        cout << "2.Exit" << endl;
        cin >> choice;

        while(choice != 1 && choice != 2){
            cout << "Enter Valid Option :";
            cin >> choice;
        }

        if(choice == 1)
            goto repeat;
        if(choice == 2)
            return;
    }

};


// NEW USER REGISTATION
void userRegister(){
    User userb;
    string username,userpassword;
    cout<<"Enter Username: ";
    cin>>username;
    cout<<endl<<"Enter User Password: "<<endl;
    cin>>userpassword;


    string user_pass;
    user_pass = username + ":" + userpassword;


    ofstream op;
    op.open("userinfo.txt",ios::app);
    op<<user_pass<<endl;
    op.close();
    cout<<"Registering user";
     for(int i=0;i<5;i++){
        Sleep(500);
        cout<<"..";
        }
    cout<<endl;
    cout<<"User registered."<<endl;
    Sleep(100);
}



// MENU FOR USER TO BUY FROM THE MENU AND PRINT THE TOTAL AMOUNT
class Menu : public User{
    public : 

    int cost[5] = {60,50,120,160,340};
    int totalCost = 0;
    string menuList[5] = {"Coffee","Tea","Burger","Momos","Pizza"};
    vector<pair<int,int>> orderList;


    void showMenu(){
        cout << "1.Coffee" <<endl;
        cout << "2.Tea" <<endl;
        cout << "3.Burger" <<endl;
        cout << "4.Momos" <<endl;
        cout << "5.Pizza" << endl;
        cout << "6.Exit" << endl;
    }


    void order(){
        repeat :
        system("CLS");
        this -> showMenu();

        cout << "Enter Your Order: ";
        int choice;
        cin >> choice;

        while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 ){
            system("CLS");
            this -> showMenu();
            cout << "Enter Valid Option From Menu : ";
            cin >> choice;
        }

        if(choice == 6)
            return;
        int quantity;
        cout << "Enter Quantity ( 1 to 10 ) : "; 
        cin >> quantity;

        
        bool check = true;

        while(check){
            if(quantity >= 1 && quantity <= 10)
                break;
            cout << "Enter Valid Quantity : ";
            cin >> quantity;
        }

        orderList.push_back({choice-1,quantity});

        cout << "1.Order More" << endl;
        cout << "2.Exit" << endl;
        cin >> choice;

        while(choice != 1 && choice != 2){
            cout << "Enter Valid Option :";
            cin >> choice;
        }

        if(choice == 1)
            goto repeat;

        cout << "User Name : "<<endl;

        for(auto i : orderList){
            cout << "Item\t\t" << "Quantity\t" << "Cost"<<endl;
            cout<< menuList[i.first] << "\t\t" << i.second << "\t\t" << cost[i.first] << endl;
            totalCost += i.second * cost[i.first];
        }
        
        cout<<endl;

        cout << "Total Cost : " << totalCost << endl;
        
        cout << "press any key to continue" << endl;
        string exit;
        cin >> exit;

        return;

    }

};

int main(){

    bool flag = true;

    while(flag){
        system("CLS");
        MainPage obj1;
        obj1.home_page();
        int choice = obj1.getChoice();
        Menu obj2;
        AdminMenu obj3;
        switch(choice){
            case 1: if(obj2.getUser()) // USER LOGIN
                        obj2.order();
                    break;
            case 2: if(obj3.getUser()) // ADMIN LOGIN
                        obj3.order();
                    break;
            case 3:userRegister(); // REGISTRATION OF NEW USER
                    break;
            case 4: flag = false; // EXIT THE MAIN MENU
                    break;
            default:
                break;
        };

        
    }
    return 0;
}