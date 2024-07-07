# Simulação de Exames de Raio-X em Hospital - Trabalho de Estrutura de Dados em C- Matheus Moroni Arçari Barcellos - Professor Thiago Paixão

## Descrição do Projeto

O projeto simula o processo de realização de exames de raio-X de tórax em um hospital, com ênfase na organização da fila para laudo médico. O projeto implementa dois Tipos Abstratos de Dados (TADs): `Patient` e `Exam`. Estes TADs são utilizados para modelar os pacientes que chegam ao hospital e os exames de raio-X.

## Estrutura do Projeto

O projeto está organizado nos seguintes arquivos:

- `hospital.h`: Arquivo contendo as definições das estruturas e das funções para manipulação dos TADs `Patient` e `Exam`.
- `hospital.c`: Implementação das funções definidas no arquivo hospital.c
- `main.c`: Função principal que testa a criação e uso dos TADs `Patient` e `Exam`.
- `Makefile`: Arquivo para compilar o projeto usando o comando `make`.

## Tipos Abstratos de Dados (TADs)

### Patient

O TAD `Patient` representa um paciente no sistema:

- Identificação única do paciente (`int id`)
- Nome do paciente (`char* name`)
- Data de nascimento (`struct tm* birthdate`)

Funções associadas:

- `Patient* create_patient(int id, const char *name, struct tm *birthdate)`
- `void destroy_patient(Patient *patient)`
- `int get_patient_id(Patient* patient)`
- `const char* get_patient_name(Patient* patient)`
- `struct tm* get_patient_birthdate(Patient* patient)`
- `void print_patient(Patient* patient)`

### Exam

O TAD `Exam` representa um exame realizado por um paciente com as seguintes informações:

- Identificação única do exame (`int id`)
- Identificação única do paciente (`int patient_id`)
- Identificação única do aparelho de raio-X utilizado para realização do exame (`int rx_id`)
- Horário de realização do exame (`struct tm* time`)

Funções associadas:

- `Exam* create_exam(int id, int patient_id, int rx_id, struct tm *time)`
- `void destroy_exam(Exam *exam)`
- `int get_exam_id(Exam *exam)`
- `int get_exam_patient_id(Exam *exam)`
- `int get_exam_rx_id(Exam *exam)`
- `struct tm* get_exam_time(Exam *exam)`
- `void print_exam(Exam *exam)`

## Compilação e Execução

Para compilar e executar o projeto, siga os passos abaixo:

1. Clone o repositório ou faça o download dos arquivos `hospital.h`, `hospital.c`, `main.c` e `Makefile`.
2. Abra um terminal e abra o diretório onde os arquivos foram salvos.
3. Execute o comando `make` para compilar o projeto.
4. Execute o comando `./hospital` para rodar o programa.
