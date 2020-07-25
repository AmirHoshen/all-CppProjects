//
// Created by shira on 14/04/2020.
//
# pragma once
#include <string>
#include <iostream>
using namespace std;

namespace family {
    class Tree;
}

class family::Tree{
private:
    string root;
    int deptht;
    Tree *father,*mother;

public:
    Tree(string root){ //Constructor
        this->root=root;
        this->deptht=0;
        this->father= nullptr;
        this->mother= nullptr;
    }
    ~Tree(){ //Destructor
        if (this->father!= nullptr)
            delete this->father;
        if (this->mother!= nullptr)
            delete this->mother;
    }

    Tree& addFather(string root,string father);
    Tree& addMother(string root,string mother);
    string relation(string name);
    string find(string relation);
    void display();
    void remove(string remove);

private:
    bool addFather(Tree *tree, string root, string father);
    bool addMother(Tree *tree, string root, string mother);
    void display(Tree *tree,string* myFamily,int depth);
    bool remove(Tree *root,string toRemove);
    string relation(Tree *tree,string name,int depth,int gender);
    string whatTheRelation(int depth,int gender);
    string find(Tree *tree,string relation,int depth,int gender);
};
