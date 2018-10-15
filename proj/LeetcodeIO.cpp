//
//  LeetcodeIO.cpp
//  leetcode
//
//  Created by 郭子乐 on 2018/7/26.
//  Copyright © 2018年 郭子乐. All rights reserved.
//

#include "LeetcodeIO.hpp"

vector<string> leetcodeio::readVecStrCsv(string csv_file_path) {
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
vector<string> leetcodeio::readVecStrLc(string file_path){
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

vector<vector<string>> leetcodeio::readMatStrCsv(string csv_file_path) {
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

vector<vector<string>> leetcodeio::readMatStrLc(string file_path){
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
