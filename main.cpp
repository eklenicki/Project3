#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

struct Airport{
private:
    string code, name, date, month;
    vector<string> carriers;
    int monthNum, year, delCarriers, delLateAircraft, delNAS, delSecurity, delWeather;
    int totCarriers, flightsCancelled, flightsDel, flightsDiverted, flightsOnTime, flightsTot;
    int minDelCarrier, minDelLateAircraft, minDelNAS, minDelSecurity, minDelTotal, minDelWeather;
public:
    Airport(string code, string name, string date, int monthNum, string month, int year, int delCarriers,
            int delLateAircraft, int delNAS, int delSecurity, int delWeather, string carriers, int totCarriers,
            int flightsCancelled, int flightsDel, int flightsDiverted, int flightsOnTime, int flightsTot, int minDelCarrier,
            int minDelLateAircraft, int minDelNAS, int minDelSecurity, int minDelTotal, int minDelWeather){
        this->code = code;
        this->name = name;
        this->date = date;
        this->monthNum = monthNum;
        this->month = month;
        this->year = year;
        this->delCarriers = delCarriers;
        this->delLateAircraft = delLateAircraft;
        this->delNAS = delNAS;
        this->delSecurity = delSecurity;
        this->delWeather = delWeather;
        this->totCarriers = totCarriers;
        this->flightsCancelled = flightsCancelled;
        this->flightsDel = flightsDel;
        this->flightsDiverted = flightsDiverted;
        this->flightsOnTime = flightsOnTime;
        this->flightsTot = flightsTot;
        this->minDelCarrier = minDelCarrier;
        this->minDelLateAircraft = minDelLateAircraft;
        this->minDelNAS = minDelNAS;
        this->minDelSecurity = minDelSecurity;
        this->minDelTotal = minDelTotal;
        this->minDelWeather = minDelWeather;
        string airline = "";
        for (int j = 0; j < carriers.size(); j++) {
            if (carriers[j] != ',') {
                airline += carriers[j];
            } else {
                this->carriers.push_back(airline);
                airline = "";
            }
        }
        this->carriers.push_back(airline);
    }

    int getDelay(){
        return this->flightsDel;
    }

    int getMin(){
        return this->minDelTotal;
    }

    string getName(){
        string answer = this->name + " (" + this->code + ")";
        return answer;
    }
};

class minHeap{
private:
    Airport* heap[49];
public:
    Airport* rearrangeHeap(Airport heap[], int size, int index, string type){
        int leftIndex = (index * 2) + 1;
        int rightIndex = (index * 2) + 2;
        if (leftIndex >= size && rightIndex >= size){
            return heap;
        }
        else if (rightIndex >= size){
            Airport temp = heap[index];
            heap[index] = heap[leftIndex];
            heap[leftIndex] = temp;
            return heap;
        }
        else {
            if (type == "DEL"){
                if (heap[index].getDelay() > heap[leftIndex].getDelay() || heap[index].getDelay() > heap[rightIndex].getDelay()){
                    int left = heap[leftIndex].getDelay();
                    int right = heap[rightIndex].getDelay();
                    if (left < right){
                        Airport temp = heap[index];
                        heap[index] = heap[leftIndex];
                        heap[leftIndex] = temp;
                        return rearrangeHeap(heap, size, leftIndex, type);
                    }
                    else {
                        Airport temp = heap[index];
                        heap[index] = heap[rightIndex];
                        heap[rightIndex] = temp;
                        return rearrangeHeap(heap, size, rightIndex, type);
                    }
                }
                else{
                    return heap;
                }
            }
            else {
                if (heap[index].getMin() > heap[leftIndex].getMin() || heap[index].getMin() > heap[rightIndex].getMin()){
                    int left = heap[leftIndex].getMin();
                    int right = heap[rightIndex].getMin();
                    if (left < right){
                        Airport temp = heap[index];
                        heap[index] = heap[leftIndex];
                        heap[leftIndex] = temp;
                        return rearrangeHeap(heap, size, leftIndex, type);
                    }
                    else {
                        Airport temp = heap[index];
                        heap[index] = heap[rightIndex];
                        heap[rightIndex] = temp;
                        return rearrangeHeap(heap, size, rightIndex, type);
                    }
                }
                else{
                    return heap;
                }
            }
        }
    }

    Airport getMin(Airport heap[]){
        return heap[0];
    }

    Airport* getMax(Airport heap[], int size, string type){
        int count = 0;
        for (int i = size; i > 1; i /= 2){
            count++;
        }
        int index = pow(2, count) - 1;
        for (int i = index; i < size; i++){

        }
    }
};

class airportMap{
private:
    map<int, Airport> airports;
public:

};

map<int, Airport> readFileMap(string type){
    string airportCode, airportName, date, monthName, carriers;
    string monthNum, year, delaysCarriers, delaysLateAircraft, delaysNAS, delaysSecurity, delaysWeather;
    string totalCarriers, flightsCancelled, flightsDelayed, flightsDiverted, flightsOnTime, flightsTotal;
    string minDelayedCarrier, minDelayedLateAircraft, minDelayedNAS, minDelayedSecurity, minDelayedTotal, minDelayedWeather;
    ifstream file;
    file.open("airlines.csv");
    if (file.is_open()){
        string line;
        getline(file, line, '\n');
        for (int i = 0; i < 4408; i++){
            getline(file, line, '"');
            getline(file, airportCode,'"');
            getline(file, line, '"');
            getline(file, airportName, '"');
            getline(file, line,'"');
            getline(file, date, '"');
            getline(file, line,'"');
            getline(file, monthNum,'"');
            getline(file, line,'"');
            getline(file, monthName,'"');
            getline(file, line,'"');
            getline(file, year,'"');
            getline(file, line,'"');
            getline(file, delaysCarriers,'"');
            getline(file, line,'"');
            getline(file, delaysLateAircraft,'"');
            getline(file, line,'"');
            getline(file, delaysNAS,'"');
            getline(file, line,'"');
            getline(file, delaysSecurity,'"');
            getline(file, line,'"');
            getline(file, delaysWeather,'"');
            getline(file, line,'"');
            getline(file, carriers,'"');
            getline(file, line,'"');
            getline(file, totalCarriers,'"');
            getline(file, line,'"');
            getline(file, flightsCancelled,'"');
            getline(file, line,'"');
            getline(file, flightsDelayed,'"');
            getline(file, line,'"');
            getline(file, flightsDiverted,'"');
            getline(file, line,'"');
            getline(file, flightsOnTime,'"');
            getline(file, line,'"');
            getline(file, flightsTotal,'"');
            getline(file, line,'"');
            getline(file, minDelayedCarrier,'"');
            getline(file, line,'"');
            getline(file, minDelayedLateAircraft,'"');
            getline(file, line,'"');
            getline(file, minDelayedNAS,'"');
            getline(file, line,'"');
            getline(file, minDelayedSecurity,'"');
            getline(file, line,'"');
            getline(file, minDelayedTotal,'"');
            getline(file, line,'"');
            getline(file, minDelayedWeather,'"');
            getline(file,line, '\n');

        }
    }
}

Airport* readFileHeap(string type){
    string airportCode, airportName, date, monthName, carriers;
    string monthNum, year, delaysCarriers, delaysLateAircraft, delaysNAS, delaysSecurity, delaysWeather;
    string totalCarriers, flightsCancelled, flightsDelayed, flightsDiverted, flightsOnTime, flightsTotal;
    string minDelayedCarrier, minDelayedLateAircraft, minDelayedNAS, minDelayedSecurity, minDelayedTotal, minDelayedWeather;
    ifstream file;
    file.open("airlines.csv");
    if (file.is_open()){
        string line;
        getline(file, line, '\n');
        for (int i = 0; i < 4408; i++){
            getline(file, line, '"');
            getline(file, airportCode,'"');
            getline(file, line, '"');
            getline(file, airportName, '"');
            getline(file, line,'"');
            getline(file, date, '"');
            getline(file, line,'"');
            getline(file, monthNum,'"');
            getline(file, line,'"');
            getline(file, monthName,'"');
            getline(file, line,'"');
            getline(file, year,'"');
            getline(file, line,'"');
            getline(file, delaysCarriers,'"');
            getline(file, line,'"');
            getline(file, delaysLateAircraft,'"');
            getline(file, line,'"');
            getline(file, delaysNAS,'"');
            getline(file, line,'"');
            getline(file, delaysSecurity,'"');
            getline(file, line,'"');
            getline(file, delaysWeather,'"');
            getline(file, line,'"');
            getline(file, carriers,'"');
            getline(file, line,'"');
            getline(file, totalCarriers,'"');
            getline(file, line,'"');
            getline(file, flightsCancelled,'"');
            getline(file, line,'"');
            getline(file, flightsDelayed,'"');
            getline(file, line,'"');
            getline(file, flightsDiverted,'"');
            getline(file, line,'"');
            getline(file, flightsOnTime,'"');
            getline(file, line,'"');
            getline(file, flightsTotal,'"');
            getline(file, line,'"');
            getline(file, minDelayedCarrier,'"');
            getline(file, line,'"');
            getline(file, minDelayedLateAircraft,'"');
            getline(file, line,'"');
            getline(file, minDelayedNAS,'"');
            getline(file, line,'"');
            getline(file, minDelayedSecurity,'"');
            getline(file, line,'"');
            getline(file, minDelayedTotal,'"');
            getline(file, line,'"');
            getline(file, minDelayedWeather,'"');
            getline(file,line, '\n');
        }
    }
}

void printMenu() {
    cout << "MENU:" << endl;
    cout << "0. EXIT PROGRAM" << endl;
    cout << "1. SELECT DATA STRUCTURE" << endl;
    cout << "2. PRINT ALL AIRPORTS" << endl;
    cout << "3. FIND AIRPORT WITH LEAST DELAYS" << endl;
    cout << "4. FIND AIRPORT WITH MOST DELAYS" << endl;
    cout << "5. FIND AIRPORT WITH SHORTEST DELAYS" << endl;
    cout << "6. FIND AIRPORT WITH LONGEST DELAYS" << endl;
    cout << "7. FIND AIRLINE WITH LEAST DELAYS" << endl;
    cout << "8. FIND AIRLINE WITH MOST DELAYS" << endl;
    cout << "9. SEARCH BY AIRPORT" << endl;
    cout << "10. SEARCH BY AIRLINE" << endl;
};

int checkInvalidInput (int choice){
    while (choice > 10 || choice < 0){
        cout << "INVALID CHOICE" << endl;
        printMenu();
        cout << "ENTER NEW CHOICE:" << endl;
        cin >> choice;
    }
    return choice;
}

int main() {
    cout << "Welcome to Project 3 - Airport Delay Avoider (ADA)" << endl;
    cout << "The purpose of this program is to help find which airports have the most del0ays, so you can avoid them in the future." << endl;
    int choice, dataStructure = 0;
    while (choice != 0){
        printMenu();
        cout << "ENTER CHOICE:" << endl;
        cin >> choice;
        choice = checkInvalidInput(choice);
        if (choice == 1){
            cout << "SELECT DATA STRUCTURE" << endl;
            cout << "1. MAP" << endl;
            cout << "2. MIN-HEAP" << endl;
            cout << "3. BOTH (COMPARE)" << endl;
            cout << "ENTER CHOICE:" << endl;
            cin >> dataStructure;
            while (dataStructure > 3 || dataStructure < 1){
                cout << "INVALID CHOICE" << endl;
                cout << "SELECT DATA STRUCTURE" << endl;
                cout << "1. MAP" << endl;
                cout << "2. MIN-HEAP" << endl;
                cout << "3. BOTH (COMPARE)" << endl;
                cout << "ENTER CHOICE:" << endl;
                cin >> dataStructure;
            }
        }
        else if (choice == 2){
            if (dataStructure == 0){
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){
                map<int, Airport> airportMap = readFileMap("DEL");
                for (auto iter = airportMap.begin(); iter != airportMap.end(); iter++){
                    cout << iter->second.getName() << endl;
                }
            }
            else if (dataStructure == 2){
                Airport* heap = readFileHeap("DEL");
                for (int i = 0; i < 49; i++){
                    cout << heap[i].getName() << endl;
                }
            }
            else if (dataStructure == 3){
                
            }
        }
        else if (choice == 3){
            if (dataStructure == 0){
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){

            }
            else if (dataStructure == 2){

            }
            else if (dataStructure == 3){

            }
        }
        else if (choice == 4){
            if (dataStructure == 0){
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){

            }
            else if (dataStructure == 2){

            }
            else if (dataStructure == 3){

            }
        }
        else if (choice == 5){
            if (dataStructure == 0){
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){

            }
            else if (dataStructure == 2){

            }
            else if (dataStructure == 3){

            }
        }
        else if (choice == 6){
            if (dataStructure == 0){
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){

            }
            else if (dataStructure == 2){

            }
            else if (dataStructure == 3){

            }
        }
        else if (choice == 7){
            if (dataStructure == 0){
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){

            }
            else if (dataStructure == 2){

            }
            else if (dataStructure == 3){

            }
        }
        else if (choice == 8){
            if (dataStructure == 0){
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){

            }
            else if (dataStructure == 2){

            }
            else if (dataStructure == 3){

            }
        }
        else if (choice == 9){
            if (dataStructure == 0){
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){

            }
            else if (dataStructure == 2){

            }
            else if (dataStructure == 3){

            }
        }
        else if (choice == 10){
            if (dataStructure == 0){
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){

            }
            else if (dataStructure == 2){

            }
            else if (dataStructure == 3){

            }
        }
    }
    cout << "Thank You for using the Airport Delay Avoider (ADA)" << endl;
    return 0;
}
