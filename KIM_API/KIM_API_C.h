
//
// Release: This file is part of the openkim-api.git repository.
//
// Copyright 2011 Ellad B. Tadmor, Ryan S. Elliott, and James P. Sethna
// All rights reserved.
//
// Authors: Valeriu Smirichinski, Ryan S. Elliott, Ellad B. Tadmor
//

#ifndef _KIMSERVICC_H
#define	_KIMSERVICC_H

#ifndef KIM_API_MAX_NEIGHBORS
#define KIM_API_MAX_NEIGHBORS 512
#endif

#include <stdint.h>
//#include "KIM_API.h"
//#define intptr_t long long  // for 64 bit machines
#ifdef	__cplusplus
extern "C" {
#endif
//global methods
int KIM_API_init(void * kimmdl, char *testname, char *modelname);
int KIM_API_init1(void * kimmdl, char * testinputf,char * testname, char * mdlinputf,char *mdlname);

int KIM_API_model_info(void * kimmdl, char * mdlname);

int KIM_API_string_init(void * kimmdl, char *testinputstring, char * modelname);
void KIM_API_allocate(void *kimmdl, int natoms, int ntypes, int * error);
void KIM_API_free(void *kimmdl,int * error);
void KIM_API_print(void *kimmdl,int *error);
void KIM_API_model_compute(void *kimmdl,int *error);
int KIM_API_model_init(void * kimmdl);
char * KIM_API_get_model_kim_str(char *modelname,int * error);
void KIM_API_model_destroy(void * kimmdl,int * error);
int KIM_API_model_reinit(void * kimmdl);



char * KIM_API_get_partcl_types(void * kimmdl,int* nATypes, int * error);
int KIM_API_get_partcl_type_code(void * kimmdl, char* atom, int * error);

char * KIM_API_get_params(void * kimmdl,int* nVpar, int * error);
char * KIM_API_get_free_params(void * kimmdl,int* nVpar, int * error);
char * KIM_API_get_fixed_params(void * kimmdl,int* nVpar, int * error);

char * KIM_API_get_NBC_method(void *kimmdl,int * error);

int KIM_API_get_neigh(void *kimmdl,int mode,int request,
        int *atom, int *numnei, int **nei1atom, double **Rij);

int KIM_API_get_neigh_mode(void *kimmdl,int *error);

char * KIM_API_get_status_msg(int error);
    
int KIM_API_report_error(int ln,char * fl,char * usermsg,int error);

int KIM_API_get_model_index_shift(void *kimmdl);

void KIM_API_set_model_buffer(void * kimmdl,void * ob, int * error);
void * KIM_API_get_model_buffer(void * kimmdl, int * error);
void KIM_API_set_test_buffer(void * kimmdl,void * ob, int * error);
void * KIM_API_get_test_buffer(void * kimmdl, int * error);

int KIM_API_is_half_neighbors(void *kimmdl,int * error);

//element access methods
int  KIM_API_set_data(void *kimmdl,char *nm,  intptr_t size, void *dt);
void * KIM_API_get_data(void *kimmdl,char *nm,int * error);

intptr_t KIM_API_get_size(void *kimmdl,char *nm, int * error);
intptr_t KIM_API_get_shape(void *kimmdl,char *nm, int * shape, int *error);
void KIM_API_set_shape(void *kimmdl,char *nm, int * shape, int rank,int *error);

void KIM_API_set_compute(void *kimmdl,char *nm, int flag, int *error);
void KIM_API_set_compute_by_index(void *kimmdl, int I, int flag, int *error);
int KIM_API_get_compute(void *kimmdl,char *nm,int *error);

int KIM_API_get_index(void *kimmdl,char *nm, int * error);

void KIM_API_set_data_by_index(void *kimmdl,int I, intptr_t size, void *dt, int * error);
void * KIM_API_get_data_by_index(void *kimmdl,int I, int *error);

intptr_t KIM_API_get_size_by_index(void *kimmdl,int I,int *error);
intptr_t KIM_API_get_shape_by_index(void *kimmdl,int I, int * shape,int *error);

int KIM_API_get_compute_by_index(void *kimmdl,int I,int * error);

void KIM_API_process_dEdr(void **kimmdl, double * dE, double * dr, double **dx,int *i, int *j, int *error );
void KIM_API_process_d2Edr2(void **kimmdl, double * dE, double ** dr, double **dx,int **i, int **j, int *error );
//related to Unit_Handling
double KIM_API_get_scale_conversion(char *u_from,char *u_to, int *error);
int    KIM_API_get_unit_handling(void *kimmdl,int *error);
char * KIM_API_get_unit_length(void *kimmdl, int *error);
char * KIM_API_get_unit_energy(void *kimmdl, int *error);
char * KIM_API_get_unit_charge(void *kimmdl, int *error);
char * KIM_API_get_unit_temperature(void *kimmdl, int *error);
char * KIM_API_get_unit_time(void *kimmdl, int *error);

double KIM_API_convert_to_act_unit(void * kimmdl,
                                char *length,
                                char *energy,
                                char *charge,
                                char *temperature,
                                char *time,
                                double length_exponent,
                                double energy_exponent,
                                double charge_exponent,
                                double temperature_exponent,
                                double time_exponent,
                                int *error);


//multiple data set/get methods
//
void KIM_API_setm_data(void *kimmdl, int *error, int numargs, ... );
void KIM_API_setm_data_by_index(void *kimmdl, int *error, int numargs, ... );
void KIM_API_getm_data(void *kimmdl, int *error,int numargs, ...);
void KIM_API_getm_data_by_index(void *kimmdl,int *error,int numargs, ...);
void KIM_API_getm_index(void *kimmdl, int *error, int numargs, ...);
void KIM_API_setm_compute(void *kimmdl, int *error, int numargs, ...);
void KIM_API_setm_compute_by_index(void *kimmdl, int *error, int numargs, ...);
void KIM_API_getm_compute(void *kimmdl, int *error,int numargs, ...);
void KIM_API_getm_compute_by_index(void *kimmdl, int *error,int numargs, ...);

//total 58 service routines

//fortran interface
int kim_api_init_(void * kimmdl,char ** testname, char **mdlname);
int kim_api_init1_(void * kimmdl, char ** testinputf,char ** testname, char ** mdlinputf,char **mdlname);
int kim_api_model_info_(void * kimmdl,char ** mdlname);
int kim_api_string_init_(void * kimmdl, char **testinputstring, char ** modelname);
void kim_api_allocate_(void *kimmdl, int *natoms, int *ntypes, int *error);
void kim_api_free_(void *kimmdl, int * error);
void kim_api_print_(void *kimmdl,int * error);
void kim_api_model_compute_f_(void*kimmdl, int *error);

int kim_api_model_reinit_f_(void * kimmdl);
void kim_api_model_destroy_f_(void * kimmdl, int * error);

int kim_api_model_init_f_(void * kimmdl);

void * kim_api_get_model_kim_str_(char **modelname,int *ln,int *kimerr);

int kim_api_get_neigh_mode_f_(void *kimmdl,int *error);

void * kim_api_get_partcl_types_f_(void * kimmdl,int* nATypes, int* error);
void * kim_api_get_params_f_(void * kimmdl,int* nVpar, int* error);
void * kim_api_get_free_params_f_(void * kimmdl,int* nVpar, int* error);
void * kim_api_get_fixed_params_f_(void * kimmdl,int* nVpar, int* error);

void * kim_api_get_nbc_method_f_(void * kimmdl,int* error);

int kim_api_get_partcl_type_code_(void * kimmdl, char** atom, int * error);

int kim_api_get_neigh_f_(void *kimmdl,int *mode,int *request,
        int *atom, int *numnei, int **nei1atom, double **Rij);

int kim_api_get_model_index_shift_f_(void * kimmdl);

void kim_api_set_model_buffer_f_(void * kimmdl,void * ob, int * ier);
void * kim_api_get_model_buffer_f_(void * kimmdl, int * ier);
void kim_api_set_test_buffer_f_(void * kimmdl,void * ob, int * ier);
void * kim_api_get_test_buffer_f_(void * kimmdl, int * ier);

int kim_api_is_half_neighbors_f_(void * kimmdl,int *ier);

//element access methods

int  kim_api_set_data_(void *kimmdl,char **nm,  intptr_t *size, void *dt);
void * kim_api_get_data_(void *kimmdl,char **nm, int *error);
void * kim_api_get_data_cptr_(void *kimmdl,char **nm, int *error);

intptr_t kim_api_get_size_(void *kimmdl,char **nm,int *error);
intptr_t kim_api_get_shape_(void *kimmdl,char **nm, int ** shape, int *error);
void kim_api_set_shape_(void *kimmdl,char **nm, int ** shape, int * rank,int *error);

void kim_api_set_compute_(void *kimmdl,char **nm, int *flag, int *error);
void kim_api_set_compute_by_index_f_(void *kimmdl, int *I, int *flag, int *error);
int kim_api_get_compute_(void *kimmdl,char **nm, int *error);

int kim_api_get_index_(void *kimmdl,char**nm, int *error);

void kim_api_set_data_by_index_(void *kimmdl,int * I, intptr_t * size, void *dt, int *error);
void * kim_api_get_data_by_index_(void *kimmdl,int * I, int *error);

intptr_t kim_api_get_size_by_index_(void *kimmdl,int * I, int *error);
intptr_t kim_api_get_shape_by_index_(void *kimmdl,int * I, int ** shape, int *error);

int kim_api_get_compute_by_index_(void *kimmdl,int * I, int *error);

void * kim_api_get_status_msg_f_(int * error);

int kim_api_report_error_(int * ln,char ** fl, char ** usermsg, int * ier);

void kim_api_process_dedr_f_(void **ppkim, double * dE, double * dr, double **dx, int *i, int *j, int *ier );
void kim_api_process_d2edr2_f_(void **ppkim, double * dE, double ** dr, double **dx, int **i, int **j, int *ier );

//related to Unit_Handling
double kim_api_get_scale_conversion_(char **u_from,char **u_to, int *error);
int    kim_api_get_unit_handling_f_(void *kimmdl,int *error);
char * kim_api_get_unit_length_f_(void *kimmdl, int *error);
char * kim_api_get_unit_energy_f_(void *kimmdl, int *error);
char * kim_api_get_unit_charge_f_(void *kimmdl, int *error);
char * kim_api_get_unit_temperature_f_(void *kimmdl, int *error);
char * kim_api_get_unit_time_f_(void *kimmdl, int *error);
double kim_api_convert_to_act_unit_(void * kimmdl,
                                char **length,
                                char **energy,
                                char **charge,
                                char **temperature,
                                char **time,
                                double *length_exponent,
                                double *energy_exponent,
                                double *charge_exponent,
                                double *temperature_exponent,
                                double *time_exponent,
                                int* kimerror);
#ifdef	__cplusplus
}
#endif

#endif	/* _KIMSERVICC_H */