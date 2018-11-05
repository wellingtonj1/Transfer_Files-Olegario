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
    string imp,imprimir;
    arquivobxado.open("CMP-2.txt");

    if(!arquivobxado.is_open())
    { //testa se a abertura do arquivo falhou
        cout<<"Arquivo nao aberto"<<endl;
    }
    else
    {
        string correta,vazio,aux,segun,terce,quar,senha,nome,subnome;
        string login,auxquar= "";
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
	                catch(invalid_argument){}
	              
	                if(prime>1000&&prime<3000)
	                {	
						int contador=0;
						string straux= "";				
						aux= to_string(prime);
						login="a"+aux+segun+terce+quar;
					    nome=imp.substr(26,32);
					    
					    
					    for(unsigned int y=0;y<nome.length();y++)
					    {
							if(nome[y]==' '&&nome[y+2]!=' ')
							{
								subnome=straux;
								contador++;
							}
							else
							{
								if(contador==1)
								{
									straux+=tolower(nome[y]);	
								}
							}
							
						}
					    						
					}
					if(auxquar!=quar)
					{
						imprimir="useradd -p `openssl passwd -crypt "+quar+subnome+"` -c \'"+nome+"'"+login+"\n";
						cout<<imprimir;	
						arq<<imprimir;		
					}
					auxquar=quar;
				}
			}	
			catch(out_of_range){}
			

        }
    }

    arquivobxado.close();
    arq.close();

}
