## Prime Finder
Aluno: Peter Michael Claes Krause, Matrícula: 18100869


### Instruções
1) Versão sequencial

  Compile o programa com:
  ```
  gcc prime_finder_sync -o <nome_do_output>
  ```
  E rode com:
  ```
  ./<nome_do_output>
  ```

  A versão sequencial usa o número 10.000 como "teto" de busca default. Caso queira providenciar um outro limite, simplesmente rode com:

  ```
  ./<nome_do_output> 60000
  ```
  _Rodando versão sequencial passando 60.000 como teto de busca_
___
2) Versão assíncrona

  Compile o programa com:
  ```
  gcc prime_finder_async -o <nome_do_output> -pthread
  ```
  E rode com:
  ```
  ./<nome_do_output>
  ```

  A versão assíncrona usa o número 10.000 como "teto" de busca default e 2 como número default de threads. Caso queira providenciar ambos valores, rode com:

  ```
  ./<nome_do_output> 150000 10
  ```
  _Rodando versão assíncrona passando 150.000 como teto de busca e com 10 threads_
