#ifndef FLOOR_HPP
# define FLOOR_HPP
# include "AMateria.hpp"

class Floor
{
private:
	static int size;
	static AMateria **list;

public:
	Floor();
	Floor(const Floor &f);
	Floor& operator=(const Floor &f);
	~Floor();

	static void set_list(AMateria *a);
};

#endif
