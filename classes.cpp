#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <stdint.h>
#include <sstream>
#include <typeinfo>
#include <algorithm>
#include <fstream>


using namespace std;

class JarvisBrain {        // A classe
  public:
  fstream newfile;
  string botName = "Jarvis: ";              // O acesso
    void mathIdade() {  //A função
        time_t mytime;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
        int myAgeDia = tm.tm_mday, myAgeMes = tm.tm_mon+1, myAgeAno = tm.tm_year+1900; //Por algum motivo o tm_year só pega o valor int fazendo 2022-1900
        cout << myAgeDia << "/"<< myAgeMes << "/" << myAgeAno << endl; //aquele print básico pra não errar no cálculo de data.

        int diaCriacao = 29;
        int mesCriacao = 04;
        int anoCriacao = 2004; //Faça a alteração nessas três variáveis, caso queira fazer teste de valores diferentes.

        int anoDiferenca = myAgeAno-anoCriacao;
        int mesDiferenca = anoDiferenca*12; //Foi considerado que TODOS os meses tem 30 dias.
        int diasDiferenca = (anoDiferenca*365);
        string botName = "Jarvis: ";

        cout << botName << "Fui criado " << diaCriacao << "/" << mesCriacao << "/" << anoCriacao << endl;
        cout << botName << "Tenho " << diasDiferenca << " dia(s), ou " << mesDiferenca << " mese(s) ou " << anoDiferenca << " ano(s)." << endl;
}

  void aprendizado(string x){
    string y;
    cout << botName << "Desculpe, ainda nao sei responder a isso. Poderia me ensinar?\n";
    SpeechByEspeak("Desculpe, ainda nao sei responder a isso. Poderia me ensinar?"); //Preparando o bot para aprender
    y = openPython();
    if (y == "yes"){
        string newKnowledge;
        cout << botName << "Como voce responderia a isso?\n";
        SpeechByEspeak("Como voce responderia a isso?");


      newKnowledge = openPython();

        newfile.open("botLearning.txt",ios::app);
        if (newfile.is_open())
        {
        newfile<<x<<":";
        newfile<<newKnowledge<<endl;
        newfile.close();
        newKnowledge = ""; // evitar estouro de string
        cout << botName << "Obrigado, aprendi a como responder o (" << x << ")"<< endl;
        string LearnedResponse = "Obrigado, aprendi a como responder o"+x;
        SpeechByEspeak(LearnedResponse);

    }

    }

    else if(y=="no" || "not" || "nope")
    {
      cout << botName << "Ok, nao irei aprender.\n";
      SpeechByEspeak("Ok, nao irei aprender.\n");
    }

    else{
        cout << botName << "Desculpe, nao te compreendi.";
        SpeechByEspeak("Desculpe, nao te compreendi");
    }

        

}

string openPython(){
    string command2 = "python3 speech.py > /dev/null 2>&1";
    const char* charCommand2=command2.c_str();
    system(charCommand2);
    cout << endl;

    ifstream file2("temporary.txt");
    string line2;
    if (file2.is_open()) {
       getline(file2, line2);
    }
    return line2;
}

void SpeechByEspeak(string texto){
    string command = "espeak -v +f3 \""+texto+"\"";
    const char* charCommand=command.c_str();
    system(charCommand);
    cout << endl; 

}

    };