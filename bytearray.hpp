// bytearray.hpp - заголовочный файл с описанием класса ByteArray

#ifndef BYTE_ARRAY_HPP
#define BYTE_ARRAY_HPP

	class ByteArray 
	{
		/* Класс ByteArray управляет динамичским выделением памяти 
			для маcсива байт и размещением в нём данных ----------- */
		
		private:
		
			char *m_pbuffer;		// Указатель на буфер с выделенной памятью
			unsigned int m_size; // Размер выделенной области памяти
			unsigned int length; // Размер памяти, которую на данный 
										// момент занимают данные
		
		public:
		
			/* Конcтрукторы и деструкторы класса (bytearray.cpp) */
			
				ByteArray();
				ByteArray(unsigned int size);
				ByteArray(const ByteArray & bytearray);
				ByteArray(const char *buf, unsigned int size);			
				virtual ~ByteArray();
				
			/* Селекторы класса */
			
				int getSize() const { return m_size; }
				int getLength() const { return length; }
				const char *getData() const { return m_pbuffer; }
				
			/* Модификаторы класса (setsize.cpp, setbuffer.cpp) */
			
				void setSize(unsigned int size);
				void setData(const ByteArray & bytearray);
				void setData(const char *buffer, unsigned int size);
				
			/* Методы для добавления данных в массив (adddata.cpp) */
			
				void addData(const ByteArray & bytearray);
				void addData(const char *buffer, int size);
				
			/* Другие методы класса (bytearray.cpp) */
			
				void clear();						
				void reset();
		
	}; // class ByteArray

#endif // BYTE_ARRAY_HPP
