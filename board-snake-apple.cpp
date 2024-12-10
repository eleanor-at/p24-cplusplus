
// voici un exemple de comment faire le board et le snake avec un std::vector
#include <vector>
#include <iostream>

int main()
{
    // reprenons le jeu du snake:
    // .......
    // .......
    // ..Ooo..
    // ....@..
    // .......

    // on a un board de 5 lignes et 7 colonnes avec un serpent et une pomme
    // on veut représenter le board par un tableau de caractères avec:
    //   - des '.' pour le fond
    //   - des 'O' et 'o' pour le snake
    //   - un '@' pour la pomme
    // on veut, comme en numpy avoir un tableau sous-jacent de 1 dimension de 5 x 7 cases
    // et le manipuler comme un tableau 2D de 5 lignes et 7 colonnes
    // on peut utiliser std::vector<char> pour cela

    int rows{5};
    int columns{7};

    // on crée un tableau de 5 x 7 cases initialisé à '.'
    // voir la documentation de std::vector pour plus de détails https://en.cppreference.com/w/cpp/container/vector
    // ou alors chercher sur internet des exemples d'utilisation de std::vector (pas en français)
    std::vector<char> tab(rows * columns, '.');

    // pour le snake, chaque anneau du snake est une paire d'entiers (ligne, colonne)

    // donc, par exemple vous utilisez un std::vector<std::pair<int, int>> snake
    std::vector<std::pair<int, int>> snake{{2, 2}, {2, 3}, {2, 4}};
    // et vous pouvez rajouter des anneaux au snake avec
    snake.push_back({2, 5});

    // ensuite vous mettez le snake sur le board

    // on met la tête du snake
    tab[snake[0].first * columns + snake[0].second] = 'O';
    // et le corps
    for (int i = 1; i < snake.size(); i++)
    {
        tab[snake[i].first * columns + snake[i].second] = 'o';
    }
    

    // on met la pomme
    tab[3 * columns + 4] = '@';

    // là on le parcourt pour l'afficher le board avec son snake et sa pomme
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            // on doit passer d'une indexation 2D à une indexation 1D
            std::cout << tab[r * columns + c];
        }
        std::cout << std::endl;
    }
    // mais tout ça doit être organisé dans des classes et des méthodes dans ces classes
    return 0;
}
