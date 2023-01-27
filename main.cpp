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
fstream newfile;
JarvisBrain myObj;


void aprendizado(){
    string y;
    cout << botName << "Desculpe, ainda nao sei responder a isso. Poderia me ensinar?\n"; //Preparando o bot para aprender
    cout << "Digite para o Jarvis: -";
    getline(cin, y);
    if (y == "sim"){
        string newKnowledge;
        cout << botName << "Como voce responderia a isso?\n";
        cout << "Digite para o Jarvis: -";
        getline(cin, newKnowledge);


        newfile.open("botLearning.txt",ios::app);
        if (newfile.is_open())
        {
        newfile<<x<<":";
        newfile<<newKnowledge<<endl;
        newfile.close();
        cout << botName << "Aprendido com sucesso" << endl;

    }

    }

    else{
        cout << botName << "Ok, nao irei aprender.\n";
    }

        

}

string getResponse(string input, vector<pair<string, string>> dataset) {
    for (auto p : dataset) {
        if (input == p.first) {
            return p.second;
        }
    } 
    aprendizado();
}


int main(int argc, char const *argv[])
{
    
    while (meuBoleano == true){
    
    cout << "Digite para o Jarvis: ";
    getline(cin, x);

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

    if(line.find(":" && x==line)){

            cout << botName << getResponse(x, dataset) << endl;    

    }

    string phrase = getResponse(x,dataset);
    string command = "espeak -v +f3 \""+phrase+"\"";
    const char* charCommand=command.c_str();
    system(charCommand);
    cout << endl;


    }

};
