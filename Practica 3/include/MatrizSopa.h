#include <iostream>
#include <string>

#ifndef __MATRIZ_SOPA_H__
#define __MATRIZ_SOPA_H__

using namespace std;

class matriz_sopa
{
	private:
		int fil,col;
		char** matriz;
	public:
		matriz_sopa();
		matriz_sopa(const int ,const int);
		matriz_sopa(const matriz_sopa &);
		matriz_sopa(const string &);
		~matriz_sopa();
		int getFil() const;
		int getCol() const;
		char get(const int, const int) const;
};

#endif // __MATRIZ_SOPA_H__
