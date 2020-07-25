#include <iostream>
#include <string>
#include "AncestorTree.hpp"

using namespace family;

/********************************************************************************
 Add a father for the given name Node if exists if not throw an exception.
 @param name The Node we look for in the tree.
 @param father The name  of the father (Node) we want to add.
 @return The father into the tree.
 *********************************************************************************/
Tree &Tree::addFather(string name, string father) {
    node *tmp = findNode(_root, name);
    if (tmp == NULL) throw runtime_error("This name is not a member of this tree");
    if (tmp->getFather() != NULL)throw "ERR:  Father " + tmp->getName() + " ,already exist in this tree\n";
    add(this->_root, name, father, true);
    return *this;
}

/********************************************************************************
  Add a mother for the given name Node if exists if not throw an exception.
  @param name the node we look for in the tree.
  @param mother The name  of the mother (Node) we want to add.
  @return the mother into the tree.
 ********************************************************************************/
Tree &Tree::addMother(string name, string mother) {
    node *tmp = findNode(_root, name);
    if (tmp == NULL) throw runtime_error("This name is not a member of this tree");
    if (tmp->getMother() != NULL) throw "ERR: Mother " + tmp->getName() + " ,already exist in this tree\n";
    add(this->_root, name, mother, false);
    return *this;
}

/********************************************************************************
  Display the Tree using a help method printTree.
 ********************************************************************************/
void Tree::display() {
    printTree(_root);
    cout << endl;
}

/********************************************************************************
  Receiving the ancestor tree root and printing the tree.
  if Tree is null ?  -> the tree is empty
  @param root of the tree.
 *********************************************************************************/
void Tree::printTree(node *root) {
    if (root != NULL) {
        if (root->getFather() != NULL) {
            printTree(root->getFather());
        }
        cout << root->getName() << " ";
        if (root->getMother() != NULL) {
            printTree(root->getMother());
        }
    } else {
        throw runtime_error("The tree is empty!\n");
    }
}

/********************************************************************************
 Given a name this method will return the relation of this Node to the root.
  @param name the Node name relation to the root we are looking for.
  @return (father/mother, grandfather/grandmother, great-grandfather/great-grandmother, ..etc.)
 ********************************************************************************/
string Tree::relation(string name) {
    node *tmp = findNode(this->_root, name);
    int level = getLevel(this->_root, name);
    if (tmp == NULL || level == 0)return "unrelated";
    else if (level == 1) return "me";
    bool gender = tmp->getGender();
    if (level == 2) {
        if (gender)return "father";
        return "mother";
    } else if (level == 3) {
        if (gender)return "grandfather";
        return "grandmother";
    } else {
        string great = "great-";
        for (int i = 0; i < level - 4; ++i) {
            great += "great-";
        }
        string grandParent;
        if (gender)grandParent = "grandfather";
        else grandParent = "grandmother";
        return great + grandParent;
    }
}

/********************************************************************************
  Source code from: https://www.youtube.com/watch?v=IJCg_jxOM_Q
  LVL of the root start from 1.
  using this method finds out what depth of the Node we look for.
  @param node start looking from this given Node.
  @param name the Node we are looking for in the Tree.
  @return the depth of the node who's name we looked for in the tree.
 ********************************************************************************/
int Tree::getLevel(node *root, string name) {
    node *tmp = findNode(root, name);
    if (tmp == NULL)return 0;
    return getLevelUtil(root, name, 1);
}

/********************************************************************************
   Gets the level of the name we look for in the Tree.
  @param node the root Node.
  @param name the Node depth we look for.
  @param level the level of that name Node we looked for.
  @return the current level.
 ********************************************************************************/
int Tree::getLevelUtil(node *node, string name, int level) {
    if (node == NULL)return 0;
    if (node->getName() == name)return level;
    int downLevel = getLevelUtil(node->getFather(), name, level + 1);
    if (downLevel != 0)return downLevel;
    downLevel = getLevelUtil(node->getMother(), name, level + 1);
    return downLevel;
}

/********************************************************************************
  Given a name to look for in the tree and a root Node to start from,
  This method returns the name (Node) we look for.
  @param root The Node we start looking from.
  @param name To look for in the tree.
  @return The name (Node) if exists.
 ********************************************************************************/
node *Tree::findNode(node *root, string name) {
    if (this->_root == NULL)throw runtime_error("The tree is empty!\n");
    if (root == NULL)return NULL;
    if (root->getName() == name)return root;
    node *res1 = findNode(root->getFather(), name);
    if (res1 != NULL)return res1;
    node *res2 = findNode(root->getMother(), name);
    return res2;
}

/********************************************************************************
  Given a relation string method should return the name of the Node who's in this relation.
  @param relation - father/mother , grandfather/grandmother , great-grandfather/great-grandmother, ..etc.
  @return a String the name of this Node who's associated with this given relation.
 ********************************************************************************/
string Tree::find(string relation) {
    node *fatherSide;
    node *motherSide;
    string ans;
    if (relation == "me")
        ans = _root->getName();
    else if (relation == "father") {
        if (_root->getFather() != NULL)
            ans = _root->getFather()->getName();
        else throw "No relation in the tree\n";
    } else if (relation == "mother") {
        if (_root->getMother() != NULL)
            ans = _root->getFather()->getName();
        else throw "No relation in the tree\n";
    } else if (relation == "grandfather") {
        if (_root->getFather() != NULL) {
            fatherSide = _root->getFather();
            fatherSide = fatherSide->getFather();
        }
        if (_root->getMother() != NULL) {
            motherSide = _root->getMother();
            motherSide = motherSide->getFather();
        }
        if (fatherSide != NULL) ans = fatherSide->getName();
        else if (motherSide != NULL) ans = motherSide->getName();
        else throw runtime_error("No relation\n");
    } else if (relation == "grandMother") {
        if (_root->getFather() != NULL) {
            fatherSide = _root->getFather();
            fatherSide = fatherSide->getMother();
        }
        if (_root->getMother() != NULL) {
            motherSide = _root->getMother();
            motherSide = motherSide->getMother();
        }
        if (fatherSide != NULL) ans = fatherSide->getName();
        else if (motherSide != NULL) ans = motherSide->getName();
        else throw runtime_error("No relation\n");
    } else {
        string delimiter = "-";
        size_t pos = 0;
        string token;
        int greatCounter = 0;
        while ((pos = relation.find(delimiter)) != std::string::npos) {
            relation.erase(0, pos + delimiter.length());
            greatCounter++;
        }
        bool gender;
        if (relation == "grandfather") gender = true;
        else if (relation == "grandmother") gender = false;
        else throw runtime_error("No relation");

        node *tmp = getNodeByHeight(_root, greatCounter + 2, gender);
        if (tmp == NULL) throw runtime_error("No relation\n");
        else
            ans = tmp->getName();
    }
    return ans;
}

node *Tree::getNodeByHeight(node *root, int count, bool gender) {
    if (count == 0)return root;
    else if (count == 1 && root != NULL) {
        if (gender)return root->getFather();
        return root->getMother();
    }
    node *fatherSide = NULL;
    node *motherSide = NULL;
    if (root != NULL) {
        fatherSide = getNodeByHeight(root->getFather(), count - 1, gender);
        motherSide = getNodeByHeight(root->getMother(), count - 1, gender);
    }
    if (fatherSide != NULL)return fatherSide;
    return motherSide;
}

string Tree::nodeNameAtHeight(node *node, int heightAns, bool gender) {
    if (node == NULL)return " ";
    if ((getLevel(node, node->getName()) == heightAns) && (node->getGender() == gender))
        return node->getName();
    if (gender) {
        if ((getLevel(node, node->getName()) == heightAns) && (node->getGender() == gender))
            return node->getName();
        else if (node->getFather() != NULL) {
            nodeNameAtHeight(node->getFather(), heightAns, gender);
            nodeNameAtHeight(node->getMother(), heightAns, gender);
        }
    } else {
        if ((getLevel(node, node->getName()) == heightAns) && (node->getGender() == gender))
            return node->getName();
        else if (node->getMother() != NULL) {
            nodeNameAtHeight(node->getMother(), heightAns, gender);
            nodeNameAtHeight(node->getFather(), heightAns, gender);
        }
    }
}

/********************************************************************************
  Remove a Tree (if root is given, except for the root) or a subtree from the tree.
  @param name of the person we want to remove from the Tree
   Note - if we have a name ( under the root) ,we cant delete it, we will call a help function:
   "findSubTree" that will find a path to a Node we can delete.
 ********************************************************************************/
void Tree::remove(string name) {
    if (this->_root->getName() == name)throw runtime_error("Cannot delete the root\n");
    node *removeNode = NULL;
    node *nodeRunner = NULL;
    findSubTree(this->_root, name, &removeNode);
    if (removeNode == NULL)throw runtime_error("The name you are looking for is not in the tree!\n");
    if (removeNode->getMother() != NULL && removeNode->getMother()->getName() == name) {
        nodeRunner = removeNode->getMother();
        deleteSubTree(nodeRunner);
        removeNode->setMotherToNull();
    }
    if (removeNode->getFather() != NULL && removeNode->getFather()->getName() == name) {
        nodeRunner = removeNode->getFather();
        deleteSubTree(nodeRunner);
        removeNode->setFatherToNull();
    }
}

/********************************************************************************
* This function will help us to find a path in the Tree that we want to located.
* If the target is present in either Mother or Father subtree of the Node,
* will call the Node recursive way to find the either Mother \ Father name and path.
********************************************************************************/
void Tree::findSubTree(node *root, string name, node **nodeRunner) {
    if (root == NULL)return;
    if ((root->getMother() != NULL && root->getMother()->getName() == name) ||
        (root->getFather() != NULL && root->getFather()->getName() == name)) {
        *(nodeRunner) = root;
        return;
    }
    findSubTree(root->getMother(), name, nodeRunner);
    findSubTree(root->getFather(), name, nodeRunner);
}

/********************************************************************************
 * Help method for removin, method deleting a subtree from ancestor Tree.
 * @param root the ancestor Tree root.
 *******************************************************************************/
void Tree::deleteSubTree(node *root) {
    if (root == NULL) {
        deleteSubTree(root->getFather());
        deleteSubTree(root->getMother());
    }
    if (root->getName() != _root->getName()) {
        root = NULL;
        delete root;
    }
}

/********************************************************************************
* Add a Node to the Tree for the given name node by gender.
* @param root of the Tree to add the father or mother.
* @param name Node to add the parent.
* @param parent is the parent name.
* @param gender is the parent gender.
******************************************************************************/
void Tree::add(node *root, string name, string parent, bool gender) {
    if (root != NULL && gender == true && root->getName() == name && root->getFather() == NULL) {
        root->setNode(parent, gender);
        return;
    }
    if (root != NULL && gender == false && root->getName() == name && root->getMother() == NULL) {
        root->setNode(parent, gender);
        return;
    }
    if (root != NULL) {
        add(root->getMother(), name, parent, gender);
        add(root->getFather(), name, parent, gender);
    }
    return;
}