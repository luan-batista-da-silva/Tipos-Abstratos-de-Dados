typedef struct cilindro Cilindro;

// Cria o cilindro
Cilindro* cilindro_create(float altura, float raio);

// Desaloca a memória do cilindro
void cilindro_destroy(Cilindro* cilindro);

// Area da base do Cilindro
float cilindro_areaBase(Cilindro* cilindro);

// Area da Face do Cilindro
float cilindro_areaFace(Cilindro* cilindro);

// Volume do Cilindro
float cilindro_volume(Cilindro* cilindro);
