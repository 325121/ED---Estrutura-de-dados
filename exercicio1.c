#include <stdio.h>
typedef struct{
    int ID;
    char MARCA[100];
    float VALOR;
    int ESTOQUE; 
}
    produto;

void arquivo(const char* nome, produto produtos[]){
    FILE *arquivo =fopen(nome, "r");
        if(arquivo == NULL){
            printf("ERRO AO ABRIR ARQUIVO");
                return;
        }
        int i =0;
        char linha[100];
        fgets(linha, sizeof(linha), arquivo);
        while(fscanf(arquivo,"%d %s %f %d", 
        &produtos[i].ID,
        produtos[i].MARCA,
        &produtos[i].VALOR,
        &produtos[i].ESTOQUE) == 4){
        i++;
        }

        int maior = produtos[0].VALOR;
        produto tabela_maior = produtos[0];

        for (int k = 0; k < i; k++){
            if(produtos[k].VALOR > maior){
                maior = produtos[k].VALOR;
                tabela_maior = produtos[k];
                
            }

        }
         int maior_e = produtos[0].ESTOQUE;
        produto t_estoque = produtos[0];

        for (int j = 0; j < i; j++){
            if (produtos[j].ESTOQUE > maior_e){
                maior_e = produtos[j].ESTOQUE;
                t_estoque = produtos[j];
            }

        }

        printf("PRODUTO MAIS CARO:\n");
        printf("-----------------------\n");
        printf("ID: %d\n",tabela_maior.ID );
        printf("MARCA: %s\n",tabela_maior.MARCA );
        printf("VALOR: %2.0f\n",tabela_maior.VALOR );
        printf("ESTOQUE: %d\n",tabela_maior.ESTOQUE );
        printf("-----------------------\n");
        printf("PRODUTO COM MAIOR ESTOQUE:\n");
        printf("-----------------------\n");
        printf("ID: %d\n",t_estoque.ID );
        printf("MARCA: %s\n",t_estoque.MARCA );
        printf("VALOR: %2.0f\n",t_estoque.VALOR );
        printf("ESTOQUE: %d\n",t_estoque.ESTOQUE );
        
        fclose(arquivo);

}
int main(){
    const char* arq = "informacao.txt";
    produto produtos[200];
    arquivo(arq,produtos);

    return 0;
}