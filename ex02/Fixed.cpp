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

Fixed::Fixed(void): value(0) {}

Fixed::Fixed(const int value): value(value * ft_pow(2, this->frac)) {}

Fixed::Fixed(const float value): value(roundf(value * ft_pow(2, this->frac))) {
	this->value = roundf(this->value);
}

Fixed::~Fixed(void) {}

Fixed::Fixed(Fixed const &copy) {
	*this = copy;
}

float	Fixed::toFloat(void) const {
	return (this->value * ft_pow(2, -this->frac));
}

int	Fixed::toInt(void) const {
	return (this->value * ft_pow(2, -this->frac));
}

Fixed	&Fixed::operator=(Fixed const &copy) {
	this->value = copy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &copy) const {
	Fixed	result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &copy) const {
	Fixed	result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &copy) const {
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &copy) const {
	Fixed	result(this->toFloat() / copy.toFloat());
	return (result);
}

bool	Fixed::operator==(const Fixed &copy) const {
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(const Fixed &copy) const {
	return (this->toFloat() != copy.toFloat());
}

bool	Fixed::operator<=(const Fixed &copy) const {
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator>=(const Fixed &copy) const {
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<(const Fixed &copy) const {
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>(const Fixed &copy) const {
	return (this->toFloat() > copy.toFloat());
}

Fixed	&Fixed::operator++(void) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int value) {
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (aux);
}

Fixed	Fixed::operator--(int value) {
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (aux);
}

const Fixed	&Fixed::min(Fixed const &copy1, Fixed const &copy2) {
	if (copy1 < copy2)
		return (copy1);
	return (copy2);
}

const Fixed	&Fixed::max(Fixed const &copy1, Fixed const &copy2) {
	if (copy1 > copy2)
		return (copy1);
	return (copy2);
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
