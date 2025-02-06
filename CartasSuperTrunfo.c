#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

#define CARD_LIMIT 2

#define CODE_SIZE 4
#define NAME_SIZE_LIMIT 100

typedef struct {
    char code[CODE_SIZE]; // A01\0 -> A:state, 01: city_number, \0 null
    char name[NAME_SIZE_LIMIT];
    float population;
    float area;
    float GDP;
    float touristic_points;
    float population_density;
    float GDP_per_capita;
} City;

typedef struct {
    float value;
    int index;
} Winner;

void clear_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){
        continue;
    }
}

void print_city(City *city) {
    printf("Código: %s\n", city->code);
    printf("Nome: %s\n", city->name);
    printf("População: %f\n", city->population);
    printf("Área em quilometros quadrados: %f\n", city->area);
    printf("PIB: %f\n", city->GDP);
    printf("Número de pontos turísticos: %f\n", city->touristic_points);
    printf("Densidade populacional(hab/km²): %f\n", city->population_density);
    printf("PIB per capita: %f\n", city->GDP_per_capita);
}

void list_cards(City cards[]) {
    printf("Listagem de cartas: ");
    for(int i = 0; i < CARD_LIMIT; i++) {
        printf("\n|Carta (%i): \n", i + 1);
        print_city(&cards[i]);
    }
    printf("|-----------------------------\n");
}

void compare_cards(City cards[]) {
    char first_code[CODE_SIZE];
    char second_code[CODE_SIZE];
    City first_card;
    City second_card;
    int property_number;
    printf("Comparação: \n");
    printf("Digite o código da primeira carta: ");
    scanf("%4s", first_code);
    clear_buffer();
    printf("Digite o código da segunda carta: ");
    scanf("%4s", second_code);
    clear_buffer();
    printf("Digite o número da propriedade que será comparada: \n");
    printf("População: 1\n");
    printf("Área em quilometros quadrados: 2\n");
    printf("PIB: 3\n");
    printf("Número de pontos turísticos: 4\n");
    printf("Densidade populacional(hab/km²): 5\n");
    printf("PIB per capita: 6\n");
    printf("> ");
    scanf("%d", &property_number);

    for(int i = 0; i < CARD_LIMIT; i++) {
        if(strcmp(cards[i].code, first_code)) {
            first_card = cards[i];
            continue;
        }
        if(strcmp(cards[i].code, second_code)) {
            second_card = cards[i];
            continue;
        }
    }
    
    City win_card;
    switch (property_number)
    {
        case 1:
            win_card = first_card.population > second_card.population ? first_card : second_card; 
            break;
        case 2:
            win_card = first_card.area > second_card.area ? first_card : second_card;
            break;
        case 3:
            win_card = first_card.GDP > second_card.GDP ? first_card : second_card;
            break;
        case 4:
            win_card = first_card.touristic_points > second_card.touristic_points ? first_card : second_card;
            break;
        case 5:
            win_card = first_card.population_density < second_card.population_density ? first_card : second_card;
            break;
        case 6:
            win_card = first_card.GDP_per_capita > second_card.GDP_per_capita ? first_card : second_card;
            break;
        default:
            break;
    }

    printf("Carta vencedora: %s\n", win_card.code);
}

int main() {
    City cards[CARD_LIMIT];

    for(int i = 0; i < CARD_LIMIT; i++) {
        printf("Digite os dados da cidade (%i): \n", i + 1);
        printf("Código (A01) -> A - Letra do estado | 01 -> número da cidade: ");
        scanf("%4s", cards[i].code);
        clear_buffer();
        printf("Nome: ");
        scanf("%100s", cards[i].name);
        clear_buffer();
        printf("População: ");
        scanf("%f", &cards[i].population);
        printf("Área em quilometros quadrados: ");
        scanf("%f", &cards[i].area);
        printf("PIB: ");
        scanf("%f", &cards[i].GDP);
        printf("Número de pontos turísticos: ");
        scanf("%f", &cards[i].touristic_points);

        cards[i].population_density = cards[i].population / cards[i].area;
        cards[i].GDP_per_capita = cards[i].GDP / cards[i].population;
        printf("\n");
    }
    
    int property_number;
    while(1) {
        printf("Escolha opção: \n");
        printf("Listar cartas - 1\n");
        printf("Comparar cartas por código - 2\n");
        printf("Comparar cartas por código - 3\n");
        printf("> ");
        scanf("%d", &property_number);

        if(property_number == 1) {
            list_cards(cards);
        } else if (property_number == 2) {
            compare_cards(cards);
        } else if (property_number == 3) {
            break;
        } else {
            printf("Opção inválida");
        }
    }

    return 0;
}
