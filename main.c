#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include<conio.h>
#define ANSI_COLOR_GREEN  "\u001b[32m" //cores em ANSI utilizadas

//Funcoes
int mainMenu(); // funcao de retorno que volta a opcao do menu inicial
void menuCompra(); // funcao que mostra o catalogo ao cliente
void addCarrinho();  // funcao mostra as opções do catálogo e pergunta qual o cliente quer utilizar, alem
void printMenuItems(); //funcao que mostra os itens do menu
void informaItem(); // pede ao usuário o item que deseja adicionar e a quantidade, depois adiciona o mesmo na lista;
void menuCarrinho(); //abre o menu geral do carrinho
void printCarrinho(); //mostra o carrinho atual do cliente
void limparCarrinho(); //limpa o carrinho do usuário;
void verCarteira(); //mostra o saldo atual do usuário
void addSaldo(); // adiciona saldo à carteira;
void infoApp(); //printa as informações do app

//Menu de itens
char menu_itens[4][50] = {"Madeira A","Madeira AB","Madeira B","Madeira C"};
char menu_itens_descricao[4][1000] = {"Madeira lisa, sem nó, sem casca e sem resina", "Nó bem pequeno, sem resina e casca","Nó padrão tamanho razoável sem quebrar, sem resina e casca", "Nó quebrável podendo ir resina e contendo casca"};
float menu_itens_preco[4] = {50.00,45.00,40.00,30.00};


//variaveis para a lista do carrinho
int index, IA=0, FA=24,IL, FL;


typedef struct {
    int valor, quantidade, total, id_item;
} itemCarrinho;

itemCarrinho carrinho[25];

int saldoConta = 0;
int main()
{
    IL = FL = IA -1;

    setlocale(LC_ALL, "Portuguese");          // alterar idioma para portugu�s

    int op = -1;
    while( op != 0 ){
        op = mainMenu();
         switch( op ) {
            case 1: // Ver menu (catalogo de itens)
                menuCompra();
                break;
            case 2: // Ver carrinho, da a possibilidade de editar algum item e gerenciar
                menuCarrinho();
                break;
            case 3: // Meu saldo, mostra ao usuario o seu saldo para comprar
                verCarteira();
                break;
            case 4:
                finalizarCompra();
                break;
            case 5: // info do app
                infoApp();
                break;
        case 0: // saida do programa
                printf( "\nObrigado por comprar conosco!\n\n");
                exit(0);
        default:
                printf("\nDigite uma Opcao Valida!");
                break;
        }
        getchar();       // parada da tela
        fflush(stdin);
    }

}

int mainMenu(){
     system("color 0f");
     system( "cls" );
     int opt = -1;
     printf("\n------------------");
     printf("Bem-vindo à Madeireira X!");
     printf("-----------------\n");
     printf("[1] Ir para a loja\n");
     printf("[2] Ver carrinho\n");
     printf("[3] Meu saldo\n");
     printf("[4] Finalizar compra atual\n");
     printf("[5] Saiba mais sobre a Madeireira X\n");
     printf("[0] Sair");
     printf("\n------------------");
     printf("-------------------------");
     printf("-----------------\n\n");
     printf("Digite qual opcao que deseja seguir: ");
     fflush( stdin );   // limpa buffer do teclado, funciona antes da entrada de dados
     scanf( "%d", &opt );// tecla de opcao do menu
     system( "cls" );
     return opt;
}


void printMenuItems(){
    int i;
     printf("\n--------------------");
     printf(" Nossos produtos (preço por metro) ");
     printf("--------------------\n");
     for (i=0; i<4; i++){
        printf("[%i] R$%.2f - %s \n", i + 1, menu_itens_preco[i], menu_itens[i]);
     }
     for (i=0; i<=75; i++){
        printf("-");
     }

}

void menuCompra(){
     int op = -1;

     printMenuItems();
     printf("\nO que deseja fazer?\n");
     printf("\n[1] Adicionar item 1 ao carrinho");
     printf("\n[2] Adicionar item 2 ao carrinho");
     printf("\n[3] Adicionar item 3 ao carrinho");
     printf("\n[4] Adicionar item 4 ao carrinho");
     printf("\n\n[0] Voltar");
     printf("\n\nOpção:");
     scanf("%d", &op);

     switch (op){
        case 1:
        case 2:
        case 3:
        case 4:
            system( "cls" );
            addCarrinho(op);
            break;
        case 0:
            system( "cls" );
            return;

        default:
           printf("\nOpção invalida!\n");
           printf("Pressione ENTER para voltar ao menu!");
           getchar();
           return;

    }
}



void addCarrinho(int opt){
    switch (opt){
        case 1:
        case 2:
        case 3:
        case 4:
            system( "cls" );
            addItemCarrinho(opt - 1);
            break;
        case 0:
            system( "cls" );
            return;
        default:
           printf("\nOpção invalida!\n\n");
            printf("\nPressione qualquer tecla para voltar");
           getchar();
           return;
    }
}
void addItemCarrinho(int item){
    int quantidade = 0, total = 0, index;


    printf("\nQuantos metros deseja comprar? ");
    scanf("%d", &quantidade);

    total = quantidade * menu_itens_preco[item];


    if(IA == IL && FA == FL){ //full array
            printf("\nImpossível adicionar, o carrinho está cheio\n");
    } else {
        if (IL == -1){ //there is no nodos on the list
                IL = FL = IA; //IL = 0 and FL = 0
            } else if (FL < FA){ //has space at the beginning of the array
                FL++; //FL = FL + 1
            }   else {
                    for (index = IL; index <= FL; index ++){
                        carrinho[index - 1] = carrinho[index];
                    }
                IL--;
            }

    if (quantidade > 0){
        carrinho[FL].quantidade = quantidade;
        carrinho[FL].valor = menu_itens_preco[item];
        carrinho[FL].total = total;
        carrinho[FL].id_item = item;


        printf("\n\nItem adicionado ao carrinho:");
        printf("\n\n[%i] R$%.2f - %s - %d metros\n", item + 1, menu_itens_preco[item], menu_itens[item], quantidade);
        } else {
            printf("\nQuantidade inválida!");
            return;
        }
        printf("\nPressione qualquer tecla para voltar");
        getchar();
    }
}

void printCarrinho(){
int x, opt = -1, valorTotal = 0;

    if (IL != -1 && FL != -1){
        for (index = IL; index <= FL; index ++){
            printf("\n============= %d° item ================", index + 1);
            printf("\nItem: %s", menu_itens[carrinho[index].id_item]);
            printf("\nQuantidade: %d", carrinho[index].quantidade);
            printf("\nValor do produto: %d", carrinho[index].valor);
            printf("\nValor total: %d", carrinho[index].total);
            printf("\n=======================================\n");
            valorTotal = valorTotal + carrinho[index].total;
        }
        printf("\nValor total do carrinho: %d\n\n", valorTotal);
    } else{
        printf("\nCarrinho vazio");
        printf("\nPressione ENTER para voltar ao menu");
        getchar();
        return;
    }

}
void menuCarrinho(){
    int opt = -1;
    printCarrinho();

     if (IL != -1 && FL != -1){
    printf("\n[1]Editar item");
    printf("\t\t[2] Limpar carrinho (esvaziar)");
    printf("\t\t[3] Finalizar compras");
    printf("\t\t[0] Voltar");
    printf("\n\nO que deseja fazer agora?");
    scanf("%d", &opt);
    switch (opt){
        case 1:
            system( "cls" );
            editCarrinho();
            break;
        case 2:
            limparCarrinho();
            return;
        case 3:
            finalizarCompra();
            return;
        case 0:
            system( "cls" );
            return;
        default:
            system( "cls" );
            return;
    }
    }
}

void editCarrinho(){
    int opt = -1, item, newQuantidade = 0, newTotal = 0;
    printCarrinho();
    printf("\n\nQual dos itens você deseja editar?");
    scanf("%d", &item);


    if (item - 1 > FL){
        printf("\nOpção invalida!");
        getchar();
        return;
    } else {
        system( "cls" );
        printf("\n\nQuantidade atual do %dº item: %d", item, carrinho[item - 1].quantidade);
        printf("\n\nDigite a nova quantidade:");
        scanf("%d", &newQuantidade);
        newTotal = newQuantidade * carrinho[item - 1].valor;
        carrinho[item - 1].total = newTotal;
        carrinho[item - 1].quantidade = newQuantidade;
        printf("\n\nNovo valor total do item: R$%d,00", newTotal);
        printf("\nPressione ENTER para voltar");
        getchar();
    }


}


void verCarteira(){
    int opt = -1;
    system("color 0A");
    printf("\nSALDO ATUAL: RS%d,00", saldoConta);
    printf("\n\n[1] Adicionar saldo");
    printf("\t[0] Voltar");
    printf("\n\nOpção: ");
    scanf("%d", &opt);
    if (opt == 1){
        addSaldo();
    } else return;


}

void addSaldo(){
    int valorAdd;
    system("color 0A");
    printf("\nQual quantia deseja adicionar?");
    scanf("%d", &valorAdd);

    if (valorAdd > 0){
        saldoConta = saldoConta + valorAdd;
        printf("\n\nSaldo adicionado com sucesso!");
        printf("\nPressione enter para voltar ao menu!");
        getchar();
    } else {
        printf("\n\nSaldo inválido!");
        printf("\nPressione enter para voltar ao menu!");
        getchar();
    }

}

void infoApp(){
    printf("A madeireira X tem o prazer de atender o cliente! \n\nAgora para facilitar nossas negociações trouxemos o novo sistema de venda da nossa Loja.");
    printf("\nAqui voçe pode fazer de forma rapida ");
    printf("e facil seus proprios orçamentos. Basta seguir nosso menu, selecionar a madeira desejada e a metragem");
    printf("\nentão nosso software automaticamente calculara o valor final.");
    printf("\n\nTemos a imensa satisfação de atendelo! \n NOTAS: \n ");
    printf("este é um sistema criado por estudantes do curso de Ciencia da computação da Unisc.\nVictor Paz, Eduardo Sehn, Amanaury Pavanatto e Marcio Henrique \n");

getchar();       // parada da tela

}

void limparCarrinho(){
    IL = FL = IA -1;
}
 int valorTotalCarrinho(){
    int valorTotal = 0;

     if (IL != -1 && FL != -1){
        for (index = IL; index <= FL; index ++){
            valorTotal = valorTotal + carrinho[index].total;
        }
    } else valorTotal = 0;

    return valorTotal;

 }
void finalizarCompra(){
    int opt = -1, totalCarrinho = 0;
    system("color 0A");
    totalCarrinho = valorTotalCarrinho();
    system( "cls" );
    if (IL != -1 && FL != -1){
        printf("Valor total do carrinho: %d", totalCarrinho);
        printf("\n\nSaldo da carteira: %d", saldoConta);

        printf("\n\nTem certeza que deseja finalizar as compras?");
        printf("\n\n[1] Sim \t");
        printf("[0] Não");
        printf("\n\nOpção:");
        scanf("%d", &opt);

        if (opt == 1){
            if (totalCarrinho > saldoConta){
                printf("\nImpossível finalizar a compra, o seu saldo é insuficiente!");
                printf("\n\nPressione enter para voltar ao menu!");
                getchar();
            } else {
                saldoConta = saldoConta - totalCarrinho;
                limparCarrinho();
                printf("\nCompra finalizada! Pressione enter para voltar ao menu!");
                getchar();
                return;
            }
        } else {
            return;
        }
        } else {
            printf("\nNão há o que finalizar, o carrinho está vazio!");
            printf("\nPressione Enter para voltar ao menu!");
            getchar();
            return;

    }
}


