

#ifndef _TDOCUMENTO_H_
#define _TDOCUMENTO_H_

typedef struct tDocumento tDocumento;

/**
 * Funções de callback que serão utilizadas para imprimir o documento na tela,
 * em arquivo e desalocar o dado genérico, respectivamente.
 */
typedef void (*func_ptr_imprimeNaTela)(void *dado);
typedef void (*func_ptr_imprimeEmArquivo)(void *dado, char *path);
typedef void (*func_ptr_desaloca)(void *dado);

/**
 * Função que recebe um dado genérico (representando um tipo de documento) e suas funções de callback.
 * A função cria um Documento e retorna um ponteiro para ele.
 */
tDocumento *criaDocumento(void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                          func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                          func_ptr_desaloca desaloca);

/**
 * Função que recebe um Documento e o desaloca. O dado genérico também deve ser desalocado
 * dentro dessa função.
 */
void desalocaDocumento(tDocumento *doc);

/**
 * Função que recebe um Documento genérico e o imprime na tela.
 */
void imprimeNaTelaDocumento(tDocumento *doc);

/**
 * Função que recebe um Documento genérico e o imprime em um arquivo.
 * O path representa o caminho até o diretório onde o arquivo será criado ou editado.
 */
void imprimeEmArquivoDocumento(tDocumento *doc, char *path);

#endif