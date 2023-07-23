/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 
 * Module:  main.cpp
 * Author:  Milena Maldonado, Alexander Guaman, Ronny Ibarra
 * Modified:  Lunes, Julio 17, 2023 18:24:36
 * Purpose: Control Registos 
 ***********************************************************************/
#include "Backup.h"

Backup::Backup()
{
}

Backup::~Backup()
{
}

void Backup::generarBackup(){
    time_t t;
    t=time(NULL);
    struct tm *f;
    f=localtime(&t);

    int dia,mes,anio,hora,min;
    dia=f->tm_mday;
    mes=f->tm_mon+1;
    anio=f->tm_year+1900;
    hora=f->tm_hour;
    min=f->tm_min;

    std::string linea;
    std::string texto,texto1,texto2;
    string fecha;
	string direccion;
    std::string anio1=(std::to_string(anio));
    std::string mes1=(std::to_string(mes));
    std::string dia1=(std::to_string(dia));
    std::string hora1=(std::to_string(hora));
    std::string min1=(std::to_string(min));
    fecha = dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_BackupRegistro"+".txt";
	ifstream original("registros.txt");
    while (getline(original,linea))
    {
        texto=texto+linea+"\n";
    }
    original.close();
    ofstream backup;
    backup.open(fecha);
    backup<<texto;
    backup.close();
    
    fecha = dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_Backupborrar"+".txt";
    ifstream original1("empleados.txt");
    while (getline(original1,linea))
    {
        texto1=texto1+linea+"\n";
    }
    original1.close();
    ofstream backup1;
    backup1.open(fecha);
    backup1<<texto1;
    backup1.close();
    
    ifstream original2("empleados.dat");
    fecha = dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_Backupusuarios"+".dat";
    while (getline(original2,linea))
    {
        texto2=texto2+linea+"\n";
    }
    original2.close();
    ofstream backup2;
    backup2.open(fecha);
    backup2<<texto2;
    backup2.close();
}