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
        newKnowledge = "";
        cout << botName << "Aprendido com sucesso" << endl;

    }

    }

    else{
        cout << botName << "Ok, nao irei aprender.\n";
    }

        

}


    };