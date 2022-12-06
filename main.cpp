#include <iostream>
#include <map>
#include <fstream>
#include <vector>

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

    int getter(string userInput){

    }
};

class minHeap{
private:
    Airport* heap[49];
public:
    Airport* rearrangeHeap(Airport heap[], int size, int index){
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
            if (heap[index] > heap[leftIndex] || heap[index] > heap[rightIndex]){
                int left = heap[leftIndex];
                int right = heap[rightIndex];
                if (left < right){
                    int temp = heap[index];
                    heap[index] = heap[leftIndex];
                    heap[leftIndex] = temp;
                    return rearrangeHeap(heap, size, leftIndex);
                }
                else {
                    int temp = heap[index];
                    heap[index] = heap[rightIndex];
                    heap[rightIndex] = temp;
                    return rearrangeHeap(heap, size, rightIndex);
                }
            }
            else{
                return heap;
            }
        }
    }

    int* extractMin(int heap[], int size)
    {
        int* temp = new int[size - 1];
        temp[0] = heap[size - 1];

        for (int i = 1; i < size - 1; i++){
            temp[i] = heap[i];
        }

        return rearrangeHeap(temp, size - 1, 0);
    }
};

class map{

};

void readFile(){
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

int main() {
    cout << "Welcome to Project 3 - Airport Delay Avoider (ADA)" << endl;
    cout << "The purpose of this program is to help find which airports have the most del0ays, so you can avoid them in the future." << endl;
    cout << "MENU:" << endl;
    cout << "0. EXIT PROGRAM" << endl;
    cout << "1. SELECT DATA STRUCTURE" << endl;
    cout << "2. PRINT ALL AIRPORTS" << endl;
    cout << "3. FIND AIRPORT WITH LEAST DELAYS" << endl;
    cout << "4. FIND AIRPORT WITH MOST DELAYS" << endl;
    cout << "5. FIND AIRPORT WITH SHORTEST DELAYS" << endl;
    cout << "6. FIND AIRPORT WITH LONGEST DELAYS" << endl;

    return 0;
}
