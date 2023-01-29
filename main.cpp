#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "classes.cpp" // script que tem as funções utilizadas na main
#include <vector>


using namespace std;
string UserInput;
string botName = "Jarvis: ";
JarvisBrain myObj;

string getResponse(string input, vector<pair<string, string>> dataset) {
    for (auto p : dataset) {
        if (input == p.first) {
            return p.second;
        }
            } 

    myObj.aprendizado(UserInput);
    return "nulo"; //retorno da string no caso de que nao haja conhecimento
}


int main(int argc, char const *argv[])
{
    
    while (true){
    
    UserInput = myObj.openPython(); //funcao para abrir o arquivo python

    ifstream file("botLearning.txt");
    vector<pair<string,string>> dataset;
    string line;

    if (UserInput=="exit")
    {
        string closingOutput= "closing the bot.";
        cout << botName << closingOutput << endl;
        myObj.SpeechByEspeak(closingOutput);
        break;
    }
    

    if (file.is_open()) {
        while (getline(file, line)) {
            int pos = line.find(":"); // Corta a linha pelo ":";
            string input = line.substr(0, pos);
            string output = line.substr(pos + 1);
            dataset.push_back({input, output}); // Adiciona o par entrada-saída ao conjunto de dados
            }
            
        file.close();}

    string phrase = getResponse(UserInput,dataset);
    if(phrase != "nulo"){
            cout << "You: " << UserInput << endl;
            cout << botName << phrase << endl;
            myObj.SpeechByEspeak(phrase);
       
    }
} //fecha while

};
