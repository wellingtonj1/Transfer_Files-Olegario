#include <iostream>
#include <fstream>


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
        arquivobxado.seekg(405);
        while(!arquivobxado.eof())
        {

            getline(arquivobxado,imp);
            cout<<imp<<endl;
            arq<<imp<<endl;

        }
    }

    arquivobxado.close();
    arq.close();

}
