#include "hospital.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Função para criar um novo paciente*/
Patient *create_patient(int id, const char *name, struct tm *birthdate) {
  Patient *new_patient = (Patient *)malloc(sizeof(Patient));
  if (new_patient == NULL) {
    fprintf(stderr, "Erro ao alocar memória\n");
    exit(1);
  }

  new_patient->id = id;
  new_patient->name = strdup(name);
  new_patient->birthdate = (struct tm *)malloc(sizeof(struct tm));
  if (new_patient->birthdate == NULL) {
    fprintf(stderr, "Erro ao alocar memória para birthdate\n");
    free(new_patient->name);
    free(new_patient);
    exit(1);
  }
  memcpy(new_patient->birthdate, birthdate, sizeof(struct tm));

  return new_patient;
}

/* Função para destruir um paciente*/
void destroy_patient(Patient *patient) {
  if (patient != NULL) {
    free(patient->name);
    free(patient->birthdate);
    free(patient);
  }
}

/*Função para obter o ID do paciente*/
int get_patient_id(Patient *patient) { return patient->id; }

/*Função para obter o nome do paciente*/
const char *get_patient_name(Patient *patient) { return patient->name; }

// Função para obter a data de nascimento do paciente
struct tm *get_patient_birthdate(Patient *patient) {
  return patient->birthdate;
}

/* Função para imprimir os detalhes do paciente */
void print_patient(Patient *patient) {
  printf("ID: %d\n", patient->id);
  printf("Nome: %s\n", patient->name);
  printf("Data de Nascimento: %02d-%02d-%04d\n", patient->birthdate->tm_mday,
         patient->birthdate->tm_mon + 1, patient->birthdate->tm_year + 1900);
}

/* Função para criar um novo exame*/
Exam *create_exam(int id, int patient_id, int rx_id, struct tm *time) {
  Exam *new_exam = (Exam *)malloc(sizeof(Exam));
  if (new_exam == NULL) {
    fprintf(stderr, "Erro ao alocar memória\n");
    exit(1);
  }

  new_exam->id = id;
  new_exam->patient_id = patient_id;
  new_exam->rx_id = rx_id;
  new_exam->time = (struct tm *)malloc(sizeof(struct tm));
  if (new_exam->time == NULL) {
    fprintf(stderr, "Erro ao alocar memória para time\n");
    free(new_exam);
    exit(1);
  }
  memcpy(new_exam->time, time, sizeof(struct tm));

  return new_exam;
}

/* Função para destruir um exame*/
void destroy_exam(Exam *exam) {
  if (exam != NULL) {
    free(exam->time);
    free(exam);
  }
}

/* Função para obter o ID do exame*/
int get_exam_id(Exam *exam) { return exam->id; }

/* Função para obter o ID do paciente associado ao exame*/
int get_exam_patient_id(Exam *exam) { return exam->patient_id; }

/* Função para obter o ID do aparelho de raio-X utilizado no exame*/
int get_exam_rx_id(Exam *exam) { return exam->rx_id; }

/* Função para obter o horário de realização do exame */
struct tm *get_exam_time(Exam *exam) {
  return exam->time;
}

/*Função para imprimir os detalhes do exame 
void print_exam(Exam *exam) {
  printf("Exam ID: %d\n", exam->id);
  printf("Patient ID: %d\n", exam->patient_id);
  printf("RX ID: %d\n", exam->rx_id);
  printf("Time: %02d-%02d-%04d %02d:%02d:%02d\n", exam->time->tm_mday,
         exam->time->tm_mon + 1, exam->time->tm_year + 1900,
         exam->time->tm_hour, exam->time->tm_min, exam->time->tm_sec);
}
