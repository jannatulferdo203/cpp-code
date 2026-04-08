
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


bool isKeyword(string word) {
string keywords[] = {"int","float","double","char","void","if","else",
"while","for","return","main","cout","cin"};
for(int i=0;i<12;i++){
if(word == keywords[i])
return true;
}
return false;
}


bool isOperator(string op) {
string operators[] = {"+","-","*","/","=","==","<",">","<=",">=",
"++","--","!=","<<",">>"};
for(int i=0;i<15;i++){
if(op == operators[i])
return true;
}
return false;
}


bool isSymbol(char ch) {
string symbols = "(){}[];,#";
for(int i=0;i<symbols.length();i++){
if(ch == symbols[i])
return true;
}
return false;
}

int main() {

cout << "Q1: File Read\n" << endl;

ifstream file("myfile.txt");

if (!file) {
cout << "File not found!" << endl;
return 1;
}

string line;


while (getline(file, line)) {
cout << line << endl;
}

file.close();

cout << "\nQ2: Identify valid tokens\n" << endl;

ifstream file2("myfile.txt");

int lineNo = 1;

while (getline(file2, line)) {

cout << "\nLine " << lineNo << ": " << line << endl;

for (int i = 0; i < line.length(); i++) {


if (isspace(line[i]))
continue;

if (isalpha(line[i]) || line[i]=='_') {
string word="";
while (isalnum(line[i]) || line[i]=='_') {
word += line[i];
i++;
}
i--;

if (isKeyword(word))
cout << word << " -> Keyword" << endl;
else
cout << word << " -> Identifier" << endl;
}


else if (isdigit(line[i])) {
string number="";
while (isdigit(line[i])) {
number += line[i];
i++;
}
i--;

cout << number << " -> Number" << endl;
}


else if (line[i] == '"') {
string str="\"";
i++;
while (line[i] != '"' && i < line.length()) {
str += line[i];
i++;
}
str += "\"";
cout << str << " -> String" << endl;
}


else {
string op="";
op += line[i];


if (i+1 < line.length()) {
string twoChar = op + line[i+1];
if (isOperator(twoChar)) {
cout << twoChar << " -> Operator" << endl;
i++;
continue;
}
}

if (isOperator(op))
cout << op << " -> Operator" << endl;
else if (isSymbol(line[i]))
cout << line[i] << " -> Punctuation" << endl;
}
}

lineNo++;
}

file2.close();
return 0;
}




