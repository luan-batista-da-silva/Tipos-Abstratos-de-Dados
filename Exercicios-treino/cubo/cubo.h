typedef struct cubo Cubo;

Cubo* cubo_create(float aresta); // Cria o cubo
void cubo_destroy(Cubo *cubo); // Destroir o cubo
float cubo_compAresta(Cubo *cubo); // Retorna comprimento das Arestas
void cubo_atribui(Cubo* cubo, float aresta); // Muda a aresta
float cubo_perimetro(Cubo *cubo); // Perímetro do Cubo 
float cubo_areaFace(Cubo *cubo); // Area das Faces do Cubo
float cubo_areaTotal(Cubo *cubo); // Area total do cubo
float cubo_volume(Cubo *cubo); // Volume do Cubo
float cubo_diagonal(Cubo *cubo); // Comprimento da diagonal 

