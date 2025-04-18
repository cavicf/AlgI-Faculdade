<<<<<<< HEAD
# 🧮 Trabalho 01 - Multiplicação de Matrizes

**Disciplina:** STCO01 - 2024/2  
**Entrega:** 11/10/2024  

**Dupla:**  
- Camily Victal Finamor  
- Pedro Luiz de Moraes Ferreira  

---

## 📄 Descrição

Este projeto tem como objetivo implementar um algoritmo em linguagem **C** para realizar a **multiplicação de matrizes aplicada a imagens no formato PPM (P3)** e a um filtro RGB, onde cada cor é representada por valores inteiros entre 0 e 255.

A multiplicação é feita cor a cor entre cada pixel da imagem e o correspondente pixel do filtro, e o resultado é impresso novamente no formato PPM. O filtro pode ser usado, por exemplo, para aplicar efeitos como inversão, remoção de cores ou deslocamentos visuais.

---

## 🖼️ Formato da Entrada

O programa recebe da entrada padrão:

- **Cabeçalho do PPM:**
  ```
  P3
  n n
  255
  ```

- **Matriz da imagem** `n x n` (com pixels RGB).  
- **Matriz filtro** `n x n` (com pixels RGB contendo apenas valores 0 ou 1).  

Exemplo de um pixel: `255 0 0` (vermelho puro).

---

## ⚙️ Funcionalidades Implementadas

- ✅ Leitura dinâmica das matrizes da imagem e do filtro  
- ✅ Multiplicação individual de cada componente RGB  
- ✅ Impressão do resultado no formato PPM  
- ✅ Liberação correta da memória dinâmica utilizada  

### Estrutura modular do código:

- 🧱 Criação de matrizes  
- ✖️ Multiplicação  
- 🖨️ Impressão do resultado  
- 🧹 Liberação da memória (função recursiva)

---

## 🧠 Estratégias e Boas Práticas Adotadas

- 🧩 Uso de `struct pixel` para representar um pixel RGB  
- 📝 Organização por sessões com **comentários claros**  
- 📌 Declaração das assinaturas de funções antes do `main`  
- 🧰 Modularização para facilitar manutenção e leitura  
- 🧠 Uso de **ponteiros duplos** para manipulação dinâmica de matrizes

---

## 💡 Dificuldades Encontradas

Durante o desenvolvimento, enfrentamos alguns desafios que nos ajudaram a fortalecer o entendimento sobre ponteiros e alocação dinâmica em C:

- ❗ **Manipulação de ponteiros de ponteiros:**  
  Entender como manipular e acessar elementos em uma matriz de structs dinamicamente alocada foi inicialmente confuso. Superamos isso criando funções separadas e testando blocos pequenos do código individualmente.

- 💥 **Segmentação de memória (Segmentation Faults):**  
  Ocorreram erros ao tentar acessar posições de memória não alocadas corretamente. A solução foi revisar cuidadosamente cada `malloc` e garantir que todos os acessos estavam dentro dos limites.

- 🔁 **Liberação de memória:**  
  Para evitar vazamentos de memória, implementamos uma **função recursiva** para liberar corretamente todas as linhas das matrizes.

---

## 🧪 Testes

O programa foi testado com diversas entradas de imagens e filtros, incluindo:

- ✅ Filtros identidade (não alteram a imagem)  
- ✅ Filtros que removem uma cor (como o azul)  
- ✅ Filtros que invertem a imagem horizontalmente  

---

## 🧼 Exemplo de Execução

### Entrada:
```plaintext
P3
4 4
255
255 0 0 255 0 0 0 255 0 0 255 0
...
(Final da imagem)
...
Filtro:
0 0 0 1 1 1 0 0 0 0 0 0
...
```

### Saída:
```plaintext
P3
4 4
255
0 255 0 0 255 0 0 0 0 0 0 0
...
```

---

## 📚 Aprendizados

Este trabalho nos proporcionou um aprendizado sólido sobre:

- Leitura e interpretação de arquivos PPM  
- Organização modular em C  
- Uso de structs, ponteiros e memória dinâmica  
- Importância da clareza e estruturação no código

---

## 🚀 Execução

Para compilar e executar o programa:

```bash
gcc trabalho_matrizes.c -o matriz
./matriz < entrada.txt > saida.ppm
```

> Certifique-se de redirecionar corretamente os arquivos de entrada e saída.

---

## ✅ Status

- ✔️ Entregue na plataforma RunCodes  
- ✔️ Executa corretamente todos os testes  
- ✔️ Dentro do limite de tempo (menos de 1 segundo)  
- ✔️ Sem vazamentos de memória  
- ✔️ Sem uso de bibliotecas externas  
=======
# ♟️ Trabalho 02 - Problema das N Rainhas com Pilha

**Disciplina:** STCO01 - 2024/2  
**Entrega:** 30/10/2024  

**Dupla:**  
- Camily Victal Finamor  
- Pedro Luiz de Moraes Ferreira  

---

## 📄 Descrição

Este projeto tem como objetivo implementar uma solução para o **Problema das N Rainhas** utilizando exclusivamente uma **estrutura de pilha** em linguagem **C**, substituindo a abordagem recursiva normalmente usada para backtracking.

O programa deve encontrar todas as formas possíveis de posicionar `n` rainhas em um tabuleiro `n x n`, de maneira que nenhuma rainha ataque outra, ou seja, que não compartilhem a mesma linha, coluna ou diagonal.

---

## 📥 Formato da Entrada

O programa recebe da **entrada padrão**:

- Um único número inteiro `n` representando o tamanho do tabuleiro `n x n`.

---

## 🖨️ Formato da Saída

Para cada solução encontrada:

- Uma impressão do tabuleiro com `n` linhas, cada uma contendo `n` posições:
  - `"R "` representa uma casa com uma rainha  
  - `"_ "` representa uma casa vazia

- Uma **linha em branco** separa cada solução.

As soluções são impressas em **ordem lexicográfica**, considerando as posições das rainhas.

### Exemplo de saída para `n = 4`:
```
R _ _ _ 
_ _ R _ 
_ R _ _ 
_ _ _ R 

R _ _ _ 
_ _ _ R 
_ R _ _ 
_ _ R _ 
```

---

## ⚙️ Funcionalidades Implementadas

- ✅ Resolução completa do problema das N rainhas com uso de pilha  
- ✅ Impressão de todas as soluções possíveis em ordem lexicográfica  
- ✅ Controle de backtracking utilizando pilha ao invés de recursão  
- ✅ Liberação correta da memória utilizada  

### Estrutura modular do código:

- 📥 Leitura da entrada  
- 🧠 Resolução iterativa com pilha (substituindo a recursão)  
- 🖨️ Impressão formatada das soluções  
- 🧹 Liberação de memória

---

## 🧠 Estratégias e Boas Práticas Adotadas

- 📦 Uso de uma **TAD Pilha** implementada com lista encadeada  
- 🧱 Representação da solução parcial como colunas empilhadas  
- 🔄 Backtracking feito de forma iterativa simulando a pilha da recursão  
- 🧰 Modularização clara e intuitiva  
- 🧼 Uso rigoroso de `malloc` e `free` para evitar vazamentos de memória

---

## 💡 Dificuldades Encontradas

Durante o desenvolvimento, enfrentamos desafios importantes que contribuíram para nosso amadurecimento na manipulação de estruturas de dados:

- 🤹‍♀️ **Simular recursão com pilha:**  
  Traduzir a lógica de backtracking recursivo para uma abordagem iterativa exigiu muito raciocínio e testes para manter o controle correto do estado do tabuleiro.

- 🧩 **Verificação de ataques diagonais:**  
  Implementar a verificação de ameaças em diagonais de forma eficiente foi um ponto crítico do algoritmo.

- 🔁 **Controle de loop e pilha simultaneamente:**  
  Conciliar o avanço e retrocesso no tabuleiro apenas manipulando a pilha sem perder o controle das colunas testadas foi um desafio importante.

---

## 🧪 Testes

O programa foi testado com múltiplos valores de `n`:

- ✅ Casos pequenos (`n = 1`, `n = 2`, `n = 3`)  
- ✅ Casos clássicos (`n = 4`, `n = 5`, `n = 8`)  
- ✅ Casos maiores para verificar performance
- ✅ Verificação de ordenação lexicográfica correta nas soluções  

---

## 🧼 Exemplo de Execução

### Entrada:
```
4
```

### Saída:
```
R _ _ _ 
_ _ R _ 
_ R _ _ 
_ _ _ R 

R _ _ _ 
_ _ _ R 
_ R _ _ 
_ _ R _ 
```

---

## 📚 Aprendizados

Este trabalho nos proporcionou um aprendizado valioso sobre:

- Simulação de chamadas recursivas utilizando pilha  
- Organização modular e separação de responsabilidades no código  
- Manipulação de listas encadeadas  
- Gerenciamento manual de memória dinâmica em C  
- Lógica de backtracking aplicada a problemas clássicos

---

## 🚀 Execução

Para compilar e executar o programa:

```bash
gcc pilha.c n_queens_pilha.c -o nrainhas
./nrainhas < entrada.txt
```

> O arquivo `entrada.txt` deve conter apenas o número `n` na primeira linha.

---

## ✅ Status

- ✔️ Entregue na plataforma RunCodes  
- ✔️ Executa corretamente todos os testes  
- ✔️ Dentro do limite de tempo (menos de 1 segundo)  
- ✔️ Sem vazamentos de memória (validação com Valgrind)  
- ✔️ Sem uso de bibliotecas externas  
>>>>>>> 6474c7b28bc81ef16d04e9b412009f1ca51a6def
