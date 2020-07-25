/*
*
* Created by miros on 17/04/2020.
*
*/
//1change

#pragma once
#include <map>
#include <vector>
#include <string>
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

namespace family
{
    class node{
        node *_father;
        node *_mother;
        string _name;
        bool _gender;  //false mother- true father
    public:
        node(string name, bool gender){
            this->_name = name;
            this->_gender = gender;
            _father = NULL;
            _mother = NULL;
        }
        ~node(){
            setFatherToNull();//need to write this function
            setMotherToNull();
        }
        void setFatherToNull(){
            this->_father = NULL;
        }
        void setMotherToNull(){
            this->_mother = NULL;
        }
        string getName(){
            return this->_name;
        }
        bool getGender(){
            return this->_gender;
        }
        node *getFather(){
            return this->_father;
        }
        node *getMother(){
            return this->_mother;
        }
        void setNode(string parent, bool gender){
            if(gender){//father
                node *ans = new node(parent, gender);
                this->_father = ans;
            }else{//mother
                node *ans = new node(parent, gender);
                this->_mother = ans;
            }
        }
    };
    class Tree{
        node *_root;
    public:
        Tree(string name){
            this->_root = new node(name, true);
        }
        ~Tree(){
            delete this->_root;
        }
        //implementation via cpp file
        Tree &addFather(string name, string father);
        Tree &addMother(string name, string mother);
        string find(string relation);
        string relation(string name);
        string nodeNameAtHeight(node *node, int height, bool gender);
        void display();
        void remove(string  name);
        void deleteSubTree(node *root);
        void add(node *root, string name, string parent, bool gender);
        void printTree(node *root);
        void findSubTree(node *root, string name, node **nodeRunner);
        int getLevel(node *node, string name);
        int getLevelUtil(node *node, string name, int level);
        node *findNode(node *root, string name);
        node *getNodeByHeight(node *root, int height, bool gender);
    };
} // namespace family::