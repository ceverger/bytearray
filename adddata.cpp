// add.cpp - реализация метода adddata.cpp класса ByteArray

#include "bytearray.hpp"

	void ByteArray::addData(const ByteArray & bytearray)
	{
		/* Добавление новых данных в буфер (version 1)*/
		
			if(bytearray.m_size == 0) return;
			
			if(m_size == 0)
			{
				/* Если буфер пустой и память для него не
					выделена, выделяем её, записывем в неё
					данные и выходим из метода ----------- */
					
					setData(bytearray.m_pbuffer, bytearray.m_size);
					
					return;
			}
				
			if(m_size < length + bytearray.m_size)
				{
					/* Если памяти буфера не хватает, чтобы
						добавить новые данные, то выделяем нужное
						количество памяти ----------------------- */
						
						m_size = length + bytearray.m_size;
						setSize(m_size);						
				}
								
			/* Дозаписывваем данные в буфер */
			
				for(unsigned int i = length; i < length + bytearray.m_size; ++i)
					m_pbuffer[i] = bytearray.m_pbuffer[i];
				
				length += bytearray.m_size;
	}

	void ByteArray::addData(const char *buffer, int size)
	{
		/* Добавление новых данных в буфер (version 2) */
		
			if(buffer == nullptr || size == 0) return;
			
			if(m_size == 0)
			{
				/* Если буфер пустой и память для него не
					выделена, выделяем её, записывем в неё
					данные и выходим из метода ----------- */
					
					setData(buffer, size);
					
					return;
			}
				
			if(m_size < length + size)
				{
					/* Если памяти буфера не хватает, чтобы
						добавить новые данные, то выделяем нужное
						количество памяти ----------------------- */
						
						m_size = length + size;
						setSize(m_size);						
				}
								
			/* Дозаписывваем данные в буфер */
			
				for(unsigned int i = length; i < length + size; ++i)
					m_pbuffer[i] = buffer[i];
				
				length += size;
	}
