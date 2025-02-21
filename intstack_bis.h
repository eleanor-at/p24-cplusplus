#include <iostream>
#include <stdexcept>
#include <typeinfo>

// constante entière pour la taille de la pile


// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille 12 (SIZE)
class IntStack
{
private:
    // vos attributs pour représenter la pile d'entier
    // dans cette version toutes les piles sont de taille SIZE
    // votre code ici
    int* stack;//stack doit être un pointeur pour être aloué dynamiquement et être compatible avec l'opérateur [] 
    int nb;
   
public:

    IntStack(int SIZE = 0) : stack(new int[SIZE]), nb(0) {}

    void push(int e)
    {
        // cette fonction ajoute l'entier e dans la pile
        // votre code ici
        stack[nb] = e;
        nb++;
    }
    int get_top()
    {
        // cette fonction retourne le dernier entier empilé
        // votre code ici
        return stack[nb-1];

    }
        
    
    int pop()
    {
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile
        // votre code ici
        int last = stack[nb - 1];
        nb = nb - 1 ;
        return last;

        
        
    }
    bool is_empty()
    {
        // cette fonction teste si la pile est vide
        // votre code ici
        return nb == 0;
    }
    


    void print()
    {
        // cette fonction affiche la pile, par exemple
        // [1 2 3 [ pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        // votre code ici
        
        if (nb >= 1)
        {
            std::cout<<"[";
            for (int i =0; i< nb; i++)
            {
                std::cout << stack[i]<< " ";
            }
            std::cout<<"]"<<std::endl;
        
        }
        else
        {
            std::cout<< "[[" << std::endl;
        }
        
        
    }
    ~IntStack()
    {
        delete[] stack; //destructeur
    }


};



// 1. réaliser le code pour faire fonctionner cette pile d'entier de taille fixée à la compilation
// 2. quelles sont les méthodes qui ne modifient pas l'objet sur lequel elles sont appelées
//    faites en sorte qu'elles puissent être appelées sur un objet constant
// 3. faites la fonction qui permet d'afficher un objet de type IntStack directement avec <<<
//    std::cout << s1;
//    il faut redéfinir l'operator<< en appelant la méthode print

