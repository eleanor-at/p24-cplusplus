#include <iostream>
#include <unordered_map>
#include <vector>
#include "intstack_bis.h" //pour la structure de pile j'ai utlilisé celle définie en tp avec les int
#include <queue>

void print(std::unordered_map<int, bool> dic)
        {
            for (const auto& pair : dic)
            {
                std::cout<<pair.first<< " : "<< pair.second << std::endl;
            }
        }

class Graph
{
    private:
    std::unordered_map<std::string, std::unordered_map<std::string, int> > graphe;
    void explorer(const std::string& sommet, std::unordered_map<std::string, bool> visite);


    public:
    Graph() {}
        void ajouter(const std::string& key1, const std::string& key2, int valeur)
        {
            graphe[key1][key2] = valeur;
        }
        
        
        std::unordered_map<std::string, std::unordered_map<std::string, int> >::const_iterator begin() const {
        return graphe.cbegin();
    }

    std::unordered_map<std::string, std::unordered_map<std::string, int> >::const_iterator end() const {
        return graphe.cend();
    }



        void print()
        {
            for (const auto& pair1 : graphe) //quand on parcourt les éléments du graphe, on parcourt les couples clé/valeur; on passe
                                       // par l'adresse de ces élts pour éviter les copies inutiles
                                       // on parcourt les couples clé/dictionnaire contenant les sommets adjacents et leur pondération
            {
                auto& key1 = pair1.first;
                for (const auto& pair2 : pair1.second) //on parcourt les sommets adjacents et leur pondération associée
                {
                    auto& key2 = pair2.first;
                    std::cout<<key1<< " -> " << key2<< " : "<< pair2.second <<std::endl;
                }
            }
        }
  



        const std::unordered_map<std::string, int> crochets(const std::string& name) const 
        {
            std::unordered_map<std::string, int> graphe_name;
            for (auto& pair1 : graphe)
            {
                if (pair1.first == name)
                {
                    for (auto& pair2 : pair1.second)
                    {
                        graphe_name[pair2.first] = pair2.second;

                    }
                    return graphe_name;
                }

                
            }
            static const std::unordered_map<std::string, int> empty_map;
            return empty_map;

        }

        

};

void explorer_rec(const Graph& graphe, const std::string& sommet, std::unordered_map<std::string, bool>& visite, std::unordered_map<std::string, bool>& aretes) 
            {
                visite[sommet] = true;
                for (auto& adjacent : graphe.crochets(sommet))
                            {
                                std::string fleche = " -> ";
                                std::string arete = sommet + fleche + adjacent.first;
                                
                                if (aretes.count(arete) == 0) //count retourne 1 si la clé existe et 0 sinon
                                {
                                    std::cout<< sommet << " -> " << adjacent.first << " : " << adjacent.second << std::endl;
                                    aretes[arete] = true; 
                                    explorer_rec(graphe, adjacent.first, visite, aretes);
                                }

                                //else {std::cout<< adjacent.first << " déjà vu" << std::endl;}
                            }  
            }


void parcours_profondeur_rec(const Graph graphe)

    {
        std::unordered_map<std::string, bool> visite;
        std::unordered_map<std::string, bool> aretes;

        for (const auto& pair : graphe)
        {
            
            if (visite.count(pair.first) == 0 ) //count retourne 1 si la clé existe et 0 sinon
            {
                
                explorer_rec(graphe, pair.first, visite, aretes);
                
            }
        }
    }

bool in(std::string sommet, std::vector<std::string> vector)
{
    for (int n = 0; n < vector.size(); n++)
    {
        if (vector[n] == sommet)
        {
            return true;
        }
    }
    return false;
}

int index(std::string sommet, std::vector<std::string> vector)  //permet d'obtenir la position d'un élt d'un vecteur
{
    for (int n = 0; n < vector.size(); n++)
    {
        if (vector[n] == sommet)
        {
            return n;

        }
    }
}


void explorer_to_vector(const Graph& graphe, const std::string& sommet, std::vector<std::string>& visite) //on marque les sommets adjacents dans le dic
{
    if (! in(sommet, visite))
    {
        visite.push_back(sommet);
    for (auto& adjacent : graphe.crochets(sommet))
    {
        if (not in(adjacent.first, visite))
        {
            visite.push_back(adjacent.first);
            explorer_to_vector(graphe, adjacent.first, visite);
        }
    }

    }
    

}


std::vector<std::string> graphe_to_vector(const Graph& graphe)  //le but de cette fonction est de numéroter les différents
                                                                    // sommets du graphe pour ensuite se servir de la classe déjà définie IntStack
                                                                    // et de pouvoir définir dans le meme temps la représentation par matrice d'adjacence
                                                                    // du graphe
{
    std::vector<std::string> visite;
    for (const auto& pair : graphe)
        {
            
            if (in(pair.first, visite) == 0) 
            {
                explorer_to_vector(graphe, pair.first, visite);
                
            }
        }
    return visite;

}                                                                    



void explorer_it(const Graph& graphe, const std::string& sommet, std::unordered_map<int, bool>& visite) //exploration itérative à partir de la structure
// de base Graph utilisant les dicitonnaires
{
    std::vector<std::string> vec = graphe_to_vector(graphe);
    IntStack stack;
    stack.push(index(sommet, vec));
    while (! stack.is_empty())
    {
        int int_sommet = stack.pop();
        if (visite.count(int_sommet) == 0)
        {
            visite[int_sommet] = true;

            std::cout<< vec[int_sommet] << std::endl;
            std::unordered_map<std::string, int> dic = graphe.crochets(vec[int_sommet]);
        
            for (const auto& pair: dic)
            {
                std::cout<< " -> " << pair.first << " : " << pair.second << std::endl;
                if (visite.count(index(pair.first, vec)) == 0)
                {
                    stack.push(index(pair.first, vec));
                    
                }

            }
        }
    }
  
}

void parcours_profondeur_it(const Graph& graphe)
{
    std::unordered_map<int, bool> visite;
    std::vector<std::string> vec = graphe_to_vector(graphe);
    for (int i = 0 ; i< vec.size(); i++) //on balaye tous les sommets pour être sûr de visiter toutes les composantes connexes du graphe
                                        // dans le cas où il n'est pas connexe
    {
        if (visite.count(i) == 0)
        {
            explorer_it(graphe, vec[i], visite);

        }
        
    }


}

std::vector<std::vector<int> > graphe_to_matrice(const Graph& graphe) //on obtient la matrice d'adjacence du graphe, mat[i][j] vaut le poids de l'arete si elle existe et -1 sinon
{
    std::vector<std::string> vec = graphe_to_vector(graphe);

    std::vector<std::vector<int> > mat(vec.size(), std::vector<int>(vec.size(), -1)); //on initialise la matrice à -1

    for (int i = 0; i < vec.size(); i++) 
    {
        mat[i][i] = 0; //coef diagonaux nuls
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::unordered_map<std::string, int> dic = graphe.crochets(vec[i]);
        for (const auto& elem : dic)
        {
            mat[i][index(elem.first, vec)] = elem.second;
        }
    }

    return mat;
}


void explorer_it_mat(const Graph& graphe, const std::vector<std::vector<int> >& graphe_mat, const std::string& sommet, std::unordered_map<int, bool>& visite)
{
    std::vector<std::string> vec = graphe_to_vector(graphe); //permet d'avoir des noms de sommets autre que des int, sinon inutile
    IntStack stack;
    stack.push(index(sommet, vec));
    while (! stack.is_empty())
    {
        int int_sommet = stack.pop();
        if (visite.count(int_sommet) == 0)
        {
            visite[int_sommet] = true;

            std::cout<< vec[int_sommet] << std::endl;
            
        
            for (int j = 0; j< vec.size(); j++)
            {
                if (graphe_mat[int_sommet][j] != 0 && graphe_mat[int_sommet][j] != -1)
                {
                    std::cout<< " -> " << vec[j] << " : " << graphe_mat[int_sommet][j] << std::endl;
                    if (visite.count(j) == 0)
                    {
                        stack.push(j);
                    }
                    
                    
                
                }

                

            }
        }
    }
}

void parcours_profondeur_it_mat(const Graph& graphe, const std::vector<std::vector<int> >& graphe_mat)
{
    std::unordered_map<int, bool> visite;
    std::vector<std::string> vec = graphe_to_vector(graphe);
    for (int i = 0 ; i< vec.size(); i++)
    {
        if (visite.count(i) == 0)
        {
            explorer_it_mat(graphe, graphe_to_matrice(graphe), vec[i], visite);

        }
        
    }
}
        
void explorer_largeur(const Graph& graphe, const std::string& sommet, std::unordered_map<int, bool>& visite)
{
    std::vector<std::string> vec = graphe_to_vector(graphe);
    std::queue<int> file;
    file.push(index(sommet, vec));
    while (! file.empty())
    {
        int int_sommet = file.back();
        file.pop();
        if (visite.count(int_sommet) == 0)
        {
            visite[int_sommet] = true;

            std::cout<< vec[int_sommet] << std::endl;
            std::unordered_map<std::string, int> dic = graphe.crochets(vec[int_sommet]);
        
            for (const auto& pair: dic)
            {
                std::cout<< " -> " << pair.first << " : " << pair.second << std::endl;
                if (visite.count(index(pair.first, vec)) == 0)
                {
                    file.push(index(pair.first, vec));
                    
                }

            }
        }
    }

}

void parcours_profondeur_largeur(const Graph& graphe)
{
    std::unordered_map<int, bool> visite;
    std::vector<std::string> vec = graphe_to_vector(graphe);
    for (int i = 0 ; i< vec.size(); i++) //on balaye tous les sommets pour être sûr de visiter toutes les composantes connexes du graphe
                                        // dans le cas où il n'est pas connexe
    {
        if (visite.count(i) == 0)
        {
            explorer_largeur(graphe, vec[i], visite);

        }
        
    } 


}




 //at() équivalent de [] pour objets constants
int main()
{
    Graph g ;
    std::unordered_map<int, bool> visite;
    g.ajouter("Venise", "Rouen", 140); 
    g.ajouter("Venise", "Paris", 10);
    g.ajouter("Paris", "Rouen", 40);
    g.ajouter("Rouen", "Alicante", 100);
    g.ajouter("Paris", "New York", 1000);
    std::vector<std::string> vec = graphe_to_vector(g);
    parcours_profondeur_largeur(g);

    return 0;
}