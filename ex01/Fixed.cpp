#include "Fixed.hpp"

static	float ft_pow(float base, int exp) {
	float	result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

const int	Fixed::frac = 8;

Fixed::Fixed(void): value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): value(value * ft_pow(2, this->frac)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value): value(value * ft_pow(2, this->frac)) {
	this->value = roundf(value * ft_pow(2, this->frac));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

int	Fixed::getRawBits(void) const {
	return (this->value);
}

void	Fixed::setRawBits(const int raw) {
	this->value = raw;
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr) {
	return (str << fixed_nbr.toFloat());
}

int	Fixed::toInt(void) const {
	return (this->value * ft_pow(2, -this->frac));
}

float	Fixed::toFloat(void) const {
	return (this->value * ft_pow(2, -this->frac));
}

Fixed	&Fixed::operator=(Fixed const &copy) {
	std::cout << "Assignation operator called" << std::endl;
	this->value = copy.getRawBits();
	return (*this);
}
