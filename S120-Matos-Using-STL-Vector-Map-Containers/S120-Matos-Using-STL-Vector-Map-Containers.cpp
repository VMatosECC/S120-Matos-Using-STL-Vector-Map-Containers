// S120-Matos-Using-STL-Vector-Map-Containers.cpp 

#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

using namespace std;
//Prototypes-------------------------------------
void experiment01();
void experiment02();

template <class T> void showVector(vector<T> v, string caption = "", 
                                   char terminator = ' ');
template <class T> void bubbleSort(vector<T>&  v);

//void showVector(vector<string> v, string caption = "");

int main()
{
    //experiment01();     //Processing a vector holding integers
    experiment02(); //Processing a collection of Item objects

    cout << "All done!\n";
}
//-------------------------------------------------------------
void experiment02() {
    vector<Item> v{
        Item("X1234", "banana", 1.0, "Chiquita"),
        Item("X1000", "mango", 2.0, "Chiquita"),
        Item("X7777", "orange", .25, "Chiquita"),
        Item("X5555", "grape", 1.0, "Chiquita"),
        Item("X2222", "apple", .75, "Orchard Hills"),

    };
    v.push_back(Item("X3333", "jalapeno", 2.0, "Cuervo Corp"));
    v.emplace_back("X4444", "papaya", 3.0, "Maui Corp");

    showVector(v, "Before sorting - Fruit Database", '\n');
    bubbleSort(v);
    showVector(v, "After Sorting - Fruit Database", '\n');

}


// ------------------------------------------------------------
void experiment01() {
    vector<int> v1 = { 22, 44, 11, 33, 66, 55 };
    showVector(v1, "Original collection of integers");

    //v1 = { 77, 88 };
    //showVector(v1, "After ={ } assignment");

    vector<string> v2 = { "Bart", "Marge", "Maggie", "Lisa", "Homer" };
    showVector(v2, "The Simpsons");

    bubbleSort(v1);
    showVector(v1, "Sorted collection on integers");

    bubbleSort(v2);
    showVector(v2, "The Simpsons in alphabetic order");
}

template <class T>
void showVector(vector<T> v, string caption, char terminator) {
    cout << endl << caption << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << i << ":" << v[i] << " " << terminator;
    }
    cout << endl;
}

template<class T>
void bubbleSort(vector<T>& v) {
    for (int j = v.size() -1 ; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (v[i] > v[i + 1]) {
                T temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
}



//void showVector(vector<string> v, string caption) {
//    cout << endl << caption << endl;
//    for (int i = 0; i < v.size(); i++) {
//        cout << i << ": " << v[i] << " ";
//    }
//    cout << endl;
//}