/* setdata.hpp - реализация модификаторов:
					  void setByteArray(const ByteArray & bytearray) 
					  и void setByteArray(const char *buf, int size) 
					  класса ByteArray ---------------------------- */
						 
#include "bytearray.hpp"

	void ByteArray::setData(const ByteArray & bytearray)
		{
			/* Копирование объекта буфера */
			
				if(bytearray.m_size == 0) return;
			
				if(m_size > 0) reset();
				
				m_pbuffer = new char[bytearray.m_size];
				m_size = bytearray.m_size;
				
				if(bytearray.length == 0) return;
				
				length = bytearray.length;
					
				for(unsigned int i = 0; i < length; ++i)
					m_pbuffer[i] = bytearray.m_pbuffer[i];
		}
		
	void ByteArray::setData(const char *buffer,  unsigned int size)
		{
			/* Копирование в буфер новых данных и выделение
				памяти для них, если потребуется ----------- */
			
				if(buffer == nullptr || size == 0) return;
				
				if(m_size == 0)
				{
					/* Если память для буфера еще не выделенна
						то выделяем её ------------------------- */
						
						m_pbuffer = new char[size];
						m_size = size;
				}
				
				if(m_size < size)
				{
					/* Если память для буфера была ранее выделена,  
						но её недостаточно для размещения данных, 
						то выделяем нужное количество ------------ */
						
						delete [] m_pbuffer;
						m_pbuffer = new char[size];
						m_size = size;						
				}
				
				clear();				
				length = size;
				
			/* Копирование данных в буфер */
				
				for(unsigned int i = 0; i < length; ++i)
					m_pbuffer[i] = buffer[i];				
		}	

	
						 
