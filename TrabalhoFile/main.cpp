#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream arq("logins.sh");
    ifstream arquivobxado;
    string imp;


    arquivobxado.open("CMP-2.txt");

    if(!arquivobxado.is_open())
    { //testa se a abertura do arquivo falhou
        cout<<"Arquivo nao aberto"<<endl;
    }
    else
    {
        string correta,vazio,aux;
        int numcomp;
        arquivobxado.seekg(405);
        while(!arquivobxado.eof())
        {

            getline(arquivobxado,imp);
            correta=imp.substr(4,55);
            aux=imp.substr(4,4);
            cout<<correta<<endl;
            //numcomp=stoi(aux);
            /*if(numcomp)
			{
				cout<<numcomp<<endl;
			}
			else
			{
				getline(arquivobxado,vazio);
			}*/
			
            arq<<aux<<endl;

        }
    }

    arquivobxado.close();
    arq.close();

}

