/*
 * EEPROM.h
 *
 * Created: 2/24/2020 12:08:19 AM
 *  Author: GaD_Bogdan
 */ 


#ifndef EEPROM_LIB_H_
#define EEPROM_LIB_H_

#include "main.h"

//==================================================================================================

/*Функция для инициализиции EEPROM, вызов не обязателен.*/
void EEPROM_init(void);

//==================================================================================================

/*Запись одного байта ucData в EEPROM по адресу uiAddress.*/
void EEPROM_write_byte(unsigned int uiAddress, unsigned char ucData);

//==================================================================================================

/*Чтение одного байта из EEPROM по адресу uiAddress.
  Возвращает прочитанный байт.*/
unsigned char EEPROM_read_byte(unsigned int uiAddress);

//==================================================================================================

/*Запись двух байт (int) ucData в EEPROM по адресу uiAddress.
  Функции передать указатель на переменную, использовав оператор
  разименования &*/
void EEPROM_write_word(unsigned int uiAddress, unsigned char *p_ucData);

//==================================================================================================

/*Чтение двух байт (int) ucData из EEPROM по адресу uiAddress.
  Функции передать указатель на переменную, в которую будут
  записаны данные, использовав оператор, разименования &*/
void EEPROM_read_word(unsigned int uiAddress, unsigned char *p_ucData);

//==================================================================================================

/*Запись четырех байт (long) ucData в EEPROM по адресу uiAddress.
  Функции передать указатель на переменную, использовав оператор
  разименования &*/
void EEPROM_write_dword(unsigned int uiAddress, unsigned char *p_ucData);

//==================================================================================================

/*Чтение четырех байт (long) ucData из EEPROM по адресу uiAddress.
  Функции передать указатель на переменную, в которую будут
  записаны данные, использовав оператор, разименования &*/
void EEPROM_read_dword(unsigned int uiAddress, unsigned char *p_ucData);

//==================================================================================================

/*Функция для записи строчного массива(должен оканчиваться нулем!)
  в EEPROM по адресу uiAddress.*/
void EEPROM_write_string(unsigned int uiAddress, char *string);

//==================================================================================================

/*!!!После исползования строки обязательно освободить память функцией free()!!!
  Функция для чтения строки длиной size символов (без учета нуля, т.е. Hello! это size = 6, но
  функция вернет массив из 7 элементво (под индексом 6 будет 0, означающий окончание строки) из
  EEPROM по адресу uiAdress. Возваращает указатель на первый элемент. */
char * EEPROM_read_string(unsigned int uiAddress, unsigned char size);
/*!!!После исползования строки обязательно освободить память функцией free()!!!
  Пример: char temp*;
          temp = EEPROM_read_string(Address, size);
		  free(temp);
*/

//==================================================================================================

/*!!!После исползования строки обязательно освободить память функцией free()!!!
  Функция для чтения строки длиной size символов (без учета нуля, т.е. Hello! это size = 6, но
  функция вернет массив из 7 элементво (под индексом 6 будет 0, означающий окончание строки) из
  EEPROM по адресу uiAdress. Возваращает указатель на первый элемент.
  Size > 255 */
char * EEPROM_read_string_for_int_size(unsigned int uiAddress, unsigned int size);
/*!!!После исползования строки обязательно освободить память функцией free()!!!
  Пример: char temp*;
          temp = EEPROM_read_string(Address, size);
		  free(temp);
*/

//==================================================================================================

#endif /* EEPROM_LIB_H_ */