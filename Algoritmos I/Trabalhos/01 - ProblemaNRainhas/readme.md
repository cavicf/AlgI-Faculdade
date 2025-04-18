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
