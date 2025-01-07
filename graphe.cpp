#include <iostream>
#include <unordered_map>
#include <vector>

 void print(std::unordered_map<std::string, int> dic)
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
            for (const auto& pair1 : graphe)
            {
                if (pair1.first == name)
                {
                    for (const auto& pair2 : pair1.second)
                    {
                        graphe_name.at(pair2.first) = pair2.second;

                    }
                    return graphe_name;
                }

                else 
                {
                    // Si la clé n'existe pas, retourner un dictionnaire vide ou gérer l'erreur autrement
                    static const std::unordered_map<std::string, int> empty_map;
                    return empty_map;
                }
            }

        }

        

};

void explorer(const Graph& graphe, const std::string& sommet, std::unordered_map<std::string, bool> visite) 
            {
                std::cout<<"exploration paris"<<std::endl;
                visite[sommet] = true;
                for (auto& adjacent : graphe.crochets(sommet))
                            {
                                
                                std::cout << adjacent.first << std::endl;
                                if (visite.count(adjacent.first) == 0) //count retourne 1 si la clé existe et 0 sinon
                                {
                                    std::cout<< sommet << " -> " << adjacent.first << " : " << adjacent.second << std::endl;
                                    explorer(graphe, adjacent.first, visite);
                                }

                                else {std::cout<< adjacent.first << " déjà vu" << std::endl;}
                            }  
            }


void parcours_profondeur(const Graph graphe)
    {
        std::unordered_map<std::string, bool> visite;

        for (const auto& pair : graphe)
        {
            if (visite.count(pair.first) == 0) //count retourne 1 si la clé existe et 0 sinon
            {
                explorer(graphe, pair.first, visite);
                
            }
        }
    }

        


 //at() équivalent de [] pour objets constants
int main()
{
    Graph g ;
    g.ajouter("Paris","Alicante", 10);
    g.ajouter("Paris", "Venise", 80);
    g.ajouter("Venise", "Rouen", 140);
    std::unordered_map<std::string, bool> visite;

   
   
    return 0;
}