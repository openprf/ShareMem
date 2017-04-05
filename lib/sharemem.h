#ifndef SHAREMEM_H_INCLUDED
#define SHAREMEM_H_INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif

/**
Выделение разделяемой памяти. Копирование буфера в выделенную память
Возвращает дескриптер памяти или код ошибки
**/
int sharemem_post(char* mem_name, void* data_ptr, int data_size);

/**
Получения доступа к разделяемой памяти через указатель
Возвращает указатель на память или NULL
Отрицательный размер - это код ошибки
**/
char* sharemem_get(char* mem_name, int* data_size);

/**
освобождает разделяемую память
**/
int sharemem_free(char* mem_name);
#ifdef __cplusplus
}
#endif

#endif // SHAREMEM_H_INCLUDED
