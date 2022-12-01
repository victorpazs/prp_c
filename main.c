#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Funcoes
int mainMenu(); // funcao de retorno que volta a opcao do menu inicial
void VerMenu(); // funcao que mostra o catalogo ao cliente
void addCarrinho();  // funcao mostra as opções do catálogo e pergunta qual o cliente quer utilizar, alem
void PrintMenu(); //funcao que mostra os itens do menu
void informaItem(); // pede ao usuário o item que deseja adicionar e a quantidade, depois adiciona o mesmo na lista;
int tamanhoCarrinho(); // funcao que retorna o tamanho do carrinho
void verCarrinho(); //mostra o carrinho atual do cliente

//Menu de itens
char menu_itens[4][50] = {"Madeira A","Madeira AB","Madeira B","Madeira C"};
char menu_itens_descricao[4][1000] = {"Madeira lisa, sem nó, sem casca e sem resina", "Nó bem pequeno, sem resina e casca","Nó padrão tamanho razoável sem quebrar, sem resina e casca", "Nó quebrável podendo ir resina e contendo casca"};
float menu_itens_preco[4] = {50.00,45.00,40.00,30.00};


typedef struct {
    char nome_produto[200];
    int valor, quantidade, total;
} itemCarrinho;

itemCarrinho carrinho[100];

int saldoConta = 0;
int main()
{
    setlocale(LC_ALL, "Portuguese");          // alterar idioma para portugu�s

    int op = -1;

    while( op != 0 ){
        op = mainMenu();
        system( "cls" );
         switch( op ) {
            case 1: // Ver menu (catalogo de itens)
                VerMenu();
                break;
            case 2: // Ver carrinho, da a possibilidade de editar algum item e gerenciar
                verCarrinho();
                break;


            case 4: // Meu saldo, mostra ao usuario o seu saldo para comprar
                    break;

            case 5: // info do app
                    break;
        case 0: // saida do programa
                printf( "\n entrou [0] Para sair do programa" );
                exit(0);
        default:
                printf( "\n Digite uma Opcao Valida!" );
                break;
        }
        getchar();       // parada da tela
    }

}

int mainMenu(){
    int opt = -1;
     printf("\n------------------");
     printf("Bem-vindo à Madeireira X!");
     printf("-----------------\n");
     printf("[1] Ir para a loja\n");
     printf("[2] Ver carrinho\n");
     printf("[3] Meu saldo\n");
     printf("[4] Finalizar compra atual\n");
     printf("[5] Saiba mais sobre a Madeireira X\n");
     printf("[0] Sair\n");
     printf("\n------------------");
     printf("-------------------------");
     printf("-----------------\n\n");
     printf("Digite qual opcao que deseja seguir: ");
     fflush( stdin );   // limpa buffer do teclado, funciona antes da entrada de dados
     scanf( "%d", &opt );// tecla de opcao do menu
     return opt;
}

void VerMenu(){
     int op = -1;

     PrintMenu();
     printf("\nO que deseja fazer?\n");
     printf("\n[1] Comprar");
     printf("\n[2] Voltar");
     printf("\n\nOpção:");
     scanf("%d", &op);

     switch (op){
        case 1:
            system( "cls" );
            addCarrinho();
            break;
        case 2:
            system( "cls" );
            mainMenu();
            break;
        default:
            system( "cls" );
            mainMenu();
            break;

    }
}

void PrintMenu(){
    int i;
     printf("\n--------------------");
     printf("Nossos produtos (preço por metro)");
     printf("--------------------\n");
     for (i=0; i<4; i++){
        printf("[%i] R$%.2f - %s \n", i + 1, menu_itens_preco[i], menu_itens[i]);
     }
     for (i=0; i<60; i++){
        printf("-");
     }

}


void addCarrinho(){
    int op = -1;
    printf("\nQual item deseja adicionar ao carrinho?\n\n");
    PrintMenu();
    printf("\n[0] - Voltar");
    printf("\n\nSua opção:");
    scanf("%d", &op);

    switch (op){
        case 1:
        case 2:
        case 3:
        case 4:
            system( "cls" );
            addItemCarrinho(op - 1);
            break;
        case 0:
            system( "cls" );
            mainMenu();
            break;
        default:
            system( "cls" );
            mainMenu();
            break;

    }
}
void addItemCarrinho(int item){
    int quantidade = 0, tamanho = 0, total = 0, valor = 0;
    char nome[100];
    printf("\nQuantos metros?");
    scanf("%d", &quantidade);

    valor = menu_itens_preco[item];
    nome[100] = menu_itens[item];
    total = quantidade * valor;
    if (quantidade > 0){
    tamanho = tamanhoCarrinho();

    carrinho[tamanho + 1].quantidade = quantidade;
    carrinho[tamanho + 1].nome_produto[100] = nome;
    carrinho[tamanho + 1].valor = valor;
    carrinho[tamanho + 1].total = quantidade;


    printf("\n\nItem adicionado ao carrinho:");
    printf("\n[%i] R$%.2f - %s - %d metros\n", item + 1, menu_itens_preco[item], menu_itens[item], quantidade);
    } else {
        printf("\nQuantidade inválida!");
        mainMenu();
    }
}


int tamanhoCarrinho(){
    int arr_len = *(&carrinho + 1) - carrinho;
    return arr_len;
}

void verCarrinho(){
    int x, tamanho = tamanhoCarrinho(), opt = -1;

    printf("%d", tamanho);
   /* if (tamanho > 0){
    for (x= 0; x < tamanho; x++){
        printf("\n===============");
        printf("\nItem: %s", carrinho[x].nome_produto);
        printf("\nQuantidade: %d", carrinho[x].quantidade);
        printf("\nValor do produto: %d", carrinho[x].valor);
        printf("\nValor total: %d", carrinho[x].total);
    }
    } else printf("\nCarrinho vazio");
    printf("\n\nDigite 0 para voltar ao menu:");
    scanf("%d", &opt);


    switch (opt){
        case 0:
            system( "cls" );
            mainMenu();
            break;
        default:
            system( "cls" );
            mainMenu();
            break;
    }
*/
}

