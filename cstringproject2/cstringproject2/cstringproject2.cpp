////
// Name: Luna Waller
// Program Name: Custom String Project
//
// Description: Takes a file input, takes 5 words then combines them into one,
// sorts them by ascii values, then outputs them to consle along with the length and capacity
// Along with class created and current
////

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "lunastring.h"
#include "LunaList.h"
using namespace std;

void bubbleSort(vector<LunaString>& lstring) {
    int tracker;
    do {
        tracker = 0;
        for (int i = 0; i < lstring.size() - 1; i++) {
            int result = lstring[i].compareTo(lstring[i + 1]);
            if (result > 0) {
                LunaString tempString(lstring[i]);
                lstring[i] = lstring[i + 1];
                lstring[i + 1] = tempString;
            }
            else {
                tracker++;
            }
        }
    } while (tracker != lstring.size() - 1);
}


void changer(DoubleLinkedList<LunaString> dll) {
    LunaString zip("ZIP");
    LunaString zap("ZAP");

    dll.insert(zip);
    dll.insert(zap);

    cout << "Inside changer func: size of list is " << dll.getCount() << endl;
}


int main()
{
    DoubleLinkedList<LunaString> list1;
    DoubleLinkedList<LunaString> list2;
    DoubleLinkedList<LunaString> modList1;
    DoubleLinkedList<LunaString> modList2;
    ifstream fin;
    ofstream fout;

    fin.open("infile1.txt");
    LunaString temp;
    while (!fin.eof()) {
        fin >> temp;
        list1.insert(temp);
    }
    fin.close();
    fin.open("infile2.txt");

    while (!fin.eof()) {
        fin >> temp;
        list2.insert(temp);
    }
    
    cout << "Read from file: " << endl;
    cout << "File1 Size: " << list1.getCount() << endl;
    cout << "File2 Size: " << list2.getCount() << endl;
    cout << "ModFile1 Size: " << modList1.getCount() << endl;
    cout << "ModFile2 Size: " << modList2.getCount() << endl;
    cout << endl << endl;

    modList1 = list1;
    modList2 = list2;

    cout << "Files copied to mod files: " << endl;
    cout << "File1 Size: " << list1.getCount() << endl;
    cout << "File2 Size: " << list2.getCount() << endl;
    cout << "ModFile1 Size: " << modList1.getCount() << endl;
    cout << "ModFile2 Size: " << modList2.getCount() << endl;
    cout << endl << endl;


    list2.resetIteration();
    while(list2.hasMore()) {
        modList1.remove(list2.next());
    }

    list1.resetIteration();
    while (list1.hasMore()) {
        modList2.remove(list1.next());
    }

    cout << "Removed list1 from Modlist2 vice versa: " << endl;
    cout << "File1 Size: " << list1.getCount() << endl;
    cout << "File2 Size: " << list2.getCount() << endl;
    cout << "ModFile1 Size: " << modList1.getCount() << endl;
    cout << "ModFile2 Size: " << modList2.getCount() << endl;
    cout << endl << endl;

    changer(modList1);
    changer(modList2);
    cout << endl;

    cout << "Changer Func Used: " << endl;
    cout << "File1 Size: " << list1.getCount() << endl;
    cout << "File2 Size: " << list2.getCount() << endl;
    cout << "ModFile1 Size: " << modList1.getCount() << endl;
    cout << "ModFile2 Size: " << modList2.getCount() << endl;
    cout << endl << endl;

    LunaString lstring;

    cout << "Created Count: " << lstring.getCreatedCount() << endl;
    cout << "Current Count: " << lstring.getCreatedCount() << endl;

    fout.open("outfile1.txt");
    fout << modList1;
    fout.close();

    fout.open("outfile2.txt");
    fout << modList2;

    DoubleLinkedList<int> intList;
    for (int i = 20; i > 0; i -= 2) {
        intList.insert(i);
    }

    for (int i = 25; i > 0; i -= 5) {
        intList.insert(i);
    }

    cout << "intlist: ";
    cout << intList;
    cout << "  size:" << intList.getCount() << endl << endl;

    DoubleLinkedList<double> dblList;
    for (double i = 10.9; i > 0; i -= .57) {
        dblList.insert(i);
    }

    cout << "dblList: ";
    cout << dblList;
    cout << "  size:" << dblList.getCount() << endl << endl;






    /*vector<LunaString> lstring;
    fstream fin;
    fin.open("infile2.txt");
    int j = 0;
    LunaString tempString;
    LunaString jumboTemp;
    do {
        jumboTemp = LunaString();
        for (int i = 0; i < 5; i++) {
            if (fin.eof()) {
                break;
            }
            fin >> tempString;
            jumboTemp = jumboTemp + tempString;
        }
        lstring.push_back(jumboTemp);
    } while (!fin.eof());
    bubbleSort(lstring);
    for (int i = 0; i < lstring.size(); i++) {
        cout << setw(33) << left << lstring.at(i);
        cout << lstring.at(i).length() << ":" << lstring.at(i).capacity() << endl;
    }
    cout << "Created Count: " << lstring.at(0).getCreatedCount() << endl;
    cout << "Current Count: " << lstring.at(0).getCurrentCount() << endl;
    return 0;*/


    /*
    vector<LunaString> lstring(100);
    ifstream fin;
    ofstream fout;
    fin.open("infile2.txt");
    int i = 0;
    do {
        fin >> lstring[i];
        i++;
    } while (!fin.eof());
    lstring.resize(i + 1);
    bubbleSort(lstring);
    i = 0;
    fout.open("outfile.txt");
    for (int j = lstring.size() / 6; j > 0; j--) {
        for (i = 1; i <= 6; i++) {
            fout << setw(13) << lstring[(j * 6) - i];
        }
        fout << endl;
    }
    */

    //CONSLE HERE:
    /*Read from file:
File1 Size: 1105
File2 Size: 60
ModFile1 Size: 0
ModFile2 Size: 0


Files copied to mod files:
File1 Size: 1105
File2 Size: 60
ModFile1 Size: 1105
ModFile2 Size: 60


Removed list1 from Modlist2 vice versa:
File1 Size: 1105
File2 Size: 60
ModFile1 Size: 1076
ModFile2 Size: 31


Inside changer func: size of list is 1078
Inside changer func: size of list is 33

Changer Func Used:
File1 Size: 1105
File2 Size: 60
ModFile1 Size: 1076
ModFile2 Size: 31


Created Count: 11981
Current Count: 11981
intlist: 2 4 5 6 8 10 12 14 15 16 18 20 25   size:13

dblList: 0.07 0.64 1.21 1.78 2.35 2.92 3.49 4.06 4.63 5.2 5.77 6.34 6.91 7.48 8.05 8.62 9.19 9.76 10.33 10.9   size:20*/
}



