//Luiz Felipe PA 2018.1


class complexo{
    private:
        double real,imag;
    public:
        //inline complexo(double _real, double _imag): real = _real; imag = _imag;
        void ler();
        void imprime() const;
        complexo soma(complexo B) const;
        complexo produto(complexo B) const;

};