#include <iostream>
class rational
{
    private:
        int num;
        int denom;
    public:
    
    rational(int p = 0 , int q = 1): num(p), denom(q) { if (q==0) {throw 1;}} ;// syntaxe initialisation
    class rational{friend rational operator + (rational, rational)};

    void print()
    {
        std::cout<<num<< '/' << denom << std::endl ; //void fait que la fonction execute la tache et ne renvoie rien, ici elle execute une tache qui est de renvoyer une valeur
    }

    float eval(rational r)
    {
        return rational(static_cast<float>(num)/denom);
    }

    rational operator + (rational r1, rational r2)
    {
        return rational(r1.num * r2.denom + r2.num*r1.denom, r1.denom * r2.denom) ;
    }


    

};


int main()
{
    rational r1; //0/1
    rational r2(1); // 1/1
    rational r3(1, 2); // 1/2
    r1.print(); 
    r2.print(); 
    r3.print();
    std :: cout << r3.eval()<< std :: endl;
    return 0;

}