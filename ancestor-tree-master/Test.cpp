//
// Created by shira on 16/04/2020.
//
#include "doctest.h"
#include <string>
#include "FamilyTree.hpp"
using namespace family;

/////////////////Test extreme cases/////////////////

TEST_CASE("Test:relation() - not found relation") {
    Tree t;
    CHECK_THROWS(t.relation("shira"));
    CHECK_THROWS(t.relation("moria"));
    CHECK_THROWS(t.relation("zosha"));
    CHECK_THROWS(t.relation("Haim"));
    CHECK_THROWS(t.relation("Gefen"));
    CHECK_THROWS(t.relation("Noa"));
    CHECK_THROWS(t.relation("Shilat"));
    CHECK_THROWS(t.relation("Tahel"));
    CHECK_THROWS(t.relation("Avigail"));
    CHECK_THROWS(t.relation("Shir"));
    CHECK_THROWS(t.relation("Shahar"));
    t.display();
}

TEST_CASE("Test:find() - not found name") {
    Tree t;
    CHECK_THROWS(t.find(""));
    CHECK_THROWS(t.find("?"));
    CHECK_THROWS(t.find("_"));
    CHECK_THROWS(t.find("shira"));
    CHECK_THROWS(t.find("great"));
    CHECK_THROWS(t.find("graet-"));
    CHECK_THROWS(t.find("mothe r"));
    CHECK_THROWS(t.find("graed-grandmother"));
    CHECK_THROWS(t.find("greatgreatgrandmother"));
    CHECK_THROWS(t.find("great-great-great-great-grandmother"));
    CHECK_THROWS(t.find("great-great-great-great-great-great-grandmother"));
    t.display();
}

TEST_CASE("Test:addFather() - exist Father") {
    Tree t;
    CHECK_THROWS(t.addFather("Yosef","Menachem"));
    CHECK_THROWS(t.addFather("Yaakov","Menachem"));
    CHECK_THROWS(t.addFather("Isaac","Menachem"));
    CHECK_THROWS(t.addFather("Avraham","Menachem"));
    CHECK_THROWS(t.addFather("Terah","Menachem"));
    CHECK_THROWS(t.addFather("shira","Menachem"));
    CHECK_THROWS(t.addFather("Tohar","Menachem"));
    CHECK_THROWS(t.addFather("Tali","Menachem"));
    CHECK_THROWS(t.addFather("Timon","Menachem"));
    CHECK_THROWS(t.addFather("Pumba","Menachem"));
    CHECK_THROWS(t.addFather("Simba","Menachem"));
    t.display();
}

TEST_CASE("Test:addMother() - exist Mother") {
    Tree t;
    CHECK_THROWS(t.addMother("Yosef","Shoshana"));
    CHECK_THROWS(t.addMother("Rachel","Shoshana"));
    CHECK_THROWS(t.addMother("Rivka","Shoshana"));
    CHECK_THROWS(t.addMother("Yaakov","Shoshana"));
    CHECK_THROWS(t.addMother("Isaac","Shoshana"));
    CHECK_THROWS(t.addMother("Shir","Shoshana"));
    CHECK_THROWS(t.addMother("Maor","Shoshana"));
    CHECK_THROWS(t.addMother("Yvgeni","Shoshana"));
    CHECK_THROWS(t.addMother("Netanel","Shoshana"));
    CHECK_THROWS(t.addMother("Zion","Shoshana"));
    t.display();
}

TEST_CASE("Test:remove() - Attempt to delete the root") {
    Tree t;
    CHECK_THROWS(t.remove("Yosef"));
}

/////////////////Test addFather function/////////////////
TEST_CASE("Test: addFather()") {
    Tree t;
    CHECK_NOTHROW(t.addFather("Nachor","Sarog"));
    CHECK_NOTHROW(t.addFather("Sarog","Raad"));
    CHECK_NOTHROW(t.addFather("Raad","Peleg"));
    CHECK_NOTHROW(t.addFather("Peleg","Ever"));
    CHECK_NOTHROW(t.addFather("Ever","Shalach"));
    CHECK_NOTHROW(t.addFather("Shalach","Arpashdz"));
    CHECK_NOTHROW(t.addFather("Arpashdz","Shem"));
    CHECK_NOTHROW(t.addFather("Shem","Noach"));
    CHECK_NOTHROW(t.addFather("Noach","Lemech"));
    CHECK_NOTHROW(t.addFather("Lemech","Metoshlach"));
    CHECK_NOTHROW(t.addFather("Metoshlach","Chanoch"));
    CHECK_NOTHROW(t.addFather("Chanoch","yerad"));
}

/////////////////Test addMother function/////////////////
TEST_CASE("Test: addMother()") {
    Tree t;
    CHECK_NOTHROW(t.addMother("Sara","Michal"));
    CHECK_NOTHROW(t.addMother("Michal","Maya"));
    CHECK_NOTHROW(t.addMother("Maya","Mira"));
    CHECK_NOTHROW(t.addMother("Mira","Shlomit"));
    CHECK_NOTHROW(t.addMother("Shlomit","Mriam"));
    CHECK_NOTHROW(t.addMother("Mriam","Shaked"));
    CHECK_NOTHROW(t.addMother("Shaked","Roni"));
    CHECK_NOTHROW(t.addMother("Shalach","Nina"));
    CHECK_NOTHROW(t.addMother("Arpashdz","Meri"));
    CHECK_NOTHROW(t.addMother("Shem","Nokia"));
    CHECK_NOTHROW(t.addMother("Noach","Nira"));
    CHECK_NOTHROW(t.addMother("Lemech","Arbel"));
    CHECK_NOTHROW(t.addMother("Metoshlach","Ofri"));
    CHECK_NOTHROW(t.addMother("Chanoch","Renana"));
}

/////////////////Test relation function/////////////////
TEST_CASE("Test: relation()") {
    Tree t;
    CHECK_NOTHROW(t.relation("Terah"));
    CHECK_NOTHROW(t.relation("shira"));
    CHECK_NOTHROW(t.relation("Tohar"));
    CHECK_NOTHROW(t.relation("Tali"));
    CHECK_NOTHROW(t.relation("Timon"));
    CHECK_NOTHROW(t.relation("Pumba"));
    CHECK_NOTHROW(t.relation("Simba"));
    CHECK_NOTHROW(t.relation("Mriam"));
    CHECK_NOTHROW(t.relation("Shaked"));
    CHECK_NOTHROW(t.relation("Shalach"));
    CHECK_NOTHROW(t.relation("Arpashdz"));
    CHECK_NOTHROW(t.relation("Shem"));
    CHECK_NOTHROW(t.relation("Noach"));
    CHECK_NOTHROW(t.relation("Lemech"));
    CHECK_NOTHROW(t.relation("Metoshlach"));
}

/////////////////Test find function/////////////////
TEST_CASE("Test: find()") {
    Tree t;
    CHECK_NOTHROW(t.find("father")); //yakov
    CHECK_NOTHROW(t.find("mother")); //rachel
    CHECK_NOTHROW(t.find("grandfather")); //isaac
    CHECK_NOTHROW(t.find("grandmother")); //rivka
    CHECK_NOTHROW(t.find("great-grandfather")); //avraham
    CHECK_NOTHROW(t.find("great-grandmother")); //sara
    CHECK_NOTHROW(t.find("great-great-grandfather")); //terah
    CHECK_NOTHROW(t.find("great-great-great-grandfather")); //nachor
}

/////////////////Test remove function/////////////////
TEST_CASE("Test: remove()") {
    Tree t;
    CHECK_NOTHROW(t.remove("Nachor"));
    CHECK_NOTHROW(t.remove("Terah"));
    CHECK_NOTHROW(t.remove("Sara"));
    CHECK_NOTHROW(t.remove("Rivka"));
    CHECK_NOTHROW(t.remove("Isaac"));
    CHECK_NOTHROW(t.remove("Rachel"));
    CHECK_NOTHROW(t.remove("Yaakov"));
}