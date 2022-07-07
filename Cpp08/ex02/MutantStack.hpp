#ifndef MUTANTSTACK_HPP
#define	MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy) {}
	~MutantStack() {}

	MutantStack &operator=(const MutantStack<T> &obj)
	{
		if (*this != obj)
		{
			this = obj;
		}
		return *this;
	}

	iterator begin()
	{
		// return (std::stack<T>::c.begin());
		return (this->c.begin());
	}
	iterator end()
	{
		// return (std::stack<T>::c.end());
		return (this->c.end());
	}
};

#endif