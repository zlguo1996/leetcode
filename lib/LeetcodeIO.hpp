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
    // 从文件读取vector<string>
        // csv格式
    inline vector<string> readVecStrCsv(string csv_file_path) {
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
        // leetcode格式
    inline vector<string> readVecStrLc(string file_path){
        ifstream file(file_path, ios::in);
        assert(file.is_open());
        
        string lineStr;
        vector<string> vec;
        while (getline(file, lineStr, ',')) {
            int pos_begin=0, pos_end;
            while(lineStr[pos_begin]=='['||lineStr[pos_begin]=='"') pos_begin++;
            pos_end = pos_begin;
            while(lineStr[pos_end]!='"') pos_end++;
            vec.push_back(lineStr.substr(pos_begin, pos_end-pos_begin));
        }
        
        return vec;
    }
    
    // 从文件读取vector<T>（T为int||float||double）
        // csv格式
    template <typename T>
    inline vector<vector<T>> readVecNum(string csv_file_path) {
        assert(sizeof(int)==sizeof(T)||sizeof(float)==sizeof(T)||sizeof(double)==sizeof(T));
        
        vector<T> numVec;
        vector<string> strVec = readVecStrCsv(csv_file_path);
        
        for(auto str:strVec){
            stringstream ss(str);
            T num;
            ss >> num;
            numVec.push_back(num);
        }
        
        return numVec;
    }
        // leetcode格式
    inline vector<string> readVecNumLcCsv(string file_path){
        ifstream file(file_path, ios::in);
        assert(file.is_open());
        
        string lineStr;
        vector<string> vec;
        while (getline(file, lineStr, ',')) {
            int pos_begin=0, pos_end;
            if(lineStr[pos_begin]=='[') pos_begin++;
            pos_end = pos_begin;
            while(pos_end<lineStr.size() && lineStr[pos_end]!='"') pos_end++;
            vec.push_back(lineStr.substr(pos_begin, pos_end-pos_begin));
        }
        
        return vec;
    }
    
    // -----mat-----
    // 从文件读取vector<vector<string>>
        // csv格式
    inline vector<vector<string>> readMatStrCsv(string csv_file_path) {
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
        // leetcode格式
    inline vector<vector<string>> readMatStrLc(string file_path){
        ifstream file(file_path, ios::in);
        assert(file.is_open());
        
        string lineStr;
        vector<vector<string>> mat;
        while (getline(file, lineStr, ',')) {
            if(lineStr[0]=='['){
                vector<string> line;
                mat.push_back(line);
            }
            int pos_begin=0, pos_end;
            while(lineStr[pos_begin]=='['||lineStr[pos_begin]=='"') pos_begin++;
            pos_end = pos_begin;
            while(lineStr[pos_end]!='"') pos_end++;
            mat[mat.size()-1].push_back(lineStr.substr(pos_begin, pos_end-pos_begin));
        }
        
        return mat;
    }
    
    // 从文件读取vector<vector<T>>（T为int||float||double）
        // csv格式
    template <typename T>
    inline vector<vector<T>> readMatNumCsv(string csv_file_path) {
        assert(sizeof(int)==sizeof(T)||sizeof(float)==sizeof(T)||sizeof(double)==sizeof(T));
        
        vector<vector<T>> numMat;
        vector<vector<string>> strMat = readMatStrCsv(csv_file_path);
        
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
        // leetcode格式
    template <typename T>
    inline vector<vector<T>> readMatNumLc(string file_path) {
        ifstream file(file_path, ios::in);
        assert(file.is_open());
        
        string lineStr;
        vector<vector<T>> mat;
        while (getline(file, lineStr, ',')) {
            if(lineStr[0]=='['){
                vector<T> line;
                mat.push_back(line);
            }
            int pos_begin=0, pos_end;
            while(lineStr[pos_begin]=='[') pos_begin++;
            pos_end = pos_begin;
            while(pos_end<lineStr.size() && lineStr[pos_end]!='"') pos_end++;
            stringstream ss(lineStr.substr(pos_begin, pos_end-pos_begin));
            T num;
            ss >> num;
            mat[mat.size()-1].push_back(num);
        }
        
        return mat;
    }
}


#endif /* LeetcodeIO_hpp */
