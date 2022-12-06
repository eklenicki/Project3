#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <math.h>
#include <chrono>

using namespace std;

struct Airport{
private:
    string code, name;
    vector<string> carriers;
    int delCarriers, delLateAircraft, delNAS, delSecurity, delWeather;
    int totCarriers, flightsCancelled, flightsDel, flightsDiverted, flightsOnTime, flightsTot;
    int minDelCarrier, minDelLateAircraft, minDelNAS, minDelSecurity, minDelTotal, minDelWeather;
public:
    Airport(){
        this->code = "ABC";
        this->name = "ABC AIRLINES";
        this->delCarriers = 99999999;
        this->delLateAircraft = 99999999;
        this->delNAS = 99999999;
        this->delSecurity = 99999999;
        this->delWeather = 99999999;
        this->totCarriers = 99999999;
        this->flightsCancelled = 99999999;
        this->flightsDel = 0;
        this->flightsDiverted = 99999999;
        this->flightsOnTime = 99999999;
        this->flightsTot = 99999999;
        this->minDelCarrier = 99999999;
        this->minDelLateAircraft = 99999999;
        this->minDelNAS = 99999999;
        this->minDelSecurity = 99999999;
        this->minDelTotal = 0;
        this->minDelWeather = 99999999;
    }
    Airport(string code, string name, int delCarriers, int delLateAircraft, int delNAS, int delSecurity, int delWeather,
            string carriers, int totCarriers, int flightsCancelled, int flightsDel, int flightsDiverted, int flightsOnTime,
            int flightsTot, int minDelCarrier, int minDelLateAircraft, int minDelNAS, int minDelSecurity, int minDelTotal, int minDelWeather){
        this->code = code;
        this->name = name;
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

    void combiner(Airport other){
        this->delCarriers += other.delCarriers;
        this->delLateAircraft += other.delLateAircraft;
        this->delNAS += other.delNAS;
        this->delSecurity += other.delSecurity;
        this->delWeather += other.delWeather;
        this->totCarriers += other.totCarriers;
        this->flightsCancelled += other.flightsCancelled;
        this->flightsDel += other.flightsDel;
        this->flightsDiverted += other.flightsDiverted;
        this->flightsOnTime += other.flightsOnTime;
        this->flightsTot += other.flightsTot;
        this->minDelCarrier += other.minDelCarrier;
        this->minDelLateAircraft += other.minDelLateAircraft;
        this->minDelNAS += other.minDelNAS;
        this->minDelSecurity += other.minDelSecurity;
        this->minDelTotal += other.minDelTotal;
        this->minDelWeather += other.minDelWeather;
        for (int i = 0; i < other.carriers.size(); i++){
            bool present = false;
            for (int j = 0; j < this->carriers.size(); j++){
                if (other.carriers[i] == this->carriers[j]){
                    present = true;
                }
            }
            if (present == false){
                this->carriers.push_back(other.carriers[i]);
            }
        }
    }

    void printAirport(string type){
        if (type == "DEL"){
            cout << endl;
            cout << this->name << " (" << this->code << "):" << endl;
            cout << "Study from June, 2003 - January, 2016" << endl;
            cout << endl;
            cout << "Airlines: " << endl;
            for (int i = 0; i < this->carriers.size(); i++){
                cout << carriers[i] << endl;
            }
            cout << endl;
            cout << "Total Flights Delayed: " << this->flightsDel << endl;
            cout << "Flights Delayed due to Airlines (late baggage loading, fueling, cleaning, crew problems): " << this->delCarriers << endl;
            cout << "Flights Delayed due to Late Aircrafts (plane arrived late from previous flight): " << this->delLateAircraft << endl;
            cout << "Flights Delayed due to National Aviation System (non-extreme weather, airport conditions, heavy traffic on runway): " << this->delNAS << endl;
            cout << "Flights Delayed due to Security (long lines in TSA, re-boarding airplane due to securit breach, evacuation of terminal): " << this->delSecurity << endl;
            cout << "Flights Delayed due to Extreme Weather Conditions (blizzard, hurricane, tornado, severe thunderstorm): " << this->delWeather << endl;
            cout << "Average Flights Delayed Per Month: " << (this->flightsDel/152) << endl;
        }
        else if (type == "MIN"){
            cout << endl;
            cout << this->name << " (" << this->code << "):" << endl;
            cout << "Study from June, 2003 - January, 2016" << endl;
            cout << endl;
            cout << "Airlines: " << endl;
            for (int i = 0; i < this->carriers.size(); i++){
                cout << carriers[i] << endl;
            }
            cout << endl;
            cout << "Total Minutes Delayed: " << this->minDelTotal << endl;
            cout << "Minutes Delayed due to Airlines (late baggage loading, fueling, cleaning, crew problems): " << this->minDelCarrier << endl;
            cout << "Minutes Delayed due to Late Aircrafts (plane arrived late from previous flight): " << this->minDelLateAircraft << endl;
            cout << "Minutes Delayed due to National Aviation System (non-extreme weather, airport conditions, heavy traffic on runway): " << this->minDelNAS << endl;
            cout << "Minutes Delayed due to Security (long lines in TSA, re-boarding airplane due to securit breach, evacuation of terminal): " << this->minDelSecurity << endl;
            cout << "Minutes Delayed due to Extreme Weather Conditions (blizzard, hurricane, tornado, severe thunderstorm): " << this->minDelWeather << endl;
            cout << "Average Minutes Delayed Per Month: " << (this->minDelTotal/152) << endl;
        }
        else{
            cout << endl;
            cout << this->name << " (" << this->code << "):" << endl;
            cout << "Study from June, 2003 - January, 2016" << endl;
            cout << endl;
            cout << "Airlines: " << endl;
            for (int i = 0; i < this->carriers.size(); i++){
                cout << carriers[i] << endl;
            }
            cout << endl;
            cout << "Total Flights: " << this->flightsTot << endl;
            cout << "Total Flights Delayed: " << this->flightsDel << endl;
            cout << "Total Flights Cancelled: " << this->flightsCancelled << endl;
            cout << "Total Flights Diverted: " << this->flightsDiverted << endl;
            cout << "Total Flights On Time: " << this->flightsOnTime << endl;
            cout << "Percent of Flights Delayed: " << (100 * (this->flightsDel/this->flightsTot)) << "%" << endl;
            cout << "Percent of Flights On Time: " << (100 * (this->flightsOnTime/this->flightsTot)) << "%" << endl;
        }
    }
};

class minHeap{
private:
    Airport heap[29];
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

    Airport getMax(Airport heap[], int size, string type){
        int max = 0;
        int pos;
        for (int i = 0; i < size; i++){
            int leftIndex = (i * 2) + 1;
            int rightIndex = (i * 2) + 2;
            if (leftIndex >= size && rightIndex >= size){
                if (type == "DEL"){
                    if (heap[i].getDelay() > max){
                        max = heap[i].getDelay();
                        pos = i;
                    }
                }
                else{
                    if (heap[i].getMin() > max){
                        max = heap[i].getMin();
                        pos = i;
                    }
                }
            }
        }
        return heap[pos];
    }

     Airport* insertToHeap(Airport heap[], int size, Airport flying, string type){
        bool combined = false;
        for (int i = 0; i < size; i++){
            if (heap[i].getName() == flying.getName()){
                heap[i].combiner(flying);
                combined = true;
            }
        }
        if (combined == false){
            heap[0] = flying;
        }
        return rearrangeHeap(heap, size, 0, type);
    }

    void setHeap(Airport heapIn[]){
        for (int i = 0; i < 29; i++){
            this->heap[i] = heapIn[i];
        }
    }

    Airport* getHeap(){
        return this->heap;
    }
};

class airportMap{
private:
    map<int, Airport> airports;
public:
    map<int, Airport> insertToMap(map<int, Airport> airportMap, Airport flying, string type){
        bool combined = false;
        for (auto iter = airportMap.begin(); iter != airportMap.end(); iter++){
            if (iter->second.getName() == flying.getName()){
                airportMap[iter->first].combiner(flying);
                combined = true;
            }
        }
        if (combined == false){
            if (type == "DEL"){
                airportMap[flying.getDelay()] = flying;
            }
            else{
                airportMap[flying.getMin()] = flying;
            }
        }
        return airportMap;
    }

    void setMap (map<int, Airport> airportMap){
        this->airports = airportMap;
    }

    map<int, Airport> getMap (){
        return this->airports;
    }
};

airportMap readFileMap(string type){
    airportMap mapOfAirports;
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
            mapOfAirports.setMap(mapOfAirports.insertToMap(mapOfAirports.getMap(), Airport(airportCode, airportName, stoi(delaysCarriers), stoi(delaysLateAircraft), stoi(delaysNAS), stoi(delaysSecurity), stoi(delaysWeather), carriers, stoi(totalCarriers), stoi(flightsCancelled), stoi(flightsDelayed), stoi(flightsDiverted), stoi(flightsOnTime), stoi(flightsTotal), stoi(minDelayedCarrier), stoi(minDelayedLateAircraft), stoi(minDelayedNAS), stoi(minDelayedSecurity), stoi(minDelayedTotal), stoi(minDelayedWeather)), type));
        }
    }
    return mapOfAirports;
}

minHeap readFileHeap(string type){
    minHeap heap;
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
            heap.setHeap(heap.insertToHeap(heap.getHeap(), 29, Airport(airportCode, airportName, stoi(delaysCarriers), stoi(delaysLateAircraft), stoi(delaysNAS), stoi(delaysSecurity), stoi(delaysWeather), carriers, stoi(totalCarriers), stoi(flightsCancelled), stoi(flightsDelayed), stoi(flightsDiverted), stoi(flightsOnTime), stoi(flightsTotal), stoi(minDelayedCarrier), stoi(minDelayedLateAircraft), stoi(minDelayedNAS), stoi(minDelayedSecurity), stoi(minDelayedTotal), stoi(minDelayedWeather)), type));
        }
    }
    return heap;
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
    cout << "7. SEARCH BY AIRPORT" << endl;
};

int checkInvalidInput (int choice){
    while (choice > 7 || choice < 0){
        cout << endl;
        cout << "INVALID CHOICE" << endl;
        cout << endl;
        printMenu();
        cout << "ENTER NEW CHOICE:" << endl;
        cin >> choice;
    }
    return choice;
}

int main() {
    airportMap airportMapDel = readFileMap("DEL");
    minHeap airportHeapDel = readFileHeap("DEL");
    airportMap airportMapMin = readFileMap("MIN");
    minHeap airportHeapMin = readFileHeap("MIN");
    cout << "Welcome to Project 3 - Airport Delay Avoider (ADA)" << endl;
    cout << "The purpose of this program is to help find which airports have the most delays, so you can avoid them in the future." << endl;
    int choice = 10;
    int dataStructure = 0;
    while (choice != 0){
        cout << endl;
        printMenu();
        cout << "ENTER CHOICE:" << endl;
        cin >> choice;
        choice = checkInvalidInput(choice);
        if (choice == 1){
            cout << endl;
            cout << "SELECT DATA STRUCTURE" << endl;
            cout << "1. MAP" << endl;
            cout << "2. MIN-HEAP" << endl;
            cout << "3. BOTH (COMPARE)" << endl;
            cout << "ENTER CHOICE:" << endl;
            cin >> dataStructure;
            while (dataStructure > 3 || dataStructure < 1){
                cout << endl;
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
                cout << endl;
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){
                cout << endl;
                auto start = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapDel.getMap();
                for (auto iter = mapAir.begin(); iter != mapAir.end(); iter++){
                    cout << iter->second.getName() << endl;
                }
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 2){
                cout << endl;
                auto start = chrono::steady_clock::now();
                Airport* arrHeap = airportHeapDel.getHeap();
                for (int i = 0; i < 29; i++){
                    cout << arrHeap[i].getName() << endl;
                }
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 3){
                cout << endl;
                auto start1 = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapDel.getMap();
                for (auto iter = mapAir.begin(); iter != mapAir.end(); iter++){
                    cout << iter->second.getName() << endl;
                }
                auto end1 = chrono::steady_clock::now();
                cout << endl;
                int time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time1 << " millisecond(s)" << endl;
                cout << endl;
                auto start2 = chrono::steady_clock::now();
                Airport* arrHeap = airportHeapDel.getHeap();
                for (int i = 0; i < 29; i++){
                    cout << arrHeap[i].getName() << endl;
                }
                auto end2 = chrono::steady_clock::now();
                cout << endl;
                int time2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time2 << " millisecond(s)" << endl;
                cout << endl;
                cout << "THE MAP TOOK " + to_string(time1) + " MILLISECOND(S) AND THE MIN-HEAP TOOK " + to_string(time2) + " MILLISECOND(S)" << endl;
                if (time1 > time2){
                    cout << "THE MIN-HEAP WAS FASTER BY " << time1-time2 << " SECONDS" << endl;
                }
                else if (time1 < time2){
                    cout << "THE MAP WAS FASTER BY " << time2-time1 << " SECONDS" << endl;
                }
                else {
                    cout << "THE MAP AND MIN-HEAP ARE EQUALLY FAST" << endl;
                }
            }
        }
        else if (choice == 3){
            if (dataStructure == 0){
                cout << endl;
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){
                auto start = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapDel.getMap();
                mapAir.begin()->second.printAirport("DEL");
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 2){
                auto start = chrono::steady_clock::now();
                Airport* arrHeap = airportHeapDel.getHeap();
                arrHeap[0].printAirport("DEL");
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 3){
                auto start1 = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapDel.getMap();
                mapAir.begin()->second.printAirport("DEL");
                auto end1 = chrono::steady_clock::now();
                cout << endl;
                int time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time1 << " millisecond(s)" << endl;
                auto start2 = chrono::steady_clock::now();
                Airport* arrHeap = airportHeapDel.getHeap();
                arrHeap[0].printAirport("DEL");
                auto end2 = chrono::steady_clock::now();
                cout << endl;
                int time2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time2 << " millisecond(s)" << endl;
                cout << endl;
                cout << "THE MAP TOOK " + to_string(time1) + " MILLISECOND(S) AND THE MIN-HEAP TOOK " + to_string(time2) + " MILLISECOND(S)" << endl;
                if (time1 > time2){
                    cout << "THE MIN-HEAP WAS FASTER BY " << time1-time2 << " SECONDS" << endl;
                }
                else if (time1 < time2){
                    cout << "THE MAP WAS FASTER BY " << time2-time1 << " SECONDS" << endl;
                }
                else {
                    cout << "THE MAP AND MIN-HEAP ARE EQUALLY FAST" << endl;
                }
            }
        }
        else if (choice == 4){
            if (dataStructure == 0){
                cout << endl;
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){
                auto start = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapDel.getMap();
                auto iter = mapAir.end();
                iter--;
                iter->second.printAirport("DEL");
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 2){
                auto start = chrono::steady_clock::now();
                Airport maxAir = airportHeapDel.getMax(airportHeapDel.getHeap(), 29, "DEL");
                maxAir.printAirport("DEL");
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 3){
                auto start1 = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapDel.getMap();
                auto iter = mapAir.end();
                iter--;
                iter->second.printAirport("DEL");
                auto end1 = chrono::steady_clock::now();
                cout << endl;
                int time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time1 << " millisecond(s)" << endl;
                auto start2 = chrono::steady_clock::now();
                Airport maxAir = airportHeapDel.getMax(airportHeapDel.getHeap(), 29, "DEL");
                maxAir.printAirport("DEL");
                auto end2 = chrono::steady_clock::now();
                cout << endl;
                int time2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time2 << " millisecond(s)" << endl;
                cout << endl;
                cout << "THE MAP TOOK " + to_string(time1) + " MILLISECOND(S) AND THE MIN-HEAP TOOK " + to_string(time2) + " MILLISECOND(S)" << endl;
                if (time1 > time2){
                    cout << "THE MIN-HEAP WAS FASTER BY " << time1-time2 << " SECONDS" << endl;
                }
                else if (time1 < time2){
                    cout << "THE MAP WAS FASTER BY " << time2-time1 << " SECONDS" << endl;
                }
                else {
                    cout << "THE MAP AND MIN-HEAP ARE EQUALLY FAST" << endl;
                }
            }
        }
        else if (choice == 5){
            if (dataStructure == 0){
                cout << endl;
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){
                auto start = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapMin.getMap();
                mapAir.begin()->second.printAirport("MIN");
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 2){
                auto start = chrono::steady_clock::now();
                Airport* arrHeap = airportHeapMin.getHeap();
                arrHeap[0].printAirport("MIN");
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 3){
                auto start1 = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapMin.getMap();
                mapAir.begin()->second.printAirport("MIN");
                auto end1 = chrono::steady_clock::now();
                cout << endl;
                int time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time1 << " millisecond(s)" << endl;
                auto start2 = chrono::steady_clock::now();
                Airport* arrHeap = airportHeapMin.getHeap();
                arrHeap[0].printAirport("MIN");
                auto end2 = chrono::steady_clock::now();
                cout << endl;
                int time2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time2 << " millisecond(s)" << endl;
                cout << endl;
                cout << "THE MAP TOOK " + to_string(time1) + " MILLISECOND(S) AND THE MIN-HEAP TOOK " + to_string(time2) + " MILLISECOND(S)" << endl;
                if (time1 > time2){
                    cout << "THE MIN-HEAP WAS FASTER BY " << time1-time2 << " SECONDS" << endl;
                }
                else if (time1 < time2){
                    cout << "THE MAP WAS FASTER BY " << time2-time1 << " SECONDS" << endl;
                }
                else {
                    cout << "THE MAP AND MIN-HEAP ARE EQUALLY FAST" << endl;
                }
            }
        }
        else if (choice == 6){
            if (dataStructure == 0){
                cout << endl;
                cout << "YOU MUST SELECT A DATA STRUCTURE FIRST" << endl;
                continue;
            }
            else if (dataStructure == 1){
                auto start = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapMin.getMap();
                auto iter = mapAir.end();
                iter--;
                iter->second.printAirport("MIN");
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 2){
                auto start = chrono::steady_clock::now();
                Airport maxAir = airportHeapMin.getMax(airportHeapMin.getHeap(), 29, "MIN");
                maxAir.printAirport("MIN");
                auto end = chrono::steady_clock::now();
                cout << endl;
                cout << "ELAPSED TIME OF FUNCTION: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecond(s)" << endl;
            }
            else if (dataStructure == 3){
                auto start1 = chrono::steady_clock::now();
                map<int, Airport> mapAir = airportMapMin.getMap();
                auto iter = mapAir.end();
                iter--;
                iter->second.printAirport("MIN");
                auto end1 = chrono::steady_clock::now();
                cout << endl;
                int time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time1 << " millisecond(s)" << endl;
                auto start2 = chrono::steady_clock::now();
                Airport maxAir = airportHeapMin.getMax(airportHeapMin.getHeap(), 29, "MIN");
                maxAir.printAirport("MIN");
                auto end2 = chrono::steady_clock::now();
                cout << endl;
                int time2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
                cout << "ELAPSED TIME OF FUNCTION: " << time2 << " millisecond(s)" << endl;
                cout << endl;
                cout << "THE MAP TOOK " + to_string(time1) + " MILLISECOND(S) AND THE MIN-HEAP TOOK " + to_string(time2) + " MILLISECOND(S)" << endl;
                if (time1 > time2){
                    cout << "THE MIN-HEAP WAS FASTER BY " << time1-time2 << " SECONDS" << endl;
                }
                else if (time1 < time2){
                    cout << "THE MAP WAS FASTER BY " << time2-time1 << " SECONDS" << endl;
                }
                else {
                    cout << "THE MAP AND MIN-HEAP ARE EQUALLY FAST" << endl;
                }
            }
        }
        else if (choice == 7){
            if (dataStructure == 0){
                cout << endl;
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
    cout << endl << "Thank You for using the Airport Delay Avoider (ADA)";
    return 0;
}
