#include "helmsys.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
void getfilename(char* filename)
{
  char files[] = "./DATA/coordinates_custom.dat";
  strcpy(filename,files);
}

void getcoords(double coords[2][2])
{
  coords[0][0] = 0.0  ;
  coords[0][1] = 1.0  ;
  coords[1][0] =-1.0 ;
  coords[1][1] = 2.0 ;

}
void getdomain(double coords[2][2])
{
  coords[0][0] = 0.0  ;
  coords[0][1] = 0.08  ;
  coords[1][0] = 0.0  ;
  coords[1][1] = 0.486 ;

}


void getnnodes(int &n)
{
  n = 15;
}

void getcoilcoords(double coords[15][2], int& noc, char* filename)
{
noc = 0;
char line[100];
int pos=0,flag=0;
 std::ifstream myfile (filename);
      if (myfile.is_open())
    {
while ( myfile )
 {   
   pos = myfile.tellg();
   myfile.getline(line,100);
   if (line[0]!='#' )
   if (strlen(line)!=0)
                {
     myfile.seekg(pos);
     myfile>>coords[noc][0]>>coords[noc][1];
     ++noc;   
     std::cout<<"\n R="<<coords[noc-1][0]<<" Z="<<coords[noc-1][1]<<"\n";
} 
}    
     
 for(int i=0;i<noc;i++)
 {
     coords[i][0]=coords[i][0]/1000.0;
     coords[i][1]=coords[i][1]/1000.0;
 }

        myfile.close();
                  }
                
                   else std::cout << "Unable to open file";

}
