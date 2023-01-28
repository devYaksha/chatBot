#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "classes.cpp"
#include <vector>


using namespace std;
string x;
bool meuBoleano = true;
string botName = "Jarvis: ";

JarvisBrain myObj;



string getResponse(string input, vector<pair<string, string>> dataset) {
    for (auto p : dataset) {
        if (input == p.first) {
            return p.second;
        }
        
    } 

    myObj.aprendizado(x);
    return "nulo";
}


int main(int argc, char const *argv[])
{
    
    while (meuBoleano == true){
    
    x = myObj.openPython();

    ifstream file("botLearning.txt");
    vector<pair<string,string>> dataset;
    string line;

    if (x=="exit")
    {
        cout << botName << "Fechando o bot..."<<endl;
        break;
    }
    

    if (file.is_open()) {
        while (getline(file, line)) {
            // Corta a linha pelo ":";
            int pos = line.find(":");
            string input = line.substr(0, pos);
            string output = line.substr(pos + 1);
            // Adiciona o par entrada-saída ao conjunto de dados
            dataset.push_back({input, output});
            }
            
        file.close();}
    string phrase = getResponse(x,dataset);
    if(line.find(":" && x==line)&& phrase != "nulo"){

            cout << botName << phrase << endl;    

    }


    string command = "espeak -v +f3 \""+phrase+"\"";
    const char* charCommand=command.c_str();
    system(charCommand);
    cout << endl;


    }

};
