/* bytearray.hpp - файл исходного кода с реализацией конструкторов,
					 	 деструкторов и некоторых других методов класса 
 					    ByteArray -------------------------------------- */

#include "bytearray.hpp"

	ByteArray::ByteArray()
	{
		/* Реализация конструктора класса по умолчанию */
		
			m_pbuffer = nullptr;
			m_size = 0;
			length = 0;
	}
	
	ByteArray::ByteArray(unsigned int size)
	{
		/* Релизация пользовательского конструктора (version 1) */
		
			if(size == 0) return;
			
			m_pbuffer = new char[size];
			m_size = size;
			length = 0;
			
			clear();
	}
		
	ByteArray::ByteArray(const char *buffer, unsigned int size)
	{
		/* Релизация пользовательского конструктора (version 2) */
		
			if(buffer == nullptr || size == 0) return;
			
			m_pbuffer = new char[size];
			m_size = size;
			length = 0;
			
			clear();
	}
		
	ByteArray::ByteArray(const ByteArray & bytearray)
	{
		/* Релизация конструктора копирования */
		
			if(bytearray.m_size == 0) return;
			
			m_pbuffer = new char[bytearray.m_size];
			m_size = bytearray.m_size;
			length = bytearray.length;
				
			for(unsigned int i = 0; i < m_size; ++i)
				m_pbuffer[i] = bytearray.m_pbuffer[i];
	}
	
	ByteArray::~ByteArray()
	{
		/* Релизация деструктора по умолчанию */
		
			delete [] m_pbuffer;
	}
	
	void ByteArray::clear()
	{
		/* Очистка буфера от данных */
		
			for(unsigned int i = 0; i < m_size; ++i) 
				m_pbuffer[i] = '\0';
			
			length = 0;
	}
	
	void ByteArray::reset()
	{
		/* Сброс буфера (освобождение памяти буфера) */
		
			delete [] m_pbuffer;
			
			m_pbuffer = nullptr;
			m_size = 0;
			length = 0;
	}
