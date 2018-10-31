#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

/*	Only c++11 
 * Compile:
 * 
 * g++ -Wall -std=c++0x -c "%f"
 * 
 * Build:
 * 
 * g++ -Wall -std=c++0x -o "%e" "%f"
 * 
 */

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
        string correta,vazio,aux,segun,terce,quar,senha,nome,subnome;
        string login;
        int prime,y=0;
        arquivobxado.seekg(405);
        arq<<"#!/bin/bash"<<endl;
        while(!arquivobxado.eof())
        {

            getline(arquivobxado,imp);
            correta=imp.substr(4,55);
            aux=imp.substr(4,4);
            //cout<<correta<<endl;
            if(aux!="")
            {
				
                try
                {
                    prime= stoi(aux);
                    segun=(imp.substr(9,1));
					terce=(imp.substr(11,3));
					quar=(imp.substr(15,4));
                }
                catch(invalid_argument)
                {
                }
                if(prime>1000&&prime<3000)
                {
					aux= to_string(prime);
					login="a"+aux+segun+terce+quar;
				    nome=imp.substr(26,29);
                   
                    for(unsigned int x=0;x<nome.size();x++)
                    {
						if(nome.substr(26,x)==" ")
						{
							for(unsigned int w=0;w<nome.size();w++)
							{
								if(nome.substr(x,y)==" ")
								{
									subnome=quar+nome.substr(x,y);
									cout<<"useradd -p `openssl passwd -crypt "<<subnome<<"` -c '"<<nome<<"'"<<login<<endl;
									arq<<"useradd -p `openssl passwd -crypt "<<subnome<<"` -c '"<<nome<<"'"<<login<<endl;
								}
							}
						}
					}
					
                                        
                    
                }

            }


        }
    }

    arquivobxado.close();
    arq.close();

}

