#include <iostream>
#include <string>

using namespace std;

#ifndef __VECTOR_PALABRAS_H__
#define __VECTOR_PALABRAS_H__

class vector_palabras
{
	private:
		int ocupado,reserva;
		string* vector;

		void resize();
	public:
		vector_palabras();
		vector_palabras(const int);
		vector_palabras(const vector_palabras &);
		~vector_palabras();
		void aniade(const string &);
		int getOcupado() const;
		string get(const int) const;

		vector_palabras & operator=(const vector_palabras &);
};

#endif // __VECTOR_PALABRAS_H__
