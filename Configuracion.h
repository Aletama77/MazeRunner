#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

class Configuracion {
    public:
    Configuracion();
    ~Configuracion();
    float getvolumenPartida();
    float getvolumenMainTheme();
    void setvolumenPartida(int n);
    void setvolumenMainTheme(int n);
    void setmute();





    private:
    float _volumenPartida;
    float _volumenMainTheme;







};



#endif // CONFIGURACION_H_INCLUDED
