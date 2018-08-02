//
//  LeetcodeIO.hpp
//  leetcode
//
//  Created by 郭子乐 on 2018/7/26.
//  Copyright © 2018年 郭子乐. All rights reserved.
//

#ifndef LeetcodeIO_hpp
#define LeetcodeIO_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace test{
    void test();
}

/*
 * Name: LeetcodeIO library
 * Function: Print vector/mat to cout, read vector/mat from csv file.
 */
namespace leetcodeio {
    
    /*--------------------------print-----------------------*/
    // 打印vector<T>
    template <typename T>
    inline void printVec(vector<T> vec, string format = ",") {
        int i=0;
        for(; i<vec.size()-1; i++){
            cout << vec[i] << format;
        }
        if(i<vec.size()) cout << vec[i] << endl;
    }
    
    // 打印vector<vector<T>>
    template <typename T>
    inline void printMat(vector<vector<T>> mat, string format_ele = ",", string format_line = "\n") {
        for(auto array:mat){
            for (int i=0; i<array.size()-1; i++) {
                cout << array[i] << format_ele;
            }
            if(array.size()!=0) cout << array.back();
            cout << format_line;
        }
    }
    
    /*--------------------------read-----------------------*/
    // -----vector-----
    // 从文件读取vector<string>
        // csv格式
    vector<string> readVecStrCsv(string csv_file_path);
        // leetcode格式
    vector<string> readVecStrLc(string file_path);
    
    // 从文件读取vector<T>（T为int||float||double）
        // csv格式
    template <typename T>
    inline vector<T> readVecNumCsv(string csv_file_path) {
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
    template <typename T>
    inline vector<T> readVecNumLc(string file_path){
        ifstream file(file_path, ios::in);
        assert(file.is_open());
        
        string lineStr;
        vector<T> vec;
        while (getline(file, lineStr, ',')) {
            int pos_begin=0, pos_end;
            if(lineStr[pos_begin]=='[') pos_begin++;
            pos_end = pos_begin;
            while(pos_end<lineStr.size() && lineStr[pos_end]!='"') pos_end++;
            
            stringstream ss(lineStr.substr(pos_begin, pos_end-pos_begin));
            T num;
            ss >> num;
            vec.push_back(num);
        }
        
        return vec;
    }
    
    // -----mat-----
    // 从文件读取vector<vector<string>>
        // csv格式
    vector<vector<string>> readMatStrCsv(string csv_file_path);
        // leetcode格式
    vector<vector<string>> readMatStrLc(string file_path);
    
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
