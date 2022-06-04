#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

# define GREEN	"\033[1;32m"
# define WHITE	"\033[0;37m"


class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
public:
	// Constructors and Destructor.
	ClapTrap();
	ClapTrap(const ClapTrap &);
	ClapTrap(const std::string &name);
	~ClapTrap();

	// Overload Member functions
	ClapTrap	&operator=(const ClapTrap &);

	// Member functions
	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	void 		setName(const std::string &name);
	void		setHitPoints(unsigned int hitPoints);
	void		setEnergyPoints(unsigned int energyPoints);
	void		setAttackDamage(unsigned int attackDamage);
	
	const std::string	&getName() const;
	unsigned int		getHitPoints() const;
	unsigned int		getEnergyPoints() const;
	unsigned int		getAttackDamage() const;

};

#endif