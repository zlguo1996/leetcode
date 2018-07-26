#ifndef LeetcodeIO_hpp
#define LeetcodeIO_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/*
 * Name: LeetcodeIO library
 * Function: Print vector/mat to cout, read vector/mat from csv file.
 */
namespace leetcodeio {
    
    /*--------------------------print-----------------------*/
    // 打印vector<T>
    template <typename T>
    inline void printVec(vector<T> vec) {
        int i=0;
        for(; i<vec.size()-1; i++){
            cout << vec[i] << ",";
        }
        if(i<vec.size()) cout << vec[i] << endl;
    }
    
    // 打印vector<vector<T>>
    template <typename T>
    inline void printMat(vector<vector<T>> mat) {
        for(auto array:mat){
            for (int i=0; i<array.size()-1; i++) {
                cout << array[i] << ",";
            }
            if(array.size()!=0) cout << array.back();
            cout << endl;
        }
    }
    
    /*--------------------------read-----------------------*/
    // -----vector-----
    // 从csv文件读取vector<string>
    inline vector<string> readVecStr(string csv_file_path) {
        ifstream file(csv_file_path, ios::out);
        assert(file.is_open());
        
        string lineStr;
        vector<string> strArray;
        while (getline(file, lineStr)) {
            stringstream ss(lineStr);
            string str;
            
            while (getline(ss, str, ',')) {
                strArray.push_back(str);
            }
        }
        
        return strArray;
    }
    // 从csv文件读取vector<T>（T为int||float||double）
    template <typename T>
    inline vector<vector<T>> readVecNum(string csv_file_path) {
        assert(sizeof(int)==sizeof(T)||sizeof(float)==sizeof(T)||sizeof(double)==sizeof(T));
        
        vector<T> numVec;
        vector<string> strVec = readVecStr(csv_file_path);
        
        for(auto str:strVec){
            stringstream ss(str);
            T num;
            ss >> num;
            numVec.push_back(num);
        }
        
        return numVec;
    }
    
    // -----mat-----
    // 从csv文件读取vector<vector<string>>
    inline vector<vector<string>> readMatStr(string csv_file_path) {
        ifstream file(csv_file_path, ios::out);
        assert(file.is_open());
        
        string lineStr;
        vector<vector<string>> strMat;
        while (getline(file, lineStr)) {
            stringstream ss(lineStr);
            string str;
            
            vector<string> strArray;
            while (getline(ss, str, ',')) {
                strArray.push_back(str);
            }
            strMat.push_back(strArray);
        }
        
        return strMat;
    }
    
    // 从csv文件读取vector<vector<T>>（T为int||float||double）
    template <typename T>
    inline vector<vector<T>> readMatNum(string csv_file_path) {
        assert(sizeof(int)==sizeof(T)||sizeof(float)==sizeof(T)||sizeof(double)==sizeof(T));
        
        vector<vector<T>> numMat;
        vector<vector<string>> strMat = readMatStr(csv_file_path);
        
        for(auto strArray:strMat){
            vector<T> numArray;
            for(auto str:strArray){
                stringstream ss(str);
                T num;
                ss >> num;
                numArray.push_back(num);
            }
            numMat.push_back(numArray);
        }
        
        return numMat;
    }
}


#endif /* LeetcodeIO_hpp */
