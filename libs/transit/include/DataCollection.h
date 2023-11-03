#ifndef DataCollection_MODEL_H_
#define DataCollection_MODEL_H_
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
#include <ctime>
#include "math/vector3.h"
#include <bits/stdc++.h> 
using namespace std;

/**
 * @brief this class is used to collect data about the Car Accident
 */
class DataCollection{
  protected:
    /**
    * @brief constructor.
    */
    DataCollection(){
        numCrash = 0;
        curtime ="";
        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];
        time (&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer,sizeof(buffer),"%d-%m-%Y,%H:%M:%S",timeinfo);
        std::string str(buffer);
        filename = "CrashData_"+str+".csv";
        carname = "";
    }

    static DataCollection* DataCollection_; //!< DataCollection_
    string curtime; //!< curtime
    string filename; //!< filename
    int numCrash;   //!< tolat number of crash happend
    string carname; //!< The name of car that crash

 public:
    /**
    * @brief Parameter constructor.
    */
    DataCollection(DataCollection &other) = delete;
    /**
    * @brief operator "="
    */
    void operator=(const DataCollection &) = delete;
    static DataCollection *GetInstance(){
        if(DataCollection_==nullptr){
            DataCollection_ = new DataCollection();
        }
        return DataCollection_;
    }
    /**
    * @brief Write details of the crash in to the csv file
    * @param[in] filename
    * @param[in] position
    */
    void OutputCsv(string filename, Vector3 position){
        ofstream myFile(filename,ios::app);
        std::streampos posf = myFile.tellp();  // store current location
        myFile.seekp(0, std::ios_base::end);   // go to end
        bool empty = (myFile.tellp() == 0);

        if(empty){
            myFile <<"Name of the car"<<","<< "Crash Position" <<","<<"Crash Time"<< "," << "Crash Number" << "\n";
        }
        string x = to_string(position.x);
        string y = to_string(position.y);
        string z = to_string(position.z);
        string pos = "[" + x + "," + y + "," + z + "]";
        myFile <<carname<<","<<pos << "," <<curtime<<","<< numCrash << "\n";
        myFile.close();
    }
    /**
    * @brief Count the total number of the crash that was happend
    */
    void IncreNumCrash(){ numCrash++; }
    /**
    * @brief Save the crash time
    * @param[in] tmp
    */
    void Settime(string tmp){curtime=tmp;}
    /**
    * @brief Get the csv file name
    * @return filename
    */
    string Getfilename(){return filename;}
    /**
    * @brief Save the name of the car that just crash
    * @param[in] tmp
    */
    void Setcarname(string tmp){carname = tmp;}
};


#endif