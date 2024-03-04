// setsize.cpp - реализация модификатора void setSize(unsigned int size)
// 				  класса ByteArray

#include "bytearray.hpp"

	void ByteArray::setSize(unsigned int size)
	{
		/* В данном методе происходит установка
		   или изменение размера буфера ------- */
			
			if(size == 0) return;
			
			if(m_size == 0)
			{
				/* Если ранее память не выделялась, то выделяем
					и выходим из метода ------------------------ */
				
				m_pbuffer = new char[size];
				m_size = size;
				
				return;
			}
			
			char *p_temp = m_pbuffer;		
			m_pbuffer = new char[size];
			m_size = size;		
			
			if(length > 0)
			{
				/* Если в старом буфере есть данные, то копируем  
					их в новый буфер учитывая его новый размер -- */
					
					length = length > m_size ? m_size : length;
					
					for(unsigned int i = 0; i < length; ++i)
						m_pbuffer[i] = p_temp[i];
			}
					
			delete [] p_temp;				 
	}	
