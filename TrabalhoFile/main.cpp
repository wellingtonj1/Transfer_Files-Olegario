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
        int prime;
        arquivobxado.seekg(405);
        arq<<"#!/bin/bash"<<endl;
        while(!arquivobxado.eof())
        {
			try
			{
			    getline(arquivobxado,imp);
			    aux=imp.substr(4,4);
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
						int o,p,auxo;
						aux= to_string(prime);
						login="a"+aux+segun+terce+quar;
					    nome=imp.substr(26,32);
					    
						o=nome.find(" ");
						auxo=o;
						for( ;o<nome.size();o++)
						{
							if(nome.substr(o,1)==" ")
							{
								p=o;
							}
						}
						subnome=quar+nome.substr(auxo,p);
					}
	                //cout<<subnome;						
					cout<<"useradd -p `openssl passwd -crypt "<<subnome<<"` -c '"<<nome<<"'"<<login<<endl;
					arq<<"useradd -p `openssl passwd -crypt "<<subnome<<"` -c '"<<nome<<"'"<<login<<endl;		
				}
			}
            	
			catch(out_of_range)
			{
			}

        }
    }

    arquivobxado.close();
    arq.close();

}
