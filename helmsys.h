#ifndef HELMSYS
#define HELMSYS

#define NCOILMAX 15
void getfilename(char * filename);
void getcoords(double coord[2][2]);
void getdomain(double coord[2][2]);
void getnnodes(int &n);
void getcoilcoords(double coords[NCOILMAX][2], int& noc, char* filename);
#endif
