#include <stdio.h> 
#include <string.h>

typedef struct{
    char CPF[100];
    char NOME[100];
    char EMAIL[100];
    char CELULAR[100];

} produto_p;

typedef struct{
    char PLACA[100];
    char MARCA[100];
    char MODELO[100];
    char CPF[100];

} produto_v;

// FUNÇÃO PARA ACESSAR ARQUIVO PROPRIETARIOS
int arquivo_p(const char* nome, produto_p prorietario[]){
    FILE *arquivo = fopen(nome, "r");
        if(arquivo == NULL){
            printf("ERRO AO ABRIR ARQUIVO");
            return -1;
            
        }

        char linha[100];
        int i = 0;
        fgets(linha,sizeof(linha),arquivo);


        while(fscanf(arquivo, "%99[^,],%99[^,],%99[^,],%99[^\n]\n",
            prorietario[i].CPF,
            prorietario[i].NOME,
            prorietario[i].EMAIL,
            prorietario[i].CELULAR) == 4){ 
        
        i++;

        } 
    fclose(arquivo);

    return i;
}
// FUNÇÃO PARA ACESSAR ARQUIVO VEICULOS
int arquivo_v(const char* nome, produto_v veiculo[]){
    FILE *arquivo = fopen(nome, "r");
        if(arquivo == NULL){
            printf("ERRO AO ABRIR ARQUIVO");
            return -1;
            
        }

        char linha[100];
        int k = 0;
        fgets(linha,sizeof(linha),arquivo);


        while(fscanf(arquivo, "%99[^,],%99[^,],%99[^,],%99[^\n]\n",
            veiculo[k].MARCA,
            veiculo[k].PLACA,
            veiculo[k].MODELO,
            veiculo[k].CPF) == 4){ 
                
        k++;

        } 
    fclose(arquivo);

    return k;
}

// FUNÇÃO QUE NÃO RETORNA NADA PARA MANIPULAR AS INFORMAÇOES PEDIDAS
void informa(produto_p proprietario[], produto_v veiculo[],int arquivo_p, int arquivo_v){
        for(int y =0; y<arquivo_p; y++){
            for(int j =0; j<arquivo_v; j++){
                if(strcmp(proprietario[y].CPF,veiculo[j].CPF)==0){
                    printf("---------------------------\n");        
                    printf("NOME:%s\n",proprietario[y].NOME);
                    printf("EMAIL:%s\n",proprietario[y].EMAIL);
                    printf("PLACA:%s\n",veiculo[j].PLACA);
                    printf("MODELO:%s\n",veiculo[j].MODELO);
                    printf("MARCA:%s\n",veiculo[j].MARCA);

                }
            }

        }

}

int main(){
    // as struct proprietario e veeiculo

    produto_p proprietario[100];
    produto_v veiculo[100];

    // os arquivos txt, proprietario e veiculos


    const char* arq_proprietario = "proprietarios.txt";
    const char* arq_veiculos = "veiculos.txt";

    // as funções para abrir o arquivo e deixa ele bonito, formatação

    int qt_proprietario = arquivo_p(arq_proprietario,proprietario);
    int qt_veiculo = arquivo_v(arq_veiculos,veiculo);

    // função que não retorna nada, vulgo: void 

    informa(proprietario, veiculo, qt_proprietario, qt_veiculo);

    return 0;
}