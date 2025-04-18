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
