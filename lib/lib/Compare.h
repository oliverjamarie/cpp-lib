#ifndef COMP_H
#define COMP_H

#define TEMP template <class T>

using namespace std;

TEMP
class Compare {
    public:
        static int compare(T,T);
        bool equals(T,T);

};

TEMP
bool Compare<T>::equals(T obj1, T obj2){
    return compare(obj1,obj2) == 0;
}

TEMP
int Compare<T>::compare(T obj1, T obj2){
    try{
        cout << "COMPARING GENERICS\n";
        return obj1.compare(obj2);
    }
    catch (std::string e){
        cout << e << endl << "Implement a compare function for your object\n";
    }
}

template<>
int Compare<int>::compare(int num1, int num2){
    if (num1 == num2){
        return 0;
    }
    if (num1 < num2) {
        return -1;
    }
    return 1;
}

template<>
int Compare<float>::compare(float num1, float num2){
    cout << "COMPARING FLOAT\n";
    if (num1 == num2){
        return 0;
    }
    if (num1 < num2) {
        return -1;
    }
    return 1;
}

template<>
int Compare<double>::compare(double num1, double num2){
    cout << "COMPARING DOUBLE\n";
    if (num1 == num2){
        return 0;
    }
    if (num1 < num2) {
        return -1;
    }
    return 1;
}

template<>
int Compare<char>::compare(char char1, char char2){
    cout << "COMPARING CHAR\n";
    if (char1 == char2){
        return 0;
    }
    if (char1 < char2) {
        return -1;
    }
    return 1;
}


#endif