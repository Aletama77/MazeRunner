#ifndef CONSUMIBLE_H_INCLUDED
#define CONSUMIBLE_H_INCLUDED

enum TIPO {

    NULO = 0,
    SUMAVIDA = 1,
    RESTAVIDA = 2,
    SUMATIEMPO = 3,
    RESTATIEMPO  = 4,
    AUMENTAVISION =5,
    RESTAVISION=6,
    MOSTRARMAPA=7

};

class Consumible{
    public:
        Consumible();
        ~Consumible();
        void setTipo(int n);
        int getTipo();

    private:
      int _tipo;





};







#endif // CONSUMIBLE_H_INCLUDED
