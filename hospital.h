#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <time.h>

/* Definição da estrutura Patient*/
typedef struct {
  int id;
  char *name;
  struct tm *birthdate;
} Patient;

/*Funções para manipulação de Patient*/
Patient *create_patient(int id, const char *name, struct tm *birthdate);
void destroy_patient(Patient *patient);
int get_patient_id(Patient *patient);
const char *get_patient_name(Patient *patient);
struct tm *get_patient_birthdate(Patient *patient);
void print_patient(Patient *patient);

/* Definição da estrutura Exam*/
typedef struct {
  int id;
  int patient_id;
  int rx_id;
  struct tm *time;
} Exam;

/* Funções para manipulação de Exam*/
Exam *create_exam(int id, int patient_id, int rx_id, struct tm *time);
void destroy_exam(Exam *exam);
int get_exam_id(Exam *exam);
int get_exam_patient_id(Exam *exam);
int get_exam_rx_id(Exam *exam);
struct tm *get_exam_time(Exam *exam);
void print_exam(Exam *exam);

#endif /*HOSPITAL_H*/
