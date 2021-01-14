//=========================
// Alperen Demirtürkoðlu
// 1804010006
// Item Comparator v1.1
//========================

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Menu {

public:
    string all[50]; // memory for all items
    string high[25]; // memory for high
    string low[25]; // memory for low
    string mid[25]; // memory for middle
    string line;
    int p1, p2; // to choosing items
    int opt;    // operation for comparator menu
    int i = -2; // skips first 2 lines in text menu

    void Welcome() {

        cout << "\t===========================================" << endl;
        cout << "\tWelcome to ITEM COMPARATOR Application v1.1" << endl;
        cout << "\t              by DMR Software              " << endl;
        cout << "\t===========================================" << endl << endl;
        system("pause");

        cout << endl << "\tStarting ";
        for (int a = 0; a <= 5; a++) {
            cout << ".";
            for (int j = 0; j <= 120000000; j++);
        }

        MainMenu();

    }

    void MainMenu() {
        system("cls");
        int choice;
    Mmenu:
        cout << "\t=======================================" << endl;
        cout << "\t              MAINMENU                 " << endl;
        cout << "\t=======================================" << endl;
        cout << "\t       (1) See all products            " << endl;
        cout << "\t       (2) Comparator Mode             " << endl;
        cout << "\t       (3) Exit                        " << endl << endl;

        cout << "\tEnter your chocice : ";
        cin >> choice;
        if (choice == 1)
        {

            DisplayItems();
        }
        else if (choice == 2) {
            cMenu();
        }
        else if (choice == 3) {
            cout << endl << endl << "\tThank to using our programme :)" << endl << endl;
            system("pause");
            exit(0);
        }
        else {
            cout << "\tInvalid option! Try again... " << endl;
            system("pause");
            system("cls");
            goto Mmenu; // Look 35
        }

    }



    void DisplayItems() {
        system("cls");

        cout << "\t=====================================================" << endl;
        cout << "\t                      ALL ITEMS                      " << endl;
        cout << "\t=====================================================" << endl << endl;
        ifstream file("product.txt");
        if (file.is_open()) {
            while (!file.eof()) {
                getline(file, line);
                cout <<"\t " << line << endl;
            }// end while
        } file.close(); // end if
        cout << endl;
        system("pause");

        MainMenu();
    } // end func


    void ComparatorItems() {
        system("cls");
        cout << "\t=====================================================" << endl;
        cout << "\t             COMPARATOR FROM ALL ITEMS               " << endl;
        cout << "\t=====================================================" << endl << endl;
        ifstream file("product.txt");
        if (file.is_open()) {
            while (!file.eof()) {
                getline(file, line);
                if (i >= 0) {
                    all[i] = line;
                }
                i++;
                cout << "\t " << line << endl;
            }// end while
        } file.close(); // end if
        i = -2;
        cout << endl << endl << "\tEnter your products No to compare : " << endl;
        cin >> p1 >> p2;
        cout << "\t " << all[p1 - 1] << endl << "\t " << all[p2 - 1] << endl << endl;
        system("pause");
        cMenu();
    }

    void DisplayHigh() {
        system("cls");

        cout << "\t=====================================================" << endl;
        cout << "\t                   HIGH PRICE ITEMS                  " << endl;
        cout << "\t=====================================================" << endl << endl;

        ifstream file("high_price.txt");
        if (file.is_open()) {
            while (!file.eof()) {
                getline(file, line);
                if (i >= 0) {
                    high[i] = line;
                }
                i++;
                cout <<"\t " << line << endl;
            }// end while
        } file.close(); // end if
        i = -2;
        cout << endl << endl << "\tEnter your products No to compare : " << endl;
        cin >> p1 >> p2;
        cout << "\t " << high[p1 - 1] << endl << "\t " << high[p2 - 1] << endl << endl;
        system("pause");
        cMenu();

    }

    void DisplayMid() {
        system("cls");

        cout << "\t=====================================================" << endl;
        cout << "\t                 MIDDLE PRICE ITEMS                  " << endl;
        cout << "\t=====================================================" << endl << endl;

        ifstream file("middle_price.txt");
        if (file.is_open()) {
            while (!file.eof()) {
                getline(file, line);
                if (i >= 0) {
                    mid[i] = line;
                }
                i++;
                cout << "\t " << line << endl;
            }// end while
        } file.close(); // end if
        i = -2;
        cout << endl << endl << "\tEnter your products No to compare : " << endl;
        cin >> p1 >> p2;
        cout << "\t " << mid[p1 - 1] << endl << "\t " << mid[p2 - 1] << endl << endl;
        system("pause");
        cMenu();
    }

    void DisplayLow() {
        system("cls");

        cout << "\t=====================================================" << endl;
        cout << "\t                   LOW PRICE ITEMS                   " << endl;
        cout << "\t=====================================================" << endl << endl;

        ifstream file("low_price.txt");
        if (file.is_open()) {
            while (!file.eof()) {
                getline(file, line);
                if (i >= 0) {
                    low[i] = line;
                }
                i++;
                cout << "\t " << line << endl;
            }// end while
        } file.close(); // end if
        i = -2;
        cout << endl << endl << "\tEnter your products No to compare : " << endl;
        cin >> p1 >> p2;
        cout << "\t " << low[p1 - 1] << endl << "\t " << low[p2 - 1] << endl << endl;
        system("pause");
        cMenu();
    }

    void cMenu() {
    C:
        system("cls");
        cout << "\t=====================================================" << endl;
        cout << "\t                  COMPARATOR MENU                    " << endl;
        cout << "\t=====================================================" << endl << endl;
        cout << "\t             (1) Choosing from all items             " << endl;
        cout << "\t             (2) Choosing from high price items      " << endl;
        cout << "\t             (3) Choosing from middle price items     " << endl;
        cout << "\t             (4) Choosing from low price items        " << endl;
        cout << "\t             (5) Back                                 " << endl << endl;
        cout << "\tEnter option : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            ComparatorItems();
            break;
        case 2:
            DisplayHigh();
            break;
        case 3:
            DisplayMid();
            break;
        case 4:
            DisplayLow();
            break;
        case 5:
            MainMenu();
            break;

        default:
            cout << "\tInvalid number entered..." << endl;
            system("pause");
            goto C;
            break;
        }
    }

};

//class Comparator : public Menu {

//};


int main() {
    Menu menu;
    menu.Welcome();

    return 0;
}
