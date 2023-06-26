#include "Fixed.hpp"

const int	Fixed::frac = 8;

Fixed::Fixed(void): value(0) {
	std::cout << "Fixed object created with default constructor" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Fixed object destroyed" << std::endl;
}

Fixed::Fixed(Fixed const & copy) {
	std::cout << "Fixed object copied" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy) {
	std::cout << "Assignment operator called" << std::endl;
	this->value = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(const int raw) {
	this->value = raw;
}
