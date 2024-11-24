#include "JugadorArchivo.h"
#include "Jugador.h"


JugadorArchivo::JugadorArchivo(const char *fileName)
{
    strcpy(_fileName, fileName);
}

bool JugadorArchivo::guardar(const Jugador &registro)
{
    FILE *pFile;
    bool result;

    pFile = fopen(_fileName, "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&registro, sizeof(Jugador), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

Jugador JugadorArchivo::leer(int pos)
{
    FILE *pFile;
    Jugador registro,registro2;

    pFile = fopen(_fileName, "rb");

    if(pFile == nullptr)
    {
        return registro;
    }

    fseek(pFile, sizeof(Jugador) * pos, SEEK_SET);

    fread(&registro, sizeof(Jugador), 1, pFile);

    fclose(pFile);
     if(!registro.getEliminado()){
      return registro;
     }else{
        registro2.setEliminado(true);
        return registro2;
     }

}


int JugadorArchivo::getCantidad()
{
    int total, cantidad;
    FILE *pFile;
    pFile = fopen(_fileName, "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    total = ftell(pFile);

    fclose(pFile);

    return total / sizeof(Jugador);
}


bool JugadorArchivo::leerTodos(Jugador registros[], int cantidad)
{
    FILE *pFile;
    bool result;

    pFile = fopen(_fileName, "rb");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fread(registros, sizeof(Jugador), cantidad, pFile) == cantidad;

    fclose(pFile);

    return result;
}


bool JugadorArchivo::guardar(int pos, const Jugador &registro)
{
    FILE *pFile;
    bool result;

    pFile = fopen(_fileName, "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Jugador) * pos, SEEK_SET);

    result = fwrite(&registro, sizeof(Jugador), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

int JugadorArchivo::buscar(int dni)
{
    Jugador registro;
    int cant = getCantidad();
    for(int i=0; i<cant; i++)
    {
        registro = leer(i);
        if(registro.getDni()==dni)
        {
            return i;
        }
    }
    return -1;
}
